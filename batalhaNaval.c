#include <stdio.h>

int main()
{
    int tamanho = 10;
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int mapa[10][10] = {0};
    int destroyer1[] = {3, 3, 3};
    int destroyer2[] = {3, 3, 3};

    printf("TABULEIRO BATALHA NAVAL \n");
    printf("   ");

    // Colocando primeiro navio
    int linha1 = 2, coluna1 = 4;
    for (int x = 0; x < 3; x++)
    {
        mapa[linha1][coluna1 + x] = destroyer1[x];
    }

    // Colocando segundo navio
    int linha2 = 6, coluna2 = 2;
    for (int x = 0; x < 3; x++)
    {
        mapa[linha2 + x][coluna2] = destroyer2[x];
    }

    // Gerando as colunas
    for (int x = 0; x < tamanho; x++)
    {
        printf("%c ", coluna[x]);
    }
    printf("\n");

    // Gerando o restante do tabuleiro
    for (int x = 0; x < tamanho; x++)
    {
        int linha = x + 1;
        linha == 10 ? printf("%d ", x + 1) : printf(" %d ", x + 1);
        for (int y = 0; y < tamanho; y++)
        {
            printf("%d ", mapa[x][y]);
        }
        printf("\n");
    }
}