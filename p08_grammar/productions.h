/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramática para expresiones aritméticas
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 16/11/2021
 * 
 * @file productions.h 
 * @brief Donde se aloja la declaración de la clase Productions y la declaracion
 * de sus metodos. La clase Productions contiene un 
 * std::vector<std::pair<Symbol, std::vector<Chain>>> que será la variable que
 * usaremos a modo de alphabeto y conjunto de símbolos terminales en la clase
 * Grammar.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 */

#ifndef _PRODUCTIONS_
#define _PRODUCTIONS_

#include "symbol.h"
#include "chain.h"

/**
 * @class Productions.
 * @brief Una gramática debe tener producciones, que un conjunto de símbolos
 * no terminales que pueden generar otros símbolos no terminales y terminales,
 * esta clase se encarga de definir esas producciones y usarlas según convenga. 
 */
class Productions {

};
#endif