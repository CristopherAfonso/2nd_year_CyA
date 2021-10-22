// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingeniera Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 21/10/21
//
// Archivo main_code_analyzer.cc: programa cliente
// Contiene la funcion main del proyecto que usa la clase
// AnalyzerFilesCC para poder realizar operaciones con archivos
// de entrada con extension ".cc", estas operaciones son:
// Crear un nuevo archivo en el directorio actual con extension ".txt"
// donde se ejecuta el programa, y rellenar ese fichero con datos extraidos
// del fichero de entrada ".cc", entre los datos que son analizados del fichero
// ".cc" y añadidos al ".txt" destacamos:
//
// 1. Nombre del archivo de entrada
// 2. Descripcion del programa (comentario general si lo hay)
// 3. Variables declaradas (int y double), en que linea se situan, su nombre,
//    el valor de su inicialización, y sin son de tipo int o double en concreto
// 4. Bucles (for y while), en que linea se declararon y de que tipo son
// 5. Main (muestra un true/false si se trata de un archivo ".cc" que contenga 
//    una funcion main)
// 6. Comentarios (de una o varias lineas) indica si un comentario ocupa una o 
//    varias lineas, indica en que lineas estan y los muestra
//
// Si quiere saber mas detalles sobre como usar el programa ejecutable,
// ejecute: ./main_code_analyzer --help
// para mas informacion
// 
// Referencias:
// Enlaces de Interes
// 
// Historial de Revisiones 
// 21/10/21 - Creacion (primera version) del codigo
// 

#include "analyzer_files_cc_class.h"

// Mensaje principal que informa sobre lo que hace el programa por encima
void MainMessage(const std::string& kNameFile, const std::string& kHelp) {
  std::cout << '\n' << kNameFile << ": Programa que recibe un archivo con";
  std::cout << "\nextension \".cc\" o \".c++\" y crea un archivo con";
  std::cout << "\nextension \".txt\" donde vuelca en este, informacion";
  std::cout << "\nrelacionada con el contenido del archivo dado.";
  std::cout << "\nPara mas informacion sobre su uso ejecute:";
  std::cout << '\n' << kNameFile << ' ' << kHelp;
}

//Mensaje de informacion que explica detalladamente lo que hace el programa
void HowToUseThisProgram(const std::string& kNameFile) {
  std::cout << '\n' << kNameFile << " es un programa que recibe archivos";
  std::cout << "\nescritos en C++ unicamente y en base a su contenido, crea";
  std::cout << "\nun archivo de texto y vuelva en el los resultados del";
  std::cout << "\nanalisis del primer archivo, su modo de uso es este:";
  std::cout << '\n' << kNameFile << " input_file.cc output_file.txt";
  
  std::cout << "\n\nDonde \"input_file.cc\" es el archivo escrito en C++";
  std::cout << "\n(tambien es valida la extension \".c++\", pero ninguna mas)";
  std::cout << "\ny output_file.txt es el nombre que le queremos dar a";
  std::cout << "\nnuestro archivo de texto de salida (solo se acepta la";
  std::cout << "\nextension \".txt\").";

  std::cout << "\n\nEl contenido que tendra el archivo de salida una vez";
  std::cout << "\ncreado sera el siguiente descrito:";
  std::cout << "\n1. Nombre del archivo analizado (el que damos al programa).";
  std::cout << "\n2. Comentario de Cabecera (si lo hubiera).";
  std::cout << "\n3. Variables Declaradas (solo tipo \"int\" y \"double\").";
  std::cout << "\n   Se supondra que cada declaracion de variable se hara en";
  std::cout << "\n   una unica linea y que cada linea tendremos una unica";
  std::cout << "\n   declaracion, sino el programa solo capta la primera.";
  std::cout << "\n   Si las variables se declaran en un bucle se ignoran.";
  std::cout << "\n   Para cada variable se guarda, su tipo, nombre, la linea";
  std::cout << "\n   en la que se declaran y si se ha inicializado o no en la";
  std::cout << "\n   propia declaracion, tambien hay un control de cuantas";
  std::cout << "\n   variables de cada tipo se han definido en el archivo.";
  std::cout << "\n4. Uso de Bucles (solo tipo \"for\" y \"while\").";
  std::cout << "\n   Para cada bucle detectado se almacenara el tipo de";
  std::cout << "\n   bucle, y la linea de codigo donde se ha encontrado,";
  std::cout << "\n   tambien se llevara un control del numero de bucles de";
  std::cout << "\n   cada tipo que se han utilizado en el archivo.";
  std::cout << "\n5. Programa Principal, se muestra si el archivo analizado";
  std::cout << "\n   tiene o no una funcion \"int main\".";
  std::cout << "\n6. Comentarios, se incluyen los comentarios de una linea y";
  std::cout << "\n   de multiples lineas (\"//...\" y \"/*...*/\").";
  std::cout << "\n   Se indica el tipo de comentario, las lineas donde se";
  std::cout << "\n   encuentra cada uno y su contenido tambien, si hay un";
  std::cout << "\n   comentario de cabecera, se muestra en el punto 2.\n\n";
}

//Mensaje de error
void ErrorInputMessage(const std::string& kNameFile, const std::string& kHelp) {
  std::cerr << "\nWarning! Faltan/Sobran argumentos para usar este programa";
  std::cerr << "\nSi quiere información sobre como usarlo pruebe:";
  std::cerr << "\n" << kNameFile << ' ' << kHelp << "\n\n";
}

int main(int argc, char* argv[]) {

  const std::string kNameFile{argv[0]};
  const std::string kHelp{"--help"};

  //Si se ejecuta el programa sin parametros, sale el mensaje principal
  if(argc == 1) {
    MainMessage(kNameFile, kHelp);
    exit(EXIT_SUCCESS);
  }

  //Argumento que sera el nombre del archivo a analizar o indicara mostar el
  //mensaje de informacion
  const std::string KInputFile{argv[1]};

  //Si en vez de dar un archivo de entrada, se solicita el modo de funcionar
  //del programa, sale el mensaje de informacion
  if(KInputFile == kHelp) {
    HowToUseThisProgram(kNameFile);
    exit(EXIT_SUCCESS);
  }

  //Si no hay solicitud de mensaje de informacion y no hay exactamente 3
  //argumentos de entrada, se muestra el mensaje de error con los argumentos
  //y se detiene el programa
  if(argc < 3 || argc > 3) {
    ErrorInputMessage(kNameFile, kHelp);
    exit(EXIT_FAILURE);
  }

  

  return 0;
}
