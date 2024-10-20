
#include "Arbol.cpp"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    Arbol arbolito; // Instancia de clase Árbol
    int lim;
    int data;
    int tipoOrden;
    int opcion;

    try {
        cout << "¿Cuántos datos deseas insertar?" << endl;

        while (true) {
            cin >> lim;
            if (cin.fail() || lim <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Por favor, ingresa un número entero positivo." << endl;
            } else {
                break;
            }
        }

        cout << "***El primer dato será el nodo raíz del nivel 0.***\n\n";

        for (int i = 0; i < lim; i++) {
            cout << "Dato a insertar: " << endl;

            while (true) {
                cin >> data;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Por favor, ingresa un número entero." << endl;
                } else {
                    arbolito.raiz = arbolito.insertarNodo(arbolito.raiz, data);
                    break;
                }
            }

        }
    } catch (const exception &e) {
        cout << "Ocurrió un error: " << e.what() << endl;
    }


    // Menú 
    do {
        cout << "=========================================\n";
        cout << "          Opciones del Árbol            \n";
        cout << "=========================================\n";
        cout << "1. Recorrido Preorder\n";
        cout << "2. Recorrido Inorder\n";
        cout << "3. Recorrido Postorder\n";
        cout << "4. Recorrido Nivel por Nivel\n";
        cout << "5. Mostrar ancestros de un nodo\n";
        cout << "6. Saber el nivel de un elemento\n";
        cout << "7. Saber la altura de todo el árbol\n";
        cout << "8. Terminar programa\n";
        cout << "=========================================\n";
        cout << "Selecciona una opción (1-8): ";
        cin >> opcion;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Ingresa un número válido.\n";
        }

        switch (opcion) { 
            case 1:
                tipoOrden = 1; // Preorden
                arbolito.visit(tipoOrden);
                cout << endl;
                break;
            case 2:
                tipoOrden = 2; // Inorden
                arbolito.visit(tipoOrden);
                cout << endl;
                break;
            case 3:
                tipoOrden = 3; // Postorden
                arbolito.visit(tipoOrden);
                cout << endl;
                break;
            case 4:
                tipoOrden = 4; // Nivel por Nivel
                arbolito.visit(tipoOrden);
                break;
            case 5: 
            {
                int value;
                try{   
                    while (true) {
                        cout << "Ingresar el nodo: ";
                        cin >> value;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                            cout << "Por favor, ingresa un número entero." << endl;
                        } else {
                            if (arbolito.whatlevelamI(value) < 0) {
                                cout << "El nodo " << value << " no se encuentra en el árbol. Por favor, intenta de nuevo." << endl;
                            } else {
                                cout << "Ancestros de " << value << ": ";
                                arbolito.ancestors(arbolito.raiz, value);
                                cout << endl << endl;
                                break; 
                            }
                        }
                    }
                } catch (const exception &e) {
                    cout << "Ocurrió un error: " << e.what() << endl;
                }
            break;
            }
            case 6:
            {
                int value;
                try{
                    while (true) {
                        cout << "Ingresar el nodo: ";
                        cin >> value;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                            cout << "Por favor, ingresa un número entero." << endl;
                        } else {
                            int nivel = arbolito.whatlevelamI(value);
                            if (nivel < 0) {
                                cout << "El nodo " << value << " no se encuentra en el árbol. Por favor, intenta de nuevo." << endl;
                            } else {
                                cout << "El nivel del nodo " << value << " es: " << nivel << endl;
                                cout << endl << endl;
                                break;
                            }
                        }
                    }
                } catch (const exception &e) {
                    cout << "Ocurrió un error: " << e.what() << endl;
                }
            break;
            }
            case 7:
                cout << "La altura del árbol es: " << arbolito.height(arbolito.raiz);
                cout << endl << endl;
                break;
            case 8:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Favor de intentar de nuevo.\n";
                break;
        }
    } while (opcion != 8);

    return 0;
}
