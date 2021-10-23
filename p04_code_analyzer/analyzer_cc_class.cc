// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 21/10/2021
//
// Archivo analyzer_files_cc_class.cc:
// 
// Donde se desarrollan las funciones de la clase AnalyzerFilesCC contenida
// en el archivo de cabecera analyzer_files_cc_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 21/10/2021 - Creacion (primera version) del codigo
// 

#include "analyzer_cc_class.h"

AnalyzerCC::AnalyzerCC(const std::string& kFileName, std::ifstream& in_file) {
  file_name_ = kFileName;

  //vector que nos almacenará el archivo dividido en lineas
  std::string whole_file{""};

  //mientras queden lineas por leer, se añaden al vector whole_file
  while(!in_file.eof()) {
    std::string aux_line;
    getline(in_file, aux_line);//cogemos la linea
    //como la linea se coge sin el salto de linea, lo añadimos con la linea
    whole_file += '\n' + aux_line;
  }

  

}

std::ostream& operator<<(std::ostream& cout, const AnalyzerCC& file) {
  cout << "PROGRAM: " << file.file_name_;
  cout << "\nDESCRIPTION: " << file.file_description_;
  
  cout << "\n\nVARIABLES: ";
  if(file.vec_var_name_.size() == file.vec_var_line_.size()) {
    for(size_t i{0}; i < file.vec_var_line_.size(); ++i) {
      cout << "\n[Line " << file.vec_var_line_.at(i) << "] ";
      if(file.vec_var_name_.at(i).find("int") != std::string::npos) {
        cout << "INT: " << file.vec_var_name_.at(i).substr(4);
        continue;
      }
      if(file.vec_var_name_.at(i).find("double") != std::string::npos) {
        cout << "DOUBLE: " << file.vec_var_name_.at(i).substr(7);
        continue;
      }
      cout << "ERROR: algo ha ido mal al detectar el tipo de variables";
      break;
    }
    cout << '\n';

  }else {
    cout << "\nAlgo ha ido mal al guardar las variables\n";
  }

  cout << "\nSTATEMENTS:";
  if(file.vec_loop_line_.size() == file.vec_loop_name_.size()) {
    for(size_t i{0}; i < file.vec_loop_line_.size(); ++i) {
      cout << "\n[Line " << file.vec_loop_line_.at(i) << "] LOOP: ";
      if(file.vec_var_name_.at(i).find("for") != std::string::npos) {
        cout << "for";
        continue;
      }
      if(file.vec_var_name_.at(i).find("while") != std::string::npos) {
        cout << "while";
        continue;
      }
      cout << "ERROR: algo ha ido mal al detectar el tipo de bucle";
      break;
    }
    cout << '\n';

  }else {
    cout << "\nAlgo ha ido mal al guardar las lineas de los bucles\n";
  }

  cout << "\nMAIN: ";
  if(file.is_it_main_) {
    cout << "True";

  } else {
    cout << "False";
  }
  cout << '\n';

  cout << "\nCOMMENTS: ";
  if(file.file_description_.size() > 0) {
    cout << "\n[Line " << file.vec_comm_line_.at(0) << "] DESCRIPTION"; 
  }

  if(file.vec_comm_line_.size() == file.vec_comm_body_.size()) {
    for(int i{file.file_description_.size() > 0 ? 1 : 0}; 
        i < int(file.vec_comm_line_.size()); ++i) {
      cout << "\n[Line " << file.vec_comm_line_.at(i) << "] ";
      cout << file.vec_comm_body_.at(i);
    }

  }else {
    cout << "\nAlgo ha ido mal al guardar las lineas de los comentarios\n";
  }
  cout << '\n';

  return cout;  
}
