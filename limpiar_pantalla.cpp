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