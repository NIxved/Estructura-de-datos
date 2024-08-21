1. Codigo
// Función para sumar dos enteros
int Suma(int a, int b) {
    return a + b;  // Devuelve la suma de los dos enteros
}

// Función para sumar dos números de punto flotante
float Suma(float a, float b) {
    return a + b;  // Devuelve la suma de los dos números flotantes
}

// Función para concatenar dos cadenas de texto
string Suma(const string& a, const string& b) {
    string s = a + b;  // Concatena las dos cadenas
    return s;  // Devuelve la cadena resultante
}

2 Codigo.
int main() {
    int i1 = 1; int i2 = -5;  // Declaración e inicialización de dos enteros
    cout << Suma(i1, i2) << endl;  // Muestra la suma de i1 e i2 en la consola

    float f1 = 0.02; float f2 = 5.98;  // Declaración e inicialización de dos números de punto flotante
    cout << Suma(f1, f2) << endl;  // Muestra la suma de f1 y f2 en la consola

    const char* c1 = "a"; const char* c2 = "z";  // Declaración e inicialización de dos cadenas de caracteres constantes
    cout << Suma(c1, c2) << endl;  // Muestra la concatenación de c1 y c2 en la consola
ex
    return 0;  
}
3 Codigo.

// Plantilla de función para sumar dos valores de cualquier tipo de datos
template <class T> 
T Suma(const T &x, const T &y) {
    return (x + y);  // Devuelve la suma de x e y, de tipo T
}

int main() {
    // Uso de la plantilla de función Suma con diferentes tipos de datos

    cout << Suma<int>(20, 23) << endl;  // Llama a Suma con enteros, muestra 43
    cout << Suma<float>(0.23, 5.66) << endl;  // Llama a Suma con flotantes, muestra 5.89
    cout << Suma<long>(2, 6) << endl;  // Llama a Suma con enteros largos, muestra 8

    return 0;  // Termina el programa
}

4 codigo.

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;  // Devuelve x si es mayor que y; de lo contrario, devuelve y
}

int main() {
    // Uso de la plantilla de función myMax con diferentes tipos de datos

    cout << myMax<int>(20, 23) << endl;  // Llama a myMax con enteros, muestra el mayor valor (23)
    cout << myMax<char>('e', 'r') << endl;  // Llama a myMax con caracteres, muestra el mayor carácter ('r')

    return 0; 
}

5 codigo.
 
// Plantilla de clase para mostrar información sobre un valor de cualquier tipo
template <class T>
class info {
public:
    /* Constructor del tipo template */
    info(T A) {
        // Muestra el valor de A y su tamaño en bytes
        cout << "A = \t" << A << "\t size of data: " << sizeof(A) << "\t bytes\n";
    }
};

int main() {
    // Instanciación de objetos de la clase info con diferentes tipos de datos

    info<char> p('X');  // Crea un objeto info para un carácter ('X') y muestra su valor y tamaño
    info<int> h(11);  // Crea un objeto info para un entero (11) y muestra su valor y tamaño
    info<float> d(3.14159);  // Crea un objeto info para un flotante (3.14159) y muestra su valor y tamaño

    return 0;  
}
6. Codigo

  bool Escena::ActualizarVisual(string nomObj) {
    std::stack<Objeto> aux;  // Pila auxiliar para almacenar objetos temporalmente
    Objeto miObj;  // Variable para el objeto actual
    std::list<Punto> miNube;  // Lista de puntos (nube de puntos) del objeto
    std::list<Punto>::iterator punIt;  // Iterador para recorrer la lista de puntos
    int visualTr = 0, visualFl = 0;  // Contadores para puntos visibles y no visibles
    float miCoor[3];  // Arreglo para almacenar las coordenadas de un punto
    bool encontrado = false;  // Indica si se ha encontrado el objeto
    bool actualizado = false;  // Indica si se ha actualizado la visualización

    // Mientras haya objetos en la pila y no se haya encontrado el objeto buscado
    while (!objetos.empty() && !encontrado) {
        miObj = objetos.top();  // Obtiene el objeto en la cima de la pila
        objetos.pop();  // Elimina el objeto de la pila

        // Si el nombre del objeto coincide con el nombre buscado
        if (miObj.ObtenerNombre() == nomObj) {
            encontrado = true;  // Marca que el objeto ha sido encontrado
            miNube = miObj.ObtenerNube();  // Obtiene la nube de puntos del objeto
            visualTr = 0;  // Reinicia el contador de puntos visibles
            visualFl = 0;  // Reinicia el contador de puntos no visibles

            // Recorre todos los puntos en la nube de puntos
            for (punIt = miNube.begin(); punIt != miNube.end(); punIt++) {
                miCoor = punIt->ObtenerCoord();  // Obtiene las coordenadas del punto actual

                // Verifica si el punto está dentro de los límites de visibilidad
                if (miCoor[0] >= limX[0] && miCoor[0] <= limX[1] &&
                    miCoor[1] >= limY[0] && miCoor[1] <= limY[1] &&
                    miCoor[2] >= limZ[0] && miCoor[2] <= limZ[1]) {
                    visualTr++;  // Incrementa el contador de puntos visibles
                } else {
                    visualFl++;  // Incrementa el contador de puntos no visibles
                }
            }

            // Actualiza el estado de la visualización según los puntos visibles y no visibles
            if (visualTr == miNube.size() && visualFl == 0) {
                miObj.FijarIndVisual("completa");  // Todos los puntos son visibles
            } else if (visualTr == 0 && visualFl == miNube.size()) {
                miObj.FijarIndVisual("nula");  // Ningún punto es visible
            } else {
                miObj.FijarIndVisual("parcial");  // Algunos puntos son visibles
            }
            actualizado = true;  // Marca que la visualización ha sido actualizada
        } else {
            aux.push(miObj);  // Si no es el objeto buscado, lo coloca en la pila auxiliar
        }
    }

    // Devuelve los objetos de la pila auxiliar a la pila original
    while (!aux.empty()) {
        miObj = aux.top();  // Obtiene el objeto de la cima de la pila auxiliar
        aux.pop();  // Elimina el objeto de la pila auxiliar
        objetos.push(miObj);  // Devuelve el objeto a la pila original
    }

    return actualizado;  // Retorna si la visualización fue actualizada o no
}

