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

int main() {


    std::cout << "----- M E N U ----- \n1)Registrar \n2)Buscar \n3)Calcular medallas por pais \n4)Mejor atleta \n5)Mostrar todos \n6)Salir" << std::endl;
    std::cin >> pepe;
    switch (pepe) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                std::cout << "llegale" << std::endl;
                break;
        }

    while(pepe >= 7){
        std::cout << "Opcion incorrecta, seleccione otra" << std::endl;
        std::cin >> pepe;
    }


    }


    return 0;
}