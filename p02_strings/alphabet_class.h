// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo alphabet_class.h: Donde se aloja la declaración de la clase
//         alfabeto y sus metodos
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
//         08/10/2021 - Creacion (primera version) del codigo

#ifndef Alphabet_class_body
#define Alphabet_class_body

#include <iostream>
#include <string>

template <class T>
class Alphabet {
  public:
    Alphabet(std::string set) {};
    inline int Get_Set_Size(void);
  
  private:
    int _set_size{0};
    T* _set{NULL};
};




#endif