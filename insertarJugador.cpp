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
    // system("cls"); // Para Windows
    system("clear"); // Para Linux/Mac
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
        return false; // Si no hay nada en la lista regresa falso
    }
    Jugador *actual = frente; // Se crea una variable auxiliar para poder buscar

    do
    {
        if (actual->id == IDexiste)
        {
            return true; // En el caso que al buscar un id coincida, va a retornar true
        }
        actual = actual->siguiente; // Hasta que lo encuentre va a recorrer toda la lista de jugadores

    } while (actual != frente); // Hasta que llegue de nuevo al frente

    return false; // De lo contrario, si no lo encontro despues de recorrer, regresa falso
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
        cout << "El id ya existe,ingrese otro id y vuelva a intentarlo." << endl;
        delete nuevo;
        return;
    }

    nuevo->puntaje = 0; // Iguala el puntaje del nuevo jugador en 0

    if (frente == NULL) // Si no hay nada en el frente, guarda los datos en el frente y en la cola al solo haber 1 elemento
    {
        frente = nuevo;
        cola = nuevo;
        nuevo->siguiente = frente; // Hace que el nuevo elemento apunte al primero, convirtiendolo en circular
    }
    else
    {
        cola->siguiente = nuevo; // Si ya habia un elemento, el siguiente elemento que se agregue va a ir despues de la cola actual
        nuevo->siguiente = frente;
        cola = nuevo;
    }
}