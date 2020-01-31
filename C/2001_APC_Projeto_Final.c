#include <stdio.h> /*  biblioteca padrão  */
#include <stdlib.h> /*  usada para a função getchar()  */
/**/

typedef struct{
    char nome[21], historia[401];
    int indole, alinhamento, profissao, meta, moradia, van, completo;
    /*  o atributo int completo serve para confirmar que todas as características foram preenchidas  */
} personagem;

personagem piloto = {0};

/*    Seção de funções tipo void que contém apenas textos    */

void introducao();
void menu();
void saida();
void entradaincorreta();
void sempiloto();

/*    Seção de funções interativas    */

void criacao();

int main(){
    char opcao;

    system("clear");
    introducao();
    
    /* getchar() - espera o enter para prosseguir */
    getchar(); 

    while (1){
        system("clear");
        menu();
        scanf(" %c", &opcao);
        /*  aqui o getchar() le o ENTER para evitar que ele seja lido dentro das opções  */
        getchar();
        switch (opcao) {
        case '1':
        /*  criação de personagem  */
            system("clear");
            getchar();
            criacao();
            break;
        
        case '2':
        /*  iniciar o jogo, mas confere primeiro se há um piloto  */
            system("clear");
            if (piloto.completo == 0){
                sempiloto();
            }
            getchar();
            break;
        
        case '3':
        /*  sair do jogo  */
            system("clear");
            saida();
            return 0;
            break;

        default:
            system("clear");
            entradaincorreta();
            getchar(); 
            break;
        }


    }
    
    return 0;
}

void introducao (){
    printf( "\nSeja bem-vinde ao Choque de Cultura, o RPG\n\n"
            "Clique em ENTER para continuar\n");
}

void menu(){
    printf( "\nHoje, é diaa 21/09/19, dia da grande manifestação\n"
            "dos motoristas do transporte alternativo.\n"
            "E é claro que os pilotos do Choque de Cultura\n"
            "não poderiam estar de fora\n\n");

    /* Menu */
    printf( "1. Criar um piloto\n"
            "2. Iniciar a missão\n"
            "3. Sair\n\n");
}

void saida(){
    printf( "\nRogerinho: achou que a gente ia perseguir você?\n"
            "Achou errado otário!\n"
            "Pode vazar.\n");
}

void entradaincorreta(){
    printf( "\nRogerinho: que isso rapá!?\n"
            "Tá achando que isso aqui é um jogo, é?\n"
            "Escolhe uma opção que existe\n\n"
            "Clique em ENTER para continuar\n");

}

void sempiloto(){
    printf( "\nRenan: até Renanzinho é alguém e tu não\n"
            "Se quiser jogar tem que existir primeiro\n\n"
            "Clique em ENTER para continuar\n");
}

void criacao(){
    
}