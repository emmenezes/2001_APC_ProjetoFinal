#include <stdio.h> /*  biblioteca padrão  */
#include <stdlib.h> /*  usada para a função getchar()  */
#include <string.h> /*  usada para as funções de string, como [^/n]  */
#include <time.h> /*  usada para a geração de números aleatórios  */

typedef struct{
    char nome[21], historia[401];
    int completo, vida, indole, alinhamento, profissao, meta, moradia, van;
    /*  o atributo int completo serve para confirmar que todas as características foram preenchidas  */
} personagem;

personagem piloto;
int criacaop = 0;

/*    Seção de funções tipo void que contém apenas textos    */

void introducao();
void menu();
void saida();
void entradaincorreta();
void sempiloto();
void fimdejogoruim();
void fimdejogobom();

/*    Seção de funções interativas    */

void criacao();
void trescharadas();
void placadavan();

int main(){
    piloto.vida = 100;
    char opcao[1] = {'0'};

    system("clear");
    introducao();
    
    /* getchar() - espera o enter para prosseguir */
    getchar(); 

    while (1){
        system("clear");
        menu();
        scanf("%s", opcao);
        /*  aqui o getchar() le o ENTER para evitar que ele seja lido dentro das opções  */
        getchar();
        switch (opcao[0]) {
        case '1':
        /*  criação de personagem  */
            system("clear");
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

/*  Seção de funções tipo void que contém apenas textos  */

void introducao (){
    printf( "\nSeja bem-vinde ao Choque de Cultura, o RPG\n\n"
            "Clique em ENTER para continuar\n");
}

void menu(){
    printf( "\nHoje, é dia 21/09/19, dia da grande manifestação\n"
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
            "Pode vazar.\n\n");
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

/*  Seção de funções interativas  */

void criacao(){
    int infosalvas = 0;
    printf( "Os pilotos do Choque olham para você do outro lado da manifestação\n"
            "Infelizmente você parece ser a única pessoa a ter uma van\n"
            "E ser facilmente intimidada\n"
            "Se quiser fugir, é só digitar 0 e clicar em ENTER\n"
            "Tudo pronto? Podemos continuar?\n\n"
            "Clique em ENTER para continuar\n\n");
    getchar();

    while (1){
        switch (criacaop)
        {
        case 0:
            /* Primeira vez a colocar um nome */
            system("clear");
            printf( "\nRogerinho: Ei, rapá, qual o teu nome?\n\n"
                    "Simone pelo seu fone de ouvido: ei, aqui tem limite de caractere\n"
                    "não passe dos 20, que se for maior que isso, ele vão esquecer\n"
                    "haha\n\n");
            scanf("%[^\n]", piloto.nome);
           	criacaop = 1;
            break;

        case 1:
            system("clear");
            printf( "\nMaurílio: Mas fala ai, quem que é você?\n\n"
                    "Simone: Bem, aqui você só tem 3 opções,\n"
                    "então escolha com cuidado,\n"
                    "Tô de olho!\n\n");
            printf( "1. Só falo com tranquilidade\n"
                    "2. Me chamam de palestrinha\n"
                    "3. Só trabalho pra dar conforto pro meu filhote\n\n");
            scanf("%d", &piloto.indole);
            criacaop = 2;
            break;
            
        case 2: 
        	system("clear");
        	printf( "\nRenan: Esse cara parece muito estranho, Rogerinho, não confio nele não\n\n"
	                "Simone: Outras 3 opções, você sabe como funciona\n"
	                "Mas fala só para mim, quem é você? De verdade!\n\n");
	        printf( "1. Piloto de van, ué?\n"
	                "2. Ciclista disfarçado...\n"
	                "3. Ex (ou não) motorista de Uber\n\n");
	        scanf("%d", &piloto.alinhamento);
	        criacaop = 3;
	        break;
        
		case 3:
			system("clear");
			printf(	"Julinho: Fala ai o que tu faz, dodói\n\n"
					"Simone: 3 opções, blá, blá, blá...\n\n");
			printf(	"1. Levo os atores do Projac de lá para cá\n"
					"2. Vendo suplementos alimentares de Iguaba\n"
					"3. Conduzo pessoas em um transporte alternativo\n\n");
			scanf("%d", &piloto.profissao);
			criacaop = 4;
	        break;

		case 4: 
			system("clear");
			printf(	"Renan: isso ainda parece muito suspeito\n\n"
					"Simone: joga a real, você dirige por quê?\n\n");
			printf(	"1. Arrumo encrenca com idosos\n"
					"2. Capoto (ou não)\n"
					"3. Vendo meus produtos e familiares a pilotos\n\n");
			scanf("%d", &piloto.meta);
			criacaop = 5;
	        break;

		case 5:
			system("clear");
			printf(	"Maurílio: é o seguinte, como o Renan ainda não confia em ti,\n"
					"fala ai onde tu mora com esse trabalho ai\n\n");
			printf(	"1. Na Kombi\n"
					"2. Terreno da casa da minha avó\n"
					"3. Numa casa sujeita a invasões de lagartos mordedores,\n"
					"com meu filho, fruto de um relacionamento com minha prima de 1º grau\n\n");
			scanf("%d", &piloto.moradia);
			criacaop = 6;
	        break;

		case 6:
			system("clear");
			printf(	"Rogerinho: Mas fala aí, como é que tu chegou aqui\n\n"
					"Simone: e os limites de caractere voltaram!\n\n"
					"Aqui são duzentos e depois já pode me chamar de wiki\n"
					"haha\n\n");
			getchar();
			scanf("%[^\n]", piloto.historia);
			criacaop = 7;
	        break;
	        
	    case 7:
	    	system("clear");
	    	printf(	"Julinho: e como é que a gente vai?\n\n");
	    	printf(	"1. Kombi Branca 84\n"
					"2. Sprinter Branca\n");
			if (piloto.indole != 2){
				printf("3. Towner Azul Bebê\n");
			}
			printf("\n");
			scanf("%d", &piloto.van);
	    	criacaop = 8;
	        break;

        case 9:
            /*  saida padrão, duas opções: apagar tudo ou confirmar tudo  */
            system("clear");
            printf( "Simone: Ihhh, vai sair mesmo?\n"
                    "Não julgo, faria o mesmo\n"
                    "haha\n\n"
                    "Digite 0 e clique ENTER para confirmar\n"
                    "Digite 1 e cloque ENTER para cancelar e voltar à criação\n\n");
            scanf("%d", &criacaop);
            while (criacaop < 0 || criacaop > 1){
                    scanf("%d", &criacaop);
            }
            if (criacaop == 0){
                printf( "Simone: Só mais uma coisinha,\n");
                switch (infosalvas)
                {
                case 0:
                    /* code */
                    printf( "Bem, não tenho nenhuma informaçãos sua.\n"
                            "Pode ir embora mesmo, desconhecido...\n\n");
                    break;
                
                case 1:
                    printf( "Bem, eu já sei o seu nome e vou deixar guardado\n"
                            "Até mais\n");

                case 2:
                    printf( "Sei seu nome e também sua índole"
                            "Te vejo por aí\n");

                case 3:
                    printf( "Sei nome, indole e alinhamento\n"
                            "");


                default:
                    printf( "Ihhh, parece aqui que vocês está muito além do meu código\n"
                            "Que estranho, deveria chamar você de bug?\n"
                            "Volte ao meu, e tente novamente\n\n");
                    break;
                }

                return;
            }
            break;
        }
        
        if (criacaop == 8){
        	piloto.completo = 1;
        	system("clear");
        	printf(	"Simone: bem, olhei a ficha aqui, e parece que está tudo ok\n"
					"Agora já pode ir lá jogar, e se quiser mudar algo, pode também\n\n"
					"Clique ENTER para continuar\n");
			getchar();
        	break;
		}
            /*Sair da carcaterização de personagem*/
        
    }
    getchar();
}
