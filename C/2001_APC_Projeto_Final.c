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
void iniciojogo();
void evento2();
void evento3();
void trescharadas();
int charadas(int n);
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
            } else {
            	iniciojogo();
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
	printf("\n");
    printf( "           Seja bem-vinde ao Choque de Cultura, o RPG\n\n"
            "           Clique em ENTER para continuar");
}

void menu(){
	printf("\n");
    printf( "           Hoje, é dia 21/09/19, dia da grande manifestação\n"
            "           Dos motoristas do transporte alternativo.\n"
            "           E é claro que os pilotos do Choque de Cultura\n"
            "           Não poderiam estar de fora\n\n");

    /* Menu */
    printf( "1. Criar um piloto\n"
            "2. Iniciar a missão\n"
            "3. Sair\n\n");
}

void saida(){
	printf("\n");
    printf( "Rogerinho: Achou que a gente ia perseguir você?\n"
            "           Achou errado otário!\n"
            "           Pode vazar.\n\n");
}

void entradaincorreta(){
	printf("\n");
    printf( "Rogerinho: Que isso rapá!?\n"
            "           Tá achando que isso aqui é um jogo, é?\n"
            "           Escolhe uma opção que existe\n\n"
            "           Clique em ENTER para continuar\n");

}

void sempiloto(){
	printf("\n");
    printf( "Renan:     Até Renanzinho é alguém e tu não\n"
            "           Se quiser jogar tem que existir primeiro\n\n"
            "           Clique em ENTER para continuar\n");
}

/*  Seção de funções interativas  */

void criacao(){
	printf("\n");
    printf( "Simone:    Ei, você, você mesmo, sim, eu estou falando do seu fone de ouvido\n"
			"           não sei como cheguei aqui, mas acho que tenho que te ajudar\n"		
			"           Vi que os pilotos estão ai, e se eles forem presos, não recebo\n"
			"           Então *limpa a garganta*, vou usar meu poderes onipresentes para te ajudar\n"
			"           Agora, os pilotos do Choque olham para você do outro lado da manifestação\n"
            "           Infelizmente você parece ser a única pessoa a ter uma van\n"
            "           E ser facilmente intimidada\n"
            "           Tudo pronto? Podemos seguir?\n\n"
            "Clique em ENTER para continuar\n\n");
	piloto.completo = 0;
	getchar();
	__fpurge(stdin);
	
    while (1){
		switch (criacaop){
	        case 0:
	        /*  Nome  */
	            system("clear");
	            printf("\n");
	            printf( "Rogerinho: Ei, rapá, qual o teu nome?\n\n"
	                    "Simone:    Ei, aqui tem limite de caractere\n"
	                    "           Não passe dos 20, que se for maior que isso, ele vão esquecer\n"
	                    "           haha\n\n");
	            scanf(" %[^\n]", piloto.nome);
	           	criacaop = 1;
	            break;
	
	        case 1:
	        /*  Índole  */
	            system("clear");
	            printf("\n");
	            printf( "Maurílio: Mas fala ai, quem que é você, %s?\n\n"
	                    "Simone:    Bem, aqui você só tem 3 opções,\n"
	                    "           Então escolha com cuidado,\n"
	                    "           Tô de olho!\n\n", piloto.nome);
	            printf( "1. Só falo com tranquilidade\n"
	                    "2. Me chamam de palestrinha\n"
	                    "3. Só trabalho pra dar conforto pro meu filhote\n\n");
	            scanf("%d", &piloto.indole);
	            criacaop = 2;
	            break;
	            
	        case 2: 
	        /*  Alinhamento  */
	        	system("clear");
	        	printf("\n");
	        	printf( "Renan:     Esse cara parece muito estranho, Rogerinho, não confio nele não\n\n"
		                "Simone:    Outras 3 opções, você sabe como funciona\n"
		                "           Mas fala só para mim, quem é você? De verdade!\n\n");
		        printf( "1. Piloto de van, ué?\n"
		                "2. Ex (ou não) motorista de Uber\n"
		                "3. Ciclista disfarçado...\n\n");
		        scanf("%d", &piloto.alinhamento);
		        criacaop = 3;
		        break;
	        
			case 3:
			/*  Profissão  */
				system("clear");
				printf("\n");
				printf(	"Julinho:   Fala ai o que tu faz, dodói\n\n"
						"Simone:    3 opções, blá, blá, blá...\n\n");
				printf(	"1. Levo o pessoal da Globo de lá para cá\n"
						"2. Conduzo pessoas em um transporte alternativo\n");
				if (piloto.alinhamento != 3){
					printf("3. Vendo suplementos alimentares de Iguaba\n");
				}
				printf("\n");
				scanf("%d", &piloto.profissao);
				criacaop = 4;
		        break;
	
			case 4: 
			/*  Meta  */
				system("clear");
				printf("\n");
				printf(	"Renan:     Isso ainda parece muito suspeito\n\n"
						"Simone:    Joga a real, você dirige por quê?\n\n");
				printf(	"1. Vendo meus produtos e familiares a pilotos\n"
						"2. Capoto (ou não)\n");
				if (piloto.alinhamento != 2){
					printf("3. Arrumo encrenca com idosos\n");
				}
				printf("\n");
				scanf("%d", &piloto.meta);
				criacaop = 5;
		        break;
	
			case 5:
			/*  Moradia  */
				system("clear");
				printf("\n");
				printf(	"Maurílio:  É o seguinte, como o Renan ainda não confia em ti,\n"
						"           Fala ai onde tu mora com esse trabalho ai\n\n");
				printf(	"1. Na Kombi\n"
						"2. Terreno da casa da minha avó\n");
				if (piloto.profissao != 3){
					printf(	"3. Numa casa sujeita a invasões de lagartos mordedores, com meu filho,\n"
							"fruto de um relacionamento com minha prima de 1º grau\n");
				}
				printf("\n");
				scanf("%d", &piloto.moradia);
				criacaop = 6;
		        break;
	
			case 6:
			/*  História  */
				system("clear");
				printf("\n");
				printf(	"Rogerinho: Mas fala aí, como é que tu chegou aqui\n\n"
						"Simone:    E os limites de caractere voltaram!\n"
						"           Aqui são 400 e depois já pode me chamar de sua wiki pessoal\n"
						"           haha\n\n");
				getchar();
				scanf("%[^\n]", piloto.historia);
				criacaop = 7;
		        break;
		        
		    case 7:
		    /* Van */
		    	system("clear");
		    	printf("\n");
		    	printf(	"Julinho:   E como é que a gente vai?\n\n");
		    	printf(	"1. Kombi Branca 84\n"
						"2. Sprinter Branca\n");
				if (piloto.indole != 2){
					printf("3. Towner Azul Bebê\n");
				}
				printf("\n");
				scanf("%d", &piloto.van);
		    	criacaop = 9;
		        break;
	
	        case 9:
	        /*  Piloto completo  */
	            system("clear");
	            printf("\n");
	        	printf(	"Simone:    Bem, olhei a ficha aqui, e parece que está tudo ok\n"
						"           Agora já pode ir lá jogar, e se quiser mudar algo, pode também\n\n"
						"Clique ENTER para continuar");
				getchar();
				piloto.completo = 1;
	            break;
	    } 
	    
		if (piloto.completo == 1){
			criacaop = 0;
			break;
		}
    }
    getchar();
}

