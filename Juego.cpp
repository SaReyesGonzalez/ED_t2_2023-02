#include "Juego.h"

Juego::Juego() {
}

int Juego::getPuntaje() {
    return puntaje;
}

void Juego::setPuntaje(int _puntaje) {
    puntaje = _puntaje;
}

void Juego::c4_facil(Tablero tablero) {
    bool gameOver = false;
    bool movimientoValido = true;
    int turno = 0;

    while (!gameOver) {
        tablero.imprimirTablero();

        if (turno == PLAYER) { //Turno jugador

            int columna;
            cout << "\n\nIngrese columna a jugar: ";
            cin >> columna;

            if (tablero.esPosicionValida(columna)) {
                int fila = tablero.getFilaValida(columna);
                tablero.jugarPieza(this.tablero, fila, columna, FICHA_JUGADOR);

                if (tablero.comprobarVictoria(FICHA_JUGADOR))
                {
                    gameOver = true;
                }
            }

            turno += 1;
            turno = turno % 2;
        }

        if (turno == IA && !gameOver) { // Turno IA

            int columna = generarNumeroAleatorio();

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
}

void Juego::c4_medio() {

}

void Juego::c4_dificil(Tablero tablero) {

    bool gameOver = false;
    bool movimientoValido = true;
    int turno = 0;

    while (!gameOver) {
        tablero.imprimirTablero();

        if (turno == PLAYER) { //Turno jugador

            int columna;
            cout << "\n\nTURNO JUGADOR" << endl;
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
}

int Juego::generarNumeroAleatorio() {
    // Inicializa la semilla del generador de números aleatorios con el tiempo actual
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Genera un número aleatorio del 1 al 7
    int numeroAleatorio = (std::rand() % 7) + 1;

    return numeroAleatorio;
}



