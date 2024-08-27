1. Codigo

// Plantilla de clase que maneja un array de elementos de tipo T
template <class T, int element>
class Exp {
public:
    T a[element];  // Declaración de un array de tamaño 'element' y tipo 'T'

    // Método para llenar el array con valores
    void put() {
        int x = -1;  // Inicializa x en -1
        for (int j = 0; j < element; j++) {  // Recorre todos los elementos del array
            a[j] = x;  // Asigna el valor de x a la posición j del array
            x++;  // Incrementa x en 1
        }
    }

    // Método para imprimir los valores del array
    void print() {
        for (int x = 6; x < element; x++) {  // Recorre el array desde el índice 6 hasta el final
            cout << a[x] << " << \n";  // Imprime el valor en la posición x del array
        }
        cout << "\n ...Fin! \n";  // Imprime un mensaje de fin
    }
};

int main() {
    Exp<int, 16> objeto;  // Crea un objeto de la clase plantilla Exp con tipo int y tamaño 16
    objeto.put();  // Llama al método put para llenar el array del objeto
    objeto.print();  // Llama al método print para imprimir los valores del array

    return 0;  
}

2. Codigo
  // Protocolo de Collection
template <class Object>
class Collection {
public:
    // Destructor virtual para permitir la limpieza adecuada de los recursos en las subclases
    virtual ~Collection() { }

    // Métodos virtuales puros que deben ser implementados por cualquier clase derivada
    virtual void insert(const Object &x) = 0;  // Inserta un objeto en la colección
    virtual void remove(const Object &x) = 0;  // Elimina un objeto de la colección
    virtual Cref<Object> find(const Object &x) const = 0;  // Busca un objeto en la colección y devuelve una referencia constante

    virtual bool isEmpty() const = 0;  // Verifica si la colección está vacía
    virtual void makeEmpty() = 0;  // Vacía la colección
};

3. Codigo
  // Protocolo para una pila (Stack)
template <class Object>
class Stack {
public:
    // Destructor virtual para asegurar la correcta destrucción de objetos derivados
    virtual ~Stack() { }

    // Métodos virtuales puros que deben ser implementados por las clases derivadas

    virtual void push(const Object &x) = 0;  // Inserta un objeto en la cima de la pila
    virtual void pop() = 0;  // Elimina el objeto en la cima de la pila
    virtual const Object &top() const = 0;  // Devuelve el objeto en la cima de la pila sin eliminarlo

    virtual bool isEmpty() const = 0;  // Verifica si la pila está vacía
    virtual void makeEmpty() = 0;  // Vacía la pila
};

4. Codigo

int main() {
    stack<int> st;  // Declara una pila de enteros

    // Inserta elementos en la pila
    st.push(10);  // Inserta 10 en la pila
    st.push(20);  // Inserta 20 en la pila
    st.push(30);  // Inserta 30 en la pila
    st.push(40);  // Inserta 40 en la pila

    // Elimina dos elementos de la pila
    st.pop();  // Elimina el elemento en la cima (40)
    st.pop();  // Elimina el siguiente elemento en la cima (30)

    // Mientras la pila no esté vacía
    while (!st.empty()) {
        cout << ' ' << st.top();  // Imprime el elemento en la cima de la pila
        st.pop();  // Elimina el elemento en la cima
    }

    cout << "\n ... fin \n";  // Imprime un mensaje indicando el fin del programa

    return 0;  
}

5. Codigo

  // Protocolo para una cola (Queue)
template <class Object>
class Queue {
public:
    // Destructor virtual para asegurar la correcta destrucción de objetos derivados
    virtual ~Queue() { }

    // Métodos virtuales puros que deben ser implementados por las clases derivadas

    virtual void enqueue(const Object &x) = 0;  // Inserta un objeto al final de la cola
    virtual void dequeue() = 0;  // Elimina el objeto al frente de la cola
    virtual const Object &getFront() const = 0;  // Devuelve el objeto al frente de la cola sin eliminarlo

    virtual bool isEmpty() const = 0;  // Verifica si la cola está vacía
    virtual void makeEmpty() = 0;  // Vacía la cola
};

6. Codigo


int main() {
    // Crea una cola de cadenas de texto
    queue<string> animales;

    // Inserta elementos en la cola
    animales.push("Gato");
    animales.push("Hormiga");
    animales.push("Conejo");
    animales.push("Perro");

    // Muestra el contenido inicial de la cola
    cout << "\n Cola inicial: \n";
    tool_cola(animales);  // Llama a la función tool_cola para mostrar la cola

    // Elimina un elemento de la cola
    animales.pop();

    // Muestra el contenido final de la cola después de la eliminación
    cout << "\n Cola Final: \n";
    tool_cola(animales);  // Llama a la función tool_cola para mostrar la cola

    return 0; 
}

// Función de utilidad para mostrar el contenido de la cola
void tool_cola(queue<string> objeto) {
    cout << "\n Tamaño de la cola: " << objeto.size() << "\n";  // Muestra el tamaño de la cola

    // Mientras la cola no esté vacía
    while (!objeto.empty()) {
        cout << objeto.front() << " ";  // Muestra el elemento al frente de la cola
        objeto.pop();  // Elimina el elemento al frente de la cola
    }

    cout << endl;  
}

