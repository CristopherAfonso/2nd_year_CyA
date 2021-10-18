// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 17/10/2021
// Archivo symbol_class.h: Donde se aloja la declaración de la clase
//         simbolo y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes

#ifndef _SYMBOL_CLASS_
#define _SYMBOL_CLASS_

#include <iostream>
#include <string>

class Symbol {
 public:

  //Constructores
  Symbol(void);
  Symbol(std::string& chain);
  Symbol(char& chain);
  Symbol(Symbol& symbol);

  //Setters y Getter
  void SetSymbol(std::string& chain);
  void SetSymbol(Symbol& symbol);
  std::string GetSymbol(void) const;

  //Operadores
  Symbol operator=(Symbol& chain);
  bool operator==(Symbol& chain);
  bool operator==(const Symbol& chain) const;

  //Operadores de Flujo de entrada y salida
  friend std::ostream& std::operator<<(std::ostream& output, Symbol& symbol);
  friend std::ostream& std::operator<<(std::ostream& output, const Symbol symbol);
  friend std::istream& std::operator>>(std::istream& input, Symbol& symbol);
  

 private:
  std::string symbol_{""};  
};

#endif