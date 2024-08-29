/****************************************
Autor: David Leon
Fecha: 28 de agosto 2024
Materia: Estructura de Datos
Tema: Taller02
****************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


struct Cancion {
    std::string nombre;
    std::string autor;
    std::string genero;
    std::string album;
    int ano;

    bool operator<(const Cancion &otra) const {
        return nombre < otra.nombre;
    }
};

// Función para leer el archivo y almacenar las canciones
std::vector<Cancion> leerArchivo(const std::string &nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::vector<Cancion> canciones;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return canciones;
    }

    int numCanciones;
    archivo >> numCanciones;
    archivo.ignore(); // Ignorar el salto de línea después del número

    for (int i = 0; i < numCanciones; ++i) {
        Cancion cancion;
        std::getline(archivo, cancion.nombre, '|');
        std::getline(archivo, cancion.autor, '|');
        std::getline(archivo, cancion.genero, '|');
        std::getline(archivo, cancion.album, '|');
        archivo >> cancion.ano;
        archivo.ignore(); // Ignorar el salto de línea

        canciones.push_back(cancion);
    }

    archivo.close();
    return canciones;
}

// Función para listar todos los autores presentes, ordenados alfabéticamente
void listarAutores(const std::vector<Cancion> &canciones) {
    std::set<std::string> autores;
    for (const auto &cancion : canciones) {
        autores.insert(cancion.autor);
    }

    std::cout << "Autores ordenados alfabéticamente:\n";
    for (const auto &autor : autores) {
        std::cout << autor << std::endl;
    }
}

// Función para listar todas las canciones de un autor, ordenadas alfabéticamente
void listarCancionesPorAutor(const std::vector<Cancion> &canciones, const std::string &autor) {
    std::vector<std::string> cancionesAutor;
    for (const auto &cancion : canciones) {
        if (cancion.autor == autor) {
            cancionesAutor.push_back(cancion.nombre);
        }
    }
    std::sort(cancionesAutor.begin(), cancionesAutor.end());

    std::cout << "Canciones de " << autor << " ordenadas alfabéticamente:\n";
    for (const auto &nombre : cancionesAutor) {
        std::cout << nombre << std::endl;
    }
}

// Función para listar todos los álbumes presentes, ordenados cronológicamente
void listarAlbumes(const std::vector<Cancion> &canciones) {
    std::map<int, std::set<std::string>> albumes;
    for (const auto &cancion : canciones) {
        albumes[cancion.ano].insert(cancion.album);
    }

    std::cout << "Álbumes ordenados cronológicamente:\n";
    for (const auto &par : albumes) {
        for (const auto &album : par.second) {
            std::cout << par.first << " - " << album << std::endl;
        }
    }
}

// Función para listar todas las canciones de un álbum, ordenadas alfabéticamente
void listarCancionesPorAlbum(const std::vector<Cancion> &canciones, const std::string &album) {
    std::vector<std::string> cancionesAlbum;
    for (const auto &cancion : canciones) {
        if (cancion.album == album) {
            cancionesAlbum.push_back(cancion.nombre);
        }
    }
    std::sort(cancionesAlbum.begin(), cancionesAlbum.end());

    std::cout << "Canciones del álbum " << album << " ordenadas alfabéticamente:\n";
    for (const auto &nombre : cancionesAlbum) {
        std::cout << nombre << std::endl;
    }
}

// Función para listar todas las canciones ordenadas alfabéticamente primero por álbum y luego por nombre
void listarCancionesPorAlbumYNombre(const std::vector<Cancion> &canciones) {
    std::map<std::string, std::set<std::string>> albumesCanciones;
    for (const auto &cancion : canciones) {
        albumesCanciones[cancion.album].insert(cancion.nombre);
    }

    std::cout << "Canciones ordenadas alfabéticamente por álbum y luego por nombre:\n";
    for (const auto &par : albumesCanciones) {
        std::cout << "Álbum: " << par.first << std::endl;
        for (const auto &nombre : par.second) {
            std::cout << " - " << nombre << std::endl;
        }
    }
}


void mostrarMenu() {
    std::cout << "\nSeleccione una opción:\n";
    std::cout << "1. Listar todos los autores\n";
    std::cout << "2. Listar canciones por autor\n";
    std::cout << "3. Listar todos los álbumes\n";
    std::cout << "4. Listar canciones por álbum\n";
    std::cout << "5. Listar canciones ordenadas por álbum y nombre\n";
    std::cout << "6. Salir\n";
}


void ejecutarOpcion(int opcion, const std::vector<Cancion> &canciones) {
    std::string entrada;

    switch (opcion) {
        case 1:
            listarAutores(canciones);
            break;
        case 2:
            std::cout << "Ingrese el nombre del autor: ";
            std::cin.ignore();
            std::getline(std::cin, entrada);
            listarCancionesPorAutor(canciones, entrada);
            break;
        case 3:
            listarAlbumes(canciones);
            break;
        case 4:
            std::cout << "Ingrese el nombre del álbum: ";
            std::cin.ignore();
            std::getline(std::cin, entrada);
            listarCancionesPorAlbum(canciones, entrada);
            break;
        case 5:
            listarCancionesPorAlbumYNombre(canciones);
            break;
        case 6:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
            break;
    }
}


int main() {
    std::vector<Cancion> canciones = leerArchivo("canciones.txt");
    if (canciones.empty()) {
        return 1;
    }

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        ejecutarOpcion(opcion, canciones);
    } while (opcion != 6);

    return 0;
}
