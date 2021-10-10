// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo main_strings.cc: programa cliente.
//         Contiene la funcion main del proyecto que usa las clases X e Y que
//         realizan el trabajo de leer el fichero de entrada identificando 
//         patrones en el texto que dan lugar al fichero de salida.
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
//         08/10/2021 - Creacion (primera version) del codigo

#include <fstream>

#include "alphabet_class.h"
#include "word_class.h"

//Mensaje de error si no se cumple con el numero de argumentos
void ErrorMessage(char& function_name) { 
  std::cout << "\nWarning! , Faltan/Sobran argumentos para este programa";
  std::cout << "\nPara más información sobre como funciona pruebe:";
  std::cout << "\n'" << function_name << "' --help\n\n";
}

void ErrorOpcode() { 
  std::cout << "\nOpCode invalido, intentelo de nuevo\n\n";
}

//Explica al usuario como usar el programa
void InfoMessage(char& function_name) { 
  std::cout << "\nDescripcion:";
  std::cout << "\n" << function_name << " es un programa el cual recibe un";
  std::cout << "\nfichero de texto y devuelve como salida otro. La forma de";
  std::cout << "\nusar el programa es esta:\n\n";
  std::cout << "'" << function_name << " [input_file] [output_file] [opcode]'";
  std::cout << "\n\ninput_file: archivo de texto que le pasamos al programa";
  std::cout << "\noutput_file: nombre del archivo que se creara\n";
  std::cout << "\nopcode es el número que identifica a la operacion a hacer\n";

  std::cout << "\nEspecificaciones del archivo input_file:";
  std::cout << "\nEl archivo input_file puede ser tan extenso como se desee,";
  std::cout << "\nlas lineas pueden ser tan largas como se desee, y cada";
  std::cout << "\nlinea debe contener minimo dos cadenas, la ultima cadena";
  std::cout << "\bde la fila se procesaria como parte de la clase 'word' y";
  std::cout << "\nla primera como parte de la clase 'alphabet', si en una";
  std::cout << "\nlinea hay mas de dos cadenas, la ultima seria parte de";
  std::cout << "\nla clase 'word' y el resto serian simbolos de la clase";
  std::cout << "\n'alphabet'\n";

  std::cout << "\nDetalles de las operaciones:";
  std::cout << "\nOpCode '1' Longitud: Se escribe en output_file la longitud";
  std::cout << "\nde cada cadena de entrada (se cuentan sus simbolos)";
  std::cout << "\nOpCode '2' Inversa: Se escribe en el output_file la inversa";
  std::cout << "\nde cada cadena de entrada (se invierten sus simbolos)";
  std::cout << "\nOpCode '3' Prefijos: Se escribe en output_file el conjunto";
  std::cout << "\nde cadenas que son prefijos de la cadena de entrada";
  std::cout << "\nOpCode '4' Sufijos: Se escribe en output_file el conjunto";
  std::cout << "\nde cadenas que son sufijos de cada cadena de entrada\n";
  std::cout << "OpCode '5' Subcadenas: Se escribe en output_file el conjunto";
  std::cout << "\nde subcadenas para cada cadena de entrada\n\n";
}

int main(int argc, char* argv) {
  
  const std::string kHelp{"--help"};
  
  //Se solicita conocer el modo de uso del programa
  if((kHelp == "--help")) { 
    InfoMessage(argv[0]);
    exit(EXIT_SUCCESS);
  }
  
  //Error al pasar parametros
  if(argc < 3 || argc > 5) { 
    ErrorMessage(argv[0]);
    exit(EXIT_FAILURE);
  }

  //OpCode mal puesto
  if(int(argv[3]) < 49 || int(argv[3]) > 53) { 
    ErrorOpcode();
    exit(EXIT_FAILURE);
    
  }

  const std::string kNameInput{argv[1]};
  const std::string kNameOutput{argv[2]};
  const std::string kOpCode{argv[3]};
  std::string line = "";
  std::ifstream input_file(kNameInput);
  std::ofstream output_file(kNameOutput);

  //Mientras hayan lineas sin leer del archivo, se lee la siguiente
  while(getline(input_file, line)) {
    std::vector<std::string> set_in_line;
    std::string chain = "";
    std::size_t counter_line_position{0};
    
    //Leo toda la linea actual del archico 
    for(char* place{&line.front()}; *(place) != line.back(); ++place, 
    ++counter_line_position) {
      if(*(place) == ' ') {
        continue;
      }

      if(chain == "") {
        chain = chain.substr(counter_line_position);
      }
      else {
        set_in_line.emplace_back(chain);
        chain = chain.substr(counter_line_position);
      }

    }

    Alphabet alphabet(set_in_line);
    Word word(chain);

    switch(std::stoi(kOpCode)) {
      case '1':
      break;

      case '2':
      break;

      case '3':
      break;

      case '4':
      break;

      case '5':
      break;

      default:
        exit(EXIT_FAILURE);
    }
  }

  input_file.close(); //Cerramos el archivo que leemos, y liberamos memoria
  
  return 0;
}