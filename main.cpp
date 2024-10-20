// Act 3.4 - Actividad Integral de Árboles (Evidencia Competencia)
// Elizabeth Jauregui Zarate (A01253381)

/* El presente programa lee el # de elementos del árbol (1era línea del archivo) y sus respectivos datos (2da línea) de un archivo .txt.
   El programa guarda los datos en un árbol binario. Mediante el uso de los recorridos inOrder, se acomodan los datos de menor a mayor y 
   se imprime el mínimo de comparaciones siguiendo este formato : m + n - 1. 
*/   
#include "Arbol.cpp"
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    Arbol arbolito; 
    Nodo* r = nullptr;
    vector<int> datos;

    arbolito.leerNodosDesdeArchivo("pedidos.txt");

    arbolito.inOrden(arbolito.raiz, datos);

    if (!datos.empty()) {
        //arbolito.imprimirVector(datos);

        arbolito.minComparaciones(datos);
    } else {
        cout << "El vector de datos está vacío. Asegúrate de que 'pedidos.txt' contenga datos válidos." << endl;
    }

    return 0;
}
