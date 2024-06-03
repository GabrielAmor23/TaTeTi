# Explicación del código:
1. Definición del tablero: Se crea una matriz board de 3x3 para representar el tablero de Tic-Tac-Toe.
2. Funciones de utilidad:
- mostrarTablero(): Muestra el tablero en la consola.
- MovimientoValido(int movimiento): Verifica si un movimiento es válido.
- realizarMovimiento(char jugador, int movimiento): Realiza un movimiento en el tablero.
- verificarVictoria(char jugador): Comprueba si un jugador ha ganado.
- verificarEmpate(): Verifica si el juego ha terminado en empate.
1. Lógica principal del juego:
- Se alternan los turnos entre los jugadores 'X' y 'O'.
- Se verifica la validez del movimiento y se actualiza el tablero.
- Se comprueba si alguien ha ganado o si hay empate después de cada movimiento.
1. Mostrar el resultado: Al final, se muestra quién ha ganado o si el juego terminó en empate.