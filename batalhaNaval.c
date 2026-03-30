#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int main() {

    int tabuleiro [LINHAS][COLUNAS] = {0};
    int menu;

    do {
        printf("\n### MENU BATALHA NAVAL ###\n\n");
        printf("1) posicionar navio na horizontal\n");
        printf("2) posicionar navio na vertical\n");
        printf("3) posicionar navio na horizontal\n");
        printf("4) Resetar tabuleiro\n");
        printf("5) exibir tabuleiro atual\n");
        printf("0) Sair\n");
        printf("Digite uma opção valida\n\n");
        
        scanf("%d", &menu); 

        switch (menu){
            case 1:
            {
                int selecaoI , selecaoJ , contador;
                printf("Selecione uma coluna de 0 a %d pois o navio ocupara o espaco que escolheu mais dois espacos para a direita (tamanho do navio eh de 3 casas)\n", COLUNAS - TAMANHO_NAVIO);
                scanf("%d" , &selecaoI); 
                printf("Selecione uma linha de 0 a %d:\n", LINHAS - 1);
                scanf("%d" , &selecaoJ);
                contador = selecaoI + (TAMANHO_NAVIO - 1); 
                // verificando dados de entrada
                if ((selecaoI >= 0 && selecaoI <= (COLUNAS - TAMANHO_NAVIO)) && (selecaoJ >= 0 && selecaoJ <= (LINHAS - 1))){
                    while (selecaoI <= contador){
                        tabuleiro [selecaoJ][selecaoI] = 3;
                        selecaoI++;
                    }
                    printf("Navio posicionado!\n");
                } else {
                    printf("Selecione uma linha e coluna valida\n");
                }
            }
            break;
            case 2:
                        {
                int selecaoI , selecaoJ , contador;
                printf("Selecione uma coluna de 0 a %d:\n", COLUNAS - 1);
                scanf("%d" , &selecaoI); 
                printf("Selecione uma linha de 0 a %d pois o navio ocupara o espaco que escolheu mais dois espacos para baixo (tamanho do navio eh de 3 casas)\n", LINHAS - TAMANHO_NAVIO);
                scanf("%d" , &selecaoJ);
                contador = selecaoJ + (TAMANHO_NAVIO - 1);  
                // verificando dados de entrada
                if ((selecaoI >= 0 && selecaoI <= (COLUNAS - 1)) && (selecaoJ >= 0 && selecaoJ <= (LINHAS - TAMANHO_NAVIO))){
                    while (selecaoJ <= contador){
                        tabuleiro [selecaoJ][selecaoI] = 3;
                        selecaoJ++;
                    }
                    printf("Navio posicionado!\n");
                } else {
                    printf("Selecione uma linha e coluna valida\n");
                }
            }
            break;
            case 3:
            {
                printf("\n--- POSICIONANDO NAVIOS DIAGONAIS ---\n");
                // navio 1
                int linhaDiag1 = 1;
                int colunaDiag1 = 1;
                int sobreposicao1 = 0; 
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    if (tabuleiro[linhaDiag1 + i][colunaDiag1 + i] == 3) {
                        sobreposicao1 = 1;
                    }
                }
                if (sobreposicao1 == 0) {
                    for (int i = 0; i < TAMANHO_NAVIO; i++) {
                        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = 3;
                    }
                    printf("Navio Diagonal 1 posicionado com sucesso!\n");
                } else {
                    printf("ERRO: Ja existe um navio no caminho do Diagonal 1!\n");
                }
                //diagonal 2
                int linhaDiag2 = 5;
                int colunaDiag2 = 8;
                int sobreposicao2 = 0;
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    if (tabuleiro[linhaDiag2 + i][colunaDiag2 - i] == 3) {
                        sobreposicao2 = 1; 
                    }
                }
                if (sobreposicao2 == 0) {
                    for (int i = 0; i < TAMANHO_NAVIO; i++) {
                        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = 3;
                    }
                    printf("Navio Diagonal 2 posicionado com sucesso!\n");
                } else {
                    printf("ERRO: Ja existe um navio no caminho do Diagonal 2!\n");
                }
            }
            break;
            case 4:
            for (int l = 0; l < LINHAS; l++) {
                    for (int c = 0; c < COLUNAS; c++) {
                        tabuleiro [l][c] = 0;
                    }
                }
            printf("Tabuleiro resetado\n");
            break;
            case 5:
            //imprimindo tabuleiro
            printf("\n--- TABULEIRO ATUAL ---\n");
            printf("  ");
                for (int c = 0; c < COLUNAS; c++) {
                    printf("%d ", c);
                }
                printf("\n");
                for (int l = 0; l < LINHAS; l++) {
                    printf("%d ", l);
                    for (int c = 0; c < COLUNAS; c++) {
                        printf("%d ", tabuleiro[l][c]);
                    }
                    printf("\n");
                }
                break;
            default:
            break;
            }
    } while (menu != 0); //sai quando for 0

    return 0;
}