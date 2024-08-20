/************
Autor: David León
Materia: Estructura de Datos
Fecha 24-7-2024
Tema: Notación asintotica
************/

#include <iostream>
#include <string>
#include <math.h>
#include "biblioteca.h" //se incluye la libreria biblioteca.h para llamar a las funciones.
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
  cin >> option;  // Se captura la opción seleccionada por el usuario
  
  // Se utiliza una estructura switch para ejecutar diferentes funciones según la opción seleccionada
  switch(option) {
    case 1: {
      // Caso 1: Se realiza una suma recursiva de números hasta el valor dado
      int sumaNumeros = sumaRecursiva(9);
      cout << "Suma Recursiva: " << sumaNumeros << endl;
      break;
    }
    case 2: {
      // Caso 2: Se calculan los cuadrados de los números pares hasta el valor dado
      int resultadoCuadradosPares = cuadradosPares(33);
      cout << "Cuadrados Pares: " << resultadoCuadradosPares << endl;
      break;
    }
    case 3: {
      // Caso 3: Se realiza un cálculo similar al caso 2 pero con una implementación diferente
      int resultadoCuadradosPares2 = cuadradosPares2(33);
      cout << "Cuadrados Pares2: " << resultadoCuadradosPares2 << endl;
      break;
    }
    case 4: {
      // Caso 4: Se calcula el n número en la secuencia de Fibonacci
      int numFib = fibNumero(9);
      cout << "Número Fibonacci: " << numFib << endl;
      break;
    }
    case 5: {
      // Caso 5: Se realiza una búsqueda lineal de un carácter en una cadena de texto
      string palabra = "Palabra";
      char substring = 'g';
      bool caracter = lineal(palabra, substring, palabra.length()-1);
      cout << "Carácter encontrado: " << (caracter ? "Sí" : "No") << endl;
      break;
    }
    default:
      // Si la opción ingresada no es válida, se notifica al usuario
      cout << "Opción inválida" << endl;
      break;
  }

  return 0; 
}
