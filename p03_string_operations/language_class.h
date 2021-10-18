// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 17/10/2021
// Archivo language_class.h: Donde se aloja la declaración de la clase
//         lenguage y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes

#ifndef _LANGUAGE_CLASS_
#define _LANGUAGE_CLASS_

#include <fstream>

#include "word_class.h"
#include "alphabet_class.h"

class Language {
 public:
  //Constructores
  Language(void);
  Language(std::vector<Symbol>& alphabet, std::vector<Symbol>& word);
  Language(Language& language);

  //Setters y Getters
  void SetWordToLanguage(Word& word);
  void SetAlphabetToLanguage(Alphabet& alphabet);
  Word GetWordOfLanguage(void);
  Alphabet GetAlphabetOfLanguage(void);

  //Operadores
  void operator=(Language& language);
 
 private:
  Word word_user_;
  Alphabet alphabet_user_;
};

#endif