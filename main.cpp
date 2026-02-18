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

void esperar()//commit 1
{
    cout << "\nPresione ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
}

void menu()
{
    cout << "\033[34m ===================================\033[0m" << endl;

    cout << "\033[34m|\033[35m      MENU DE OPCIONES             \033[34m|\033[0m" << endl;

    cout << "\033[34m|===================================|\033[0m" << endl;

    cout << "\033[34m|     \033[33mIngrese una opcion:           \033[34m|\033[0m" << endl;

    cout << "\033[34m|     \033[32m1. Ingresar jugadores.        \033[34m|\033[0m" << endl;
    cout << "\033[34m|     \033[32m2. Empezar a jugar.           \033[34m|\033[0m" << endl;
    cout << "\033[34m|     \033[32m3. Eliminar jugador.          \033[34m|\033[0m" << endl;
    cout << "\033[34m|     \033[32m4. Instrucciones.             \033[34m|\033[0m" << endl;
    cout << "\033[34m|     \033[32m5. Mostrar ganador.           \033[34m|\033[0m" << endl;
    cout << "\033[34m|     \033[32m6. Mostrar jugadores.         \033[34m|\033[0m" << endl;
    cout << "\033[34m|     \033[32m7. Salir del juego.           \033[34m|\033[0m" << endl;

    cout << "\033[34m|___________________________________|\033[0m" << endl;
}

void menuJugar()
{
    cout << "\033[34m|==============================|\033[0m" << endl;

    cout << "\033[34m|\033[35m       MODO DE JUEGO          \033[34m|\033[0m" << endl;

    cout << "\033[34m|==============================|\033[0m" << endl;

    cout << "\033[34m| \033[32m1. Seleccion manual.         \033[34m|\033[0m" << endl;

    cout << "\033[34m| \033[32m2. Seleccion aleatoria.      \033[34m|\033[0m" << endl;

    cout << "\033[34m|______________________________|\033[0m" << endl;

    cout << "\033[33m Ingrese una opcion:       \033[0m" << endl;
}

void instrucciones()
{
    cout << "\033[34m ____________________________________________________________________________________\033[0m" << endl;

    cout << "\033[34m|\033[0m                                                                                    \033[34m|\033[0m" << endl;

    cout << "\033[34m|\033[35m                                    INSTRUCCIONES                                   \033[34m|\033[0m" << endl;

    cout << "\033[34m|____________________________________________________________________________________|\033[0m" << endl;

    cout << "\033[34m|\033[0m                                                                                    \033[34m|\033[0m" << endl;

    cout << "\033[34m|  \033[33mPara poder jugar piedra papel o tijeras se hace lo siguiente:\033[34m                     |\033[0m" << endl;

    cout << "\033[34m|  \033[32m1. Cada partida se hace entre 2 personas.\033[34m                                         |\033[0m" << endl;

    cout << "\033[34m|  \033[32m2. Los jugadores podran escoger una entre 3 opciones: piedra, papel o tijeras.\033[34m    |\033[0m" << endl;

    cout << "\033[34m|  \033[32m3. La Piedra solo puede ganarle a las tijeras.\033[34m                                    |\033[0m" << endl;

    cout << "\033[34m|     \033[32mEl papel solo puede ganarle a la piedra.\033[34m                                       |\033[0m" << endl;

    cout << "\033[34m|     \033[32mLas tijeras solo pueden ganarle al papel.\033[34m                                      |\033[0m" << endl;

    cout << "\033[34m|____________________________________________________________________________________|\033[0m" << endl;
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

    cout << "Ingrese el nombre: " << endl;//agregar un getline para agregar nombres con espacios
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nuevo->jugador);

    cout << "Ingrese el id unico del jugador:" << endl;
    cin >> nuevo->id;

    if (ExisteID(frente, nuevo->id))
    {

        cout << "El id ya existe,ingrese otro id y vuelva a intentarlo." << endl
             << endl;
        esperar();

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
        cola->siguiente = nuevo;   // Si ya habia un elemento, el siguiente elemento que se agregue va a ir despues de la cola actual
        nuevo->siguiente = frente; // El nuevo elemento apuntara al frente.
        cola = nuevo;
    }
}

