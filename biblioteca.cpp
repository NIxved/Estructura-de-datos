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

// Función recursiva que suma todos los números naturales desde 1 hasta n
int sumaRecursiva(int n){
  if(n <= 1) {  //Si n es 1 o menor, simplemente devuelve n
    return n;
  }
  else{
    return n + sumaRecursiva(n-1);  // Llamada recursiva que suma n con la suma de los números anteriores
  }
};

// Función recursiva que suma los cuadrados de los números pares desde n hasta 0
int cuadradosPares(int n){
  if(n == 0){  //Si n es 0, devuelve 0
    return n;
  }
  else if(n % 2 == 0) {  // Verifica si n es par
    return n*n + cuadradosPares(n-1);  // Suma el cuadrado de n si es par, y llama recursivamente con n-1
  } else {
    return cuadradosPares(n - 1);  // Si n es impar, simplemente llama a la función con n-1 sin sumar
  }
};

// Otra versión de la función que suma los cuadrados, pero aquí se suma (n+n)^2
int cuadradosPares2(int n){
  if(n == 0){  //si n es 0, devuelve 0
    return n;
  } else {
    return pow(n+n,2) + cuadradosPares2(n - 1);  // Suma el cuadrado de (n+n) y llama recursivamente con n-1
  }
};

// Función recursiva que calcula el n-ésimo número de Fibonacci
int fibNumero(int n){
  if(n <= 1){  // si n es 0 o 1, devuelve n
    return n;
  } else {
    return fibNumero(n-1) + fibNumero(n-2);  // Calcula el n número de Fibonacci usando recursión
  }
};

// Función que verifica si un carácter c está presente en una cadena utilizando un enfoque recursivo para buscar desde el final hacia el principio
bool lineal(string s, char c, int l){
  if(l < 0){  // si l es menor que 0, hemos revisado toda la cadena y no se encontró el carácter
    return false;
  } else if (s[l] == c){  // Si el carácter en la posición l es igual a c, devuelve verdadero
    return true;		
  } else {
    return lineal(s, c, l-1);  // Llamada recursiva que revisa el carácter anterior en la cadena
  }
};
