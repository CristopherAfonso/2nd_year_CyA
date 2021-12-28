/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 27/12/2021
 * 
 * @file main_functions.h 
 * @brief Donde se aloja la declaración de las funciones del archivo cliente
 * de nuestro programa.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 27/12/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 27/12/21 - Funciones del main terminadas.
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>

void Usage(int argc, char* argv[]);
void MainMessage(const std::string& kProgramName, const std::string& kHelp);
void HelpMessage(const std::string& kProgramName, const std::string& kHelp);
void ErrorSoMuchParameters(const std::string& kProgramName, 
                           const std::string& kHelp);
void ErrorConfigFileExtension(const std::string& kProgramName, 
                              const std::string& kHelp);
void ErrorOpenConfigFile(const std::string& kProgramName, 
                         const std::string& kHelp);
void ErrorNoNumber(const std::string& kProgramName, const std::string& kHelp);
void Backpack(char* argv[]);