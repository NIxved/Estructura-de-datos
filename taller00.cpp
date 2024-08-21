/********************************
Fecha: 21 de agosto 2024
Autor: David León
Tema: Taller 00
Estructura de Datos
*********************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;


struct venta {
    int cantidad;
    double precio;
};


struct Cliente {
    string nombre;
    string nombreproducto;
    string direccion;
    string telefono;
};

// Función que genera un número aleatorio entre 0 y 25
int generarNumeroAleatorio() {
    return rand() % 26;
}


void capturarDatosCliente(Cliente *cliente) {
    cout << "Nombre del cliente: ";
    getline(cin, cliente->nombre);
  

    cout << "Dirección del cliente: ";
    getline(cin, cliente->direccion);

    cout << "Teléfono del cliente: ";
    getline(cin, cliente->telefono);
    cout << "Nombre del producto: ";
    getline(cin, cliente->nombreproducto);
    
}


void imprimirFactura(Cliente *cliente, venta *ventaActual) {
    ofstream archivoFactura("factura.txt");
    
    if (archivoFactura.is_open()) {
        archivoFactura << "Factura de Venta\n";
        archivoFactura << "----------------\n";
        archivoFactura << "Nombre del cliente: " << cliente->nombre << endl;
        archivoFactura << "Dirección del cliente: " << cliente->direccion << endl;
        archivoFactura << "Teléfono del cliente: " << cliente->telefono << endl;
        archivoFactura << "Nombre del producto: " << cliente->nombreproducto << endl;
        archivoFactura << "Cantidad de productos: " << ventaActual->cantidad << endl;
        archivoFactura << "Precio por producto: $" << ventaActual->precio << endl;
        archivoFactura << "Valor a pagar: $" << ventaActual->cantidad * ventaActual->precio << endl;
        
        archivoFactura.close();
        cout << "Factura impresa en 'factura.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir la factura." << endl;
    }
}

int main() {
    // Punto 1: Declaramos un array de 10 enteros
      int array[10];

    // Punto 2: Inicializamos la semilla para generar números aleatorios
    srand(time(0));

    // Punto 3: Llenamos el array con números aleatorios entre 0 y 25
    for (int i = 0; i < 10; i++) {
        array[i] = generarNumeroAleatorio();
    }

    // Punto 4: Creamos un puntero que apunta al primer elemento del array
    int* array_puntero = array;

    // Punto 5: Imprimimos el contenido del array usando el puntero
    for (int i = 0; i < 10; i++) {
        cout << "Elemento " << i << ": " << *(array_puntero + i) << endl;
    }

    // Punto 6: Imprimimos las direcciones de memoria de cada elemento del array usando el puntero
    for (int i = 0; i < 10; i++) {
        cout << "Direccion del elemento " << i << ": " << (array_puntero + i) << endl;
    }

cout<< "Presione enter para pasar al punto 2"  <<endl;
   
    cin.ignore();

    // Capturamos los datos del cliente
    Cliente cliente;
    capturarDatosCliente(&cliente);

    venta *puntero, valor_venta;
    puntero = &valor_venta;

    cout << "Cantidad de productos: ";
    cin >> (*puntero).cantidad;

    cout << "Precio del producto: ";
    cin >> (*puntero).precio;

    
    cout << "Valor a pagar: $" << (*puntero).cantidad * (*puntero).precio << endl;

   
    imprimirFactura(&cliente, puntero);

    return 0;
}
