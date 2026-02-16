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