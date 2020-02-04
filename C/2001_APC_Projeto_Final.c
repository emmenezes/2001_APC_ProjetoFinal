/*
APC 2020/0 - Projeto Final
Eduarda Costa de Menezes - 170032353

Este projeto se trata de um jogo de RPG simples, que pode ser dividido assim:
1. Criação de personagem
	1.1 Escolha de características individuais
2. História
	2.1. Narrativas intercaladas
	2.2. Opções que mudam de acordo com as características escolhidas
	2.3. Jogo de perguntas com 3 alternativas, sendo uma certa
	2.4. JOgo de adivinhação de um número de 4 dígitos

Para a narrativa, me baseei no programa Choque de Cultura da TV Quase e por causa dessa decisão,
vários trechos da narrativa não são fluidos e/ou forçados. Espero que isso não estrague muito a experiência.

No mais, o código tenta ser auto-explicativo e no github.com/emmenezes/linguagens/tree/criacao_sc/C há
algum complemento, ainda incompleto.
*/

#include <stdio.h> 		/*  Biblioteca padrão  */
#include <stdlib.h> 	/*  Usada para a função getchar()  */
#include <string.h> 	/*  Usada para as funções de string, como [^/n]  */
#include <time.h> 		/*  Usada para a geração de números aleatórios  */

typedef struct{
    char nome[21], historia[401];
    int completo, vida, indole, alinhamento, profissao, meta, moradia, van;
    /*  O atributo int completo serve para confirmar que todas as características foram preenchidas  */
} personagem;

/*  Criação da variável piloto tipo personagem global para facilitar seu acesso  */
personagem piloto;
/*  Variável usada para o controle da criação de personagem  */
int criacaop = 0;

/*  Seção de funções tipo void que contém apenas textos
	Eu escolhi assim no início para que a função int main() fosse concisa    */

void introducao();
void menu();
void saida();
void entradaincorreta();
void sempiloto();
void fimdejogoruim();
void fimdejogobom();

/*  Seção de funções interativas  
	Nessas funções é possível inserir valores */

void criacao();
void iniciojogo();
void evento2();
void evento3();
void trescharadas();
int charadas(int n);
void placadavan();
void creditos();


/*  Função raiz do jogo  */
int main(){
	/*  Configuração incial do jogo: vida do jogador, entrada no menu, 
	    e captura do horário para os sorteios  */
    piloto.vida = 100;
    char opcao[1] = {'0'};
	srand(time(NULL));

	/*  Início do jogo  */
	/* system("clear") - limpeza de tela, função recorrente  */
    system("clear");
    introducao();
    
    /* getchar() - espera o enter para prosseguir, função recorrente  */
    getchar(); 

    while (1){
		/*  Limpeza da tela, opções do menu e recebe escolha do jogador  */
        system("clear");
        menu();
        scanf("%s", opcao);

        /*  getchar() usado para ler o enter e evitar bugs nas funções  */
        getchar();

        switch (opcao[0]) {
        case '1':
        /*  Criar de personagem  */
            system("clear");
            criacao();
			break;
        
        case '2':
        /*  Iniciar o jogo, mas confere primeiro se há um piloto  */
            system("clear");
            if (piloto.completo == 0){
                sempiloto();
            } else {
            	iniciojogo();
			}
            getchar();
            break;
        
        case '3':
        /*  Sair do jogo  */
            system("clear");
            saida();
            return 0;
            break;

        default:
		/*  Entrada inválida  */
            system("clear");
            entradaincorreta();
            getchar(); 
            break;
        }
    }
    return 0;
}


/*  Seção de funções tipo void com apenas texto
    E apesar do nome, algumas funções assim estão no final para deixar a leitura em ordem cronológica  */

/*  Tela de início do jogo  */
void introducao (){
	printf("\n");
    printf( "           Seja bem-vinde ao Choque de Cultura, o RPG\n\n"
            "           Clique em ENTER para continuar");
}


