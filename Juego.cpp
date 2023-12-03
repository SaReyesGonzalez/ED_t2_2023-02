#include <limits>
#include "Juego.h"

Juego::Juego() {
}

int Juego::getPuntaje() {
    return puntaje;
}

void Juego::setPuntaje(int _puntaje) {
    puntaje = _puntaje;
}

void Juego::c4_facil(Tablero tablero) {  // LISTO !!!!!!!
    bool gameOver = false;
    bool movimientoValido = true;
    int turno = 0;

    while (!gameOver) {
        tablero.imprimirTablero();

        if (turno == PLAYER) { //Turno jugador
            int columna;
            cout << "\nIngrese columna a jugar: ";
            cin >> columna;

           movimientoValido = tablero.agregarFicha(columna - 1,FICHA_JUGADOR);

           while (!movimientoValido) {
               cout << "\nMovimiento invalido" << endl;

               cout << "\nIngrese columna a jugar: ";
               cin >> columna;

               movimientoValido = tablero.agregarFicha(columna - 1, FICHA_IA);
           }

            gameOver= tablero.comprobarVictoria(FICHA_JUGADOR);
        }

        if (turno == IA) { // Turno IA

            int columna = generarNumeroAleatorio();

            tablero.agregarFicha(columna - 1, FICHA_IA);

            gameOver= tablero.comprobarVictoria(FICHA_IA);
        }

        turno += 1;
        turno = turno % 2;
    }

    if (turno == 1) {
        tablero.imprimirTablero();
        cout << "\n\n¡¡¡ FELICIDADES, HAS GANADO !!!" << endl;

    } else {
        tablero.imprimirTablero();
        cout << "\n\nLo lamento, no hay nada pudieras haber hecho ante el poder de la IA..." << endl;
    }
}  // LISTO !!1

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
            cout << "\nIngrese columna a jugar: ";
            cin >> columna;

            movimientoValido = tablero.agregarFicha(columna - 1,FICHA_JUGADOR);

            while (!movimientoValido) {
                cout << "\nMovimiento invalido" << endl;

                cout << "\nIngrese columna a jugar: ";
                cin >> columna;

                movimientoValido = tablero.agregarFicha(columna - 1, FICHA_IA);
            }

            gameOver = tablero.comprobarVictoria(FICHA_JUGADOR);
        }

        if (turno == IA) { // Turno IA

            int columna;
            int alfa = -numeric_limits<int>::infinity();
            int beta = numeric_limits<int>::infinity();

            pair<int,int> p = tablero.minimax(5,alfa,beta,true);
            columna = p.first;

            movimientoValido = tablero.agregarFicha(columna - 1,FICHA_IA);

            while (!movimientoValido) {
                movimientoValido = tablero.agregarFicha(columna - 1, FICHA_IA);
            }

            gameOver = tablero.comprobarVictoria(FICHA_IA);
        }

        turno += 1;
        turno = turno % 2;
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



