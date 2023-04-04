/* 
 * File:   QAPGreedy.h
 * Author: carlos
 *
 * Created on 4 de abril de 2023, 13:49
 */
#include <vector>

#ifndef QAPGREEDY_H
#define QAPGREEDY_H

class QAPGreedy {
    private:
        std::vector<int> potencialFlujo;
        std::vector<int> potencialDistancia;
        
        //permutación solución final
        std::vector<int> solucion;
        
        void actualizarFlujos();
        void actualizarDistancia();
        void calcularSolucion();
        
    public:
        QAPGreedy(const std::vector<std::vector<int>> & flujos, const std::vector<std::vector<int>> & distancias);
        
        std::vector<int> getSolucion();

};

#endif /* QAPGREEDY_H */

