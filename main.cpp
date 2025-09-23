#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string nombreArchivo = "atletas.csv";

void crearArchivo() {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::ofstream nuevoArchivo(nombreArchivo);
        nuevoArchivo << "Nombre,Pais,Disciplina,Genero,Medallas\n";
        nuevoArchivo.close();
    }
    archivo.close();
}

void registrarAtleta() {
    std::string nombre, pais, disciplina, genero;
    int medallas;

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Pais: ";
    std::getline(std::cin, pais);
    std::cout << "Disciplina: ";
    std::getline(std::cin, disciplina);
    std::cout << "Genero (M/F): ";
    std::getline(std::cin, genero);
    std::cout << "Medallas de oro: ";
    std::cin >> medallas;
    std::cin.ignore();

    std::ofstream salida(nombreArchivo, std::ios::app);
    salida << nombre << "," << pais << "," << disciplina << "," << genero << "," << medallas << "\n";
    salida.close();

    std::cout << "Atleta registrado.\n";
}

void buscarAtleta() {
    std::string nombreBuscar;
    std::cout << "Nombre del atleta a buscar: ";
    std::getline(std::cin, nombreBuscar);

    std::ifstream in(nombreArchivo);
    std::string linea;
    std::getline(in, linea);
    bool encontrado = false;

    while (std::getline(in, linea)) {
        std::stringstream ss(linea);
        std::string nombre, pais, disciplina, genero, medStr;
        std::getline(ss, nombre, ',');
        std::getline(ss, pais, ',');
        std::getline(ss, disciplina, ',');
        std::getline(ss, genero, ',');
        std::getline(ss, medStr, ',');

        if (nombre == nombreBuscar) {
            std::cout << "Pais: " << pais << " | Medallas: " << medStr << std::endl;
            encontrado = true;
        }
    }
    if (!encontrado) std::cout << "Atleta no encontrado.\n";
    in.close();
}

void medallasPorPais() {
    std::string paisBuscar;
    std::cout << "Pais: ";
    std::getline(std::cin, paisBuscar);

    std::ifstream in(nombreArchivo);
    std::string linea;
    std::getline(in, linea);
    int total = 0;

    while (std::getline(in, linea)) {
        std::stringstream ss(linea);
        std::string nombre, pais, disciplina, genero, medStr;
        std::getline(ss, nombre, ',');
        std::getline(ss, pais, ',');
        std::getline(ss, disciplina, ',');
        std::getline(ss, genero, ',');
        std::getline(ss, medStr, ',');

        if (pais == paisBuscar) {
            total += std::stoi(medStr);
        }
    }
    in.close();
    std::cout << "Total de medallas de " << paisBuscar << ": " << total << std::endl;
}


void mejorAtleta() {
    std::ifstream in(nombreArchivo);
    std::string linea;
    std::getline(in, linea);

    std::string mejorNombre;
    int maxMedallas = -1;

    while (std::getline(in, linea)) {
        std::stringstream ss(linea);
        std::string nombre, pais, disciplina, genero, medStr;
        std::getline(ss, nombre, ',');
        std::getline(ss, pais, ',');
        std::getline(ss, disciplina, ',');
        std::getline(ss, genero, ',');
        std::getline(ss, medStr, ',');

        int med = std::stoi(medStr);
        if (med > maxMedallas) {
            maxMedallas = med;
            mejorNombre = nombre;
        }
    }
    in.close();

    if (maxMedallas >= 0)
        std::cout << "El mejor atleta es " << mejorNombre 
                  << " con " << maxMedallas << " medallas.\n";
    else
        std::cout << "No hay atletas registrados.\n";
}

void mostrarTodos() {
    std::ifstream in(nombreArchivo);
    std::string linea;
    std::getline(in, linea);
    std::cout << "--- Lista de atletas ---\n";
    while (std::getline(in, linea)) {
        std::cout << linea << std::endl;
    }
    in.close();
}


int main() {
    crearArchivo();
    int opcion = 0;

    do {
        std::cout << "----- M E N U ----- \n"
                  << "1) Registrar \n"
                  << "2) Buscar \n"
                  << "3) Calcular medallas por pais \n"
                  << "4) Mejor atleta \n"
                  << "5) Mostrar todos \n"
                  << "6) Salir\n"
                  << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: registrarAtleta(); break;
            case 2: buscarAtleta(); break;
            case 3: medallasPorPais(); break;
            case 4: mejorAtleta(); break;
            case 5: mostrarTodos(); break;
            case 6: std::cout << "Llegale we"; break;
            default: std::cout << "Opcion incorrecta.\n"; break;
        }

    } while(opcion != 6);

    return 0;
}
