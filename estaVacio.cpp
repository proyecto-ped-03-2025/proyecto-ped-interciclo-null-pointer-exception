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