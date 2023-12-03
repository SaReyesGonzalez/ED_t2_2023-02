//
// Created by sebastian on 30-11-23.
//

#include "miTablero.h"

/*
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

bool gameOver = false;
    bool movimientoValido = true;
    int turno = 0;

    while (!gameOver) {
        tablero.imprimirTablero();

        if (turno == PLAYER) { //Turno jugador

            int columna;
            cout << "Ingrese columna a jugar: ";
            cin >> columna;

            movimientoValido = tablero.agregarFicha(columna - 1, FICHA_JUGADOR);

            while (!movimientoValido) {
                cout << "\nMovimiento invalido" << endl;

                cout << "\nIngrese columna a jugar: ";
                cin >> columna;

                movimientoValido = tablero.agregarFicha(columna - 1, FICHA_JUGADOR);
            }

            turno += 1;
            turno = turno % 2;

            gameOver = tablero.comprobarVictoria(FICHA_JUGADOR);

        }

        if (turno == IA && !gameOver) { // Turno IA
            int columna;

            columna = tablero.elegirMejorJugada(FICHA_IA);

            movimientoValido = tablero.agregarFicha(columna - 1, FICHA_IA);

            while (!movimientoValido) {
                cout << "\nMovimiento invalido" << endl;

                cout << "\nIngrese columna a jugar: ";
                cin >> columna;

                movimientoValido = tablero.agregarFicha(columna - 1, FICHA_IA);
            }

            turno += 1;
            turno = turno % 2;

            gameOver= tablero.comprobarVictoria(FICHA_IA);
        }
    }

    if (turno == 1) {
        tablero.imprimirTablero();
        cout << "\n\n¡¡¡ FELICIDADES, HAS GANADO !!!" << endl;

    } else {
        tablero.imprimirTablero();
        cout << "\n\nLo lamento, no hay nada pudieras haber hecho ante el poder de la IA..." << endl;
    }

    */