// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo word_class.h: Donde se aloja la declaración de la clase
//         cadena y sus metodos
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
//         08/10/2021 - Creacion (primera version) del codigo

#ifndef _WORD_CLASS_
#define _WORD_CLASS_

#include <iostream>
#include <string>

class Word {
 public:
  Word(); // Constructor por Defecto
  Word(std::string word);

 private:
  std::string word_ = "";
};

#endif