#include <stdio.h>


float probabilidade(float numCartela, float numSorteados, float aux);

int main(){
		//variaveis locais utilizadas
	int numCartela, numSorteados, numMarcado, numAcerto ;

	printf("Digite quantos numeros tem a cartela: ");
		scanf("%d", &numCartela);
	printf("Digite quantos n° da cartela vao ser sorteados: ");
		scanf("%d", &numSorteados);
	printf("Digite quantos n° vai marcar: ");
		scanf("%d", &numMarcado);
	printf("Digite quantos n° quer acertas dos %d  n° que vao ser sorteados: ", numSorteados);
		scanf("%d", &numAcerto);

	/*
		Faz a probabilidade ex: da mega sena que é 60 digitos e sortea 6, quer acerta 5 números
		jogando 7 digitos em 1 cartela
		possibilidades = C[60,6] / ( C[7,5] * C[53,1] )
	*/
	int a = probabilidade(numCartela, numSorteados, abs(numCartela - numSorteados));
	int b = probabilidade(numMarcado, numAcerto, abs(numAcerto - numMarcado));
	int c = probabilidade(numCartela-numMarcado, abs(numSorteados - numAcerto ), abs(  (numCartela-numMarcado) - (numSorteados - numAcerto)  )  );

	//possibilidades de acerto
	printf(":::: Essa e a possibilidade que tem de acerto 1 em %d ::::\n", a/(b*c) );

}
	
	//Calcula a probabilidade de C[x.x] em recursão
float probabilidade(float numCartela, float numSorteados, float aux){
		//caso aux seja igual a número total retorna 1.
		//Pois ex:   10!/10! = 1 conforme imagens anexadas com o código
	if(numCartela == aux)
		return 1;
	else if(numSorteados <= 1)
		return numCartela * probabilidade(numCartela-1, 1, aux);
	else
		return (numCartela/numSorteados) * probabilidade(numCartela-1, numSorteados-1, aux);
}

