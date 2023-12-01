#include "Tablero.h"
#include <iostream>
#include <algorithm>

Tablero::Tablero() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            tablero[i][j] = NEUTRO;
        }
    }
}

void Tablero::imprimirTablero() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 1; j <= WIDTH; j++) {
        cout << "--";
    }

    cout << endl;

    for (int j = 1; j <= WIDTH; j++) {
        cout << j << " ";
    }
}

void Tablero::jugarPieza(char t[HEIGHT][WIDTH], int fila, int col, char ficha) {
    t[fila][col] = ficha;
}

bool Tablero::esPosicionValida(int col) {
    return tablero[HEIGHT - 1][col] == NEUTRO;
}

int Tablero::getFilaValida(int col) {
    for (int f = 0; f < HEIGHT; f++) {
        if (tablero[f][col] == NEUTRO) {
            return f;
        }
    }

    return -1;
}

bool Tablero::comprobarVictoria(char ficha) {

    // Posiciones horizontales
    for (int c = 0 ; c < WIDTH - 3 ; c++) {
        for (int f = 0 ; f < HEIGHT ; f++) {
            if  ((tablero[f][c] == ficha) && (tablero[f][c+1]) == ficha &&
                (tablero[f][c+2]) == ficha && (tablero[f][c+3] == ficha))
                {
                    return true;
                }

        }
    }

    // Posiciones verticales
    for (int c = 0 ; c < WIDTH ; c++) {
        for (int f = 0 ; f < HEIGHT - 3 ; f++) {
            if  ((tablero[f][c] == ficha) && (tablero[f+1][c]) == ficha &&
                 (tablero[f+2][c]) == ficha && (tablero[f+3][c] == ficha))
                {
                    return true;
                }

        }
    }

    // Diagonales positivas
    for (int c = 0 ; c < WIDTH - 3 ; c++) {
        for (int f = 0 ; f < HEIGHT - 3 ; f++) {
            if  ((tablero[f][c] == ficha) && (tablero[f+1][c+1]) == ficha &&
                 (tablero[f+2][c+2]) == ficha && (tablero[f+3][c+3] == ficha))
            {
                return true;
            }

        }
    }

    // Diagonales negativas
    for (int c = 0 ; c < WIDTH - 3 ; c++) {
        for (int f = 3 ; f < HEIGHT ; f++) {
            if  ((tablero[f][c] == ficha) && (tablero[f-1][c+1]) == ficha &&
                 (tablero[f-2][c+2]) == ficha && (tablero[f-3][c+3] == ficha))
            {
                return true;
            }
        }
    }

    return false;
}

int Tablero::evaluarVentana(vector<char> window, char ficha) {
    return 0;
}

int Tablero::puntajeJugada(char aux_t[HEIGHT][WIDTH], char ficha) {
    int puntaje = 0;

    // Puntaje columna central
    vector<int> arrayCentral;

    for (int i = 0; i < HEIGHT; ++i) {
        arrayCentral.push_back(tablero[i][WIDTH / 2]);
    }
    int contCentro = count(arrayCentral.begin(), arrayCentral.end(), ficha);
    puntaje += contCentro * 3;

    // Puntaje horizontal
    for (int f = 0; f < HEIGHT; f++) {
        char* ptrFila = tablero[f];

        for (int c = 0; c <= WIDTH - LARGO_VENTANA; c++) {
            char* ptrVentana = ptrFila + c;
            vector<char> ventana(ptrVentana, ptrVentana + LARGO_VENTANA);
            puntaje += evaluarVentana(ventana, ficha);
        }
    }

    // Puntuación vertical
    for (int c = 0; c < WIDTH; c++) {
        vector<int> arrayColumnas;

        for (int f = 0; f < HEIGHT; f++) {
            arrayColumnas.push_back(tablero[f][c]);
        }

        for (int f = 0; f <= HEIGHT - LARGO_VENTANA; f++) {
            vector<char> window(arrayColumnas.begin() + f, arrayColumnas.begin() + f + LARGO_VENTANA);
            puntaje += evaluarVentana(window, ficha);
        }
    }

    // Puntuación diagonal positiva
    for (int f = 0; f <= HEIGHT - LARGO_VENTANA; f++) {
        for (int c = 0; c <= WIDTH - LARGO_VENTANA; c++) {
            vector<char> window;

            for (int i = 0; i < LARGO_VENTANA; ++i) {
                window.push_back(tablero[f + i][c + i]);
            }

            puntaje += evaluarVentana(window, ficha);
        }
    }

    // Puntuación diagonal positiva invertida
    for (int f = 0; f <= HEIGHT - LARGO_VENTANA; f++) {
        for (int c = 0; c <= WIDTH - LARGO_VENTANA; c++) {
            vector<char> window;

            for (int i = 0; i < LARGO_VENTANA; i++) {
                window.push_back(tablero[f + LARGO_VENTANA - 1 - i][c + i]);
            }
            puntaje += evaluarVentana(window, ficha);
        }
    }

    return puntaje;
}


bool Tablero::esNodoTerminal() {
    return comprobarVictoria(FICHA_JUGADOR) || comprobarVictoria(FICHA_IA) || getPosicionesValidas().empty();
}


pair<int,int> Tablero::minimax(int profundidad, int alfa, int beta, bool jugadorMax) {
    vector<int> posicionesValidas = getPosicionesValidas();
    bool esTerminal = esNodoTerminal();

    if (profundidad == 0 || esTerminal)
    {
        if (esTerminal)
        {
            if (comprobarVictoria(FICHA_IA))
            {
                return make_pair(-1,100000000000);

            } else if (FICHA_JUGADOR) {
                return make_pair(-1, -10000000000);

            } else {
                return make_pair(-1,0);
            }
        }

        else {
            //return make_pair(-1, puntajeJugada(FICHA_IA)); //CORREGIR
        }
    }

    if (jugadorMax) {
        int valor = -numeric_limits<int>::infinity();
        int column = rand() % posicionesValidas.size();

        for (int col : posicionesValidas) {
            int row = getFilaValida(col);
            vector<vector<int>> b_copy = tablero;
            jugarPieza(b_copy, row, col, FICHA_IA);
            int new_score = minimax(b_copy, profundidad - 1, alfa, beta, false).second;

            if (new_score > valor) {
                valor = new_score;
                column = col;
            }

            alfa = std::max(alfa, valor);

            if (alfa >= beta) {
                break;
            }
        }

    }
}



vector<int> Tablero::getPosicionesValidas() {
    vector<int> posicionesValidas;

    for (int col = 0; col < WIDTH; col++) {
        if (esPosicionValida(col)) {
            posicionesValidas.push_back(col);
        }
    }

    return posicionesValidas;
}

int Tablero::elegirMejorJugada(char ficha) {

    vector<int> posicionesValidas = getPosicionesValidas();

    int mejorPuntaje = -100;
    int mejorColumna = eleccionAleatoria(posicionesValidas);

    for (int col : posicionesValidas) {

        char temp_tablero[HEIGHT][WIDTH];

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                temp_tablero[i][j] = tablero[i][j];
            }
        }

        int puntaje = puntajeJugada(temp_tablero, ficha);

        if (puntaje > mejorPuntaje) {
            mejorPuntaje = puntaje;
            mejorColumna = col;
        }
    }

    return mejorColumna;
}


int Tablero::eleccionAleatoria(vector<int> &lugaresValidos) {
    int random_index = rand() % lugaresValidos.size();
    return lugaresValidos[random_index];
}
