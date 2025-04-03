#include <stdio.h>

#define TAMANHO 10
#define DESTROYER 3

int main()
{
    char linha[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int mapa[TAMANHO][TAMANHO] = {0};
    int colunaDestroyer[] = {0, 4, 8, 9};

    printf("TABULEIRO BATALHA NAVAL \n");
    printf("   ");

    // Posicoes Destroyer
    // O primeiro e segundo valor é a posição X e Y, e o terceiro define a direção ( 1 - Horizontal, 2 - Vertical, 3 - Diagonal, 4 - Diagonal Inverse);
    int posicoesDestroyer[4][3] = {
        {0, 2, 1},
        {6, 9, 2},
        {2, 1, 3},
        {7, 3, 4}};

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < DESTROYER; y++)
        {
            if (posicoesDestroyer[x][2] == 1)
            {
                mapa[posicoesDestroyer[x][0]][posicoesDestroyer[x][1] + y] = DESTROYER;
            }
            else if (posicoesDestroyer[x][2] == 2)
            {
                mapa[posicoesDestroyer[x][0] + y][posicoesDestroyer[x][1]] = DESTROYER;
            }
            else if (posicoesDestroyer[x][2] == 3)
            {
                mapa[posicoesDestroyer[x][0] + y][posicoesDestroyer[x][1] + y] = DESTROYER;
            }
            else if (posicoesDestroyer[x][2] == 4)
            {
                mapa[posicoesDestroyer[x][0] - y][posicoesDestroyer[x][1] + y] = DESTROYER;
            }
        }
    }

    // Gerando as colunas
    for (int x = 0; x < TAMANHO; x++)
    {
        printf("%c ", linha[x]);
    }
    printf("\n");

    // Gerando o restante do tabuleiro
    for (int x = 0; x < TAMANHO; x++)
    {
        int linha = x + 1;
        linha == 10 ? printf("%d ", x + 1) : printf(" %d ", x + 1);
        for (int y = 0; y < TAMANHO; y++)
        {
            printf("%d ", mapa[x][y]);
        }
        printf("\n");
    }
}