1. Codigo
#include <stdlib.h>
#include <iostream>

using namespace std;

// Definición de la estructura de un nodo para un árbol binario
struct node {
    int data;           // Dato almacenado en el nodo
    struct node *left;  // Puntero al hijo izquierdo
    struct node *right; // Puntero al hijo derecho
};

// Función para crear un nuevo nodo en el árbol
struct node *newNode(int data) {
    // Se asigna memoria para un nuevo nodo
    struct node *node = (struct node *)malloc(sizeof(struct node));

    // Se asigna el valor proporcionado al nodo
    node->data = data;

    // Inicializa los punteros izquierdo y derecho como NULL (ningún hijo)
    node->left = NULL;
    node->right = NULL;

    // Retorna el puntero al nuevo nodo creado
    return (node);
}
2. Codigo
  // Recorrido Preorden
void traversePreOrder(struct node *temp) {
    if (temp != NULL) {
        // Imprime el dato del nodo actual
        cout << " " << temp->data;
        // Recorrido en el subárbol izquierdo
        traversePreOrder(temp->left);
        // Recorrido en el subárbol derecho
        traversePreOrder(temp->right);
    }
}

// Recorrido Inorden
void traverseInOrder(struct node *temp) {
    if (temp != NULL) {
        // Recorrido en el subárbol izquierdo
        traverseInOrder(temp->left);
        // Imprime el dato del nodo actual
        cout << " " << temp->data;
        // Recorrido en el subárbol derecho
        traverseInOrder(temp->right);
    }
}

// Recorrido Postorden
void traversePostOrder(struct node *temp) {
    if (temp != NULL) {
        // Recorrido en el subárbol izquierdo
        traversePostOrder(temp->left);
        // Recorrido en el subárbol derecho
        traversePostOrder(temp->right);
        // Imprime el dato del nodo actual
        cout << " " << temp->data;
    }
}

int main() {
    // Creación de nodos del árbol
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    // Imprime el recorrido preorden
    cout << "Preorder traversal: ";
    traversePreOrder(root);

    // Imprime el recorrido inorden
    cout << "\nInorder traversal: ";
    traverseInOrder(root);

    // Imprime el recorrido postorden
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);

    return 0;
}
3. Codigo
  // Definición de la clase para el nodo de un árbol binario de búsqueda (BST)
class BST_arbol {
    int data;           // Dato almacenado en el nodo
    BST_arbol *left;    // Puntero al hijo izquierdo
    Nodo *right;        // Puntero al hijo derecho
};

// Función para crear un nuevo nodo en el árbol
Nodo *crearNodo(int dato) {
    Nodo *nuevoNodo = new Nodo(); // Asigna memoria para un nuevo nodo
    nuevoNodo->data = dato;       // Asigna el dato al nodo
    nuevoNodo->left = nullptr;    // Inicializa el puntero izquierdo a NULL
    nuevoNodo->right = nullptr;   // Inicializa el puntero derecho a NULL
    return nuevoNodo;             // Retorna el nuevo nodo creado
}


int main() {
    Nodo *root = crearNodo(1);       // Crea el nodo raíz con el dato 1
    root->left = crearNodo(2);       // Crea el hijo izquierdo del nodo raíz con el dato 2
    root->right = crearNodo(3);      // Crea el hijo derecho del nodo raíz con el dato 3
    root->left->left = crearNodo(4); // Crea el hijo izquierdo del nodo 2 con el dato 4
    root->left->right = crearNodo(5); // Crea el hijo derecho del nodo 2 con el dato 5
    root->left->right->left = crearNodo(9); // Crea el hijo izquierdo del nodo 5 con el dato 9
    root->right->left = crearNodo(6); // Crea el hijo izquierdo del nodo 3 con el dato 6
    root->right->right = crearNodo(7); // Crea el hijo derecho del nodo 3 con el dato 7
    root->right->right->left = crearNodo(15); // Crea el hijo izquierdo del nodo 7 con el dato 15

    return 0;
}
4. Codigo
  void imprimir_arbol(Nodo *root) {
    // Si el nodo actual es NULL, retorna sin hacer nada
    if (root == nullptr) return;

    // Imprime el dato del nodo actual
    cout << root->data << endl;

    // Llama recursivamente a la función para el subárbol izquierdo
    imprimir_arbol(root->left);

    // Llama recursivamente a la función para el subárbol derecho
    imprimir_arbol(root->right);
}
5. Codigo
  void imprimir_arbol(Nodo *root) {
    // Si el nodo actual es NULL, retorna sin hacer nada
    if (root == nullptr) return;

    // Llama recursivamente a la función para el subárbol izquierdo
    imprimir_arbol(root->left);

    // Imprime el dato del nodo actual
    cout << root->data << endl;

    // Llama recursivamente a la función para el subárbol derecho
    imprimir_arbol(root->right);
}
6. Codigo
  void imprimir_arbol(Nodo *root) {
    // Si el nodo actual es NULL, retorna sin hacer nada
    if (root == nullptr) return;

    // Llama recursivamente a la función para el subárbol izquierdo
    imprimir_arbol(root->left);

    // Llama recursivamente a la función para el subárbol derecho
    imprimir_arbol(root->right);

    // Imprime el dato del nodo actual
    cout << root->data << endl;
}
7. Codigo
  class BST_arbol {
    int data;           // Almacena el dato del nodo
    BST_arbol *left;    // Puntero al hijo izquierdo
    BST_arbol *right;   // Puntero al hijo derecho

public:
    BST_arbol();        // Constructor por defecto
    BST_arbol(int);     // Constructor parametrizado

    // Función para imprimir el árbol en inorden
    void Imprimir_InOrder(BST_arbol*);

    // Función para insertar un nuevo nodo en el árbol
    BST_arbol* Insertar(BST_arbol*, int);

    // Función para encontrar el valor mínimo en el árbol
    int MinValor(BST_arbol*);
};
8. Codigo
  BST_arbol* BST_arbol::Insertar(BST_arbol *nodo, int valor) {
    // Si el nodo actual es nullptr, se ha encontrado el lugar para insertar el nuevo nodo
    if (nodo == nullptr)
        return new BST_arbol(valor); // Crea un nuevo nodo con el valor dado

    // Se recorre el árbol para encontrar la posición correcta para el nuevo nodo
    if (valor > nodo->data)
        nodo->right = Insertar(nodo->right, valor); // Inserta en el subárbol derecho si el valor es mayor que el dato del nodo actual
    else
        nodo->left = Insertar(nodo->left, valor); // Inserta en el subárbol izquierdo si el valor es menor o igual que el dato del nodo actual

    // Retorna el nodo actual después de la inserción
    return nodo;
};