void iniciojogo(){
	int evento = 1, escolha = 0;
				
	/*  Passo 1 - Introdução  */
	printf(	"Simone:    Bem, imagino que você saiba muito bem onde isso começou...\n"
			"           Foi naquela manifestação, você e sua vanzinha estavam tranquilos\n"
			"           Viam tudo longe do fuzuê, mas um burburinho alto começou\n"
			"           E quando se deu conta, já tava tendo pauladas para todo lado\n"
			"           Você pensou em fugir na hora, como qualquer um, e parecia que\n"
			"           Só a sua van tava intacta e foi por isso que você chegou aqui!\n"
			"           Nem deu tempo de fugir direito que os 4 pilotos do choque já te perseguiam:\n"
			"Rogerinho: Vamo vazar que o Maurílio não pode ficar foragido de novo\n"
			"Simone:    E vocês correram na hora!\n"
			"           Bem, agora que eles já conhecem você, e todo mundo já entrou no carro\n"
			"           Vocês tão longe da manifestação agora\n"
			"           Podemos seguir com um pouco de paz, eu acho...\n\n");
	printf("Clique em ENTER para continuar");
	getchar();
	
	/*  Passo 2 - Evento 1 - Comum para todas as escolhas  */
	system("clear");
	printf(	"Julinho:   Quem que cê tá fazendo, Rogerinho, não é essa via não!\n"
			"Rogerinho: Você acha que não sei usar um GPS?!\n"
			"Maurílio:  Se a polícia me pegar, vou mandar prender vocês também\n"
			"Renan:     Maurílio, olha o que você tá falando\n"
			"*Renan tira o celular da mão de Rogerinho*\n"
			"Renan:     Aqui diz que é só dobrar a direita\n"
			"Maurílio:  É isso que eu tá falando, na direita tem uma blitz!\n"
			"           Tem que ir pela esquerda\n"
			"Rogerinho: Eu já falei, e volto a repetir, se formos pelo viaduto\n"
			"           Vai se mais rápido e nem passamos pela polícia\n"
			"Julinho:   Aí, dodói, tu que é da cidade, fala logo pra esses imbecis o melhor caminho:\n\n");
	printf( "1. Seguir pela direita, como o Renan diz\n"
			"2. Ir pela esquerda, como o Maurílio falou\n"
			"3. Passa pelo viaduto, como o Rogerinho apontou\n\n");
	scanf("%d", &escolha);
	
	/*  Passo 3 - Narrativa a partir da escolha  */
	system("clear");
	if (escolha == 1){
		printf(	"Simone:    Bem, o Google Maps e Renan estavam certos: pela direita vocês seguriam de boas\n");
	} else if(escolha == 2){
		printf(	"Simone:    O Maurílio nem é da cidade, mas já manjou tudo, o caminho tava bom\n");
	} else {
		printf(	"Simone:    Se esse é o mais rápido ou não, eu não sei, mas foi suave seguir a sugestão de Rogerinho\n");
	}
	printf(	"           Parece que esses motoristas de meia tigela estavam lezando\n"
			"           Toda a polícia deve ter ido para a concentração\n");
	printf(	"\n\nClique em ENTER para continuar");
	getchar();
	getchar();
	
	evento2();
}

