/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulacion de DFA's (Autómatas Finitos Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/11/2021
 * 
 * @file trans_func.h 
 * @brief Donde se aloja la declaración de la clase TransFunc y la declaracion
 * de sus metodos. La clase TransFunc tiene un std::vector<std::vector<size_t>>
 * que es una matriz que actua como tabla de transiciones, ahí guardamos todas
 * las posibles transiciones que tiene nuestro Dfa desde cada uno de sus
 * estados, y también tiene un atributo especial que es un
 * std::vector<std::string>> que coge los simbolos del alfabeto del Dfa, y su
 * posición relativa desde el inicio de este, la guarda en orden, de modo que
 * sin importar que simbolos tengamos en el alfabeto, podemos colocarle una
 * columna en la matriz según su orden en el alfabeto.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 05/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include 
 *
 */

#ifndef _TRANS_FUNC_
#define _TRANS_FUNC_

#include <iostream>
#include <string>
#include <vector>

class TransFunc {

};
#endif
