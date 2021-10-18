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
// Archivo symbol_class.cc: Donde se desarrollan las funciones de la clase
//         simbolo contenida en el archivo de cabecera symbol_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 17/10/2021 - Creacion (primera version) del codigo

#include "symbol_class.h"

// Constructor por defecto
Symbol::Symbol(void) = default;

// Constructor normal
Symbol::Symbol(std::string& chain) {
  symbol_ = chain;
}

//Constructor para cuando no hay alfabeto y hay que deducirlo
Symbol::Symbol(char& chain) {
  symbol_ = chain;
}

// Constructor de copia
Symbol::Symbol(Symbol& symbol) {
  symbol_ = symbol.GetSymbol();
}

// Setters sobrecargados
void Symbol::SetSymbol(std::string& chain) {
  symbol_ = chain;
}

void Symbol::SetSymbol(Symbol& symbol) {
  symbol_ = symbol.GetSymbol();
}

std::string Symbol::GetSymbol(void) const {
  return symbol_;
}

Symbol Symbol::operator=(Symbol& chain) {
  chain.SetSymbol(symbol_);
}

bool operator==(const Symbol& chain1, const Symbol& chain2) {
  return chain1.GetSymbol() == chain2.GetSymbol();
}

std::ostream& std::operator<<(std::ostream& output, Symbol& symbol) {
  output << symbol.GetSymbol();
  return output;
}

std::ostream& std::operator<<(std::ostream& output, const Symbol symbol) {
  output << symbol.GetSymbol();
  return output;
}

std::istream& std::operator>>(std::istream& input, Symbol& symbol) {
  std::string temp{""};
  input >> temp;
  symbol.SetSymbol(temp);
  return input;
}

