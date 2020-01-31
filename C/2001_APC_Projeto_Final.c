#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[21], historia[401];
    int indole, alinhamento, profissao, meta, moradia, van;
} personagem;

personagem piloto = {0};

/*  Nessa seção de funções tipo void, 
    estão menus, entre outros textos    */

void introducao();
void menu();
void sair();

int main(){
    char opcao;

    introducao();
    getchar();
    while (1){
        menu();
        system("cls");
        scanf("%c", &opcao);
        switch (opcao) {
        case '1':
            /* code */
            break;
        
        case '2':
            /* code */
            break;
        
        case '3':
            return 0;
            /* code */
            break;

        default:
            break;
        }


    }
    
    return 0;
}

void introducao (){
    printf( "Seja bem-vinde ao Choque de Cultura, o RPG\n"
            "Clique em ENTER para continuar\n");
}

void menu(){
    printf( "Hoje, é dia 21/09/19, dia da grande manifestação\n"
            "dos motoristas do transporte alternativo.\n"
            "E é claro que os pilotos do Choque de Cultura\n"
            "não poderiam estar de fora\n");

    /* Menu */
    printf( "1. Criar um piloto\n"
            "2. Iniciar a missão\n"
            "3. Sair\n\n");
}

void sair(){

}