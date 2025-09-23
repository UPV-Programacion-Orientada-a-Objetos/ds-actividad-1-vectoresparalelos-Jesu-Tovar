#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string nombreArchivo = "atletas.txt";

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
    salida << nombre << "," << pais << "," << disciplina << ","
           << genero << "," << medallas << "\n";
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



int main() {
    crearArchivo();
    int pepe = 0;


    std::cout << "----- M E N U ----- \n1)Registrar \n2)Buscar \n3)Calcular medallas por pais \n4)Mejor atleta \n5)Mostrar todos \n6)Salir" << std::endl;
    std::cin >> pepe;
    std::cin.ignore();
    switch (pepe) {
        case 1: registrarAtleta(); break;
        case 2: buscarAtleta(); break;
        case 6: std::cout << "Adios.\n"; break;
        default: std::cout << "Opcion incorrecta.\n"; break;
        }

    while(pepe >= 7){
        std::cout << "Opcion incorrecta, seleccione otra" << std::endl;
        std::cin >> pepe;
    }
    
    return 0;
    }
