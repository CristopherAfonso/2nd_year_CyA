/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramática para expresiones aritméticas
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 16/11/2021
 * 
 * @file productions.cc
 * @brief Donde se desarrollan las funciones de la clase Productions contenida
 * en el archivo de cabecera productions.h.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 */

#include "productions.h"

/**
 * @fn Productions::Productions(void)
 * @brief Constructor por defecto, inicializa el multimap vacio. 
 */
Productions::Productions(void) : prod_() {}

/**
 * @fn Productions::Productions(const char& non_terminal, 
 *                       std::pair<size_t, std::string> prod)
 * @brief Constructor predeterminado, coge los valores que se le pasan a la
 * función y inicializa el primer elemento del multimap con ellos.
 * 
 * @param non_terminal clave del multimap.
 * @param prod valor del multimap.
 */
Productions::Productions(const char& non_terminal, 
                         std::pair<size_t, std::string> prod) {
  prod_.insert(std::make_pair(non_terminal, prod));
}

/**
 * @fn Productions::Productions(const char& non_terminal, const size_t& num, 
 *                        const std::string& prod)
 * @brief Segundo constructor predeterminado, hace lo mismo que el anterior
 * pero de otra forma
 * 
 * @param non_terminal clave del elemento del multimap
 * @param num etiqueta para encontrar la producción concreta
 * @param prod cadena por la que se sustituye a "non_terminal"
 */
Productions::Productions(const char& non_terminal, const size_t& num, 
                         const std::string& prod) {
  prod_.insert(std::make_pair(non_terminal, std::make_pair(num, prod)));
}

/**
 * @fn Productions::Productions(const Productions& prod)
 * @brief Constructor de copia
 * 
 * @param prod objeto del que copiaremos sus atributos para crear uno nuevo
 */
Productions::Productions(const Productions& prod) 
    : prod_(prod.prod_) {}

/**
 * @fn void Productions::SetProd(const char& non_terminal, const size_t& num, 
 *                               const std::string& prod)
 * @brief Setter, introduce un nuevo elemento en el multimap
 * 
 * @param non_terminal clave del elemento del multimap
 * @param num etiqueta para hallar la producción concreta
 * @param prod cadena por la que se sustituye a "non_terminal"
 */
void Productions::SetProd(const char& non_terminal, const size_t& num,
                          const std::string& prod) {
  prod_.insert(std::make_pair(non_terminal, std::make_pair(num, prod)));
}

/**
 * @fn void Productions::SetProd(const char& non_terminal, 
 *                               std::pair<size_t, std::string>& prod)
 * @brief Setter, introduce un nuevo elemento en el multimap.
 * 
 * @param non_terminal clave del elemento del multimap
 * @param prod objeto que contiene, una etiqueta para identificar la producción
 * y la producción en sí.
 */
void Productions::SetProd(const char& non_terminal, 
                          std::pair<size_t, std::string>& prod) {
  prod_.insert(std::make_pair(non_terminal, prod));
}

/**
 * @fn std::pair<std::multimap<char, std::pair<size_t, std::string>>::iterator,
 * std::multimap<char, std::pair<size_t, std::string>>::iterator> 
 * Productions::GetEqRang(const char& non_terminal)
 * @brief Getter, devuelve el rango de elementos que coincidan con la clave
 * pasada a la función, en forma de iteradores.
 * 
 * @param non_terminal clave que dicta la búsqueda, y le dice a la función que
 * devuelva el rango de elemento donde coinciden la clave con este parámetro
 * @return std::pair<std::multimap<char, std::pair<size_t, std::string>>::iterator,
 * std::multimap<char, std::pair<size_t, std::string>>::iterator> 
 */
std::pair<std::multimap<char, std::pair<size_t, std::string>>::iterator,
std::multimap<char, std::pair<size_t, std::string>>::iterator> 
Productions::GetEqRang(const char& non_terminal) {
  return prod_.equal_range(non_terminal);
}

/**
 * @fn std::string Productions::GetProd(const char& non_terminal, 
 *                                const size_t& num) const
 * @brief Getter, devuelve una producción concreta con ayuda de los parámetros
 * que se le pasan a la función.
 * 
 * @param non_terminal clave del elemento del multimap
 * @param num etiqueta para encontrar la producción concreta
 * @return std::string, es la producción hallada, si los argumentos de la
 * función están mal, este valor será vacío.
 */
std::string Productions::GetProd(const char& non_terminal, 
                                 const size_t& num) const {
  std::string aux{""};
  for (auto i: prod_) {
    if (i.first == non_terminal && i.second.first == num) {
      aux = i.second.second;
    }
  }
  return aux;
}

/**
 * @fn size_t Productions::Size(void) const
 * @brief Devuelve la cantidad de elementos que contiene el multimap
 * 
 * @return size_t, es el tamaño del multimap
 */
size_t Productions::Size(void) const {
  return prod_.size();
}

/**
 * @fn std::ostream& operator<<(std::ostream& out, const Productions& prod)
 * @brief Sobrecarga del operador de extracción.
 * 
 * @param out objeto de flujo de salida
 * @param prod objeto que queremos mostrar por la salida estándar
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Productions& prod) {
  out << '\n';
  for (auto i: prod.prod_) {
    out << i.first << '(' << i.second.first << ')' << " -> ";
    out << i.second.second << '\n';
  }
  return out;
}