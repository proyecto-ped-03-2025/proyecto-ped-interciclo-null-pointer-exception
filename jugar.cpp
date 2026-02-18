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

void esperar() // Función para pausar la ejecución y esperar a que el usuario presione ENTER
{
    cout << "\nPresione ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
}

void jugar(Jugador *frente, Jugador *cola)
{
    if (estaVacio(frente))
    {
        esperar();
        return;
    }

    Jugador *jugador1 = NULL;
    Jugador *jugador2 = NULL;

    jugador1 = frente;

    if (frente == cola) // Verifica si hay un solo jugador en la lista circular, si es asi no se puede jugar
    {
        cout << "Se necesita mas de un jugador para poder empezar" << endl
             << endl;
        esperar();
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
        cout << "\033[31mOpcion invalida.\033[0m" << endl;
    }

    do
    {
        jugador2 = jugador1->siguiente; // El jugador 2 sera el que sigue del jugador 1 para que se enfrenten entre si
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
                    cout << "Esto es un empate" << endl; // si ambos jugadores escogen la misma opcion, se declara un empate
                    esperar();
                }
                else if ((opcion == 1 && opcion2 == 3) || (opcion == 2 && opcion2 == 1) || (opcion == 3 && opcion2 == 2))
                // se verifican todos los casos en los que pueda ganar el jugador 1
                {

                    cout << "Ha ganado : " << jugador1->jugador << endl
                         << endl;
                    jugador1->puntaje++; // Si el jugador 1 gana, se le suma un punto a su puntaje
                    esperar();
                }
                else
                {
                    cout << "Ha ganado : " << jugador2->jugador << endl
                         << endl;
                    jugador2->puntaje++; // Caso contrario el jugador 2 gana puntos
                    esperar();
                }
            }
            else if (modo == 2)
            {

                int num2 = (rand() % 3) + 1;
                int num = (rand() % 3) + 1;                             // Con esto quiere decir que va a generar un numero aleatoreo entre 1 al 3
                const char *jugadas[] = {"Piedra", "Papel", "Tijeras"}; // Se crea un arreglo de strings para mostrar la jugada que hizo cada jugador

                cout << jugador1->jugador << " jugo: " << jugadas[num - 1] << endl;/* Se muestra la jugada del jugador 1,
                 se le resta 1 al numero generado para que coincida con el indice del arreglo*/
                cout << jugador2->jugador << " jugo: " << jugadas[num2 - 1] << endl;

                if (num == num2)
                {
                    cout << "Esto es un empate" << endl;
                    esperar();
                }
                else if ((num == 1 && num2 == 3) || (num == 2 && num2 == 1) || (num == 3 && num2 == 2))
                {

                    cout << "Ha ganado : " << jugador1->jugador << endl;
                    jugador1->puntaje++;
                    esperar();
                }
                else
                {
                    cout << "Ha ganado : " << jugador2->jugador << endl;
                    jugador2->puntaje++;
                    esperar();
                }
            }
            else
            {
                cout << "opcion invalida" << endl;
            }

            jugador2 = jugador2->siguiente; /* El jugador 2 se mueve al siguiente jugador para que se enfrente con el jugador 1,
            hasta que el jugador 2 vuelva a ser el mismo que el jugador 1, lo que quiere decir que ya se enfrentaron con todos los jugadores*/

        } while (jugador2 != frente); // se va a mover el jugador 2 hasta que este vuelva a ser el mismo que el jugador 1

        jugador1 = jugador1->siguiente; // una vez pase lo anterior, el jugador 1 pasa a ser el siguiente jugador

    } while (jugador1 != cola); // se va a mover el jugador 1 hasta que llegue a la cola, lo que quiere decir que ya se enfrentaron todos los jugadores entre si
}