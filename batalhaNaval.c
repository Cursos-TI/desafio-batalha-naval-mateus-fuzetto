#include <stdio.h>

#define TAMANHO 10
#define DESTROYER 3
#define HABILIDADE 5

void ataqueTriangulo(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    for (int habilidade = 0; habilidade < 3; habilidade++)
    {
        int i = linha + habilidade;
        if (i > TAMANHO)
            break;

        for (int j = coluna - habilidade; j <= coluna + habilidade; j++)
        {
            if (j >= 0 && j < TAMANHO)
            {
                tabuleiro[i][j] = HABILIDADE;
            }
        }
    }
}

void ataqueCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    for (int habilidade = 0; habilidade < 3; habilidade++)
    {
        int i = linha + habilidade;
        if (i > TAMANHO)
            break;

        int habilitySize = habilidade == 1 ? 2 : 0;

        for (int j = coluna - habilitySize; j <= coluna + habilitySize; j++)
        {
            if (j >= 0 && j < TAMANHO)
            {
                tabuleiro[i][j] = HABILIDADE;
            }
        }
    }
}

void ataqueOctagono(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    for (int habilidade = 0; habilidade < 3; habilidade++)
    {
        int i = linha + habilidade;
        if (i > TAMANHO)
            break;

        int habilitySize = habilidade == 1 ? 1 : 0;

        for (int j = coluna - habilitySize; j <= coluna + habilitySize; j++)
        {
            if (j >= 0 && j < TAMANHO)
            {
                tabuleiro[i][j] = HABILIDADE;
            }
        }
    }
}

int main()
{
    char linha[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int mapa[TAMANHO][TAMANHO] = {0};

    printf("TABULEIRO BATALHA NAVAL \n");
    printf("   ");

    // Posicoes Destroyer
    // O primeiro e segundo valor é a posição ie Y, e o terceiro define a direção ( 1 - Horizontal, 2 - Vertical, 3 - Diagonal, 4 - Diagonal Inverse);
    int posicoesDestroyer[4][3] = {
        {0, 2, 1},
        {6, 9, 2},
        {2, 1, 3},
        {7, 3, 4}};

    // Coloca os navios no mapa
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < DESTROYER; j++)
        {
            if (posicoesDestroyer[i][2] == 1)
            {
                mapa[posicoesDestroyer[i][0]][posicoesDestroyer[i][1] + j] = DESTROYER;
            }
            else if (posicoesDestroyer[i][2] == 2)
            {
                mapa[posicoesDestroyer[i][0] + j][posicoesDestroyer[i][1]] = DESTROYER;
            }
            else if (posicoesDestroyer[i][2] == 3)
            {
                mapa[posicoesDestroyer[i][0] + j][posicoesDestroyer[i][1] + j] = DESTROYER;
            }
            else if (posicoesDestroyer[i][2] == 4)
            {
                mapa[posicoesDestroyer[i][0] - j][posicoesDestroyer[i][1] + j] = DESTROYER;
            }
        }
    }

    //Criei funções para cada ataque.

    //Ataque Triangulo
    ataqueTriangulo(mapa, 1, 7);

    //Ataque Cruz
    ataqueCruz(mapa, 5, 6);
    
    //Ataque Octagono
    ataqueOctagono(mapa, 1, 1);

    // Gerando as colunas
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%c ", linha[i]);
    }
    printf("\n");

    // Gerando o restante do tabuleiro
    for (int i = 0; i < TAMANHO; i++)
    {
        int linha = i + 1;
        linha == 10 ? printf("%d ", i + 1) : printf(" %d ", i + 1);
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
}