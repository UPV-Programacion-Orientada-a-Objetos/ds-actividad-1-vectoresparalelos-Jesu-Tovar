#include <iostream>
#include <fstream>
#include <string>

void registrar(std::string nom[], std::string pa[], std::string dis[], std::string ge[]){

}
int main() {

int pepe = 1;

    while(pepe <= 5){

    std::string nombreArchivo = "atletas.txt";
    std::ifstream archivo(nombreArchivo);
    int pepito = 0;

    if (!archivo.is_open()) {
        std::ofstream nuevoArchivo(nombreArchivo);
        nuevoArchivo << "Nombre,Pais,Disciplina,Genero,Medallas\n";
        nuevoArchivo.close();
    } else {
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (!linea.empty()) {
                pepito++;
            }
        }
        archivo.close();
    }

    std::string nombre[pepito], pais[pepito], disciplina[pepito], genero[pepito];
    int medalla[pepito];

    std::cout << "----- M E N U ----- \n1)Registrar \n6)Salir" << std::endl;
    std::cin >> pepe;

    while(pepe >= 7){
        std::cout << "Opcion incorrecta, seleccione otra" << std::endl;
        std::cin >> pepe;
    }

    if(pepe == 1){
        Registrar()
    }


    }


    return 0;
}