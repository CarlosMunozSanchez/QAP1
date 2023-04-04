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
        
        /**
         * @brief Actualiza el vector de potencial de flujos.
         * @param flujos Matriz de flujos asociada.
         */
        void actualizarFlujos(const std::vector<std::vector<int>> & flujos);
        
        /**
         * @brief Actualiza el vector de potencial de distancias.
         * @param distancias Matriz de distancias asociada.
         */
        void actualizarDistancia(const std::vector<std::vector<int>> & distancias);
        
        /**
         * @brief Calcula la solución al problema de forma Greedy, usando
         * los potenciales de flujo y distancia.
         */
        void calcularSolucion();
        
    public:
        QAPGreedy(const std::vector<std::vector<int>> & flujos, const std::vector<std::vector<int>> & distancias);
    

        std::vector<int> getPotencialDistancia() const {
            return potencialDistancia;
        }

        std::vector<int> getPotencialFlujo() const {
            return potencialFlujo;
        }

        std::vector<int> getSolucion() const {
            return solucion;
        }

        
};

#endif /* QAPGREEDY_H */