/*  Menu inicial  */
void menu(){
	printf("\n");
    printf( "           Hoje, é dia 21/09/19, dia da grande manifestação\n"
            "           Dos motoristas do transporte alternativo em Brasília.\n"
            "           E é claro que os pilotos do Choque de Cultura\n"
            "           Não poderiam estar de fora\n\n");

    /*  Menu  */
    printf( "1. Criar um piloto\n"
            "2. Iniciar a missão\n"
            "3. Sair\n\n");
	/*  Essa organização de colocar as opções em um printf separado da narrativa é recorrente  */
}


/*  Tela de saída  */
void saida(){
	printf("\n");
    printf( "Rogerinho: Achou que a gente ia perseguir você?\n"
            "           Achou errado otário!\n"
            "           Pode vazar.\n\n");
}

/*  Tela de entrada incorreta  */
void entradaincorreta(){
	printf("\n");
    printf( "Rogerinho: Que isso rapá!?\n"
            "           Tá achando que isso aqui é um jogo, é?\n"
            "           Escolhe uma opção que existe\n\n"
            "           Clique em ENTER para continuar\n");

}

/*  Tela de início de jogo sem piloto  */
void sempiloto(){
	printf("\n");
    printf( "Renan:     Até Renanzinho é alguém e tu não\n"
            "           Se quiser jogar tem que existir primeiro\n"
			"           Vai lá e cria um piloto logo!\n\n"
            "           Clique em ENTER para continuar");
}

/*  Seção de funções interativas  */

/*  Função de criação de personagem  
	Infelizmente, permite entradas incorretas e não permite voltar ao menu sem terminar o processo  */
