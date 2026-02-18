#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void menuJugar()
{
    cout << "\033[34m|==============================|\033[0m" << endl;

    cout << "\033[34m|\033[35m       MODO DE JUEGO          \033[34m|\033[0m" << endl;

    cout << "\033[34m|==============================|\033[0m" << endl;

    cout << "\033[34m| \033[32m1. Seleccion manual.         \033[34m|\033[0m" << endl;

    cout << "\033[34m| \033[32m2. Seleccion aleatoria.      \033[34m|\033[0m" << endl;

    cout << "\033[34m|______________________________|\033[0m" << endl;

    cout << "\033[33m Ingrese una opcion:       \033[0m" << endl;
}
void menuOpciones()
{
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijeras" << endl;
}
