#ifndef T2_C4_JUEGO_H
#define T2_C4_JUEGO_H

#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int const PLAYER = 0;
int const IA = 1;

class Juego  {

private:
    int puntaje;

public:

    // HACER QUE EL ARBOL GUARDE UN VALOR QUE REPRESENTE EL ESTADO ACTUAL DE LA PARTIDA

    Juego();

    int getPuntaje();

    void setPuntaje(int _puntaje);

    void c4_facil(Tablero tablero);

    void c4_medio();

    void c4_dificil(Tablero tablero);

    int generarNumeroAleatorio();


};


#endif //T2_C4_JUEGO_H
