/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Simulacion de NFA's (Autómatas Finitos No Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 11/11/2021
 * 
 * @file state_nfa.h 
 * @brief Donde se aloja la declaración de la clase StateNfa y la declaracion
 * de sus metodos. La clase StateNfa tiene un std::multimap<Symbol, size_t>,
 * que representa las transiciones para cada simbolo, un size_t que representa
 * el estado actual y un bool que representa si el estado es de aceptación,
 * si es true, es que sí es de aceptación.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 11/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 */

#ifndef _STATE_NFA_
#define _STATE_NFA_

#include <iostream>
#include <map>

#include "symbol.h"

class StateNfa {
 public:
  /// Constructores. Hay 3, el por defecto, el predeterminado y el de copia.
  StateNfa(void);
  StateNfa(const size_t& state, const bool& aceptation);
  StateNfa(const StateNfa& state);

  /// Setters.
  void SetState(const size_t& state);
  void SetAceptationState(void);
  void SetAceptationState(const bool& aceptation_state);
  void SetTransition(const Symbol& symbol, const size_t& state);

  /// Getters.
  size_t GetState(void) const;
  std::pair<Symbol, size_t> GetTransition(void) const;
  bool GetAceptationStatus(void) const;

  /// Funciones de la clase (Métodos).
  size_t NumTransitions(void) const;
  size_t Count(const Symbol& symbol) const;
  std::pair<Symbol, size_t> Find(const Symbol& symbol) const;
  bool Contains(const Symbol& symbol) const;
  std::pair<std::multimap<Symbol, size_t>*, 
            std::multimap<Symbol, size_t>*> EqRang(const Symbol& symbol) const;
  std::pair<Symbol, size_t> LowerBound(const Symbol& symbol) const;
  std::pair<Symbol, size_t> UpperBound(const Symbol& symbol) const;

  /// Operadores sobrecargados.
  void operator=(const StateNfa& state);
  bool operator==(const StateNfa& state) const;

  /// Operadores de flujo de entrada y salida.
  friend std::istream& operator>>(std::istream& input, StateNfa& state_nfa);
  friend std::ostream& operator<<(std::ostream& out, const StateNfa& state_nfa);

 private:
  size_t state_; ///< Número que representa el estado actual.
  std::multimap<Symbol, size_t> transitions_; ///< Transiciones señaladas.
  bool aceptation_; ///< Señala si es un estado de aceptación.
};

#endif