7. Codigo
  // Imprime el contenido del contenedor c.
template <class Container>
void printCollection(const Container &c) {
    // Define un iterador constante para el contenedor
    typename Container::const_iterator itr;  
    
    // Recorre el contenedor desde el inicio hasta el final
    for (itr = c.begin(); itr != c.end(); ++itr) {
        cout << *itr << endl;  // Imprime el elemento actual apuntado por el iterador
    }
}
8. Codigo.

int main() {
    // Inicializa 2 vectores
    vector<int> v1, v2;

    // Añade elementos a los vectores
    for (int i = 1; i <= 10; i++) {
        v1.push_back(i);  // Añade los números del 1 al 10 en v1
        v2.push_back(i + 2);  // Añade los números del 3 al 12 en v2
    }

    // Inicializa un iterador 'itr' que apunta al primer elemento del vector v1
    vector<int>::iterator itr = v1.begin();

    // Copia los elementos del vector v2 al inicio del vector v1
    copy(v2.begin(), v2.end(), inserter(v1, itr));

    // Imprime los elementos del vector v1 después de copiar los elementos de v2
    cout << "Elementos del vector v1 después de copiar los elementos de v2 son: " << endl;
    for (itr = v1.begin(); itr != v1.end(); ++itr) {
        cout << " " << *itr;  // Imprime cada elemento de v1
    }

    cout << "\n\n";  // Imprime un par de saltos de línea para finalizar la salida

    return 0; 
}

9. Codigo
  // Clase que define un functor para verificar si un número es menor que 50
class menorQue50 {
public:
    // Sobrecarga del operador () para actuar como un functor
    bool operator()(int x) const {
        return x < 50;  // Devuelve true si x es menor que 50, de lo contrario devuelve false
    }
};

// Se declara el iterador del tipo de contenedor vector<int>
vector<int>::iterator iterador;

// Utiliza la función find_if para encontrar el primer elemento en el vector que cumple la condición de menorQue50
iterador = find_if(v.begin(), v.end(), menorQue50());

10. Codigo

int main() {
    // Crea una lista de enteros e inicializa con algunos valores
    list<int> lista00 = {12, 5, 10, 9, 7, 0, -1};

    // Inserta elementos al inicio y al final de la lista
    lista00.push_front(11);  // Inserta 11 al inicio de la lista
    lista00.push_back(18);   // Inserta 18 al final de la lista

    // Encuentra el primer elemento en la lista que es igual a 10
    auto it = std::find(lista00.begin(), lista00.end(), 10);

    // Si el elemento fue encontrado, inserta 21 antes de ese elemento
    if (it != lista00.end()) {
        lista00.insert(it, 21);  // Inserta 21 antes del elemento encontrado
    }

    // Recorre la lista e imprime cada elemento
    for (int x : lista00) {
        cout << x << '\n';  // Imprime el valor de x seguido de un salto de línea
    }

    return 0; 
}
11. Codigo
  
int main(void) {
    // Inicializa tres listas de enteros
    list<int> lista00;  // Lista vacía
    list<int> lista01 = {10, 20, 30};  // Lista inicializada con tres valores
    list<int> lista02(lista01.begin(), lista01.end());  // Copia los elementos de lista01 a lista02
    list<int> lista03(move(lista01));  // Mueve los elementos de lista01 a lista03 (lista01 queda vacía)

    // Imprime el tamaño de lista00
    cout << "Tamaño de Lista00: " << lista00.size() << endl;

    // Imprime el contenido de lista02
    cout << "Contenido de la Lista002: " << endl;
    for (auto it = lista02.begin(); it != lista02.end(); ++it) {
        cout << *it << endl;  // Imprime cada elemento de lista02
    }

    // Imprime el contenido de lista03
    cout << "Contenido de la Lista003: " << endl;
    for (auto it = lista03.begin(); it != lista03.end(); ++it) {
        cout << *it << endl;  // Imprime cada elemento de lista03
    }

    return 0;  
}
12. Codigo

 
int main() {
    // Inicializa conjuntos de diferentes tipos de datos
    set<string> conjunto00{"iphone", "android", "basic", "landline"};
    set<char> conjunto01{'a', 'b', 'c', 'd'};
    set<int> conjunto02{1, 3, 4, 5};

    int i = 5;  // Inicializa la variable entera i con el valor 5

    // Inserta elementos en conjunto02 utilizando un bucle
    // Aquí se comentaron partes del código, pero en su estado original, 
    // esta sección podría estar diseñada para insertar múltiples elementos 
    // utilizando un bucle y la función insert.
    for (auto it1 = conjunto00.begin(); it1 != conjunto00.end(); ++it1, ++i) {
        conjunto02.insert('a' + i);  // Inserta valores en conjunto02
    }

    // Imprime el tamaño del conjunto00
    cout << "Tamaño del conjunto00: " << conjunto00.size() << endl;

    // Imprime el tamaño del conjunto01
    cout << "Tamaño del conjunto01: " << conjunto01.size() << endl;

    cout << "\n";  // Imprime un salto de línea para separar la salida

    return 0; 
}

