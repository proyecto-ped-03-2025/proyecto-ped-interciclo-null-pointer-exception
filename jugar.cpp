#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Jugador
{
    string jugador;
    int id;
    int puntaje;
    Jugador *siguiente;
};

void menuJugar()
{
    cout << "|==============================" << endl;
    cout << "|       MODO DE JUEGO          |" << endl;
    cout << "|==============================|" << endl;
    cout << "| 1. Seleccion manual.         |" << endl;
    cout << "| 2. Seleccion aleatoria.      |" << endl;
    cout << "|______________________________|" << endl;
    cout << " Ingrese una opcion:       " << endl;
}

void menuOpciones()
{
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijeras" << endl;
}

bool estaVacio(Jugador *frente)
{
    if (frente == NULL)
    {
        cout << "No hay ningún jugador actualmente" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void jugar(Jugador *frente, Jugador *cola)
{
    if (estaVacio(frente))
    {
        return;
    }

    Jugador *jugador1 = NULL;
    Jugador *jugador2 = NULL;

    jugador1 = frente;

    if (frente == cola)
    {
        cout << "Se necesita mas de un jugador para poder empezar" << endl
             << endl;
        return;
    }

    int modo = 0;

    menuJugar();
    cin >> modo;

    if (modo == 1)
    {
        cout << "Modo MANUAL seleccionado." << endl;
    }
    else if (modo == 2)
    {
        cout << "Modo ALEATORIO seleccionado." << endl;
    }
    else
    {
        cout << "Opcion invalida." << endl;
    }

    do
    {
        jugador2 = jugador1->siguiente;
        cout << "Partida entre " << jugador1->jugador << " y " << jugador2->jugador << endl
             << endl;

        do
        {
            if (modo == 1)
            {
                int opcion = 0;
                int opcion2 = 0;

                cout << "Ingrese la opcion de " << jugador1->jugador << ": " << endl;
                menuOpciones();
                cin >> opcion;
                cout << "Ingrese la opcion de " << jugador2->jugador << ": " << endl;
                menuOpciones();
                cin >> opcion2;

                if (opcion == opcion2)
                {
                    cout << "Esto es un empate" << endl;
                }
                else if ((opcion == 1 && opcion2 == 3) || (opcion == 2 && opcion2 == 1) || (opcion == 3 && opcion2 == 2))
                {
                    cout << "Ha ganado : " << jugador1->jugador << endl
                         << endl;
                    jugador1->puntaje++;
                }
                else
                {
                    cout << "Ha ganado : " << jugador2->jugador << endl
                         << endl;
                    jugador2->puntaje++;
                }
            }
            else if (modo == 2)
            {
                int num2 = (rand() % 3) + 1;
                int num = (rand() % 3) + 1;
                if (num == num2)
                {
                    cout << "Esto es un empate" << endl;
                }
                else if ((num == 1 && num2 == 3) || (num == 2 && num2 == 1) || (num == 3 && num2 == 2))
                {
                    cout << "Ha ganado : " << jugador1->jugador << endl;
                    jugador1->puntaje++;
                }
                else
                {
                    cout << "Ha ganado : " << jugador2->jugador << endl;
                    jugador2->puntaje++;
                }
            }
            else
            {
                cout << "opcion invalida" << endl;
            }

            jugador2 = jugador2->siguiente;

        } while (jugador2 != frente);

        jugador1 = jugador1->siguiente;

    } while (jugador1 != cola);
}