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
// Archivo dfa_dna_class.cc:
// 
// Donde se desarrollan las funciones de la clase DfaDna contenida
// en el archivo de cabecera dfa_dna_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 27/10/2021 - Creacion (primera version) del codigo
//              Solo he creado el archivo, le he puesto el comentario de
//              cabecera y declarado su include
// 

#include "dfa_dna_class.h"

DfaDna::DfaDna() {
  // Como no puedo usar la inialización en lista, creo unos objetos y se los
  // paso a los de la clase con el operador "="
  const char kA{'A'};
  const char kC{'C'};
  const char kG{'G'};
  const char kT{'T'};
  const std::string kAlphabetName{"ADN"};
  const Alphabet aux_alphabet(kAlphabetName, kA, kC, kG, kT);
  alphabet_ = aux_alphabet;
  
  const std::string kAllStatusName{"de arranque del DFA"};
  const size_t kAllStatusNum{6};
  const SetStatus aux_all_status(kAllStatusName, kAllStatusNum);
  all_status_ = aux_all_status;

  initial_state_ = 0;

  const std::string kNameAcepStatus{"de aceptación del DFA"};
  const std::vector<size_t> kVecAcepStatus{2, 4};
  const SetStatus aux_aceptation_status(kNameAcepStatus, kVecAcepStatus);
  aceptation_status_ = aux_aceptation_status;

  // Creamos el vector que hará de función de transición y ponemos los valores
  // de la función con ayuda de un for y varios if's, no uso un switch porque 
  // no me dejaba declarar una variable dentro de un case
  std::vector<std::vector<size_t>> vec_aux_trans_func;
  for (size_t i{0}; i < kAllStatusNum; ++i) {
    // Quería hacer un switch dentro del for, pero no me dejaba inicializar un
    // vector dentro de un case si había más de un case
    if (i == 0) {
      std::vector<size_t> aux{1, 5, 5, 3};
      vec_aux_trans_func.emplace_back(aux);
      continue;
    }

    if (i == 1 || i == 2) {
      std::vector<size_t> aux{2, 1, 1, 1};
      vec_aux_trans_func.emplace_back(aux);
      continue;
    }

    if (i == 3 || i == 4) {
      std::vector<size_t> aux{3, 3, 3, 4};
      vec_aux_trans_func.emplace_back(aux);
      continue;
    }

    if (i == 5) {
      std::vector<size_t> aux{5, 5, 5, 5};
      vec_aux_trans_func.emplace_back(aux);
    }
  }

  const TransFunc aux_trans_func(vec_aux_trans_func, alphabet_);
  trans_func_ = aux_trans_func;
}

DfaDna::DfaDna(const DfaDna& dfa_dna) {
  alphabet_ = dfa_dna.alphabet_;
  all_status_ = dfa_dna.all_status_;
  initial_state_ = dfa_dna.initial_state_;
  aceptation_status_ = dfa_dna.aceptation_status_;
  trans_func_ = dfa_dna.trans_func_;
}

bool DfaDna::IsItInAlphabet(const std::string& dna_chain) {
  return alphabet_.IsItInAlphabet(dna_chain);
}

std::vector<std::string> DfaDna::AllAcceptedSubstr(const std::string& dna_chain) {
  std::vector<std::string> result;
  // Este if sería igual al if del main_dna_sequencer.cc donde miro si la
  // cadena tiene simbolos desconocidos, pero lo hago dos veces, una aquí
  // y otra allí porque así me aseguro de que nunca se le pase una cadena
  // invalida, por si en el futuro en una futura modificación del programa
  // reusara esta función y lo usara en un lugar donde no tenga el if del main
  if (!alphabet_.IsItInAlphabet(dna_chain)) {
    result.emplace_back("Error al leer la cadena de ADN, tiene simbolos desconocidos");
  } else {
    if (dna_chain.size() < 2) {
      result.emplace_back("Error, cadena muy pequeña para ser evaluada");
    } else {
      std::string act_substr{""};
      size_t act_state{initial_state_};

      // Este for recorre las longitudes que tendremos que coger a la hora de
      // ir extrayendo substring de la cadena dna_chain, empieza en 2 y termina
      // en la logitud total de la cadena
      for (size_t i{2}; i <= dna_chain.size(); ++i) {
        // Este for recorre la cadena dna_chain y va marcando la primera
        // posición donde vamos a empezar a extraer la substring
        for (size_t j{0}; (i + j) <= dna_chain.size(); ++j) {
          // Guardamos en cada iteración en act_substr el valor de todas las
          // substrings posibles de la cadena dna_chain
          act_state = 0;
          act_substr = dna_chain.substr(j, i);
          for (size_t k{0}; k < act_substr.size(); ++k) {
            // Pasamos al siguiente estado por cada simbolo de la cadena que
            // quede por leer
            const char aux_char = act_substr[k];
            act_state = trans_func_.NextState(act_state, aux_char);
          }
          // Si el estado actual es de aceptación, entonces se añade la
          // subcadena a la string de retorno
          if (aceptation_status_.IsItAState(act_state)) {
            if (result.size() == 0) {
              result.emplace_back(act_substr);
            } else {
              for (size_t i{0}; i < result.size(); ++i) {
                if (act_substr == result[i]) break;
                if (i == (result.size() - 1)) result.emplace_back(act_substr);
              }
            }
          }
        }
      }
    }
  }

  return result;
}