void criacao(){
	/*  Aviso inicial a respeito da narradora da história, a Simone dos Prazeres  */
	printf("\n");
    printf( "Simone:    Ei, você, você mesmo, sim, eu estou falando do seu fone de ouvido\n"
			"           Não sei como cheguei aqui, mas acho que tenho que te ajudar\n"		
			"           Vi que os pilotos estão ai, e se eles forem presos, não recebo\n"
			"           Então *limpa a garganta*, vou usar meu poderes onipresentes para te ajudar\n\n"
			"           Agora, os pilotos do Choque olham para você do outro lado da manifestação\n"
            "           Infelizmente você parece ser a única pessoa a ter uma van\n"
            "           E ser facilmente intimidada\n"
            "           Tudo pronto? Podemos seguir?\n\n"
            "Clique em ENTER para continuar");
	
	/*  Aqui a variável completo é zerada, para que toda vez que a função for acessada seja possível refazê-la  */
	piloto.completo = 0;
	getchar();

	/*  A função __fpurge() foi a alternativa que achei a fflush(), ambas servem para limpar o cachê
		em caso de entrada de char logo após int, mas só consegui usar de forma eficiente a primeira  */
	__fpurge(stdin);
	
    while (1){
		switch (criacaop){
			/*  Para lidar com o processo sequencial na criação, usei a estrutura switch apesar de ser equivalente
				a escrever tudo sequencial, pois no início tentei aplicar uma possibilidade de sair da criação
				no meio do processo, de voltar em alguma característica após a primeira tentativa, etc, no entanto
				a tentativa deu errado e eu preferi não deletar e deixei os processos com switch case mesmo
				Ao final de cada decisão a variável criacaop muda para o valor da seguinte  
				
				Nas categorias 3 - Profissão, 4 - Meta, 5 - Moradia e 7 - Van, há limitações decorrentes de 
				escolhas prévias  */

	        case 0:
	        /*  0 - Nome  */
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
	        /*  1 - Índole  */
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
	        /*  2 - Alinhamento  */
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
			/*  3 - Profissão  */
				system("clear");
				printf("\n");
				printf(	"Julinho:   Fala ai o que tu faz, dodói\n\n"
						"Simone:    3 opções, blá, blá, blá...\n\n");
				printf(	"1. Levo o pessoal da Globo de lá para cá\n"
						"2. Conduzo pessoas em um transporte alternativo\n");
				/*  Não há opção de venda para ciclistas  */
				if (piloto.alinhamento != 3){
					printf("3. Vendo suplementos alimentares de Iguaba\n");
				}
				printf("\n");
				scanf("%d", &piloto.profissao);
				criacaop = 4;
		        break;
	
			case 4: 
			/*  4 - Meta  */
				system("clear");
				printf("\n");
				printf(	"Renan:     Isso ainda parece muito suspeito\n\n"
						"Simone:    Joga a real, você dirige por quê?\n\n");
				printf(	"1. Vendo meus produtos e familiares a pilotos\n"
						"2. Capoto (ou não)\n");
				/*  Não há a opção de encrenca para motoristas de Uber  */
				if (piloto.alinhamento != 2){
					printf("3. Arrumo encrenca com idosos\n");
				}
				printf("\n");
				scanf("%d", &piloto.meta);
				criacaop = 5;
		        break;
	
			case 5:
			/*  5 - Moradia  */
				system("clear");
				printf("\n");
				printf(	"Maurílio:  É o seguinte, como o Renan ainda não confia em ti,\n"
						"           Fala ai onde tu mora com esse trabalho ai\n\n");
				printf(	"1. Na Kombi\n"
						"2. Terreno da casa da minha avó\n");
				/*  Não há a opção ter casa para quem vende produtos  */
				if (piloto.profissao != 3){
					printf(	"3. Numa casa sujeita a invasões de lagartos mordedores, com meu filho,\n"
							"fruto de um relacionamento com um parente de 1º grau\n");
				}
				printf("\n");
				scanf("%d", &piloto.moradia);
				criacaop = 6;
		        break;
	
			case 6:
			/*  6 - História  */
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
		    /* 7 - Van */
		    	system("clear");
		    	printf("\n");
		    	printf(	"Julinho:   E como é que a gente vai?\n\n");
		    	printf(	"1. Kombi Branca 84\n"
						"2. Sprinter Branca\n");
				/*  Não há a opção Towner (van do Renan) se for Palestrinha  */
				if (piloto.indole != 2){
					printf("3. Towner Azul Bebê\n");
				}
				printf("\n");
				scanf("%d", &piloto.van);
		    	criacaop = 9;
		        break;
	
	        case 9:
	        /*  Piloto completo, mensagem de confirmação e tela de transição para o menu  */
	            system("clear");
	            printf("\n");
	        	printf(	"Simone:    Bem, olhei a ficha aqui, e parece que está tudo ok\n"
						"           Agora já pode ir lá jogar, e se quiser mudar algo, pode também\n\n"
						"Clique ENTER para continuar");
				getchar();
				piloto.completo = 1;
	            break;
	    } 
	    
		/*  Função que serve para zerar a variável de controle da ordem da estrutura de switch case  */
		if (piloto.completo == 1){
			criacaop = 0;
			break;
		}
    }
	/*  Pausa para transição de tela, técnica recorrente  */
    getchar();
}

/*  1º Momento do Jogo, se refere a narrativa inicial, uma escolha e narrativa seguinte  */
void iniciojogo(){
	/*  A variável "escolha" vai ser comum dentro de cada evento para recebimento da entrada  */
	int escolha = 0;
				
	/*  Passo 1 - Introdução  
		Breve sumário do prefácio da história  */
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
	
	/*  Passo 2 - Evento 1 - Comum para todas as escolhas  
		A primeira escolha é simples e trata apenas da escolha do caminho, todas as alternativas estão certas  */
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
	__fpurge(stdin);
	
	/*  Passo 3 - Narrativa a partir da escolha  
		Só por incremento a narrativa seguinte depende da escolha*/
	system("clear");
	if (escolha == 1){
		printf(	"Simone:    Bem, o Google Maps e Renan estavam certos: pela direita vocês seguiriam de boas\n");
	} else if(escolha == 2){
		printf(	"Simone:    O Maurílio nem é da cidade, mas já manjou tudo, o caminho tava bom\n");
	} else {
		printf(	"Simone:    Se esse é o mais rápido ou não, eu não sei,\n"
				"           Mas foi suave seguir a sugestão de Rogerinho\n");
	}
	printf(	"           Parece que esses motoristas de meia tigela estavam lezando\n"
			"           Toda a polícia deve ter ido para a concentração\n");
	printf(	"\n\nClique em ENTER para continuar");
	getchar();

	/*  Chamada do momento seguinte  */
	evento2();
}

