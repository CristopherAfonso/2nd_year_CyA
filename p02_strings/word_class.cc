// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo word_class.cc: Donde se desarrollan las funciones de la clase
//         cadena contenida en el archivo de cabecera word_class.h.
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
//         08/10/2021 - Creacion (primera version) del codigo

#include <iostream>
#include "word_class.h"

Word::Word(const std::string& word) {
  word_ = word;
  for(size_t i{0}; i < word.size(); ++i) {
    characters_of_the_word_.emplace_back(word.at(i));
  }
}

size_t Word::WordSize() {
  return word_.size();
}

int Word::WordSize(Alphabet& set) {

  size_t size{0};
  size_t position{0};
  size_t lenght{1};
  std::string aux_string{""};
  bool symbol_found{false};
  
  while(position < word_.size()) {
    while((position + lenght) <= word_.size()) {
      aux_string = word_.substr(position, lenght);
      for(size_t i{0}; i < set.SizeAlphabet(); ++i) {
        if(aux_string == set.VecPlace(i)) {
          ++size;
          symbol_found = true;
          break;
        }
      }

      if(symbol_found) {
        symbol_found = false;
        break;
      }

      ++lenght;
    }

    position += lenght;
    lenght = 1;
  }
  
  return size;
}

std::string Word::WordInverse() {
  std::string result{""};
  for(size_t i{word_.size() - 1}; i >= 0; --i) {
    result.push_back(i);
  }
}

std::string Word::WordInverse(Alphabet& set) {
  
}
