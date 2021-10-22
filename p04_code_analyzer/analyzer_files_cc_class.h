// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia (ESIT)
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 21/10/2021
// Archivo analyzer_files_cc_class.h: 
// 
// Donde se aloja la declaración de la clase
// AnalyzerFilesCC y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes
// 

#ifndef _ANALYZER_FILES_CC_
#define _ANALYZER_FILES_CC_

#include <iostream>
#include <string>
#include <regex>
#include <fstream>

class AnalyzerFilesCC {
 public:
  AnalyzerFilesCC();
  AnalyzerFilesCC(const std::string& kFileName, std::ifstream& input_file);

  //Operadores
  friend std::ostream& operator<<(std::ostream& cout, const AnalyzerFilesCC& AnalyzedFile);

 private:
  const std::string kFileName_;
  const std::string kFileDescription_;

};

#endif
