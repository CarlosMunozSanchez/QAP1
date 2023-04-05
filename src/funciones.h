/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: carlos
 *
 * Created on 5 de abril de 2023, 12:21
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

/**
 * @brief Función que lee los datos del fichero de entrada y actualiza.
 * los vectores flujo y distancia con dichos valores.
 * @param entrada ubicación del fichero de entrada.
 * @param flujos matriz de flujos.
 * @param distancias matriz de distancias.
 */
void leerDatos(const std::string & entrada , std::vector<std::vector<int>> & flujos, std::vector<std::vector<int>> & distancias);

/**
 * @brief Función para mostrar por pantalla una matriz.
 * @param matriz  Matriz que se desea mostrar.
 */
void mostrarMatriz(const std::vector<std::vector<int>> & matriz);

/**
 * @brief Función que calcula el coste de una solución. 
 * @param permutacion Solución propuesta al problema.
 * @param flujos Matriz de flujos asociada.
 * @param distancias Matriz de distancias asociada.
 * @return El coste asociado al vector solución proporcionado
 */
int evaluarSolucion(const std::vector<int> & permutacion, const std::vector<std::vector<int>> & flujos, const std::vector<std::vector<int>> & distancias );

#endif /* FUNCIONES_H */

