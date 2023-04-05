/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 5 de abril de 2023, 12:11
 */

#include <iostream>
#include <chrono>
#include "QAPGreedy.h"
#include "QAPBL.h"
#include "funciones.h"

using namespace std;
using namespace std::chrono;

/*
 * 
 */
int main(int argc, char** argv){
    
    if(argc != 3){
        cerr << "Uso: " << argv[0] << " [archivo de datos] [semilla]" << endl;
        exit(-1);
    }
    
    //lectura de datos de entrada
    string entrada(argv[1]);
    int seed = atoi(argv[2]);
    
    vector<vector<int>> flujos, distancias;
    
    leerDatos(entrada, flujos, distancias);
    
    vector<int> solucion;
    
    cout << "---------------------------------------------------------------" << endl;
    
    //Greedy
    auto momentoInicio = high_resolution_clock::now();
    QAPGreedy greedy(flujos, distancias);
    
    solucion = greedy.getSolucion();
    auto momentoFin = high_resolution_clock::now();
    
    cout << "Solución greedy con coste " << evaluarSolucion(solucion, flujos, distancias);    
    mostrarVector(solucion);
    
    microseconds tiempo = duration_cast<std::chrono::microseconds>(momentoFin - momentoInicio);
    cout << "Tiempo Pasado: " << tiempo.count() / 1000.0 << endl;
    
    
    cout << "---------------------------------------------------------------" << endl;
    
    //Búsqueda local
    momentoInicio = high_resolution_clock::now();
    QAPBL bl(flujos, distancias, seed);
    
    solucion = bl.getSolucion();
    momentoFin = high_resolution_clock::now();
    
    cout << "Solución búsqueda local con coste " << evaluarSolucion(solucion, flujos, distancias);    
    mostrarVector(solucion);
    
    tiempo = duration_cast<std::chrono::microseconds>(momentoFin - momentoInicio);
    cout << "Tiempo Pasado: " << tiempo.count() / 1000.0 << endl;
}