bool estaVacio(Jugador *frente)
{
    if (frente == NULL) // Verifica si el inicio de la cola esta nula o vacia
    {
        cout << "No hay ningun jugador actualmente" << endl;
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
                int num = (rand() % 3) + 1; // Con esto quiere decir que va a generar un numero aleatoreo entre 1 al 3
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

void mostrarJugadores(Jugador *frente)
{
    if (estaVacio(frente))
    {
        return;
    }

    Jugador *aux = frente; // Crea una variable auxiliar para mostrar a los jugadores con sus ids y sus puntajes

    cout << "----- LISTA DE JUGADORES -----" << endl;

    do
    {
        cout << "Nombre: " << aux->jugador
             << " | ID: " << aux->id
             << " | Puntaje: " << aux->puntaje << endl;

        aux = aux->siguiente; // una vez imprime los datos del primer jugador, pasa a imprimir los datos del siguiente

    } while (aux != frente); // hasta que este llegue a volver a ser el del frente
}

void mostrarGanador(Jugador *frente)
{
    if (estaVacio(frente)) // Verifica si el primer elemento esta vacio
    {
        return;
    }

    Jugador *aux = frente;     // Crea una variable auxiliar para el uso del frente
    Jugador *ganador = frente; // Se guarda inicialmente al jugador que este primeramente guardado

    do
    {
        if (aux->puntaje > ganador->puntaje) // Compara el puntaje del jugador actual con el del ganador, si es mayor se guarda como nuevo ganador
        {
            ganador = aux; // Si el puntaje del jugador actual es mayor que el del ganador, se actualiza el ganador con el jugador actual
        }
        aux = aux->siguiente; // Se mueve al siguiente jugador en la lista circular

    } while (aux != frente);

    cout << "===== GANADOR DE LA COMPETENCIA =====" << endl;
    cout << "Nombre: " << ganador->jugador << endl;
    cout << "ID: " << ganador->id << endl;
    cout << "Puntaje: " << ganador->puntaje << endl;
}

// funcion

void eliminar(Jugador *&frente, Jugador *&cola)
{
    if (estaVacio(frente))
    {
        esperar();
        return;
    }

    int idEliminar;
    cout << "Ingrese el id del jugador a eliminar: " << endl;
    cin >> idEliminar;

    Jugador *actual = frente;
    Jugador *anterior = NULL;

    while (actual->id != idEliminar) // Verifica si el id a eliminar es igual
    {
        if (actual->siguiente == frente)
        {
            cout << "Jugador con ID " << idEliminar << " no encontrado." << endl
                 << endl;
            esperar();
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == frente) // Si el jugador a eliminar es el primero de la lista
    {
        if (frente == cola) // Si solo hay un jugador en la lista, al eliminarlo se vacia la lista
        {
            frente = NULL;
            cola = NULL;
        }
        else // Si hay mas de un jugador, el frente se mueve al siguiente y la cola apunta al nuevo frente
        {
            frente = frente->siguiente;
            cola->siguiente = frente;
        }
    }
    else // si no es el primero, el anterior apunta al siguiente del actual
    {
        anterior->siguiente = actual->siguiente;
        if (actual == cola) // Si el jugador a eliminar es el ultimo de la lista, el anterior se convierte en la nueva cola
        {
            cola = anterior;
        }
    }

    delete actual;
    cout << "Jugador con ID " << idEliminar << " eliminado exitosamente." << endl;
    esperar();
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
            esperar();
            break;
        case 5:
            mostrarGanador(frente);
            esperar();
            break;
        case 6:
            mostrarJugadores(frente);
            esperar();
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