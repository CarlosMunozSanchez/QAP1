/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 5 de abril de 2023, 12:11
 */

#include <iostream>
#include "QAPGreedy.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(){

    string fichero = "./Instancias_QAP/chr22a.dat";
    
    vector<vector<int>> flujos, distancias;
    
    leerDatos(fichero, flujos, distancias);
    
    //mostrarMatriz(flujos);
    //mostrarMatriz(distancias);
    
    //int valores[] = {15, 2, 21, 8, 16, 1, 7, 18, 14, 13, 5, 17, 6, 11, 3, 4, 20, 19, 9, 22, 10, 12};
    int valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
    vector<int> solucion (valores, valores + sizeof(valores) / sizeof(int) );
    
    for(int i = 0; i < solucion.size(); i++){
        cout << solucion[i] << " ";
    }
    
    cout << endl;
    
    int s = evaluarSolucion(solucion, flujos, distancias);
    
    cout << s << endl;
    
    
    cout << "SOLUCIÓN GREEDY" << endl;
    
    QAPGreedy greedy(flujos, distancias);
    
    s = evaluarSolucion(greedy.getSolucion(), flujos, distancias);
    
    solucion = greedy.getSolucion();
    
    for(int i = 0; i < solucion.size(); i++){
        cout << solucion[i] << " ";
    }
    
    cout << endl << s << endl;
    
}



