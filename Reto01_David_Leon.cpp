//*************************************************
//Autor David León
//Fecha de entrega: 24-7-24
//Materia: Estructura de Datos
//Tema: Reto 01
//*************************************************
#include <iostream>
#include <string>
#include <thread>
#include <chrono> // Estas bibliotecas las utilicé para simular tiempos de espera

using namespace std;

// La siguiente clase define la interfaz para todas las cafeteras que deseen implementar 
// las funcionalidades de preparación de capuchino o tinto. Las empresas Oster y Haceb
// deben derivar de esta clase y proporcionar las implementaciones específicas para los métodos.
// Métodos:
// - hacerCapuchino: Método para definir la lógica de la preparación de un capuchino.
// - hacerTinto: Método para definir la lógica de la preparación de un tinto.

class Cafetera {
public:
    virtual void hacerCapuchino() = 0; 
    virtual void hacerTinto() = 0;
};

// Método para hacer capuchino en la cafetera Oster:
// - Imprime un mensaje indicando el inicio de la preparación.
// - Llama al método calentarAgua para simular el calentamiento del agua.
// - Llama al método molerCafe para simular el molido del café.
// - Llama al método espumarLeche para simular el proceso de espumar la leche.
// - Llama al método combinarIngredientes con el argumento "capuchino" para 
//   simular la combinación de los ingredientes.
// - Imprime un mensaje indicando que el capuchino está listo para servir.

class CafeteraOster : public Cafetera {
public:
    void hacerCapuchino() override {
        cout << "Preparando capuchino con la cafetera Oster..." << endl;
        calentarAgua();
        molerCafe();
        espumarLeche();
        combinarIngredientes("capuchino");
        cout << "Capuchino con la cafetera Oster listo para servir!" << endl;
    }

    // Lo mismo que la anterior parte pero con tinto.
    void hacerTinto() override {
        cout << "Preparando tinto con la cafetera Oster..." << endl;
        calentarAgua();
        molerCafe();
        combinarIngredientes("tinto");
        cout << "Tinto con la cafetera Oster listo para servir!" << endl;
    }

private:
    // Método para calentar agua:
    // - Imprime un mensaje indicando que el agua está siendo calentada
    // - Simula el tiempo de calentamiento con una duración de 2 segundos.
    void calentarAgua() {
        cout << "Calentando agua..." << endl;
        this_thread::sleep_for(chrono::seconds(2)); 
    }

    // Método para moler café:
    // - Imprime un mensaje indicando que el café está siendo molido
    // - Simula el tiempo de molido con una duración de 2 segundos.
    void molerCafe() {
        cout << "Moliendo café..." << endl;
        this_thread::sleep_for(chrono::seconds(2)); 
    }

    // Método para espumar leche:
    // - Imprime un mensaje indicando que la leche está siendo espumada
    // - Simula el tiempo de espumado con una duración de 2 segundos.
    void espumarLeche() {
        cout << "Espumando leche..." << endl;
        this_thread::sleep_for(chrono::seconds(2)); 
    }

    // Método para combinar ingredientes:
    // - Este método toma un argumento que indica el tipo de bebida que se está preparando.
    // - Imprime un mensaje indicando que los ingredientes están siendo combinados para la bebida especificada.
    // - Simula el tiempo de combinación con una duración de 2 segundos.
    void combinarIngredientes(const string& tipo) {
        cout << "Combinando ingredientes para " << tipo << "..." << endl;
        this_thread::sleep_for(chrono::seconds(2)); 
    }
};

// Lo mismo que el proceso pasado pero para Haceb

class CafeteraHaceb : public Cafetera {
public:
    void hacerCapuchino() override {
        cout << "Preparando capuchino con la cafetera Haceb..." << endl;
        calentarAgua();
        molerCafe();
        espumarLeche();
        combinarIngredientes("capuchino");
        cout << "Capuchino con la cafetera Haceb listo para servir!" << endl;
    }

    void hacerTinto() override {
        cout << "Preparando tinto con la cafetera Haceb..." << endl;
        calentarAgua();
        molerCafe();
        combinarIngredientes("tinto");
        cout << "Tinto con la cafetera Haceb listo para servir!" << endl;
    }

private:
    void calentarAgua() {
        cout << "Calentando agua..." << endl;
        this_thread::sleep_for(chrono::seconds(3)); 
    }

    void molerCafe() {
        cout << "Moliendo café..." << endl;
        this_thread::sleep_for(chrono::seconds(3)); 
    }

    void espumarLeche() {
        cout << "Espumando leche..." << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }

    void combinarIngredientes(const string& tipo) {
        cout << "Combinando ingredientes para " << tipo << "..." << endl;
        this_thread::sleep_for(chrono::seconds(3)); 
    }
};

// Ejemplo:

int main() {
    Cafetera* oster = new CafeteraOster();
    Cafetera* haceb = new CafeteraHaceb();

    oster->hacerCapuchino();
    oster->hacerTinto();

    haceb->hacerCapuchino();
    haceb->hacerTinto();

    delete oster;
    delete haceb;

    return 0;
}
