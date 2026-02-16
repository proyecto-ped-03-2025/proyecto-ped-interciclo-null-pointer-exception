#include <iostream>
using namespace std;

struct Jugador
{
    string jugador;
    int id;
    int puntaje;
    Jugador *siguiente;
};

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