/*  2º Momento do Jogo, se refere a uma escolha que depende do alinhamento e narrativa seguinte */
void evento2(){
	int escolha = 0;
	system("clear");

	/*  Passo 4 - O alinhamento do piloto elimina uma das possibilidades  
		A escolha é a respeito de um tema de conversa, que sempre será menosprezado pelos pilotos  */
	printf(	"Simone:    Como não tem mais discussão, você não acha um bom momento para puxar conversa?\n"
			"           Eu sei, eu sei, o nervosismo de capotar (ou não) não deixa você pensar direito\n"
			"           Aqui tem alguns tópicos que me parecem inofensivos...\n\n");
	
	/*  A proposta pedia que cada alinhamento tivesse uma opção a menos, mas para facilitar as réplicas
		Foi feito um jogo com as entradas para que elas se encaixem em três números sem precisar de mais ifs
		As três possíveis alternativas de resposta e sua numeração corresponde às réplicas:
			1. Essas pistas tão boas, né?
			2. Hoje, parece tranquilo, mas um carro quase me atropelou aqui semana passada
			3. O clima tá bom hoje, né?  */

	if (piloto.alinhamento == 1){
		printf("1. Essas pistas tão boas, né?\n");
		printf("2. Hoje, parece tranquilo, mas um carro quase me atropelou aqui semana passada\n\n");
		scanf("%d", &escolha);
		__fpurge(stdin);
		/*  Para o alinhamento 1, a entrada equivale à réplica  */
	}
	if (piloto.alinhamento == 2){
		printf("1. Hoje, parece tranquilo, mas um carro quase me atropelou aqui semana passada\n");
		printf("2. O clima tá bom hoje, né?\n\n");
		scanf("%d", &escolha);
		__fpurge(stdin);
		escolha++;
		/*  Para o alinhamento 2, a entrada + 1 equivale à réplica  */
	}
	if (piloto.alinhamento == 3){
		printf("1. Essas pistas tão boas, né?\n");
		printf("2. O clima tá bom hoje, né?\n\n");
		scanf("%d", &escolha);
		__fpurge(stdin);
		escolha = escolha == 1 ? escolha : escolha++;
		/*  Para o alinhamento 3, a entrada equivale à réplica se for 1, e se não for, deve ser 3*/
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
	/*  Chamada do momento seguinte  */
	evento3();
}

/*  3º Momento do Jogo, se refere a uma escolha que pode retornar ao 2º Momento e outra que depende da profisssão,
	aém da narrativa seguinte*/
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
		/*  Opção se a profissão for "Levo o pessoal da Globo de lá para cá"  */
		printf ("3. Ir pela direita e comentar que de tanto levar o pessoal da Globo, você sabe de cor o caminho\n");
	} else if (piloto.profissao == 2){
		/*  Opção se a profissão for "Conduzo pessoas em um transporte alternativo"  */
		printf ("3. Ir pela direita e comentar que todo santo dia passa por ali\n");
	} else {
		/*  Opção se a profissão for "3. Vendo suplementos alimentares de Iguaba"  */
		printf ("3. Ir pela direita e comentar sobre seus clientes de suplementos que são daquela região\n");
	}
	printf("\n");
	scanf("%d", &escolha);
	__fpurge(stdin);

	/*  Passo 7 - Narrativa a partir da escolha, sendo que a escolha 1 não ocorre nada,
		a segunda volta para o momento anterior, e a terceira tem uma recepção negativa que não muda em nada  */
	system("clear");
	if (escolha == 1){
		printf("Simone:    Nada de surpeendente acontece, esse era o caminho certo");
	} else if (escolha == 2){
		/*  Narrativa que justifica à volta e tenta justificar a ligação entre os dois pontos  */
		printf(	"Simone:    Ei, aquela placa ali à esquerda, deveríamos passar nela de acordo com o mapa...\n"
				"Rogerinho: Eu disse que era uma direita não tão direita assim!\n"
				"           Agora passamos do ponto, vamos ter que dar o retorno lá longe!\n"
				"           Quantas vezes vou ter que repetir que eu tô entendendo o Google!!!\n"
				"*Renan parte pra cima de Rogeirnho seu mata-leão já testando em Julinho*\n"
				"Renan:     Calma! Mantenha a calma!\n"
				"Simone:    Lá vamos nós de novo...");
		printf(	"\n\nClique em ENTER para continuar");
		getchar();
		evento2();
		return;
	} else {
		printf( "Simone:    Assim, você acertou o caminho, beleza\n"
				"           Isso não que dizer que eles receberam bem esse teu comentário aí...");
	}

	printf(	"\n\nClique em ENTER para continuar");
	getchar();
	/*  Chamada do momento seguinte  */
	trescharadas();
}