void evento2(){
	int escolha = 0;

	system("clear");

	/*  Passo 4 - O alinhamento do piloto elimina uma das possibilidades  */
	printf(	"Simone:    Como não tem mais discussão, você não acha um bom momento para puxar conversa?\n"
			"           Eu sei, eu sei, o nervosismo de capotar (ou não) não deixa você pensar direito\n"
			"           Aqui tem alguns tópicos que me parecem inofensivos...\n\n");
	
	if (piloto.alinhamento == 1){
		printf("1. Essas pistas tão boas, né?\n");
		printf("2. Hoje, parece tranquilo, mas um carro quase me atropelou aqui semana passada\n\n");
		scanf("%d", &escolha);
	}
	if (piloto.alinhamento == 2){
		printf("1. Hoje, parece tranquilo, mas um carro quase me atropelou aqui semana passada\n");
		printf("2. O clima tá bom hoje, né?\n\n");
		scanf("%d", &escolha);
		escolha++;
	}
	if (piloto.alinhamento == 3){
		printf("1. Essas pistas tão boas, né?\n");
		printf("2. O clima tá bom hoje, né?n\n");
		scanf("%d", &escolha);
		escolha = escolha == 1 ? escolha : escolha++;
	}

	/*  Passo 5 - Narrativa a partir da escolha  */
	system("clear");
	if (escolha == 1){
		printf(	"Julinho:   Rapaz, sendo sincero contigo, eu prefiro a minha emoção lá no rio\n"
				"           Cheio de morro pra tudo quanto é lado, é radical\n"
				"Renan:     E radical é jovem, %s!", piloto.nome);
	} else if(escolha == 2){
		printf(	"Rogerinho: ATROPELADO?! Como assim atropelado!?\n"
				"           Como um piloto de primeira é quase atropelado\n"
				"           Se você dissesse que quase atropelou alguém aí tudo bem, mas assim não dá\n"
				"           Espero que tenha sido para substituir um pneu hein...");
	} else {
		printf(	"Simone:    Vixi, dá onde você tirou que isso era uma boa opção??\n"
				"           Só porque você podia escolher, não quer dizer que era para escolher isso!\n"
				"           Agora eles vão ficar olhando torto para você por todo o caminho...");
	}
	printf(	"\n\nClique em ENTER para continuar");
	getchar();
	getchar();
	evento3();
	
}

void evento3(){
	int escolha = 0;

	system("clear");

	/*  Passo 6 - Das três alternativas, uma volta ao evento 2 e outra é determinada pela profissão  */
	printf(	"Simone:    Retas e mais retas à sua frente, não se preocupe\n"
			"           Estou com uma sensação que alguém dormiu no banco de trás\n"
			"           Até poderia pedir para você ver quem foi, mas não quero saber, sério...\n\n"
			"Simone:    E a lá, parece que tem uma tesourinha chegando.\n"
			"Julinho:   Rapaz, que coisa esquisita essas voltinhas, eu não tô entendendo nada\n"
			"Rogerinho: Aqui diz que é só dobrar à direita, mas não tão à direita assim\n"
			"Renan:     Como não tão à direita assim, isso existe?\n"
			"Rogerinho: Existe! Tá aqui no aplicativo ó\n"
			"Simone:    Bem, é você que tá dirigindo, não me julgue e faça algo que senão você vai passar\n\n");
	printf( "1. Ir pela a direita não tão à direita assim sem dizer nada\n"
			"2. Ir pela direita tão à direita assim, só para testar\n");
	if (piloto.profissao == 1){
		printf ("3. Ir pela direita e comentar que de tanto levar o pessoal da Globo, você sabe de cor o caminho\n");
	} else if (piloto.profissao == 2){
		printf ("3. Ir pela direita e comentar sobre seus clientes de suplementos que são daquela região\n");
	} else {
		printf ("3. Ir pela direita e comentar que todo santo dia passa por ali\n");
	}
	printf("\n");
	scanf("%d", &escolha);

	/*  Passo 7 - Narrativa a partir da escolha  */
	system("clear");
	if (escolha == 1){
		printf("Simone:    Nada de surpeendente acontece, esse era o caminho certo");
	} else if (escolha == 2){
		printf(	"Simone:    Ei, aquela placa ali à esquerda, deveríamos passar nela de acordo com o mapa...\n"
				"Rogerinho: Eu disse que era uma direita não tão direita assim!\n"
				"           Agora passamos do ponto, vamos ter que dar o retorno lá longe!\n"
				"           Quantas vezes vou ter que repetir que eu tô entendendo o Google!!!\n"
				"*Renan parte pra cima de Rogeirnho seu mata-leão já testando em Julinho*\n"
				"Renan:     Calma! Mantenha a calma!\n"
				"Simone:    Lá vamos nós de novo...");
		printf(	"\n\nClique em ENTER para continuar");
		getchar();
		getchar();
		evento2();
		return;
	} else {
		printf( "Simone:    Assim, você acertou o caminho, beleza\n"
				"           Isso não que dizer que eles receberam bem esse teu comentário aí...");
	}

	printf(	"\n\nClique em ENTER para continuar");
	getchar();
	getchar();
	trescharadas();
}

