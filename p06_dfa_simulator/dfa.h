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
 * @file dfa.h 
 * @brief Donde se aloja la declaración de la clase Dfa y la declaracion de sus
 * metodos. La clase Dfa contiene 5 atributos privados y son:
 * Un objeto Alphabet, dos SetStatus, uno TransFunc, y un const size_t, este 
 * último el const size_t, representará el estado inicial del Dfa, a un objeto
 * Dfa, hay que pasarle uno Chain, y el Dfa analizará al objeto Chain y
 * devolverá un resultado diciendo si ha aceptado al objeto Chain o lo ha
 * rechazado.
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

#ifndef _DFA_
#define _DFA_

#include "alphabet.h"
#include "chain.h"
#include "set_status.h"
#include "trans_func.h"

class Dfa {

};
#endif