/*  4º Momento do Jogo, se refere ao jogo das três charadas
	Para deixar a função mais focada em funcionalidade, as perguntas e respostas estão na função charadas()  */
void trescharadas(){
	/* CONTINUAR AQUI */
	int sorteio[3] = {0}; /* variável de controle para evitar perguntas repetidas */
	int n = 1; /* charada sorteada */
	int resposta = 0, i;

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
		do {
			n = rand()%15 + 1;  /*sorteio de 15, sendo que começa em 1 */
		} while (n == sorteio[0] && n == sorteio[1]);
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
		printf(	"Renan:     Qual o nome lo livro do Rambo?\n\n");
		printf(	"1. Rambo\n"
				"2. Rambo, o livro\n"
				"3. O livro do Rambo\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 1){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 2){
		printf(	"Rogerinho: O que não é cultura jovem?\n"
				"           E Renan, você sabe muito bem que não é!\n\n");
		printf(	"1. Slack line e Bruno de Luca\n"
				"2. Skate e Destruição\n"
				"3. Urso\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 3){
		printf(	"Julinho:   Qual o filme obviamente mais complexo?\n\n");
		printf(	"1. Laranja mecânica\n"
				"2. 2001 - Uma odisseia no espaço\n"
				"3. Se eu fosse você 2\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 3){
			return 1;
		} else {
			return 0;
		}
	}
	if (n == 4){
		printf(	"Maurílio:  A justiça...?\n");
		printf(	"1. É justa\n"
				"2. Tem que acabar\n"
				"3. Existe\n\n");
		scanf(" %i", &entrada);
		__fpurge(stdin);
		if (entrada == 2){
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
	int sorteio[4] = {0}, reserva[4] = {1,1,1,1}, palpite[4] = {0};
	int i, j, k, x, certo, errado, palpitejunto, fim = 0;
	
	system("clear");
	printf(	"Simone:    É, você é uma pessoa de muita firmeza e ninguém pode contestar\n"
			"           E sabe o que tem  na frente uma blitz! Mas esses pilotos já viram milhares assim...\n"
			"           Eles não tão nem aí pra quem tá no carro (você ouviu o suspiro de alívio do Maurílio, né?)\n"
			"           Eles querem confirmar a placa do carro e só, e isso você sabe!\n"
			"           ...\n           ...\n"
			"           Eu não acredito que você não sabe...\n"
			"           Pela fé, eu acho que eles vão te dar uma colher de chá, mas fica de olho\n"
			"           Eu já disse que essa van tem limite!\n\n"
			"Clique ENTER para continuar");
    getchar();
	system("clear");

	/*  Passo 9.1 - Descubra o número - Sorteio dos números  */
	for (i = 0; i < 4; i++)	{
		do {
			x = rand()%10;
		} while (x == sorteio[0] || x == sorteio[1] || x == sorteio[2]);

		sorteio[i] = x;
	}

	/*  Passo 9.2 - Descubra o número - Advinhe os números  */

	/* Descomente a linha debaixo para receber o valor sorteado
    printf("%d %d %d %d\n", sorteio[3], sorteio[2], sorteio[1], sorteio[0]); */

	printf("Simone:    Que os palpites comece: ");
	for (i = 0; i < 10; i++) {
		/*  Reset das variáveis de controle  */
        reserva[0] = 1;
        reserva[1] = 1;
        reserva[2] = 1;
        reserva[3] = 1;
        certo = 0;
        errado = 0;

        /*  Recepção do palpite e separação por dígito  */
		scanf("%i", &palpitejunto);
        palpite[3] = palpitejunto/1000;
        palpite[2] = (palpitejunto/100)%10;
        palpite[1] = (palpitejunto%100)/10;
        palpite[0] = palpitejunto%10;
		__fpurge(stdin);

        /*  Primeiro confere quais os números estão certos nos locais certos  */
		for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++){
                if(palpite[j] == sorteio[k] && reserva[k] == 1 && j == k){
                    reserva[j] = 0;
                    certo++;
                }
            }
		}

        /*  Depois confere quais dos números restantes estão certos nos locais errados  */
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++){
                if(palpite[j] == sorteio[k] && reserva[k] == 1){
                    reserva[k] = 0;
                    errado++;
                }
            }
		}

		/*  Imprime o resultado do palpite e a vida restante  */
		piloto.vida -= 10;
        
		if (piloto.vida <= 0){
			printf(	"Simone:    EU FALEI QUE A DROGA DESSA VAN TINHA LIMITE!\n"
					"*A conexão falhou bem na hora para poupar você de ouvir toda a bronca*\n\n"
					"Clique ENTER para continuar");
			getchar();
			fim = 0;
			break;
		} else if (certo == 4) {
            printf(	"\nSimone:    E É POR ISSO QUE O BRASILEIRO EXISTE,\n"
					"           É PORQUE ELE NÃO DESISTE NUNCA!!!\n"
					"           Graças a você sobrevivmentos e podemos continuar pela estrada, amém\n\n"
					"Clique ENTER para continuar");
			fim = 1;
			getchar();
            break;
        } else {
            printf( "\nSimone:    Esse foi o palpite %02d, sendo    %d certa(s)    %d certa(s) no lugar errado\n"
					"           Essa van ainda tem o limite de %d%%"
                    "\n\nSimone:    Próximo palpite: ", i+1, certo, errado, piloto.vida);
        }

	}

	if (fim){
		fimdejogobom();
	} else {
		fimdejogoruim;
	}
}

