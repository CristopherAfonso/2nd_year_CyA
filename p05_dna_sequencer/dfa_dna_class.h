// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia (ESIT)
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 27/10/2021
// Archivo dfa_dna_class.h: 
// 
// Donde se aloja la declaración de la clase
// DfaDna y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes
// 

#ifndef _DFA_DNA_CLASS_
#define _DFA_DNA_CLASS_

#include "alphabet_class.h"
#include "set_status_class.h"
#include "trans_func_class.h"

class DfaDna {
 public:
  DfaDna(); // Constructor que usaré
  DfaDna(const DfaDna& dfa_dna); // constructor de copia

  // Funciones
  bool IsItInAlphabet(const std::string& dna_chain);
  std::vector<std::string> AllAcceptedSubstr(const std::string& dna_chain); 

 private:
  Alphabet alphabet_;
  SetStatus all_status_;
  size_t initial_state_;
  SetStatus aceptation_status_;
  TransFunc trans_func_;
};

#endif