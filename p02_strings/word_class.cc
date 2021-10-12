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

int Word::Size() {
  return word_.size();
}

int Word::Size(Alphabet& set) {

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

std::string Word::Inverse() {
  std::string result{""};
  for(int i{int(word_.size() - 1)}; i >= 0; --i) {
    result = result + word_.at(i);
  }

  return result;
}

std::string Word::Inverse(Alphabet& set) {
  std::string result{""};
  
  
  
  return result;
}

std::string Word::Prefixes() {
  std::string result{"& "};
  std::string aux{""};

  for(size_t i{0}; i < characters_of_the_word_.size(); ++i) {
    aux = aux + characters_of_the_word_.at(i);
    result = result + aux + ' ';
  }

  return result;
}

std::string Word::Prefixes(Alphabet& set) {
  std::string result{"& "};
  
  
  
  return result;
}

std::string Word::Suffixes() {
  std::string result{"& "};
  std::string aux{""};
  
  for(int i{int(characters_of_the_word_.size() - 1)}; i >= 0; --i) {
    aux = characters_of_the_word_.at(i) + aux;
    result = result + aux + ' ';
  }

  return result;
}

std::string Word::Suffixes(Alphabet& set) {
  std::string result{"& "};
  
  
  
  return result;
}

std::string Word::Substrings() {
  std::string result{"& "};
  size_t lenght{1};

  while(lenght <= word_.size()) {
    for(size_t i{0}; i < (word_.size() - lenght + 1); ++i) {
      result = result + word_.substr(i, lenght) + ' ';
    }
    ++lenght;
  }
    
  return result;
}

std::string Word::Substrings(Alphabet& set) {
  std::string result{"& "};
  
  
  
  return result;
}
