#include "Arbol.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

// Definición del constructor por defecto de la clase Nodo
Nodo::Nodo() {
    right = left = nullptr;
}

// Definición del constructor que recibe un dato
Nodo::Nodo(int d) {
    dato = d;
    right = left = nullptr;
}

// Obtener datos
int Nodo::getDato() {
    return dato;
}
        
Nodo* Nodo::getLeft() {
    return left;
}
        
Nodo* Nodo::getRight() {
    return right;
}
  
void Nodo::setLeft(Nodo *_left) {
    left = _left;
}
  
void Nodo::setRight(Nodo *_right) {
    right = _right;
}
  
void Nodo::setDato(int _dato) {
    dato = _dato;
}

// Destructor de la clase Nodo
Nodo::~Nodo(){}

// Constructor de la clase Arbol
Arbol::Arbol(){
    raiz = nullptr;
}

// La complejidad en el peor caso es O(n), donde n es la altura del árbol.
// El método realiza una comparación en cada nivel del árbol para decidir si inserta en el subárbol izquierdo o derecho.
// En el peor de los casos, la inserción puede requerir recorrer la altura completa del árbol.
Nodo* Arbol::insertarNodo(Nodo *r, int d) {
    if (r == nullptr) {
        return new Nodo(d);
    } 
    // Comparación del valor d con el dato del nodo actual.
    if (d < r->getDato()) {
        // Si d es menor, insertamos en el subárbol izquierdo.
        r->setLeft(insertarNodo(r->getLeft(),d));
    } else if (d > r->getDato()) {
        // Si d es mayor, insertamos en el subárbol derecho.
        r->setRight(insertarNodo(r->getRight(),d));
    } else {
        cout << "ERROR. Solo puede existir una vez el valor." << endl;
    }
    return r;
}

// Complejidad en el peor caso es de O(n^2), donde insertar un nodo tiene una complejidad O(n), y el bucle se itera n veces.
void Arbol::leerNodosDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    // Complejidad O(n), donde n es el número de elementos en el archivo.
    // Se lee un número entero desde el archivo, que tiene una complejidad O(1).
    int numeroDeElementos;
    archivo >> numeroDeElementos;

    if (!archivo) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    // Complejidad temporal de O(n), donde n son el número de nodos.
    // Se insertan los elementos del .txt en nodos para formar el árbol
    // Si hay n elementos en el archivo, el bucle se ejecuta n veces.
    for (int i = 0; i < numeroDeElementos; i++) {
        int valor;
        if (archivo >> valor) {
            raiz = insertarNodo(raiz, valor);
        } else {
            cout << "No se pudo leer el valor #" << (i + 1) << endl;
            break; 
        }
    }

    archivo.close();
}

// La complejidad en el peor caso es O(n), donde n es el número de nodos en el árbol.
// Método para realizar el recorrido en inOrden	
// Cada nodo se visita una vez y se realiza una operación constante para cada nodo. 
// Por lo tanto, el número total de llamadas recursivas es proporcional a la cantidad de nodos en el árbol.
void Arbol::inOrden(Nodo* r, vector<int>& datos) {
    if (r != nullptr) {
        inOrden(r->getLeft(), datos);
        datos.push_back(r->getDato());
        inOrden(r->getRight(), datos);
    }
}

/*
void Arbol::imprimirVector(const vector<int>& datos) {
    cout << "Contenido del vector: ";
    for (int d : datos) {
        cout << d << " ";
    }
    cout << endl;
}
*/

// Complejidad temporal de O(n^2), donde n es el número inicial de elementos en el vector.
// Las operaciones de eliminación e inserción tienen relación directa con el tamaño del vector, que disminuye en cada paso.
// O(n) para cada iteración, y como hay n−1 iteraciones, la complejidad total es O(n^2).
void Arbol::minComparaciones(vector<int>& datos) {
    int comparacion = 0;
    // En cada iteración, el tamaño de datos se reduce en 1, ya que eliminamos dos elementos pero añadimos uno nuevo. 
    while (datos.size() > 1){
        int suma = datos[0] + datos[1] - 1;
        comparacion += suma;

        // Se eliminan los dos primeros elementos del vector
        datos.erase(datos.begin());   
        datos.erase(datos.begin());     
        // Se agrega la suma de la operación anterior al inicio del vector  
        datos.insert(datos.begin(), suma);
    }
    cout << "Número mínimo de comparaciones: " << comparacion << endl;
}

// Destructor de la clase Arbol
Arbol::~Arbol(){}
