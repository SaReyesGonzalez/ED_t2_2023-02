#include <iostream>
#include "Juego.h"
#include "Tablero.h"

using namespace std;

int main() {

    Juego* juego = new Juego();
    Tablero* tablero = new Tablero();

    char dificultad;

    cout << "Bienvenido a Connect4!! Por: Sebastian Reyes G." << endl;

    cout << "\nDificultades: " << endl;
    cout << "A) Facil" << endl;
    cout << "B) Medio" << endl;
    cout << "C) Dificl" << endl;

    cout << "\n¿En que dificultad desea jugar? ";
    cin >> dificultad;

    switch (dificultad){

        case 'a':
        case 'A':
            juego->c4_facil(*tablero);
            //juego->finalizarPartida(tablero);

            break;

        case 'b':
        case 'B':
            //juego->c4_medio();
            //juego->finalizarPartida(tablero);

            break;

        case 'c':
        case 'C':
            juego->c4_dificil(*tablero);
            //juego->finalizarPartida(tablero);

            break;

        default:
            cout << "Por favor seleccione una dificultad valida." << endl;
    }

    return 0;
}


