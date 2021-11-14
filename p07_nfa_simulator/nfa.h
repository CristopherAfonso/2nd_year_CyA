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
 * @file nfa.h 
 * @brief Donde se aloja la declaración de la clase Nfa y la declaracion de sus
 * metodos. La clase Nfa contiene 4 atributos privados y son:
 * Un objeto Alphabet, dos SetStatus, y un size_t, este último
 * el size_t, representará el estado inicial del Nfa, a un objeto Nfa,
 * hay que pasarle uno Chain, y el Nfa analizará al objeto Chain y devolverá
 * un resultado diciendo si ha aceptado al objeto Chain o lo ha rechazado.
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

#ifndef _NFA_
#define _NFA_

#include <fstream>

#include "alphabet.h"
#include "chain.h"
#include "set_status.h"

/**
 * @class Nfa.
 * @brief Clase que imitará el funcionamiento de un Nfa que le pasaremos su
 * definición por medio de un archivo. 
 */
class Nfa {
 public:
  /// Constructores. Tenemos 3, el por defecto, el que creamos nosotros 
  /// (que lo usaremos más) y el de copia.
  Nfa(void);
  Nfa(std::ifstream& nfa_def);
  Nfa(const Nfa& nfa);

  /// Getters.
  Alphabet GetAlphabet(void) const;
  SetStatus GetAllStatus(void) const;
  int GetInitialState(void) const;
  SetStatus GetAceptationStatus(void) const;
  bool Fail(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItInAlphabet(const Chain& chain) const;
  bool EvalStr(const Chain& chain) const;
  void EvalStrInFile(std::ifstream& input, std::ofstream& out) const;
  void ShowTransFunc(void) const;

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Nfa& dfa);

 private:
  Alphabet alphabet_; ///< Alfabeto del DFA.
  SetStatus all_status_; ///< Conjunto de estados totales.
  int initial_state_; ///< Estado inicial del Dfa.
  SetStatus aceptation_status_; ///< Conjunto de estados de aceptación.

  bool creation_failed_; ///< Nos dice si el archivo ".dfa" está correcto.
};
#endif
