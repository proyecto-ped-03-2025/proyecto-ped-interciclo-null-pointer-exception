#include <iostream>
using namespace std;

struct Jugador
{
    string jugador;
    int id;
    int puntaje;
    Jugador *siguiente;
};

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