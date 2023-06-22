#include <stdio.h> // Biblioteca de entrada e saída de dados
#include <stdlib.h> // Biblioteca de conversão das strings
#include <conio.h> // Biblioteca de manipulação de caracteres
#include <locale.h> // Biblioteca de acentuação de caracteres
#include <windows.h> // Biblioteca dos códigos do cmd
#include <time.h> //Biblioteca para função rand
#include <stdlib.h> //Biblioteca para função rand
#include <string.h> // Biblioteca para funções da string

#if defined(_WIN32)
    #define WINDOWS_SYSTEM
    #include <Windows.h>
#else
    #define UNIX_SYSTEM
    #include <unistd.h>
#endif

#define MAX_NOME 50
#define MAX_JOGADORES 100

typedef struct {
    char nome[MAX_NOME];
    int vitorias;
    int derrotas;
} Jogador;

void bubbleSort(Jogador jogadores[], int n) {
    int i, j;
    Jogador temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (jogadores[j].vitorias < jogadores[j+1].vitorias) {
                temp = jogadores[j];
                jogadores[j] = jogadores[j+1];
                jogadores[j+1] = temp;
            }
        }
    }
}

void exibirRanking(Jogador jogadores[], int numJogadores) {
    printf("\n--- RANKING ---\n");
    for (int i = 0; i < numJogadores; i++) {
        printf("%s - V: %d / D: %d\n", jogadores[i].nome, jogadores[i].vitorias, jogadores[i].derrotas);
    }
}

void adicionarVitorias(Jogador jogadores[], int numJogadores, char nome[]) {
    for (int i = 0; i < numJogadores; i++) {
        if (strcmp(jogadores[i].nome, nome) == 0) {
            int vitorias;
            printf("Digite o número de vitórias para %s: ", nome);
            scanf("%d", &vitorias);
            jogadores[i].vitorias += vitorias;
            break;
        }
    }
}

void my_sleep(int sleepms)
{
    #ifdef WINDOWS_SYSTEM
        Sleep(sleepms);
    #else
        usleep(sleepms * 1000);
    #endif
}



