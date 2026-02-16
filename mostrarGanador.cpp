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