7. Codigo
  // Función que une dos objetos de la escena en uno nuevo
bool Escena::NuevoObjPorUnion(string nomObj1, string nomObj2) {
    std::stack<Objeto> aux, objs;  // Pilas auxiliares para manejar los objetos
    Objeto miObj, miObjU;  // Variables para los objetos actuales

    // Extrae los objetos de la pila y busca los que coinciden con los nombres dados
    while (!objetos.empty()) {
        miObj = objetos.top();  // Toma el objeto en la cima de la pila
        objetos.pop();  // Elimina el objeto de la pila

        // Verifica si el objeto actual coincide con uno de los nombres dados
        if (miObj.ObtenerNombre() == nomObj1 || miObj.ObtenerNombre() == nomObj2) {
            objs.push(miObj);  // Guarda el objeto en la pila de objetos a procesar
        } else {
            aux.push(miObj);  // Si no coincide, lo guarda en la pila auxiliar
        }
    }

    aux.push(miObjU);  // Agrega el nuevo objeto a la pila auxiliar

    std::list<Punto> miNube, nubeUn;  // Listas para las nubes de puntos de los objetos
    std::list<Punto>::iterator punIt;  // Iterador para recorrer las nubes de puntos

    miObj = objs.top();  // Toma el primer objeto para la unión
    objs.pop();  // Elimina el objeto de la pila

    miNube = miObj.ObtenerNube();  // Obtiene la nube de puntos del primer objeto
    for (punIt = miNube.begin(); punIt != miNube.end(); punIt++) {
        nubeUn.push_back(*punIt);  // Agrega los puntos a la nueva nube
    }

    miObj = objs.top();  // Toma el segundo objeto para la unión
    objs.pop();  // Elimina el objeto de la pila

    miNube = miObj.ObtenerNube();  // Obtiene la nube de puntos del segundo objeto
    for (punIt = miNube.begin(); punIt != miNube.end(); punIt++) {
        if (!miObjU.BuscarPunto(*punIt)) {
            nubeUn.push_back(*punIt);  // Agrega los puntos a la nueva nube, si no están ya
        }
    }

    // Actualiza el nuevo objeto con la unión de las nubes de puntos
    miObjU.FijarNombre("Union_" + obj1.ObtenerNombre() + "_" + obj2.ObtenerNombre());
    miObjU.FijarNube(nubeUn);
    miObjU.ActualizarCentroide();

    aux.push(miObjU);  // Guarda el nuevo objeto en la pila auxiliar

    // Devuelve los objetos de la pila auxiliar a la pila original
    while (!aux.empty()) {
        miObj = aux.top();  // Toma el objeto de la cima de la pila auxiliar
        aux.pop();  // Elimina el objeto de la pila auxiliar
        objetos.push(miObj);  // Devuelve el objeto a la pila original
    }

    // Actualiza la visualización del nuevo objeto
    ActualizarVisual(miObjU);

    return true;  // Indica que la operación fue exitosa
}

// Función para buscar un punto en la nube de puntos del objeto
bool Objeto::BuscarPunto(Point p) {
    bool enc = false;  // Indica si se encontró el punto
    std::list<Punto>::iterator punIt;  // Iterador para recorrer la nube de puntos

    // Recorre la nube de puntos buscando el punto p
    for (punIt = nube.begin(); punIt != nube.end() && !enc; punIt++) {
        if (*punIt == p) enc = true;  // Si encuentra el punto, marca enc como true
    }
    return enc;  // Devuelve si se encontró o no el punto
}

// Función para actualizar el centroide de la nube de puntos del objeto
void Objeto::ActualizarCentroide() {
    float miCoor[3], cent[3] = {0.0, 0.0, 0.0};  // Coordenadas y centroide inicializado a 0
    std::list<Punto>::iterator punIt;  // Iterador para recorrer la nube de puntos

    // Recorre todos los puntos para calcular el centroide
    for (punIt = nube.begin(); punIt != nube.end(); punIt++) {
        miCoor = punIt->ObtenerCoord();  // Obtiene las coordenadas del punto actual
        cent[0] += miCoor[0];  // Suma la coordenada X al acumulador
        cent[1] += miCoor[1];  // Suma la coordenada Y al acumulador
        cent[2] += miCoor[2];  // Suma la coordenada Z al acumulador
    }

    // Calcula el promedio para obtener el centroide
    cent[0] /= nube.size();
    cent[1] /= nube.size();
    cent[2] /= nube.size();

    // Asigna el nuevo centroide al objeto
    centroide = cent;
}
