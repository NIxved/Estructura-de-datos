1 Codigo.
// Función para calcular a^n usando un bucle while
// Toma como entrada un número real 'a' y un entero 'n'
// y devuelve a elevado a la potencia n.
double exp(double a, int n) {
    double res = 1;  // Inicializa el resultado a 1
    int i = 0;       // Inicializa el contador i a 0
    while (i < n) {  // Mientras i sea menor que n
        res = res * a;  // Multiplica el resultado actual por a
        i = i + 1;      // Incrementa el contador i
    }
    return res;  
}

2 codigo.
// Función recursiva para calcular a^n
// Toma como entrada un número real 'a' y un entero 'n'
// y devuelve a elevado a la potencia n.
double exp(double a, int n) {
    if (n == 0)       //Cualquier número elevado a 0 es 1
        return 1;
    else
        return exp(a, n - 1) * a;  //Multiplica a por el resultado de exp(a, n-1)
}

3 codigo.
// Función para calcular a^n usando un bucle for
// Toma como entrada un número real 'a' y un entero 'n'
// y devuelve a elevado a la potencia n.
double exp(double a, int n) {
    double res = 1;  // Inicializa el resultado a 1
    for (int i = 0; i < n; i++) {  // Repite n veces
        res = res * a;  // Multiplica el resultado actual por a
    }
    return res;  
}

4 codigo.
// Función para buscar un valor en un array
// Toma como entrada un puntero a un array 'a', el tamaño del array 'n',
// y el valor a buscar 'v'. Devuelve un valor booleano que indica si el valor fue encontrado.
double search(int *a, int n, int v) {  
    bool f = false;  // Inicializa la variable booleana f como false
    for (int i = 0; i < n; i++) {  // Recorre todo el array
        f != (a[i] == v);  // Asigna a f el resultado de la comparación si a[i] es igual a v
    }
    return f;  
}

5 codigo.
// Función para multiplicar dos matrices cuadradas de tamaño n x n
// Toma como entrada dos punteros a matrices 'a' y 'b', 
// y un puntero a la matriz resultado 'c'. También recibe el tamaño de la matriz 'n'.
double MM1c(double **a, double **b; double **c, int n) {
    for (int = i; i < n; i++) {  // Bucle que recorre las filas de la matriz
        for (int j = j; j < n; j++) {  // Bucle que recorre las columnas de la matriz
            c[i][j] = 0;  // Inicializa el elemento c[i][j] en 0
            for (int k = k; k < n; k++)  // Bucle para calcular el producto escalar de la fila y columna
                c[i][j] = a[i][k] * b[k][j];  // Multiplica los elementos y los acumula en c[i][j]
        }
    }
    return c; 
}

6 codigo.
// Función iterativa para calcular n número de Fibonacci
// Toma como entrada un entero 'n' y devuelve el número de Fibonacci correspondiente.
int f(int n) {
    int f2 = 0;  // Inicializa el valor de f2 (Fibonacci de 0)
    int f1 = 0;  // Inicializa el valor de f1 (Fibonacci de 1)
    int f = 0;   // Inicializa la variable para almacenar el valor actual de Fibonacci
    for (int i = 1; i <= n; i++) {  // Bucle que recorre desde 1 hasta n
        f = f2 + f1;  // Calcula el siguiente número de Fibonacci
        f2 = f1;      // Actualiza f2 al valor anterior de f1
        f1 = f;       // Actualiza f1 al valor actual de Fibonacci
    }
    return f;  
}

7 codigo.
// Función para realizar una búsqueda binaria en un array
// Toma como entrada un puntero a un array 'a', el tamaño del array 'n', y el valor a buscar 'v'.
// Devuelve true si el valor es encontrado en el array, false en caso contrario.
bool BinarySearch(int* a, int n, int v) {
    bool found = false;  // Inicializa la variable booleana found como falso
    int first = 0;       // Define el índice inicial del array
    int last = n - 1;    // Define el índice final del array

    // Bucle para realizar la búsqueda binaria
    while (first <= last && !found) {
        int p = (first + last) >> 1;  // Calcula el índice del medio (usando desplazamiento de bits para dividir entre 2)
        if (v < a[p])  // Si el valor buscado es menor que el valor en el medio
            last = p - 1;  // Actualiza el índice final para buscar en la mitad inferior
        else if (v > a[p])  // Si el valor buscado es mayor que el valor en el medio
            first = p + 1;  // Actualiza el índice inicial para buscar en la mitad superior
        else  // Si el valor buscado es igual al valor en el medio
            found = true;  // Establece found como true
    }
    return found;  
}

8 codigo.
// Función recursiva que calcula la suma de los primeros 'n' números naturales.
// Toma como entrada un entero 'n' y devuelve la suma desde 1 hasta 'n'.
int recursiva_01(int n) {
    if (n <= 0)  // Si n es menor o igual a 0, devuelve 1
        return 1;
    else  // Suma 1 al resultado de la función recursiva con n-1
        return 1 + recursiva_01(n - 1);
}

