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

void limpiarPantalla()
{
    system("clear"); // Para Linux/Mac (cambiar a "cls" para Windows)
}

void menu()
{
    cout << " ===================================" << endl;
    cout << "|      MENU DE OPCIONES             |" << endl;
    cout << "|===================================|" << endl;
    cout << "|     Ingrese una opcion:           |" << endl;
    cout << "|     1. Ingresar jugadores.        |" << endl;
    cout << "|     2. Empezar a jugar.           |" << endl;
    cout << "|     3. Eliminar jugador.          |" << endl;
    cout << "|     4. Instrucciones.             |" << endl;
    cout << "|     5. Mostrar ganador.           |" << endl;
    cout << "|     6. Mostrar jugadores.         |" << endl;
    cout << "|     7. Salir del juego.           |" << endl;
    cout << "|___________________________________|" << endl;
}

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

void instrucciones()
{
    cout << " ____________________________________________________________________________________" << endl;
    cout << "|                                                                                    |" << endl;
    cout << "|                                    INSTRUCCIONES                                   |" << endl;
    cout << "|____________________________________________________________________________________|" << endl;
    cout << "|                                                                                    |" << endl;
    cout << "|  Para poder jugar piedra papel o tijeras se hace lo siguiente:                     |" << endl;
    cout << "|  1.Cada partida se hace entre 2 personas.                                          |" << endl;
    cout << "|  2. los jugadores podran escoger una entre 3 opciones: piedra, papel o tijeras.    |" << endl;
    cout << "|  3. La Piedra solo puede ganarle a las tijeras.                                    |" << endl;
    cout << "|     El papel solo puede ganarle a la piedra.                                       |" << endl;
    cout << "|     Las tijeras solo pueden ganarle al papel.                                      |" << endl;
    cout << "|____________________________________________________________________________________|" << endl;
}

void menuOpciones()
{
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijeras" << endl;
}

bool ExisteID(Jugador *frente, int IDexiste)
{
    if (frente == NULL)
    {
        return false;
    }
    Jugador *actual = frente;
    do
    {
        if (actual->id == IDexiste)
        {
            return true;
        }
        actual = actual->siguiente;
    } while (actual != frente);
    return false;
}

void insertarJugador(Jugador *&frente, Jugador *&cola)
{
    Jugador *nuevo = new Jugador;

    cout << "Ingrese el nombre: " << endl;
    cin >> nuevo->jugador;

    cout << "Ingrese el id unico del jugador:" << endl;
    cin >> nuevo->id;

    if (ExisteID(frente, nuevo->id))
    {
        cout << "El id ya existe, ingrese otro id y vuelva a intentarlo." << endl;
        delete nuevo;
        return;
    }

    nuevo->puntaje = 0;

    if (frente == NULL)
    {
        frente = nuevo;
        cola = nuevo;
        nuevo->siguiente = frente;
    }
    else
    {
        cola->siguiente = nuevo;
        nuevo->siguiente = frente;
        cola = nuevo;
    }
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

void mostrarJugadores(Jugador *frente)
{
    if (estaVacio(frente))
    {
        return;
    }

    Jugador *aux = frente;

    cout << "----- LISTA DE JUGADORES -----" << endl;

    do
    {
        cout << "Nombre: " << aux->jugador
             << " | ID: " << aux->id
             << " | Puntaje: " << aux->puntaje << endl;

        aux = aux->siguiente;

    } while (aux != frente);
}

void mostrarGanador(Jugador *frente)
{
    if (estaVacio(frente))
    {
        return;
    }

    Jugador *aux = frente;
    Jugador *ganador = frente;

    do
    {
        if (aux->puntaje > ganador->puntaje)
        {
            ganador = aux;
        }
        aux = aux->siguiente;

    } while (aux != frente);

    cout << "===== GANADOR DE LA COMPETENCIA =====" << endl;
    cout << "Nombre: " << ganador->jugador << endl;
    cout << "ID: " << ganador->id << endl;
    cout << "Puntaje: " << ganador->puntaje << endl;
}

void eliminar(Jugador *&frente, Jugador *&cola)
{
    if (estaVacio(frente))
    {
        cout << "No hay jugadores para eliminar." << endl;
        return;
    }

    int idEliminar;
    cout << "Ingrese el id del jugador a eliminar: " << endl;
    cin >> idEliminar;

    Jugador *actual = frente;
    Jugador *anterior = NULL;

    while (actual->id != idEliminar)
    {
        if (actual->siguiente == frente)
        {
            cout << "Jugador con ID " << idEliminar << " no encontrado." << endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == frente)
    {
        if (frente == cola)
        {
            frente = NULL;
            cola = NULL;
        }
        else
        {
            frente = frente->siguiente;
            cola->siguiente = frente;
        }
    }
    else
    {
        anterior->siguiente = actual->siguiente;
        if (actual == cola)
        {
            cola = anterior;
        }
    }

    delete actual;
    cout << "Jugador con ID " << idEliminar << " eliminado exitosamente." << endl;
}

int main()
{
    srand(time(NULL));
    Jugador *frente = NULL;
    Jugador *cola = NULL;

    int opcion = 0;

    while (opcion != 7)
    {
        limpiarPantalla();
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertarJugador(frente, cola);
            break;
        case 2:
            jugar(frente, cola);
            break;
        case 3:
            eliminar(frente, cola);
            break;
        case 4:
            instrucciones();
            cout << "\nPresione ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 5:
            mostrarGanador(frente);
            cout << "\nPresione ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 6:
            mostrarJugadores(frente);
            cout << "\nPresione ENTER para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 7:
            cout << "Gracias por jugar" << endl;
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
    }
    return 0;
}
