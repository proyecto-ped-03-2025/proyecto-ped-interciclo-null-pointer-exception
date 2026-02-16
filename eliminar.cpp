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