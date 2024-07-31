/************
Autor: David León
Materia: Estructura de Datos
Fecha 24-7-2024
Tema: Notación asintotica
************/

#include <iostream>
#include <string>
#include <math.h>
#include "biblioteca.h"
using namespace std;


int main() {
  int option;
  cout << "Seleccione una opción:" << endl;
  cout << "1. Suma Recursiva" << endl;
  cout << "2. Cuadrados Pares" << endl;
  cout << "3. Cuadrados Pares2" << endl;
  cout << "4. Fibonacci" << endl;
  cout << "5. Búsqueda Lineal" << endl;
  cout << "Ingrese el número de la opción: ";
  cin >> option;
  
  switch(option) {
    case 1: {
      int sumaNumeros = sumaRecursiva(9);
      cout << "Suma Recursiva: " << sumaNumeros << endl;
      break;
    }
    case 2: {
      int resultadoCuadradosPares = cuadradosPares(33);
      cout << "Cuadrados Pares: " << resultadoCuadradosPares << endl;
      break;
    }
    case 3: {
      int resultadoCuadradosPares2 = cuadradosPares2(33);
      cout << "Cuadrados Pares2: " << resultadoCuadradosPares2 << endl;
      break;
    }
     case 4: {
      int numFib = fibNumero(9);
      cout << "Número Fibonacci: " << numFib << endl;
      break;
    }
    case 5: {
      string palabra = "Palabra";
      char substring = 'g';
      bool caracter = lineal(palabra, substring, palabra.length()-1);
      cout << "Carácter encontrado: " << (caracter ? "Sí" : "No") << endl;
      break;
    }
    default:
      cout << "Opción inválida" << endl;
      break;
  }

  return 0;
  }
