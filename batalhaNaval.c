#include <stdio.h>

int main() {

    // Tabuleiro consertado: sem o '*' e com o ';' no final
    int tabuleiro [10][10] = {
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0}
    };

    int menu;

    do {
        // O menu veio para DENTRO do 'do' para repetir na tela
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
                printf("Selecione uma coluna de 0 a 7 pois o navio ocupará o espaço que escolheu mais dois espaços para a direita (tamanho do navio é de 3 casas)\n");
                scanf("%d" , &selecaoI); 
                printf("Selecione uma linha de 0 a 9:\n");
                scanf("%d" , &selecaoJ);
                contador = selecaoI + 2; 
                // verificando dados de entrada
                if ((selecaoI >= 0 && selecaoI <= 7) && (selecaoJ >= 0 && selecaoJ <= 9)){
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
                printf("Selecione uma coluna de 0 a 9:\n");
                scanf("%d" , &selecaoI); 
                printf("Selecione uma linha de 0 a 7 pois o navio ocupará o espaço que escolheu mais dois espaços para baixo (tamanho do navio é de 3 casas)\n");
                scanf("%d" , &selecaoJ);
                contador = selecaoJ + 2; 
                // verificando dados de entrada
                if ((selecaoI >= 0 && selecaoI <= 9) && (selecaoJ >= 0 && selecaoJ <= 7)){
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
                int linhaDiag1 = 1;
                int colunaDiag1 = 1;
                for (int i = 0; i < 3; i++) {
                    tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = 3;
                }
                printf("Navio Diagonal 1 posicionado com sucesso!\n");
                int linhaDiag2 = 5;
                int colunaDiag2 = 8;
                for (int i = 0; i < 3; i++) {
                    tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = 3;
                }
                printf("Navio Diagonal 2 posicionado com sucesso!\n");
            }
            break;
            case 4:
            for (int l = 0; l < 10; l++) {
                    for (int c = 0; c < 10; c++) {
                        tabuleiro [l][c] = 0;
                    }
                }
            printf("Tabuleiro resetado\n");
            break;
            case 5:
            //imprimindo tabuleiro
            printf("\n--- TABULEIRO ATUAL ---\n");
            printf("  ");
                for (int c = 0; c < 10; c++) {
                    printf("%d ", c);
                }
                printf("\n");
                for (int l = 0; l < 10; l++) {
                    printf("%d ", l);
                    for (int c = 0; c < 10; c++) {
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