void fimdejogobom(){
	system("clear");
	printf(	"Simone:    É motorista, me parece que essa aventura que vivemos juntos está acabando...\n"
			"           Eu sei, eu sei, eu nem deveria me emocionar, mal nos conhecemos...\n"
			"           Mas passamos por tantas emoções juntos, você tomou tantas decisões erradas!!\n"
			"           É isso, acho que não tenho mais nada a dizer\n"
			"           Pelo parabrisa dá pra ver que vocês já devem estar na metade do caminho para o Rio\n"
			"           Eu vou embora, porque eu sei que você sabe se virar..\n"
			"           Até mais, guerreirinho...\n\n"
			"Rogerinha: Ei, rapá, devido tuas habilidades aí, a gente tava pensando..."
			"           Você não quer entrar pro choque não?\n"
			"           Tamo precisando de alguém de confiança, e olha, você parece decente\n"
			"Simone:    É piloto, isso me parece o início de outra viagem, mas não vai ser nesse jogo aqui não!\n\n"
			"Clique ENTER para continuar");
	getchar();
	creditos();
}

void fimdejogoruim(){
	system("clear");
	printf("fim bom\n");
	getchar();
}

void creditos(){
	system("clear");
	printf(	"Eduarda:   Olá, pessoa que jogou! Tudo bem com você?\n"
			"           Espero que você tenha tido pelo menos uma experiência não entediante\n"
			"           E tenha aproveitado essa aventura bem simples que preparei\n"
			"           O quinteto protagonista desse mistura de RPG x Fanfic x Buzzfeed é da TV Quase\n"
			"           Baseado no magnífico programa \"Choque de Cultura \"\n\n"
			"           E só por curiosidade a manifestação do dia 21/09/2019 realmente aconteceu\n"
			"           Mas é mais comum achar as que aconteceram em Paris e Hong Kong no mesmo dia\n\n"
			"           E por enquanto, é isso! Esse é o meu recado final!\n"
			"           Até mais\n\n"
			"Clique...");
	
	getchar();
	main();
}