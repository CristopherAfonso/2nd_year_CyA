// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 17/10/2021
//
// Archivo language_class.cc: Donde se desarrollan las funciones de la clase
//         lenguaje contenida en el archivo de cabecera language_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 17/10/2021 - Creacion (primera version) del codigo

#include "language_class.h"

Language::Language(void): word_user_(), alphabet_user_() {}

Language::Language(std::istringstream& actual_line) {

    std::string chain{""}; //String entera que guarda las cadenas de la linea
    //String que se le pasara al constructor de la clase Language
    Symbol aux_symbol;
    int alphabet_size{-1};
    //Conjunto que se le pasara al constructor de la clase Language
    //aunque sea un vector, es nuestro alfabeto
    std::vector<Symbol> aux_alphabet; 


    //Leemos la linea, si solo tiene una cadena, el alfabeto esta vacio y hay
    //que generarlo a partir de la cadena que hay, si hay mas de una cadena
    //en la linea, se van metiendo menos la ultima leida
    while(getline(actual_line, chain, ' ')) {
      ++alphabet_size;
      if(alphabet_size > 0) {
        aux_alphabet.emplace_back(aux_symbol);
      }
      aux_symbol.SetSymbol(chain);
    }

    //Variable que será pasado a nuestro objeto word_user_
    std::vector<Symbol> aux_word;

    //Ahora recorremos chain para reconocer donde están los simbolos
    size_t base_position{0}; //variable que usamos para indicar el inicio
    for(size_t i{1}; i <= chain.size(); ++i) {
      for(auto aux_alp_actual_position: aux_alphabet) {
        if(aux_alp_actual_position.GetSymbol() == 
           chain.substr(base_position, i)) {
          aux_word.emplace_back(chain.substr(base_position, i));
          base_position = i;
          break;
        }
      } 
    }
    
    //Atributos internos ya inicializados
    alphabet_user_.SetterAlphabet(aux_alphabet);
    word_user_.SetWord(aux_word);
}

Language::Language(Language& language) {
  *this = language;
}

void Language::SetWordToLanguage(Word& word) {
  word_user_ = word;
}

void Language::SetAlphabetToLanguage(Alphabet& alphabet) {
  alphabet_user_ = alphabet;
}

Word Language::GetWordOfLanguage(void) {
  return word_user_;
}

Alphabet Language::GetAlphabetOfLanguage(void) {
  return alphabet_user_;
}

const size_t Language::Opcode1Size() {
  return word_user_.SizeWord();
}

const Word Language::Opcode2Inverse() {

  std::vector<Symbol> aux_vec_symbol;

  for(auto actualposition = aux_vec_symbol.rbegin();
      actualposition != aux_vec_symbol.rend(); ++actualposition) {
    aux_vec_symbol.emplace_back(*actualposition);
  }
  
  Word aux_word(aux_vec_symbol);

  return aux_word;
}

const std::vector<Word> Language::Opcode3Prefix() {

}

const std::vector<Word> Language::Opcode4Postfix() {

}

const std::vector<Word> Language::Opcode5Substr() {

}
const std::string Language::Opcode6ChainCmp() {

}

const Word Language::Opcode7ChainConcatenation() {

}

const Word Language::Opcode8Power() {

}
 
std::string Language::ShowLanguage(std::vector<Word>& set_words) {

}

std::string Language::ShowLanguage(Word& word) {

}

void Language::operator=(Language& language) {
  language.SetWordToLanguage(word_user_);
  language.SetAlphabetToLanguage(alphabet_user_);
}


