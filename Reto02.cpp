/************
Autor: David León
Materia: Estructura de Datos
Fecha 24-7-2024
Tema: Notación asintotica
************/

#include <iostream> 
#include <string>  
include <math.h> 

using namespace std; 

//1.  Función recursiva para calcular la suma de los números desde n hasta 1
int sumaRecursiva(int n){
  if(n <= 1) { 
    return n; // Si n es 1 o menor, retorna n
  }
  else{
    return n + sumaRecursiva(n-1); // si no, Llama a la función recursivamente y suma el valor de n.
  }
};

//2. Función recursiva para calcular la suma de los cuadrados de los números pares desde n hasta 0
int cuadradosPares(int n){
  if(n == 0){
    return n; //si n es 0, retorna 0
  }
  else if(n % 2 == 0) {
    return n*n + cuadradosPares(n-1); // Si n es par, suma su cuadrado a la suma de los cuadrados de los números anteriores
  } else {
    return cuadradosPares(n - 1); // Si n es impar, pasa al siguiente número
  }
};

//3. Otra función para calcular la suma de cuadrados+.
int cuadradosPares2(int n){
  if(n == 0){
    return n; // Si n es 0, retorna 0
  } else {
    return pow(n+n, 2) + cuadradosPares2(n - 1); // Calcula el cuadrado de (n+n) y lo suma recursivamente
  }
};

//4. Función recursiva para calcular un n número de Fibonacci
int fibNumero(int n){
  if(n <= 1){
    return n; // Caso base: si n es 0 o 1, retorna n
  } else {
    return fibNumero(n-1) + fibNumero(n-2); // Suma los dos números anteriores en la secuencia de Fibonacci
  }
};

//5.  Función recursiva para realizar una búsqueda lineal de un carácter en una cadena
bool lineal(string s, char c, int l){
  if(l < 0){
    return false; // Si se ha recorrido toda la cadena y no se encuentra el carácter, retorna falso.
  } else if (s[l] == c){
    return true; // Si el carácter actual es el buscado, retorna verdadero.
  } else {
    return lineal(s, c, l-1); // Llama a la función recursivamente con el índice anterior
  }
}

int main() {
  int option; 
  cout << "Seleccione una opción:" << endl;
  cout << "1. Suma Recursiva" << endl;
  cout << "2. Cuadrados Pares" << endl;
  cout << "3. Cuadrados Pares2" << endl;
  cout << "4. Fibonacci" << endl;
  cout << "5. Búsqueda Lineal" << endl;
  cout << "Ingrese el número de la opción: ";
  cin >> option; // Lee la opción ingresada por el usuario
  
  switch(option) { 
    case 1: {
      int sumaNumeros = sumaRecursiva(9); // Llama a la función sumaRecursiva con 9 como argumento
      cout << "Suma Recursiva: " << sumaNumeros << endl; // Imprime el resultado
      break;
    }
    case 2: {
      int resultadoCuadradosPares = cuadradosPares(33); // Llama a la función cuadradosPares con 33 como argumento
      cout << "Cuadrados Pares: " << resultadoCuadradosPares << endl; // Imprime el resultado
      break;
    }
    case 3: {
      int resultadoCuadradosPares2 = cuadradosPares2(33); // Llama a la función cuadradosPares2 con 33 como argumento
      cout << "Cuadrados Pares2: " << resultadoCuadradosPares2 << endl; // Imprime el resultado
      break;
    }
     case 4: {
      int numFib = fibNumero(9); // Llama a la función fibNumero con 9 como argumento
      cout << "Número Fibonacci: " << numFib << endl; // Imprime el resultado
      break;
    }
    case 5: {
      string palabra = "Palabra"; // Define la cadena a buscar
      char substring = 'g'; // Define el carácter a buscar
      bool caracter = lineal(palabra, substring, palabra.length()-1); // Llama a la función lineal para buscar el carácter
      cout << "Carácter encontrado: " << (caracter ? "Sí" : "No") << endl; // Imprime si el carácter fue encontrado o no
      break;
    }
    default:
      cout << "Opción inválida" << endl; // Mensaje de error si la opción no es válida
      break;
  }

  return 0; 
}
