/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 27/12/2021
 * 
 * @file main_functions.cc
 * @brief Donde se aloja el desarrollo y la implementación de las funciones
 * de nuestro archivo cliente.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 27/12/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 27/12/21 - Funciones del main terminadas.
 */

#include "main_functions.h"

void Usage(int argc, char* argv[]) {
  std::string kHelp{"--help"};
  std::string kProgramName{argv[0]};
  if (argc == 1) {
    MainMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  std::string kWeightLimit{argv[1]};
  if (kWeightLimit == kHelp) {
    HelpMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  if (argc > 3) {
    ErrorSoMuchParameters(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  std::string kFileName{argv[2]};
  if ((kFileName.size() > 4) && 
     (kFileName.substr(kFileName.size() - 4) != ".cfg")) {
    ErrorConfigFileExtension(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  /// Solo abrimos el archivo para comprobar que se puede abrir.
  std::ifstream config_file(kFileName, std::fstream::in);
  if (config_file.fail()) {
    ErrorOpenConfigFile(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }
  config_file.close();
}

void MainMessage(const std::string& kProgramName, const std::string& kHelp) {
  using std::cout;
  cout << "Usage: " << kProgramName << " <max_weight> <config_file>\n";
  cout << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cout << "para mas informacion\n";
}

void HelpMessage(const std::string& kProgramName, const std::string& kHelp) {
  using std::cout;
  cout << kProgramName << " es un programa que se limita a resolver el\n";
  cout << "famoso \"Problema de la mochila\" usando para ello un Algoritmo";
  cout << "Voraz (Greedy).\n\n";
  cout << "A este programa solo se le tienen que pasar dos parametros\n";
  cout << "El primero es el peso maximo que aguantara la mochila (double)\n";
  cout << "El segundo es el archivo de configuracion (tiene que ser un\n";
  cout << "archivo de texto con extension \".cfg\", sino no es asi el\n";
  cout << "programa no se ejecutara) que contiene una lista de los objetos\n";
  cout << "que se disponen para meter en la mochila, su peso y valor.\n\n";
  cout << "Los archivos de configuracion deben seguir esta sintaxis:\n";
  cout << "5      // Linea 1, numero de objetos\n";
  cout << "12 4   // Linea 2, Objeto 1: Peso valor, utilidad: 0,333\n";
  cout << "1 2    // Linea 3, Objeto 2: Peso valor, utilidad: 2\n";
  cout << "4 10   // Linea 4, Objeto 3: Peso valor, utilidad: 2,5\n";
  cout << "1 1    // Linea 5, Objeto 4: Peso valor, utilidad: 1\n";
  cout << "2 2    // Linea 6, Objeto 5: Peso valor, utilidad: 1\n";
}

void ErrorSoMuchParameters(const std::string& kProgramName, 
                           const std::string& kHelp) {
  using std::cout;
  cout << "Warning! se han pasado mas de dos argumentos al programa";
  cout << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cout << "para mas informacion\n";
}

void ErrorConfigFileExtension(const std::string& kProgramName, 
                              const std::string& kHelp) {
  using std::cout;
  cout << "Warning! el archivo de texto no tiene la extension \".cfg\"\n";
  cout << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cout << "para mas informacion\n";
}

void ErrorOpenConfigFile(const std::string& kProgramName, 
                         const std::string& kHelp) {
  using std::cout;
  cout << "Warning! no se pudo abrir el archivo, intentelo de nuevo\n";
  cout << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cout << "para mas informacion\n";
}