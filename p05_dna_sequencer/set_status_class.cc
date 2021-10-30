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
// Archivo set_status_class.cc:
// 
// Donde se desarrollan las funciones de la clase SetStatus contenida
// en el archivo de cabecera set_status_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//            Solo he creado el archivo, le he puesto el comentario de
//            cabecera y declarado su include
// 30/10/2021 - He terminado la clase y sus metodos

#include "set_status_class.h"

SetStatus::SetStatus() = default; 

SetStatus::SetStatus(const size_t& num_status) {
  set_status_.reserve(num_status); // Reservamos el espacio una vez
  for (size_t i{0}; i < num_status; ++i) {
    set_status_.at(i) = i; // Metemos el valor de la posicion
  }
}

SetStatus::SetStatus(const std::vector<size_t>& end_status) {
  set_status_ = end_status;
}

SetStatus::SetStatus(const SetStatus& set_status) {
  set_status_ = set_status.set_status_;
}

bool SetStatus::IsItAState(const size_t num) {
  bool result{false};
  for (auto actual_position: set_status_) {
    if (num == actual_position) {
      result = true;
      break;
    }
  }
  return result;
}


