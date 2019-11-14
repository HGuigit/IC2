#include <stdio.h>
#include <stdlib.h>

void set_maze(int matrix[100][100], int start_x, int start_y, int end_x,
              int end_y, int tam_x, int tam_y);
void solve_maze(int matrix[100][100], int current_x, int current_y, int tam_x,
                int tam_y, int count);

void print_matrix(int matrix[100][100], int tam_x, int tam_y);

void move(int matrix[100][100], int x, int y, int tam_x, int tam_y, int count);
void move_up(int matrix[100][100], int x, int y, int tam_x, int tam_y, int count);
void move_right(int matrix[100][100], int x, int y, int tam_x, int tam_y,
                int count);
void move_down(int matrix[100][100], int x, int y, int tam_x, int tam_y,
               int count);
void move_left(int matrix[100][100], int x, int y, int tam_x, int tam_y,
               int count);

/*
 * START = 2
 * WALL = 0
 * EMPTY = 1
 * END = 99
 * VISITED = a1, a2, a3,...,an
 */

int main() {
    int x, y;
    int i, j;
    int start_x, start_y, count;
    int end_x, end_y;
    int tam_x, tam_y;
    int mat[100][100];
    // int mat_aux[4][4];
    // define matriz teste

    /*int mat[4][4] = {{1, 0, 1, 1},
                                            {1, 0, 0, 1},
                                            {1, 0, 1, 1},
                                            {1, 1, 1, 0}};*/

    // Pega valores do usuário

    printf("Insira o tamanho da labirinto m x n:\n");
    scanf("%d %d", &tam_x, &tam_y);

      printf("Insira o ponto de start (ixj):\n");
    scanf("%d %d", &start_x, &start_y);
      printf("Insira o ponto de end(ixj):\n");
    scanf("%d %d", &end_x, &end_y);
      printf("Insitra a matriz:\n");

    for(i = 0; i<100; i++){
        for(j = 0; j < 100; j++){
            mat[i][j] = 0;
        }
    }
    for (i = 0; i < tam_x; i++) {
        for (j = 0; j < tam_y; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    x = end_x;
    y = end_y;
    // designado para testes

    /*start_x = 0; start_y = 0;

end_x = 0; end_y = 2;*/
    count = 2;

    set_maze(mat, start_x, start_y, end_x, end_y, tam_x, tam_y);

      print_matrix(mat, tam_x, tam_y);

    solve_maze(mat, start_x, start_y, tam_x, tam_y, count);

    printf("%d", mat[x][y] - mat[start_x][start_y]);

    if((mat[x][y] - mat[start_x][start_y]) == 97){
        printf("\n\nLabirinto sem solucao!!\n\n");
    }

    return 0;
}

void solve_maze(int mat[100][100], int current_x, int current_y, int tam_x,
                int tam_y, int count) {
      printf("Onde estou? (%d,%d)\n", current_x, current_y);

    mat[current_x][current_y] = count;

      print_matrix(mat, tam_x, tam_y);
    move(mat, current_x, current_y, tam_x, tam_y, count);
}

void print_matrix(int matrix[100][100], int tam_x, int tam_y) {
    int i, j;

    for (i = 0; i < tam_x; i++) {
        for (j = 0; j < tam_y; j++) {
            printf(" %2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void move(int matrix[100][100], int x, int y, int tam_x, int tam_y, int count) {
    move_up(matrix, x, y, tam_x, tam_y, count);
    move_right(matrix, x, y, tam_x, tam_y, count);
    move_down(matrix, x, y, tam_x, tam_y, count);
    move_left(matrix, x, y, tam_x, tam_y, count);
}

void move_up(int matrix[100][100], int x, int y, int tam_x, int tam_y,
             int count) {
    if ((matrix[x - 1][y] == 1 || matrix[x - 1][y] == 99 ||
         (matrix[x - 1][y] > matrix[x][y] + 1 && matrix[x - 1][y] > 0 &&
          matrix[x - 1][y] < 99)) &&
        matrix[x - 1][y] != 2) {
        count++;
        solve_maze(matrix, x - 1, y, tam_x, tam_y, count);
    }
}

void move_right(int matrix[100][100], int x, int y, int tam_x, int tam_y,
                int count) {
    if ((matrix[x][y + 1] == 1 || matrix[x][y + 1] == 99 ||
         (matrix[x][y + 1] > matrix[x][y] + 1 && matrix[x][y + 1] > 0 &&
          matrix[x][y + 1] < 99)) &&
        matrix[x][y + 1] != 2) {
        count++;
        solve_maze(matrix, x, y + 1, tam_x, tam_y, count);
    }
}

void move_down(int matrix[100][100], int x, int y, int tam_x, int tam_y,
               int count) {
    if ((matrix[x + 1][y] == 1 || matrix[x + 1][y] == 99 ||
         (matrix[x + 1][y] > matrix[x][y] + 1 && matrix[x + 1][y] > 0 &&
          matrix[x + 1][y] < 99)) &&
        matrix[x + 1][y] != 2) {
        count++;
        solve_maze(matrix, x + 1, y, tam_x, tam_y, count);
    }
}

void move_left(int matrix[100][100], int x, int y, int tam_x, int tam_y,
               int count) {
    if ((matrix[x][y - 1] == 1 || matrix[x][y - 1] == 99 ||
         (matrix[x][y - 1] > matrix[x][y] + 1 && matrix[x][y - 1] > 0 &&
          matrix[x][y - 1] < 99)) &&
        matrix[x][y - 1] != 2) {
        count++;
        solve_maze(matrix, x, y - 1, tam_x, tam_y, count);
    }
}

void set_maze(int matrix[100][100], int start_x, int start_y, int end_x,
              int end_y, int tam_x, int tam_y) {
    int i, j;

    for (i = 0; i < tam_x; i++) {
        for (j = 0; j < tam_y; j++) {
            if (i == start_x && j == start_y) {
                matrix[i][j] = 2;
            }
            if (i == end_x && j == end_y) {
                matrix[i][j] = 99;
            }
        }
    }
}