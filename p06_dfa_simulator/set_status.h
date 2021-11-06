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
 * @file set_status.h 
 * @brief Donde se aloja la declaración de la clase SetStatus y la declaracion
 * de sus metodos. La clase SetStatus contiene un std::set<size_t> y cada
 * elemento de este conjunto, representará un estado del conjunto de estados de
 * un Dfa (sea el conjunto de estados totales y/o de aceptación), su longitud
 * será la cantidad de estados que tiene el conjunto, y cada elemento del
 * conjunto será un número (no negativo) que representará el nombre o
 * identificador del estado, usamos un std::set<size_t> porque los estados
 * no se pueden repetir.
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

#ifndef _SET_STATUS_
#define _SET_STATUS_

#include <iostream>
#include <vector>

class SetStatus {

};
#endif
