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
    
    if(argc < 3 or argc > 4){
        cerr << "Uso: " << argv[0] << " [archivo de datos] [semilla] [archivo de solucion]" << endl;
        exit(-1);
    }
    
    //lectura de datos de entrada
    string entrada(argv[1]);
    int seed = atoi(argv[2]);
    string sol;
    vector<int> optimo;
    int costeOptimo = 1;
    
    if(argc == 4){
        sol = argv[3];
        costeOptimo = leerSolucion(sol, optimo);
    }
    
    vector<vector<int>> flujos, distancias;
    
    leerDatos(entrada, flujos, distancias);
    
    vector<int> solucion;
    
    cout << "---------------------------------------------------------------" << endl;
    cout << "Resultados del archivo " << entrada << endl << endl;
    
    //Greedy
    auto momentoInicio = high_resolution_clock::now();
    QAPGreedy greedy(flujos, distancias);
    
    solucion = greedy.getSolucion();
    auto momentoFin = high_resolution_clock::now();
    
    float fitness = costeOptimo;
    cout << "Solución greedy con coste " << evaluarSolucion(solucion, flujos, distancias, fitness) <<
            " y fitness = " << fitness << endl;    
    mostrarVector(solucion);
    
    microseconds tiempo = duration_cast<std::chrono::microseconds>(momentoFin - momentoInicio);
    cout << "Tiempo Pasado (ms): " << tiempo.count() / 1000.0 << endl;
    
    
    cout << "---------------------------------------------------------------" << endl;
    
    //Búsqueda local
    momentoInicio = high_resolution_clock::now();
    QAPBL bl(flujos, distancias, seed);
    
    solucion = bl.getSolucion();
    momentoFin = high_resolution_clock::now();
    
    fitness = costeOptimo;
    cout << "Solución búsqueda local con coste " << evaluarSolucion(solucion, flujos, distancias, fitness) <<
            " y fitness = " << fitness << endl;    
    mostrarVector(solucion);
    
    tiempo = duration_cast<std::chrono::microseconds>(momentoFin - momentoInicio);
    cout << "Tiempo Pasado (ms): " << tiempo.count() / 1000.0 << endl;
}



