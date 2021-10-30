// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingeniera Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Autómatas Finitos y Reconocimiento de Patrones
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 27/10/21
//
// Archivo main_dna_sequencer.cc: programa cliente
// Contiene la funcion main del proyecto que usa las clases
// Alphabet, SetStatus, TransFunc y DfaDna (que contiene a las tres primeras)
// para poder realizar operaciones con una cadena de ADN (un argumento pasado
// a la función main en argv[1]) y poder encontrar subcadenas de estas, y las
// subcadenas encontradas que sigan un patrón en concreto, plasmarlas en un
// archivo de salida con extensión ".txt"
//
// Si quiere saber mas detalles sobre como usar el programa ejecutable,
// ejecute: ./main_dna_sequencer --help
// para mas informacion
// 
// Referencias:
// Enlaces de Interes
// 
// Historial de Revisiones 
// 27/10/21 - Creacion (primera version) del codigo:
//            Solo he creado el archivo, le he puesto el comentario de
//            cabecera y declarado su include
// 30/10/21 - He creado y terminado la interfaz del main y he probado todos los
//            objetos de las clases excepto el de la clase DfaDna para saber si
//            funcionan antes de implementarla en esta

#include "dfa_dna_class.h"

// Mensaje principal del programa
inline void MainMenssage(const std::string& kProgramName, 
                         const std::string kHelp) {
  std::cout << "Modo de empleo: " << kProgramName << " [CADENA DE ADN] ";
  std::cout << "[NOMBRE FICHERO DE SALIDA]" << std::endl;
  std::cout << "Pruebe '" << kProgramName << " " << kHelp << "' ";
  std::cout << "para más información." << std::endl;
}

// Mensaje de instrucciones de uso del programa
void InfoMessage(const std::string kProgramName) {
  std::cout << kProgramName << " es un programa que recibe solo como";
  std::cout << "\nargumentos una cadena de ADN en su segundo argumento y el";
  std::cout << "\nnombre de un archivo de salida en su tercer argumento.";
  std::cout << "\n(Solo se admite el formato \".txt\" con uno o más";
  std::cout << "\ncaracteres a la izquierda del punto de \".txt\").";
  std::cout << "\nCon esas entradas, el programa simula el comportamiento de";
  std::cout << "\nun Autómata Finito Determinista (AFN o DFA), coge la cadena";
  std::cout << "\nde ADN dada como argumento al programa, y de ella extrae";
  std::cout << "\ntodas sus subcadenas y se las pasa al DFA para analizar si";
  std::cout << "\nalguna de ellas cumple un patrón, y el patrón que analiza";
  std::cout << "\nes si la subcadena dada, inicia y termina por 'A' o inicia";
  std::cout << "\ny termina por 'T' y tiene una longitud mayor a 2, si cumple";
  std::cout << "\nesas condiciones la subcadena se plasmará en el archivo";
  std::cout << "\n\".txt\" cuyo nombre elegirá usted en el tercer argumento.";
  std::cout << "\n\nUna cadena de ADN solo tiene 4 símbolos en su alfabeto y";
  std::cout << "\nestos son: 'A', 'C', 'G', 'T'.";
  std::cout << "\n\nSi su cadena introducida al programa tiene algún otro";
  std::cout << "\nsímbolo más a parte de los ya mencionados, el programa se";
  std::cout << "\ncerrará con un mensaje de error y no se analizará";
  std::cout << "\nla cadena de ADN y ni se plasmará en el archivo de salida";
  std::cout << "\nFin del mensage.\n";
}

// Mensaje de error debido a que no hay la cantidad de argumentos esperados por
// el programa, que son 3
inline void ErrorMessage(const std::string& kProgramName, 
                         const std::string kHelp) {
  std::cerr << "Warning!, Faltan/Sobran argumentos para este programa";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

// Si el nombre del archivo no tiene el formato esperado, se ve este mensaje
inline void ErrorFileName(const std::string& kProgramName, 
                          const std::string kHelp) {
  std::cerr << "Warning!, formato de archivo de salida no aceptado";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n"; 
}

int main(int argc, char* argv[]) {
  // Pasamos a string el nombre del programa
  const std::string kProgramName{argv[0]};
  // Palabra clave para solicitar el uso del programa
  const std::string kHelp{"--help"};
  // Si solo se ha introducido el nombre del programa, sale un mensaje breve
  if (argc == 1) {
    MainMenssage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }
  
  // Pasamos a string el nombre de la cadena de ADN
  const std::string kProgramDNAChain{argv[1]};
  // Si se solicitan las instrucciones de uso del programa, se muestran
  if ((argc == 2) && (kProgramDNAChain == kHelp)) {
    InfoMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  // Si hay más de un parametro, pero su suma no es igual a 3, entonces se
  // termina el programa con un mensaje de error
  if (argc < 3 || argc > 3) {
    ErrorMessage(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  // Pasamos a string el nombre del archivo de salida
  const std::string kProgramOutFile{argv[2]};
  // Analizamos si el tercer argumento tiene extension ".txt", sino es así
  // se termina el programa
  for (int i{int(kProgramOutFile.size() - 1)}, j{0}; (j < 5) && (i >= 0); 
       --i, ++j) { // No uso un Switch porque en cada if tengo dos condiciones
    // Si kProgramOutFile tiene como longitud 4 y contiene ".txt" no se acepta
    // o si es menor a la longitud de ".txt" que es 4 tampoco
    if (j == 0 && i <= 3) {
      ErrorFileName(kProgramName, kHelp);
      exit(EXIT_FAILURE);
    }

    if ((kProgramOutFile[i] == 't') && (j == 0 || j == 2)) continue;
    if ((kProgramOutFile[i] == 'x') && (j == 1)) continue;
    if ((kProgramOutFile[i] == '.') && (j == 3)) continue;
    if (j == 4) continue;
    ErrorFileName(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  Alphabet a;
  std::string adn{"adn"};
  char A{'A'};
  char C{'C'};
  char G{'G'};
  char T{'T'};
  Alphabet b(adn, A, C, G, T);
  Alphabet c(b);

  std::cout << b << std::endl;

  return 0;
}
