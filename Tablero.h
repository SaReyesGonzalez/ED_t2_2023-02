#ifndef T2_C4_TABLERO_H
#define T2_C4_TABLERO_H

#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

int const HEIGHT = 6;
int const WIDTH = 7;
int const LARGO_VENTANA = 4;

char const NEUTRO = 'O';
char const FICHA_JUGADOR = 'R';
char const FICHA_IA = 'A';

using namespace std;

class Tablero {
private:
    char tablero[HEIGHT][WIDTH];
    std::string partidaActual;
    int puntajeActual;

public:
    Tablero();

    void imprimirTablero();

    void jugarPieza(char t[HEIGHT][WIDTH], int fila, int col, char ficha); //BUENO

    bool esPosicionValida(int col); //BUENO

    int getFilaValida(int col); //BUENO

    bool comprobarVictoria(char ficha); //BUENO

    int evaluarVentana(vector<char> window, char ficha); // NADA

    int puntajeJugada(char aux_t[HEIGHT][WIDTH], char ficha); // FALTA

    bool esNodoTerminal(); // BUENO

    pair<int, int> minimax(int profundidad, int alfa, int beta, bool max); // NADA

    vector<int> getPosicionesValidas(); //BUENO




    int elegirMejorJugada(char ficha);

    int eleccionAleatoria(vector<int> &valid_locations);

};


#endif //T2_C4_TABLERO_H
