#include <iostream>

using namespace std;

const int TAMANO = 3;
char tablero[TAMANO][TAMANO] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void mostrarTablero() {
    cout << "-------------" << endl;
    for (int i = 0; i < TAMANO; ++i) {
        cout << "| ";
        for (int j = 0; j < TAMANO; ++j) {
            cout << tablero[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool esMovimientoValido(int movimiento) {
    int fila = (movimiento - 1) / TAMANO;
    int columna = (movimiento - 1) % TAMANO;
    return movimiento >= 1 && movimiento <= 9 && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O';
}

void realizarMovimiento(char jugador, int movimiento) {
    int fila = (movimiento - 1) / TAMANO;
    int columna = (movimiento - 1) % TAMANO;
    tablero[fila][columna] = jugador;
}

bool verificarVictoria(char jugador) {
    // Verificar filas y columnas
    for (int i = 0; i < TAMANO; ++i) {
        if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ||
            (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) {
            return true;
        }
    }
    // Verificar diagonales
    if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
        (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
        return true;
    }
    return false;
}

bool verificarEmpate() {
    for (int i = 0; i < TAMANO; ++i) {
        for (int j = 0; j < TAMANO; ++j) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char jugadorActual = 'X';
    bool juegoGanado = false;
    bool juegoEmpatado = false;
    int movimiento;

    while (!juegoGanado && !juegoEmpatado) {
        mostrarTablero();
        cout << "Jugador " << jugadorActual << ", ingresa tu movimiento (1-9): ";
        cin >> movimiento;

        if (esMovimientoValido(movimiento)) {
            realizarMovimiento(jugadorActual, movimiento);
            juegoGanado = verificarVictoria(jugadorActual);
            if (!juegoGanado) {
                juegoEmpatado = verificarEmpate();
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Movimiento inválido. Inténtalo de nuevo." << endl;
        }
    }

    mostrarTablero();

    if (juegoGanado) {
        cout << "¡Jugador " << jugadorActual << " gana!" << endl;
    } else if (juegoEmpatado) {
        cout << "¡Es un empate!" << endl;
    }

    return 0;
}

