//
// Created by sebastian on 30-11-23.
//

#include "miTablero.h"

bool Tablero::agregarFicha(int columna, char ficha) {

    if (columna >= WIDTH) {
        return false;
    }

    for (int i = HEIGHT - 1; i >= 0 ; i--) {
        if (tablero[i][columna] == NEUTRO) {
            tablero[i][columna] = ficha;
            return true;
        }
    }

    return false;
}