void imprimirTabuleiro(char tabuleiro[3][3]) {
    system("cls");
    printf("Eh sua vez jogador!\n");
    printf("\n     1   2   3 ");
    printf("\n  1  %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("    ---+---+---\n");
    printf("  2  %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("    ---+---+---\n");
    printf("  3  %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

}

int verificarVitoria(char tabuleiro[3][3], char jogador) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
            return 1;
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0;
}

int a,b,L,L2; // Declaração das váriaveis das setas
int co,L3,L4; // Novas declarações do menu

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main() {
    /*Ranking*/
    Jogador jogadores[MAX_JOGADORES];
    int numJogadores = 0;
    char nome[MAX_NOME];

    // Ler dados do arquivo (se existir)
    FILE *arquivo = fopen("ranking.txt", "r");
    if (arquivo != NULL) {
        while (fscanf(arquivo, "%[^,],%d,%d\n", jogadores[numJogadores].nome, &jogadores[numJogadores].vitorias, &jogadores[numJogadores].derrotas) == 3) {
            numJogadores++;
        }
        fclose(arquivo);
    }
    /*JOGO*/
    char tabuleiro[3][3];
    char linha,coluna;
    int linha1,coluna1; //Usado para transformar Char para numero.
    char jogador = 'X';
    char ia = 'O';
    int rodada = 0;
    int escolha;
    /* MENU */
    int opcao;
    SetConsoleTitle("Ultimate Game of The Velha"); // Título do programa
    do{
        inicio:
        opcao=0;
        L=2;L2=2;b=2;
        system("cls"); // Limpar a tela dos comandos anteriores
        system("color 1F"); // Definindo a cor do fundo e a letra no cmd
        printf("Dica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
if(1){
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKKKKKKKKXXXXXXXXKKKXXXXXXXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNX0kkkkkkkOO000000OOkO00000000KNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOOOkkkkkkkOOOOOOOOOkkkOOOOOO000KKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXKOkkkkkkkkkkkkkkkkkkkkkkkkkkkOOOO00KXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkO00000KNMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0kkkkkkkkkkkkkkkkkkkkkkkkkkOOkkkOkkOOO00KNMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMWNXKOkkkkkkkkkkkOkkkkkOOkkkkkOkOOkkkkkkkkOOO0KXXWMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMXkdddddddddddddxkkkkkkxxddddddddddddddxkkkxddddkXMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMM0,..............ckkkOkc...............'dOd,....'kMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMKl,,,,.     .,:cxK0d::;,,,.     .;cccc::::;,,,,:0MMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMN0kkkko.  ..'kWWWWNl. ;dxkc.  ..:0WWWWO' .lkkkkOXMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMN0kkkkkolooodk00000xoodkkkxoooooxO0000OdloxkkkkOXMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMN0kkkkkkkkkkkkkkkkOkkkkkkkkkkkkkkkkkkkkkkkkkkkkOXMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMN0OOkkkkkkkkkkkkkkOOkkOkkkkkkkkkOkkkkkkkkkkkkkO0NMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMWNNKl,,,,;dkkkkkkkkkkkkkkkkOkkOOOkkd:,,,,,,,:ONNWMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:    .:oooooooooooooooooooooooo:.       'OMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;     ..........................      ..,OMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;             .'cccccc,.             .okONMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:             .;oddddo;.          .',lKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:              ........           ;0NWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOdl'                              ;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;           .'''''''''.        'kKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,           cKXXXXXXXXd.        ..;0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNko:.           oWMMMMMMMMx.          .:oooodKMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,              cKXNWMMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,              ..'dXNMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMNOdl.                 cKNMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMM0'                    cKNMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMO.                    cKNMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMO.                    cKNMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMO'                    cKNMMMMx.                .dMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMXdc;.                 cKNMMMMx.                .xMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMN0Od,..               ;kO0000o.           .....,kMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMN0kkkxl.         ...............         .cxxxxkXMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXXXk'        .................        .lOkkkOXMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKc..    .........,,,'.........   ..,d00000NMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNX0:...........l0XXx'..........;OXNWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc........:dxKWWMXxdc........:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc........xWMMMMMMMMO,.......:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc........xWMMMMMMMMO,.......:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc........xWMMMMMMMMO,.......:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK:........xWMMMMMWWNk'.......:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl'..       .dWMMMMMO;'.        ,0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;          .dWMMMMMk.          ,0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

    
}
        /*modificando o valor de co muda a coluna de inicio do menu que pose ser de zero ate 63*/
        /*modificando o valor de L muda a linha de inicio do menu que pode ser de zero ate 20*/
        opcao=0;co=0;/*co é a coluna onde colocar a seta*/
        L=3;/*L é a linha onde fica as opções, mudando as opções p/baixo mude o valor de L igual*/
        L2=L;    /*L2 é onde estava a seta */
        L3=L+4;  /*L3 é a linha final do menu*/
        L4=L;    /*L4 é a linha de inicio do menu*/

        gotoxy(co+5,L);     // co é a coluna de inicio do menu e L é a linha de inico do menu
        printf("1 - JOGAR");
        gotoxy(co+5,L+1);
        printf("2 - RANKING");
        gotoxy(co+5,L+2);
        printf("3 - COMO JOGAR");
        gotoxy(co+5,L+3);
        printf("4 - SOBRE");
        gotoxy(co+5,L+4);
        printf("5 - SAIR\n");

        do{                       /*loop para movimentar a seta*/
            gotoxy(co+2,L);       /*gotoxy posiciona o cursor, o co é a coluna e L é a linha onde imprimir a seta*/
            printf("-%c",16);     /*imprime a seta*/
            gotoxy(5,0);         /*posiciona o cursor fora da tela para ele não ficar piscando*/
            if(kbhit){a=getch();} /*se alguma tecla foi pressionada a igual a tecla*/
            if(a == 80){          /*80 é valor do cactere seta p/baixo do teclado*/
                L2=L;             /*L2 é posição onde estava a seta para apagar senao fica duas setas*/
                L++;              /*L aponta para a nova posição da seta*/
                if(L>L3){L=L4;}   /*L vai de 2 ate 5 pois é onde estão as 4 opções, mudando mude tambem os valores*/
            }                     /*a seta estando no 4 e for movida p/baixo ela vai para a primeira opção*/
            if(a == 72){          /*72 é valor do cactere seta p/cima do teclado*/
                L2=L;             /*L2 é onde estava a seta para apagar*/
                L--;              /*L aponta para a nova posição da seta*/
                if(L<L4){L=L3;}   /*a seta estando no 1 e for movida p/cima ela vai para a ultima opção*/
            }
            if(L!=L2){            /*se a seta for movida */
                gotoxy(co+2,L2);  /*posicione o cursor onde estava a seta*/
                printf("  ");     /*imprime espaços em branco(que sao pretos) em cima da seta para apaga-la*/
                L2=L;             /*L2 igual a nova posição da seta*/
            }
            if(a == 13){          /*se a tecla enter for pressionada*/
                opcao=L-(L4-1);        /*opcao igual a linha onde esta a opção menos um, pois a primeira opção */
                                  /*esta na linha 2*/
            }
        }while(opcao == 0);       /*repete enquanto opcao igual a zero*/

    switch (opcao) {
    case 1:
        system("cls");
        setbuf(stdin, NULL);
        printf("Digite o seu nome: ");
        fgets(nome, 50, stdin);
        printf("-- Selecione: [X] ou [O] --\n");
        opcao=0;co=0;/*co é a coluna onde colocar a seta*/
        L=3;/*L é a linha onde fica as opções, mudando as opções p/baixo mude o valor de L igual*/
        L2=L;    /*L2 é onde estava a seta */
        L3=L+1;  /*L3 é a linha final do menu*/
        L4=L;    /*L4 é a linha de inicio do menu*/
        gotoxy(co+5,L);     // co é a coluna de inicio do menu e L é a linha de inico do menu
        printf("1 - X");
        gotoxy(co+5,L+1);
        printf("2 - O");
                do{                       /*loop para movimentar a seta*/
            gotoxy(co+2,L);       /*gotoxy posiciona o cursor, o co é a coluna e L é a linha onde imprimir a seta*/
            printf("-%c",16);     /*imprime a seta*/
            gotoxy(0,23);         /*posiciona o cursor fora da tela para ele não ficar piscando*/
            if(kbhit){a=getch();} /*se alguma tecla foi pressionada a igual a tecla*/
            if(a == 80){          /*80 é valor do cactere seta p/baixo do teclado*/
                L2=L;             /*L2 é posição onde estava a seta para apagar senao fica duas setas*/
                L++;              /*L aponta para a nova posição da seta*/
                if(L>L3){L=L4;}   /*L vai de 2 ate 5 pois é onde estão as 4 opções, mudando mude tambem os valores*/
            }                     /*a seta estando no 4 e for movida p/baixo ela vai para a primeira opção*/
            if(a == 72){          /*72 é valor do cactere seta p/cima do teclado*/
                L2=L;             /*L2 é onde estava a seta para apagar*/
                L--;              /*L aponta para a nova posição da seta*/
                if(L<L4){L=L3;}   /*a seta estando no 1 e for movida p/cima ela vai para a ultima opção*/
            }
            if(L!=L2){            /*se a seta for movida */
                gotoxy(co+2,L2);  /*posicione o cursor onde estava a seta*/
                printf("  ");     /*imprime espaços em branco(que sao pretos) em cima da seta para apaga-la*/
                L2=L;             /*L2 igual a nova posição da seta*/
            }
            if(a == 13){          /*se a tecla enter for pressionada*/
                opcao=L-(L4-1);        /*opcao igual a linha onde esta a opção menos um, pois a primeira opção */
                                  /*esta na linha 2*/
            }
            if(a == 27){
                goto inicio;
            }
        }while(opcao == 0);       /*repete enquanto opcao igual a zero*/
            do
            {
                if (opcao == 1)
                {
                    jogador = 'X';
                    ia = 'O';
                }
                else if (opcao == 2)
                {
                    jogador = 'O';
                    ia = 'X';
                }
            } while (jogador != 'O' && jogador != 'X');
            jogarnovamente:
            rodada = 0;
            for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        tabuleiro[i][j] = ' ';
                    }
                }
                while (1) {
                    printf("\nJogador [%c], e a sua vez.\n\n", jogador);
                    imprimirTabuleiro(tabuleiro);

                    printf("Digite a linha: ");
                    setbuf(stdin,NULL);
                    scanf("%c", &linha);
                    printf("Digite a coluna: ");
                    setbuf(stdin,NULL);
                    scanf("%c", &coluna);

                    //Transformando char em numero para fazer operações aritmeticas
                    linha1 = linha - '0';
                    coluna1 = coluna - '0';
                    // Verificar se a posicao e valida
                    if(linha < 49 || linha > 51 || coluna < 49 || coluna > 51 || tabuleiro[linha1 - 1][coluna1 - 1] != ' '){
                    printf("Posicao invalida. Tente novamente.\n");
                    continue;
                    }
                    tabuleiro[linha1 - 1][coluna1 - 1] = jogador;
                    // ------------- JOGADA DA IA ------------- 
                    if(rodada == 0){
                        if(tabuleiro[1][1] == jogador){
                            tabuleiro[0][0] = ia;
                        }
                        else if(tabuleiro[0][0] == jogador || tabuleiro[0][2] == jogador || tabuleiro[2][0] == jogador || tabuleiro[2][2] == jogador){
                            tabuleiro[1][1] = ia;
                        }
                        else if(tabuleiro[0][1] == jogador || tabuleiro[1][0] == jogador){
                            tabuleiro[0][0] = ia;
                        }
                        else if(tabuleiro[1][2] == jogador){
                            tabuleiro[0][2] = ia;
                        }
                        else if(tabuleiro[2][1] == jogador){
                            tabuleiro[2][0] = ia;
                        }
                        
                    }
                    else if (rodada == 1)
                {
                    // CASO CENTRO (jogador jogou no centro na rod 0)
                    if (tabuleiro[0][0] == ia && tabuleiro[1][1] == jogador && ((tabuleiro[2][2] == jogador || tabuleiro[2][0] == jogador || tabuleiro[0][1] == jogador || tabuleiro[1][0] == jogador || tabuleiro[1][2] == jogador || tabuleiro[2][1] == jogador || tabuleiro[0][2] == jogador)))
                    {
                        printf("---- 0 -----");
                        if (tabuleiro[2][2] == jogador)
                        {
                                                        tabuleiro[0][2] = ia;
                        }
                        else if (tabuleiro[0][2] == jogador)
                        {
                            
                            tabuleiro[2][0] = ia;
                        }
                        else if (tabuleiro[0][1] == jogador)
                        {
                            
                            tabuleiro[2][1] = ia;
                        }
                        else if (tabuleiro[1][0] == jogador)
                        {
                            
                            tabuleiro[1][2] = ia;
                        }
                        else if (tabuleiro[1][2] == jogador)
                        {
                            
                            tabuleiro[1][0] = ia;
                        }
                        else if (tabuleiro[2][0] == jogador)
                        {

                            tabuleiro[0][2] = ia;
                        }
                        else if (tabuleiro[2][1] == jogador)
                        {
                            
                            tabuleiro[0][1] = ia;
                        }
                    }

                    // CASO QUINAS (jogador jogou nas quinas na rod 0)
                    else if (tabuleiro[1][1] == ia && (tabuleiro[2][0] == jogador || tabuleiro[0][0] == jogador || tabuleiro[0][2] == jogador || tabuleiro[2][2] == jogador))
                    {
                        if (tabuleiro[2][2] == jogador)
                        {
                            if (tabuleiro[1][0] == jogador || tabuleiro[0][1] == jogador)
                            {
                                tabuleiro[0][0] = ia;
                            }
                            else if (tabuleiro[0][0] == jogador)
                            {
                                tabuleiro[1][0] = ia;
                            }
                            else if (tabuleiro[0][2] == jogador)
                            {
                                tabuleiro[1][2] = ia;
                            }
                            else if (tabuleiro[1][2] == jogador)
                            {
                                tabuleiro[0][2] = ia;
                            }
                            else if (tabuleiro[2][0] == jogador)
                            {
                                tabuleiro[2][1] = ia;
                            }
                            else if (tabuleiro[2][1] == jogador)
                            {
                                tabuleiro[2][0] = ia;
                            }
                        }
                        else if (tabuleiro[0][0] == jogador)
                        {
                            if (tabuleiro[2][1] == jogador || tabuleiro[1][2] == jogador)
                            {
                                tabuleiro[2][2] = ia;
                            }
                            else if (tabuleiro[2][2] == jogador)
                            {
                                tabuleiro[1][0] = ia;
                            }
                            else if (tabuleiro[0][1] == jogador)
                            {
                                tabuleiro[0][2] = ia;
                            }
                            else if (tabuleiro[0][2] == jogador)
                            {
                                tabuleiro[0][1] = ia;
                            }
                            else if (tabuleiro[1][0] == jogador)
                            {
                                tabuleiro[2][0] = ia;
                            }
                            else if (tabuleiro[2][0] == jogador)
                            {
                                tabuleiro[1][0] = ia;
                            }
                        }
                        else if (tabuleiro[0][2] == jogador)
                        {
                            if (tabuleiro[1][0] == jogador || tabuleiro[2][1] == jogador)
                            {
                                tabuleiro[2][0] = ia;
                            }
                            else if (tabuleiro[2][0] == jogador)
                            {
                                tabuleiro[1][2] = ia;
                            }
                            else if (tabuleiro[0][0] == jogador)
                            {
                                tabuleiro[0][1] = ia;
                            }
                            else if (tabuleiro[0][1] == jogador)
                            {
                                tabuleiro[0][0] = ia;
                            }
                            else if (tabuleiro[1][2] == jogador)
                            {
                                tabuleiro[2][2] = ia;
                            }
                            else if (tabuleiro[2][2] == jogador)
                            {
                                tabuleiro[1][2] = ia;
                            }
                        }
                        else if (tabuleiro[2][0] == jogador)
                        {
                            if (tabuleiro[2][1] == jogador || tabuleiro[1][2] == jogador)
                            {
                                tabuleiro[2][2] = ia;
                            }
                            else if (tabuleiro[2][2] == jogador)
                            {
                                tabuleiro[1][0] = ia;
                            }
                            else if (tabuleiro[0][1] == jogador)
                            {
                                tabuleiro[0][2] = ia;
                            }
                            else if (tabuleiro[0][2] == jogador)
                            {
                                tabuleiro[0][1] = ia;
                            }
                            else if (tabuleiro[1][0] == jogador)
                            {
                                tabuleiro[2][0] = ia;
                            }
                            else if (tabuleiro[2][0] == jogador)
                            {
                                tabuleiro[1][0] = ia;
                            }
                        }
                    }
                    // CASO MEIOS (Jogador jogou nos meios na rod 0)

                    else if (tabuleiro[0][0] == ia && (tabuleiro[0][1] == jogador || tabuleiro[1][0] == jogador))
                    {
                        if (tabuleiro[0][1] == jogador)
                        {

                            if (tabuleiro[1][1] == jogador || tabuleiro[2][0] == jogador || tabuleiro[1][0] == jogador)
                            {
                                tabuleiro[2][1] = ia;
                            }
                            else if (tabuleiro[2][1] == jogador)
                            {
                                tabuleiro[1][1] = ia;
                            }
                            else if (tabuleiro[2][2] == jogador || tabuleiro[1][2] == jogador)
                            {
                                tabuleiro[2][0] = ia;
                            }
                            else if (tabuleiro[0][2] == jogador)
                            {
                                tabuleiro[1][0] = ia;
                            }
                        }
                        else if (tabuleiro[1][0] == jogador)
                        {
                            if (tabuleiro[0][1] == jogador)
                            {
                                tabuleiro[2][1] = ia;
                            }
                            else if (tabuleiro[0][2] == jogador || tabuleiro[1][1] == jogador)
                            {
                                tabuleiro[1][2] = ia;
                            }
                            else if (tabuleiro[1][2] == jogador)
                            {
                                tabuleiro[1][1] = ia;
                            }
                            else if (tabuleiro[2][0] == jogador)
                            {
                                tabuleiro[0][1] = ia;
                            }
                            else if (tabuleiro[2][1] == jogador || tabuleiro[2][2] == jogador)
                            {
                                tabuleiro[0][2] = ia;
                            }
                        }
                    }
                    else if (tabuleiro[2][0] == ia && (tabuleiro[2][1] == jogador))
                    {

                        if (tabuleiro[0][0] == jogador || tabuleiro[1][1] == jogador || tabuleiro[1][0] == jogador)
                        {
                            tabuleiro[0][1] = ia;
                        }
                        else if (tabuleiro[0][2] == jogador || tabuleiro[1][2] == jogador)
                        {
                            tabuleiro[0][0] = ia;
                        }
                        else if (tabuleiro[0][1] == jogador)
                        {
                            tabuleiro[1][1] = ia;
                        }
                        else if (tabuleiro[2][2] == jogador)
                        {
                            tabuleiro[1][0] = ia;
                        }
                    }
                    else if (tabuleiro[0][2] == ia && (tabuleiro[1][2] == jogador))
                    {
                        if (tabuleiro[2][2] == jogador)
                        {
                            tabuleiro[0][1] = ia;
                        }
                        else if (tabuleiro[2][0] == jogador || tabuleiro[2][1] == jogador)
                        {
                            tabuleiro[0][0] = ia;
                        }
                        else if (tabuleiro[0][0] == jogador || tabuleiro[1][1] == jogador)
                        {
                            tabuleiro[1][0] = ia;
                        }
                        else if (tabuleiro[1][0] == jogador)
                        {
                            tabuleiro[1][1] = ia;
                        }
                        else if (tabuleiro[0][1] == jogador)
                        {
                            tabuleiro[2][1] = ia;
                        }
                    }
                }
                    //PRINCIPAL JOGO DA IA
                else if (rodada >= 2 && rodada < 8)
                
                {
               //JOGADAS PARA IA GANHAR

               //QUINAS
               if(tabuleiro[0][2] == ' ' && ((tabuleiro[0][0] == ia && tabuleiro[0][1] == ia) || (tabuleiro[1][2] == ia && tabuleiro[2][2] == ia) || (tabuleiro[2][0] == ia && tabuleiro[1][1] == ia)))
                        {
                            tabuleiro[0][2] = ia;
                        }

                else if (tabuleiro[2][0] == ' ' &&((tabuleiro[0][0] == ia && tabuleiro[1][0] == ia) || (tabuleiro[2][1] == ia && tabuleiro[2][2] == ia) || (tabuleiro[1][1] == ia && tabuleiro[0][2] == ia)))
                        {
                            tabuleiro[2][0] = ia;
                        }
                else if (tabuleiro[0][0] == ' ' && ((tabuleiro[0][1] == ia && tabuleiro[0][2] == ia) || (tabuleiro[1][0] == ia && tabuleiro[2][0] == ia) || (tabuleiro[1][1] == ia && tabuleiro[2][2] == ia)))
                        {
                            tabuleiro[0][0] = ia;
                        }
                else if (tabuleiro[2][2] == ' ' && ((tabuleiro[2][0] == ia && tabuleiro[2][1] == ia) || (tabuleiro[0][2] == ia && tabuleiro[1][2] == ia) || (tabuleiro[1][1] == ia && tabuleiro[0][0] == ia)))
                        {
                            tabuleiro[2][2] = ia;
                        }
                //CENTRO
                else if (tabuleiro[1][1] == ' ' && ((tabuleiro[0][0] == ia && tabuleiro[2][2] == ia) || (tabuleiro[0][2] == ia && tabuleiro[2][0] == ia) || (tabuleiro[0][1] == ia && tabuleiro[2][1] == ia) || (tabuleiro[1][0] == ia && tabuleiro[1][2] == ia)))
                        {
                            tabuleiro[1][1] = ia;
                        }
                //MEIOS
                else if (tabuleiro[0][1] == ' ' && ((tabuleiro[0][0] == ia && tabuleiro[0][2] == ia) || (tabuleiro[1][1] == ia && tabuleiro[2][1] == ia)))
                        {
                            tabuleiro[0][1] = ia;
                        }
                else if (tabuleiro[1][0] == ' ' &&((tabuleiro[0][0] == ia && tabuleiro[2][0] == ia) || (tabuleiro[1][1] == ia && tabuleiro[1][2] == ia)))
                        {
                            tabuleiro[1][0] = ia;
                        }
                else if (tabuleiro[1][2] == ' ' && ((tabuleiro[0][2] == ia && tabuleiro[2][2] == ia) || (tabuleiro[1][1] == ia && tabuleiro[1][0] == ia)))
                        {
                            
                            tabuleiro[1][2] = ia;
                        }
                else if (tabuleiro[2][1] == ' ' && ((tabuleiro[2][0] == ia && tabuleiro[2][2] == ia) || (tabuleiro[1][1] == ia && tabuleiro[0][1] == ia)))
                        {
                            tabuleiro[2][1] = ia;
                        }                
                

                        //JOGADAS PARA IMPEDIR:
                        //QUINAS
                else if (tabuleiro[0][2] == ' ' && ((tabuleiro[0][0] == jogador && tabuleiro[0][1] == jogador) || (tabuleiro[1][2] == jogador && tabuleiro[2][2] == jogador) || (tabuleiro[2][0] == jogador && tabuleiro[1][1] == jogador)))
                        {
                            tabuleiro[0][2] = ia;
                        }
                else if (tabuleiro[2][0] == ' ' && ((tabuleiro[0][0] == jogador && tabuleiro[1][0] == jogador) || (tabuleiro[2][1] == jogador && tabuleiro[2][2] == jogador) || (tabuleiro[1][1] == jogador && tabuleiro[0][2] == jogador)))
                        {
                            tabuleiro[2][0] = ia;
                        }
                else if (tabuleiro[0][0] == ' ' && ((tabuleiro[0][1] == jogador && tabuleiro[0][2] == jogador) || (tabuleiro[1][0] == jogador && tabuleiro[2][0] == jogador) || (tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)))
                        {
                            tabuleiro[0][0] = ia;
                        }
                else if (tabuleiro[2][2] == ' ' && ((tabuleiro[2][0] == jogador && tabuleiro[2][1] == jogador) || (tabuleiro[0][2] == jogador && tabuleiro[1][2] == jogador) || (tabuleiro[1][1] == jogador && tabuleiro[0][0] == jogador)))
                        {
                            tabuleiro[2][2] = ia;
                        }
                //CENTRO
                else if (tabuleiro[1][1] == ' ' && ((tabuleiro[0][0] == jogador && tabuleiro[2][2] == jogador) || (tabuleiro[0][2] == jogador && tabuleiro[2][0] == jogador) || (tabuleiro[0][1] == jogador && tabuleiro[2][1] == jogador) || (tabuleiro[1][0] == jogador && tabuleiro[1][2] == jogador)))
                        {
                            tabuleiro[1][1] = ia;
                        }
                //MEIOS
                else if (tabuleiro[0][1] == ' ' && ((tabuleiro[0][0] == jogador && tabuleiro[0][2] == jogador) || (tabuleiro[1][1] == jogador && tabuleiro[2][1] == jogador)))
                        {
                            tabuleiro[0][1] = ia;
                        }
                else if (tabuleiro[1][0] == ' ' && ((tabuleiro[0][0] == jogador && tabuleiro[2][0] == jogador) || (tabuleiro[1][1] == jogador && tabuleiro[1][2] == jogador)))
                        {
                            tabuleiro[1][0] = ia;
                        }
                else if (tabuleiro[1][2] == ' ' && ((tabuleiro[1][0] == jogador && tabuleiro[1][1] == jogador) || (tabuleiro[2][2] == jogador && tabuleiro[0][2] == jogador)))
                        {
                            
                            
                            tabuleiro[1][2] = ia;
                        }
                else if (tabuleiro[2][1] == ' ' && ((tabuleiro[2][0] == jogador && tabuleiro[2][2] == jogador) || (tabuleiro[1][1] == jogador && tabuleiro[0][1] == jogador)))
                        {
                            
                            tabuleiro[2][1] = ia;
                        }
                        // CASOS EM QUE DÁ VELHA
                        // SE não existe possibilidade de vencer, jogar em lugar vazio, aleatoriamente.
                         else if(tabuleiro[0][0] == ' ' || tabuleiro[0][1] == ' ' || tabuleiro[0][2] == ' ' || tabuleiro[1][0] == ' ' || tabuleiro[1][1] == ' ' || tabuleiro[1][2] == ' ' || tabuleiro[2][0] == ' ' || tabuleiro[2][1] == ' ' || tabuleiro[2][2] == ' ')
                        {
                            while(1){
                                linha1 = rand() % 3;
                                coluna1 = rand() % 3;
                                if(tabuleiro[linha1][coluna1] == ' '){
                                    break;
                                }
                            }
                    tabuleiro[linha1][coluna1] = ia;
                        }
                }

                    //Verificar vitoria
                    if (verificarVitoria(tabuleiro, jogador)) {
                        printf("-- PLAYER [%c] VENCEU! CONGRATULATIONS!! --\n", jogador);

                        int jogadorExistente = 0;
                            for (int i = 0; i < numJogadores; i++) {
                                if (strcmp(jogadores[i].nome, nome) == 0) {
                                    jogadores[i].vitorias += 1;
                                    jogadorExistente = 1;
                                    break;
                                }
                            }
                        if (!jogadorExistente) {
                                strcpy(jogadores[numJogadores].nome, nome);
                                jogadores[numJogadores].vitorias = 0;
                                jogadores[numJogadores].derrotas = 0;
                                jogadores[numJogadores].vitorias += 1;
                                numJogadores++;
                            }

                            // Ordenar jogadores usando Bubble Sort
                            bubbleSort(jogadores, numJogadores);

                            // Salvar dados no arquivo
                            arquivo = fopen("ranking.txt", "w");
                            if (arquivo != NULL) {
                                for (int i = 0; i < numJogadores; i++) {
                                    fprintf(arquivo, "%s,%d,%d\n", jogadores[i].nome, jogadores[i].vitorias, jogadores[i].derrotas);
                                }
                                fclose(arquivo);
                            } else {
                                printf("Erro ao salvar arquivo.\n");
                            }
                        break;
                    }
                    else if (verificarVitoria(tabuleiro, ia)) {
                        printf("-- IA [%c] VENCEU! CONGRATULATIONS!! --\n", ia);
        
                        int jogadorExistente = 0;
                            for (int i = 0; i < numJogadores; i++) {
                                if (strcmp(jogadores[i].nome, nome) == 0) {
                                    jogadores[i].derrotas += 1;
                                    jogadorExistente = 1;
                                    break;
                                }
                            }
                        if (!jogadorExistente) {
                                strcpy(jogadores[numJogadores].nome, nome);
                                jogadores[numJogadores].vitorias = 0;
                                jogadores[numJogadores].derrotas = 0;
                                jogadores[numJogadores].derrotas += 1;
                                numJogadores++;
                            }

                            // Ordenar jogadores usando Bubble Sort
                            bubbleSort(jogadores, numJogadores);

                            // Salvar dados no arquivo
                            arquivo = fopen("ranking.txt", "w");
                            if (arquivo != NULL) {
                                for (int i = 0; i < numJogadores; i++) {
                                    fprintf(arquivo, "%s,%d,%d\n", jogadores[i].nome, jogadores[i].vitorias, jogadores[i].derrotas);
                                }
                                fclose(arquivo);
                            } else {
                                printf("Erro ao salvar arquivo.\n");
                            }
                        break; 
                        break;
                    }
                    // Verificar empate
                    rodada++;
                    if (rodada == 5) {
                        printf("Empate!\n");
                        int jogadorExistente = 0;
                            for (int i = 0; i < numJogadores; i++) {
                                if (strcmp(jogadores[i].nome, nome) == 0) {
                                    jogadores[numJogadores].vitorias = 0;
                                    jogadores[numJogadores].derrotas = 0;
                                    jogadorExistente = 1;
                                    break;
                                }
                            }
                        if (!jogadorExistente) {
                                strcpy(jogadores[numJogadores].nome, nome);
                                jogadores[numJogadores].vitorias = 0;
                                jogadores[numJogadores].derrotas = 0;
                                numJogadores++;
                            }

                            // Ordenar jogadores usando Bubble Sort
                            bubbleSort(jogadores, numJogadores);

                            // Salvar dados no arquivo
                            arquivo = fopen("ranking.txt", "w");
                            if (arquivo != NULL) {
                                for (int i = 0; i < numJogadores; i++) {
                                    fprintf(arquivo, "%s,%d,%d\n", jogadores[i].nome, jogadores[i].vitorias, jogadores[i].derrotas);
                                }
                                fclose(arquivo);
                            } else {
                                printf("Erro ao salvar arquivo.\n");
                            }
                        break; 
                        break;
                    }
                }
                imprimirTabuleiro(tabuleiro);
                if (rodada == 5) {
                    printf("--- DEU VELHA! ---\n");
                }
                if (verificarVitoria(tabuleiro, ia)) {
                        printf("--- IA [%c] VENCEU! CONGRATULATIONS!! ---\n", ia);}
                if (verificarVitoria(tabuleiro, jogador)) {
                        printf("--- PLAYER [%c] VENCEU! CONGRATULATIONS!! ---\n", jogador);
                        }
                printf("--- END GAME ---\n");
                printf("Aperte 'ENTER' para jogar novamente ou Aperta 'ESC' para voltar");
                while (a != 27 || a != 13){
                if(kbhit){a=getch();}
                if(a == 27){
                    goto inicio;
                }
                if(a == 13){
                    goto jogarnovamente;
                }
                }
        
        break;
    case 2:
        system("cls");
        exibirRanking(jogadores, numJogadores);
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 3:
        system("cls");
        printf("Sobre o Jogo\n\nO jogo da velha eh jogado em um tabuleiro 3x3, onde dois jogadores, geralmente representados pelos simbolos 'X' e 'O', \nalternam entre si para marcar suas jogadas no tabuleiro.\nO objetivo eh formar uma linha, coluna ou diagonal com tres simmbolos iguais (X ou O) antes do outro jogador.\n\nEh importante lembrar que, durante o jogo, os jogadores devem respeitar as seguintes regras: \n- Cada jogador so pode marcar uma celula vazia em sua jogada.\n- Nao eh permitido marcar uma celula que ja foi preenchida anteriormente.\n- Nao eh permitido alterar ou apagar a marcacao feita anteriormente em uma celula. \n\nSeguindo essas regras basicas, os jogadores podem se divertir jogando o jogo da velha.\n\nPressione 'Esc' para voltar");
        gotoxy(0,35);
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 4:
        system("cls");
        printf("Sobre\n\nTitulo: Ultimate Game Of The Velha\nVersao: 1.7.10\nAutores: Felipe Santos, Breno Oliveira\n\nPressione 'Esc' para voltar");
        gotoxy(0,35);
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 5:
        system("cls");
        printf("Voce pediu para sair, fechando programa.");
        gotoxy(0,35);

        for(a=0;a<5;a++){
            printf(".");
            gotoxy(0,30);
            Sleep(1000);
        }
        printf("!\n\n");
		exit(0);
    default:
        system("cls");
        printf("Você deve escolher uma opção válida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
        }
    }while(opcao!=5);

    return 0;
}