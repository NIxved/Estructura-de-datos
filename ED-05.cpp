1. Codigo
// Representa la data del nodo. Puede ser lo que se quiera.
typedef int DATA;

// Representa un nodo de una lista enlazada simple
class NodoS {
private:
    DATA Dato;      // Almacena el dato del nodo
    NodoS *Sig;     // Apunta al siguiente nodo en la lista

public:
    // Construye un nodo con un dato dado
    NodoS(DATA d) { Dato = d, Sig = 0L; }

    // Operaciones para obtener / cambiar el dato
    DATA ObtDato() { return Dato; }
    void AsgDato(DATA d) { Dato = d; }

    // Operaciones para cambiar / obtener la referencia al siguiente nodo
    NodoS *ObtSig() { return Sig; }
    void AsgSig(NodoS *s) { Sig = s; }
};

// Representa una lista enlazada simple con referencias a la cabecera y la cola
class ListaS {
private:
    NodoS *Cab, *Col; // Punteros a la cabeza y la cola de la lista
    int N;            // Número de elementos en la lista

    // Limpia la lista suprimiendo todos sus nodos
    void Vaciar();

public:
    // Constructor: Inicializa una lista vacía
    ListaS() { Cab = Col = 0L; N = 0; }

    // Destructor: Limpia la lista al destruir el objeto
    ~ListaS() { Vaciar(); }

    // Métodos para agregar un dato
    bool AgregarPos(DATA d, int Pos);
    bool AgregarComienzo(DATA d) { return AgregarPos(d, 0); }
    bool AgregarFinal(DATA d) { return AgregarPos(d, N); }

    // Métodos para suprimir un dato
    bool Suprimir(DATA d);
    bool Suprimir(int Pos);

    // Número de elementos en la lista
    int NumElementos() { return N; }

    // Si la lista está o no vacía
    bool EstaVacia() { return N == 0; }

    // Saber si un dato está o no en la lista
    bool EstaDato(DATA d);

    // Retornar el dato que está en una posición específica
    DATA ObtData(int Pos);
    DATA operator[](int Pos) { return ObtData(Pos); }
};

// Representa un nodo de una lista enlazada doble
class NodoD {
private:
    DATA Dato;      // Almacena el dato del nodo
    NodoD *Sig, *Ant; // Punteros al siguiente y anterior nodo

public:
    // Construye un nodo con un dato dado
    NodoD(DATA d) { Dato = d, Sig = Ant = 0L; }

    // Operaciones para obtener / cambiar el dato
    DATA ObtDato() { return Dato; }
    void AsgDato(DATA d) { Dato = d; }

    // Operaciones para cambiar / obtener las referencias
    NodoD *ObtSig() { return Sig; }
    void AsgSig(NodoD *s) { Sig = s; }

    NodoD *ObtAnt() { return Ant; }
    void AsgAnt(NodoD *a) { Ant = a; }
};

// Representa una lista enlazada doble
class ListaD {
private:
    NodoD *Cab, *Col; // Punteros a la cabeza y la cola de la lista
    int N;            // Número de elementos en la lista

    // Limpia la lista suprimiendo todos sus nodos
    void Vaciar();

public:
    // Constructor: Inicializa una lista vacía
    ListaD() { Cab = Col = 0L; N = 0; }

    // Destructor: Limpia la lista al destruir el objeto
    ~ListaD() { Vaciar(); }

    // Métodos para agregar un dato
    bool AgregarPos(DATA d, int Pos);
    bool AgregarComienzo(DATA d) { return AgregarPos(d, 0); }
    bool AgregarFinal(DATA d) { return AgregarPos(d, N); }
};

// Representa un conjunto
class Conjunto {
private:
    ListaS S; // Utiliza una lista enlazada simple para representar el conjunto

public:
    // Agregar / suprimir elementos
    void Agregar(DATA d) { S.AgregarFinal(d); }
    void Suprimir(DATA d) { S.Suprimir(d); }

    // Operaciones
    Conjunto operator +(Conjunto S1); // Unión de conjuntos
    Conjunto Union(Conjunto S1, Conjunto S2) { return S1 + S2; }

    Conjunto operator *(Conjunto S1); // Intersección de conjuntos
    Conjunto Interseccion(Conjunto S1, Conjunto S2) { return S1 * S2; }

    Conjunto operator -(Conjunto S1); // Diferencia de conjuntos
    Conjunto Diferencia(Conjunto S1, Conjunto S2) { return S1 - S2; }

    
    bool Pertenencia(DATA d) { return S.EstaDato(d); }
    bool Vacio() { return S.EstaVacia(); }
    int Cardinalidad() { return S.NumElementos(); }
    bool SubConjunto(Conjunto S1);
};
2. Codigo
  #include <list>
using namespace std;

class HashMapTable {
private:
    // Tamaño de la tabla hash
    int table_size;
    // Puntero a un arreglo que contiene las claves
    list<int> *table;

public:
    // Constructor que inicializa la tabla hash con el tamaño dado
    HashMapTable(int ts) {
        this->table_size = ts;
        table = new list<int>[table_size];
    }

    // Función hash para calcular el índice usando el tamaño de la tabla y la clave
    int hashFunction(int key) {
        return (key % table_size);
    }

    // Función para insertar una clave en la tabla hash
    void insertElement(int key) {
        int index = hashFunction(key);  // Calcula el índice
        table[index].push_back(key);    // Inserta la clave en la lista en ese índice
    }

    // Función para eliminar una clave de la tabla hash
    void deleteElement(int key) {
        int index = hashFunction(key);  // Calcula el índice
        // Encuentra la clave en la lista correspondiente al índice
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == key)              // Si encuentra la clave
                break;
        }
        // Elimina la clave si se encuentra
        if (i != table[index].end())
            table[index].erase(i);
    }

    // Función para mostrar la tabla hash completa
    void displayHashTable() {
        for (int i = 0; i < table_size; i++) {
            cout << i;
            // Recorre la lista en el índice actual
            for (auto j : table[i])
                cout << " ==> " << j;
            cout << endl;
        }
    }
};


int main() {
    // Arreglo con todas las claves a insertar en la tabla hash
    int arr[] = {20, 34, 56, 54, 76, 87};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Tamaño de la tabla hash
    HashMapTable ht(6);
    // Inserta cada clave en la tabla hash
    for (int i = 0; i < n; i++)
        ht.insertElement(arr[i]);

    // Elimina el elemento 34 de la tabla hash
    ht.deleteElement(34);

    // Muestra la tabla hash final
    ht.displayHashTable();

    return 0;
}
