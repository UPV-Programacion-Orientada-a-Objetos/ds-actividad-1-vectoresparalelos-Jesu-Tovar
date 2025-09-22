#include <iostream>
#include <fstream>
int main() {

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

    return 0;
}