void trescharadas(){
	int sorteio[3] = {0}; /* variável de controle para evitar perguntas repetidas */
	int n = 1; /* charada sorteada */
	int resposta = 0, i;
	srand(time(NULL));

	system("clear");

	/*  Passo 8.1 - Evento das três charadas - Introdução  */
	printf(	"Simone:    E mais um momento de paz se inicia na van...\n"
			"           Mas você sente que tem algo de estranho, né? Eu também, eu também... \n"
			"           ...\n"
			"Renan:     Você é dessa cidade né... Você não tá pensando em raptar a gente não, né?\n"
			"Simone:    Esse riso aí não vai disfarçar não, sua estranheza, vossa senhoria.\n"
			"Maurílio:  Faz assim, você disse que já conheci a gente, né %s,\n"
			"           Por que você não responde umas perguntinhas, só pra testar?\n"
			"Simone:    Isso não foi uma sugestão...\n"
			"           Você está ok para lidar com umas três perguntinhas simples só para avaliar o seu caráter\n\n"
			"           haha\n"
			"           Não, isso não é brincadeira\n\n", piloto.nome);
	printf ("Clique em ENTER para continuar");
	getchar();
	/*  Passo 8.2 - Evento das três charadas - Charadas  */
	for (i = 0; i < 3; i++){
		system("clear");
		/*do {
			n = rand%15 + 1;  sorteio de 15, sendo que começa em 1 
		} while (n != sorteio[0] && n != sorteio[1])*/
		sorteio[i] = 1;
		resposta = charadas(n);
		printf("\n");
		if (resposta){
			printf(	"Simone:    Tirou de letra, rapá! É isso que eu gosto de ver!\n"
					"           Seu palpite foi tão certeiro que nem piscou!\n");
		} else {
			piloto.vida -= 10;
			printf( "Simone:    E esses sinais de nervosismos, aí, são por quê?\n"
					"           Eu vi esse olho aí tremendo, essa mão que quase puxou a marcha errada\n");
			if (i == 0){
				printf(	"           Esse tua lateral arranhou e saiba que isso aqui não é GTA pra você ficar batendo, hein?\n"
						"           Essa van tem limite e agora tá em %d%%...", piloto.vida);
			} else if (i == 1){
				printf(	"           Sentiu uma parte do motor raspando naquele quebra-molas, né?\n"
						"           Essa van tem limite e agora tá em %d%%...", piloto.vida);
			} else {
				printf( "           Hmmm, esse teu retrovisor direito quase foi levado pelo poste...\n"
						"           Essa van tem limite e agora tá em %d%%...", piloto.vida);
			}
		}
		printf ("\nClique em ENTER para continuar");
		getchar();
	}
	
	system("clear");
	printf(	"Simone:    Apesar dos pesares, essa van ainda aguenta o resto da aventura com %d%%\n\n"
			"           Ou será que não?\n\n", piloto.vida);
	printf ("\nClique em ENTER para continuar");
	getchar();

	placadavan();
}

int charadas(int n){
	int entrada = 0;
	if (n == 1){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 2){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 3){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 4){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 5){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 6){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 7){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 8){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 9){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 10){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 11){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 12){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 13){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 14){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 15){
		printf(	"teste\n"
				"teste\n");
		printf(	"1. errada\n"
				"2. errada\n"
				"3. certa\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
}

void placadavan(){
	system("clear");
	printf("Chegou aqui\n\n");
}