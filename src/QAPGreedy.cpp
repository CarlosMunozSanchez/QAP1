/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   QAPGreedy.cpp
 * Author: carlos
 * 
 * Created on 4 de abril de 2023, 13:49
 */

#include "QAPGreedy.h"

QAPGreedy::QAPGreedy(const std::vector<std::vector<int>> & flujos, const std::vector<std::vector<int>> & distancias) {
    
    actualizarFlujos(flujos);
    actualizarDistancia(distancias);
    calcularSolucion();
    
}

void QAPGreedy::actualizarFlujos(const std::vector<std::vector<int>> & flujos){
    
    potencialFlujo.resize(flujos.size());
    
    for(int i = 0; i < potencialFlujo.size(); i++){
        potencialFlujo[i] = 0;
        for(int j = 0; j < potencialFlujo.size(); j++){
            potencialFlujo[i] += flujos[i][j];
        }
    }
}

void QAPGreedy::actualizarDistancia(const std::vector<std::vector<int>> & distancias){
    potencialDistancia.resize(distancias.size());
    
    for(int i = 0; i < potencialDistancia.size(); i++){
        potencialDistancia[i] = 0;
        for(int j = 0; j < potencialDistancia.size(); j++){
            potencialDistancia[i] += distancias[i][j];
        }
    }
}

void QAPGreedy::calcularSolucion(){
    solucion.resize(potencialFlujo.size());
    
    for(int i = 0; i < solucion.size(); i++){
        
        int unidad = 0;
        int aux = potencialFlujo[0];
        
        //busco la unidad con más flujo
        for(int j = 1; j < potencialFlujo.size(); j++){
            if(potencialFlujo[j] > aux){
                unidad = j;
                aux = potencialFlujo[j];
            }            
        }
        
        int loc = 0;
        aux = potencialDistancia[0];
        
        //busco la localización más céntrica
        for(int j = 1; j < potencialDistancia.size(); j++){
            if(potencialDistancia[j] < aux){
                loc = j;
                aux = potencialDistancia[j];
            }            
        }
        
        //actualizo la solución
        solucion[unidad] = loc;
        
        //modifico los valores para que no vuelvan a salir
        potencialFlujo[unidad] = -1;
        potencialDistancia[loc] = 999999;
        
    }
}


