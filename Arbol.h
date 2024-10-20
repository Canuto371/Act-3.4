#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Nodo{
private:
    Nodo *right, *left;
    int dato;

public:
    Nodo();
    Nodo(int d);
    int getDato();
    Nodo* getLeft();
    Nodo* getRight();
  	void setLeft(Nodo *_left);
  	void setRight(Nodo *_right);
    void setDato(int _dato);
    ~Nodo();
};

class Arbol {
public:
    Arbol();
    Nodo *raiz;
    Nodo* insertarNodo(Nodo *r, int d);
    void leerNodosDesdeArchivo(const string& nombreArchivo);
    void inOrden(Nodo* r, vector<int>& datos);
    void imprimirVector(const vector<int>& datos);
    void minComparaciones(vector<int>& datos);
    ~Arbol();
};

#endif