13. Codigo
  

int main() {
    // Crea un vector de enteros con 5 elementos, inicializados por defecto a 0
    std::vector<int> myvector(5);

    int i = 0;  // Inicializa una variable entera i en 0

    // Iterador inverso que apunta al inicio (final) del vector
    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    // Utiliza el iterador inverso para recorrer el vector desde el final hacia el principio
    for (; rit != myvector.rend(); ++rit)
        *rit = ++i;  // Asigna a cada posición el valor de i incrementado en 1

    // Imprime el contenido del vector
    std::cout << "myvector contiene: ";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;  // Muestra cada elemento del vector

    std::cout << '\n';  // Salto de línea para finalizar la salida

    return 0;  
}

14. Codigo //Ordenamiento burbuja normal
    int vals[N]; 

// Bucle externo que controla el número de pasadas a través del arreglo
for (int i = 0; i < N; i++) {
    // Bucle interno que realiza las comparaciones y los intercambios
    for (int j = 0; j < N - 1; j++) {
        // Si el elemento actual es mayor que el siguiente, se realiza un intercambio
        if (vals[j] > vals[j + 1]) {
            int swap = vals[j];     // Almacena el valor del elemento actual en una variable temporal
            vals[j] = vals[j + 1];  // Asigna el valor del siguiente elemento al elemento actual
            vals[j + 1] = swap;     // Asigna el valor almacenado en la variable temporal al siguiente elemento
        }
    }
}
15. codigo//ordenamiento burbuja con vectores

vector<int> vals;

// Bucle externo que controla el número de pasadas a través del vector
for (int i = 0; i < vals.size(); i++) {
    // Inicializa dos iteradores para recorrer el vector
    vector<int>::iterator j = vals.begin(); // Iterador que apunta al inicio del vector
    vector<int>::iterator k = j;            // Iterador k inicializado en el mismo punto que j

    // Bucle interno que realiza las comparaciones e intercambios utilizando iteradores
    for (k++; k != vals.end(); j++, k++) {
        // Si el elemento apuntado por j es mayor que el siguiente elemento apuntado por k
        if (*j > *k) {
            int swap = *j;  // Almacena el valor apuntado por j en una variable temporal
            *j = *k;        // Asigna el valor apuntado por k a la posición de j
            *k = swap;      // Asigna el valor almacenado en la variable temporal a la posición de k
        }
    }
}
16. Codigo//ordenamiento burbuja con Deque

    deque<int> vals; 

// Bucle externo que controla el número de pasadas a través del deque
for (int i = 0; i < vals.size(); i++) {
    // Inicializa dos iteradores para recorrer el deque
    deque<int>::iterator j = vals.begin(); // Iterador que apunta al inicio del deque
    deque<int>::iterator k = j;            // Iterador k inicializado en la misma posición que j

    // Bucle interno que realiza las comparaciones e intercambios utilizando iteradores
    for (k++; k != vals.end(); j++, k++) {
        // Si el elemento apuntado por j es mayor que el siguiente elemento apuntado por k
        if (*j > *k) {
            int swap = *j;  // Almacena el valor apuntado por j en una variable temporal
            *j = *k;        // Asigna el valor apuntado por k a la posición de j
            *k = swap;      // Asigna el valor almacenado en la variable temporal a la posición de k
        }
    }
}
17. Codigo// Ordenamineot burbuja con Lista
  
    // Bucle externo: recorre toda la lista tantas veces como su tamaño
    for(int i = 0; i < vals.size(); i++) {
        // Se inicializan dos iteradores, j y k, que apuntan al primer elemento de la lista
        list<int>::iterator j = vals.begin();
        list<int>::iterator k = j;

        // Bucle interno: recorre la lista desde el segundo elemento hasta el final
        for(k++; k != vals.end(); j++, k++) {
            // Si el valor apuntado por j es mayor que el valor apuntado por k, se intercambian
            if(*j > *k) {
                int swap = *j;  // Se guarda temporalmente el valor de j
                *j = *k;        // Se asigna el valor de k a j
                *k = swap;      // Se asigna el valor guardado en swap a k
            }
        }
    }
18. Codigo
    using namespace std;

typedef list<T> TsubLista; 

typedef list<TsubLista> TLista; 

TLista listaMulti; 

// Se crea un iterador lIt que apunta al inicio de la lista listaMulti
TLista::iterator lIt = listaMulti.begin(); 

// Bucle externo: recorre todos los elementos de listaMulti
for(; lIt != listaMulti.end(); lIt++) { 
    // Se crea un iterador sublIt que apunta al inicio de la sublista actual
    TsubLista::iterator sublIt = lIt->begin(); 

    // Bucle interno: recorre todos los elementos de la sublista actual
    for(; sublIt != lIt->end(); sublIt++) { 
        // Imprime el valor apuntado por sublIt
        cout << *sublIt << endl; 
    }
}

   
