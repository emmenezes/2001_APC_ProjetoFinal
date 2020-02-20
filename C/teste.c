#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vida = 100;

int main(){
    srand(time(NULL));
	int sorteio[4] = {0}, reserva[4] = {1,1,1,1}, palpite[4] = {0};
	int i, j, k, x, certo, errado, palpitejunto;
	
	system("clear");
	printf("Simone:    É, você é uma pessoa de muita firmeza e ninguém pode contestar");
    getchar();


	/*  Passo 9.1 - Descubra o número - Sorteio dos números  */
	for (i = 0; i < 4; i++)	{
		do {
			x = rand()%10;
		} while (x == sorteio[0] || x == sorteio[1] || x == sorteio[2]);

		sorteio[i] = x;
	}

	/*  Passo 9.2 - Descubra o número - Sorteio dos números  */
    system("clear");
    printf("%d %d %d %d\n", sorteio[3], sorteio[2], sorteio[1], sorteio[0]);
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
		vida -= 10;

        if (certo == 4){
            printf("Parabéns você acertou tudo!\n");
            break;
        } else {
            printf( "\nPalpite %02d        %d certa(s)            %d certa(s) no lugar errado\n"
                    "\nPróximo palpite: ", i+1, certo, errado);
        }

	}
    printf("venceu\n");
	
}