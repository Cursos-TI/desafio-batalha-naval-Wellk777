#include <stdio.h>
#include <stdlib.h>

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Nível Novato - Posicionamento dos Navios
void nivelNovato() {
    int tabuleiro[5][5];

    // Inicializa o tabuleiro com zeros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona um navio verticalmente (tamanho 3)
    // Coordenadas: (0,0), (1,0), (2,0)
    tabuleiro[0][0] = 1;
    tabuleiro[1][0] = 1;
    tabuleiro[2][0] = 1;

    printf("\n--- Nível Novato ---\n");
    printf("Navio Vertical (tamanho 3) posicionado em:\n");
    printf("(0,0)\n");
    printf("(1,0)\n");
    printf("(2,0)\n\n");

    // Posiciona um navio horizontalmente (tamanho 2)
    // Coordenadas: (3,2), (3,3)
    tabuleiro[3][2] = 1;
    tabuleiro[3][3] = 1;

    printf("Navio Horizontal (tamanho 2) posicionado em:\n");
    printf("(3,2)\n");
    printf("(3,3)\n\n");
}

// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
void nivelAventureiro() {
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com zeros
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona quatro navios no tabuleiro

    // Navio 1: Vertical (tamanho 3)
    // Coordenadas: (0,0), (1,0), (2,0)
    tabuleiro[0][0] = 3;
    tabuleiro[1][0] = 3;
    tabuleiro[2][0] = 3;

    // Navio 2: Horizontal (tamanho 2)
    // Coordenadas: (3,2), (3,3)
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;

    // Navio 3: Diagonal (tamanho 3) - Principal
    // Coordenadas: (5,5), (6,6), (7,7)
    tabuleiro[5][5] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][7] = 3;

    // Navio 4: Diagonal (tamanho 2) - Secundária
    // Coordenadas: (1,8), (2,7)
    tabuleiro[1][8] = 3;
    tabuleiro[2][7] = 3;

    printf("\n--- Nível Aventureiro ---\n");
    printf("Tabuleiro 10x10 com navios posicionados (0 = vazio, 3 = ocupado):\n\n");
    exibirTabuleiro(tabuleiro);
}

// Habilidade em Cone
void habilidadeCone(int tabuleiro[10][10], int centro_x, int centro_y, int raio) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // Limpa o tabuleiro
        }
    }

    for (int i = 0; i <= raio; i++) {
        for (int j = centro_y - i; j <= centro_y + i; j++) {
            if (centro_x + i < 10 && j >= 0 && j < 10) {
                tabuleiro[centro_x + i][j] = 1;
            }
        }
    }
}

// Habilidade em Cruz
void habilidadeCruz(int tabuleiro[10][10], int centro_x, int centro_y, int tamanho) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // Limpa o tabuleiro
        }
    }

    for (int i = -tamanho; i <= tamanho; i++) {
        if (centro_x + i >= 0 && centro_x + i < 10) {
            tabuleiro[centro_x + i][centro_y] = 1;
        }
        if (centro_y + i >= 0 && centro_y + i < 10) {
            tabuleiro[centro_x][centro_y + i] = 1;
        }
    }
}

// Habilidade em Octaedro
void habilidadeOctaedro(int tabuleiro[10][10], int centro_x, int centro_y, int raio) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // Limpa o tabuleiro
        }
    }

    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (abs(i) + abs(j) <= raio) {
                if (centro_x + i >= 0 && centro_x + i < 10 && centro_y + j >= 0 && centro_y + j < 10) {
                    tabuleiro[centro_x + i][centro_y + j] = 1;
                }
            }
        }
    }
}

// Nível Mestre - Habilidades Especiais com Matrizes
void nivelMestre() {
    int tabuleiro[10][10];

    printf("\n--- Nível Mestre ---\n");

    printf("\n--- Habilidade em Cone (Centro: 2,2, Raio: 2) ---\n");
    habilidadeCone(tabuleiro, 2, 2, 2);
    exibirTabuleiro(tabuleiro);

    printf("\n--- Habilidade em Cruz (Centro: 5,5, Tamanho: 3) ---\n");
    habilidadeCruz(tabuleiro, 5, 5, 3);
    exibirTabuleiro(tabuleiro);

    printf("\n--- Habilidade em Octaedro (Centro: 7,7, Raio: 2) ---\n");
    habilidadeOctaedro(tabuleiro, 7, 7, 2);
    exibirTabuleiro(tabuleiro);
}

int main() {
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    return 0;
}
