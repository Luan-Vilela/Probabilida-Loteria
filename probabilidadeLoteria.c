#include <stdio.h>

#define MAX 10000


float probabilidade(float sorteio, float numMax);
int maqSorteia(int jogo[MAX][MAX], int aposta, int cartelas, int numMax);
int troca_sucessivas(int cartelas, int n, int v[MAX][MAX]);




//probabilidade c60,6 = 60*59*58*57*56*55/6*5*4*3*2*1

int main(){
	int i, j, k;
	int numMax, sorteio;
	int aposta, cartelas;

	//numero máximo que pode ser soteado
	printf("Digite o número máximo da cartela: ");	
	scanf("%d", &numMax);
		//quantos números a maáquina vai sortear
	printf("Digite quantos número a máquina vai sortear: ");	
	scanf("%d", &sorteio);	
		// quantos números vai jogar por cartela
	printf("Quantos números vai assinalar: ");
	scanf("%d,", &aposta);
		// quantas cartelas vao ser jogadas
	printf("Quantas cartelas vai fazer: ");
	scanf("%d,", &cartelas);
		//mostra possibilidade de ganho 1 e n
	printf("Possibilidade de sorteio 1 em %d.\n", (int) probabilidade(sorteio, numMax));
	
		//seta cartela em 1 caso seja menor que 1
	if(cartelas < 1)	
		cartelas = 1;
	
	int jogo[cartelas][aposta];

	//********gera cartelas***********

	int trava = 1, aux;

	//gerar cartela aleatoria
	srand( (unsigned)time(NULL) );

	for(i = 0; i < cartelas; i++)
		for(j = 0; j < aposta; j++){
			//Cria uma trava caso o n° já tenha saido vai ficar sorteano
			//um novo n°, até sair n° inédito 
			trava = 1;    			
			while(trava){
			 	aux = rand() % numMax + 1;
			 	trava = 0;
			 	for(k = 0; k < aposta; k++){
			 		if(aux == jogo[i][k])
			 			trava = 1;
			 	}

			 	if(trava == 0){
			 		jogo[i][j] = aux;
			 	}
			 	
			}
		}

	//*************fim gera cartelas*********************
		troca_sucessivas(cartelas, aposta, jogo);

	for(i = 0; i < cartelas; i++){
		printf("\n");
		for(j = 0; j < aposta; j++)
			printf("%d ", jogo[i][j]);

	}
	printf("\n");





	return 0;
}
int troca_sucessivas(int cartelas, int n, int v[MAX][MAX]){
	int i, j,k, aux;
	
	for(k = 0; k < cartelas; k++)
		for(i = n-1; i > 0; i--)
			for(j=0; j < i; j++)
				if(v[k][j] > v[k][j+1]){
					printf("%d ", v[k][j]);
					aux = v[k][j];
					v[k][j] = v[k][j+1];
					v[k][j+1] = aux;
				}


	return 0;


}


int maqSorteia(int jogo[MAX][MAX], int aposta, int cartelas, int numMax){	
	//	jogo[i][j] = rand() % numMax + 1;
	int trava = 1, aux;
	int i, j, k;
	//gerar cartela aleatoria
	srand( (unsigned)time(NULL) );
/*
	for(i = 0; i < cartelas; i++)
		for(j = 0; j < aposta; j++)
			trava = 1;
			while(trava){
			 	aux = rand() % numMax + 1;
			 	trava = 0;
			 	for(k = 0; k < aposta; k++){
			 		if(aux == jogo[i][k])
			 			trava = 1;
			 	}

			 	if(trava == 0)
			 		jogo[i][j] = aux;
			 	
			}
			
*/
	for(i = 0; i < cartelas; i++){
		printf("\n");
		for(j = 0; j < aposta; j++)
			printf("%d ", jogo[i][j]);

	}
	
	//return;

}



//calcula a probabilidade máxima do jogo
float probabilidade(float sorteio, float numMax){
	if(sorteio == 1)
		return numMax;
	else
		return numMax / sorteio * probabilidade(sorteio-1, numMax-1);
}
	

