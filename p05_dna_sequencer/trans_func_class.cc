// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 27/10/2021
//
// Archivo trans_func_class.cc:
// 
// Donde se desarrollan las funciones de la clase TransFunc contenida
// en el archivo de cabecera trans_func_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//            Solo he creado el archivo, le he puesto el comentario de
//            cabecera y declarado su include
// 30/10/2021 - He terminado la clase y sus metodos

#include "trans_func_class.h"

TransFunc::TransFunc() = default;

TransFunc::TransFunc(const std::vector<std::vector<size_t>>& trans_func, 
                     Alphabet& alphabet) {
  trans_func_ = trans_func;
  const size_t kTwo{2}; // Tamaño de cada vector de conversion_table_
  size_t num_col{0}; // Guarda el valor de la columna actual
  std::set<char> aux{alphabet.GetAlphabet()}; // LO sacamos para usarlo
  // Marcamos que por cada simbolo, hay un vector o columna asociada
  conversion_table_.resize(aux.size()); 
  for (auto i{aux.begin()}; i != aux.end(); ++i, ++num_col) {
    conversion_table_.at(num_col).resize(kTwo); // Readimensiono el vector
    conversion_table_.at(num_col).front() = *i; // Al inicio va el caracter
    // En la segunda posicion al final, está el número que nos referencia en el
    // vector trans_func_ a cual de sus columnas hay que irse
    conversion_table_.at(num_col).back() = num_col + 1;
  }
}

TransFunc::TransFunc(const TransFunc& trans_func) {
  trans_func_ = trans_func.trans_func_;
  conversion_table_ = trans_func.conversion_table_;
}

size_t TransFunc::NextState(const size_t& actual_state, 
                            const char& actual_symbol) {
  size_t result{0};
  size_t aux{0};
  if (actual_state != 0) { // No puede ser cero nunca
    for (size_t i{0}; i < conversion_table_.size(); ++i) {
      if (conversion_table_[i].front() == std::to_string(actual_symbol)) {
        aux = std::stoi(conversion_table_[i].back());
        break; // Paramos de buscar
      }
    }
  }

  if (aux != 0) { // No puede ser cero nunca
    result = trans_func_[actual_state][aux];
  }

  return result;
}
