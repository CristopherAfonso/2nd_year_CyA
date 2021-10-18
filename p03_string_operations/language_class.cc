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

Language::Language(std::vector<Symbol>& alphabet, std::vector<Symbol>& word) {
  Alphabet temp_alphabet(alphabet);

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

void Language::operator=(Language& language) {
  language.SetWordToLanguage(word_user_);
  language.SetAlphabetToLanguage(alphabet_user_);
}


