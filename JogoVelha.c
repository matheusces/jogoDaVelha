#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void criarMatriz(char matriz[3][3]){
	int i, j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matriz[i][j] = '-';
		}
	}
}


void mostrarMatriz(char matriz[3][3]){
	int i, j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool verificarSeGanhouX(char matriz[3][3]){
	if(matriz[0][0]=='X' && matriz[1][1]=='X' && matriz[2][2]=='X'){
		return true;
	}
	else if(matriz[0][2]=='X' && matriz[1][1]=='X' && matriz[2][0]=='X'){
		return true;
	}
	else if(matriz[0][0]=='X' && matriz[0][1]=='X' && matriz[0][2]=='X'){
		return true;
	}
	else if(matriz[1][0]=='X' && matriz[1][1]=='X' && matriz[1][2]=='X'){
		return true;
	}
	else if(matriz[2][0]=='X' && matriz[2][1]=='X' && matriz[2][2]=='X'){
		return true;
	}
	else if(matriz[0][0]=='X' && matriz[1][0]=='X' && matriz[2][0]=='X'){
		return true;
	}
	else if(matriz[0][1]=='X' && matriz[1][1]=='X' && matriz[2][1]=='X'){
		return true;
	}
	else if(matriz[0][2]=='X' && matriz[1][2]=='X' && matriz[2][2]=='X'){
		return true;
	}
	else{
		return false;
	}
}

bool verificarSeGanhouO(char matriz[3][3]){
	if(matriz[0][0]=='O' && matriz[1][1]=='O' && matriz[2][2]=='O'){
		return true;
	}
	else if(matriz[0][2]=='O' && matriz[1][1]=='O' && matriz[2][0]=='O'){
		return true;
	}
	else if(matriz[0][0]=='O' && matriz[0][1]=='O' && matriz[0][2]=='O'){
		return true;
	}
	else if(matriz[1][0]=='O' && matriz[1][1]=='O' && matriz[1][2]=='O'){
		return true;
	}
	else if(matriz[2][0]=='O' && matriz[2][1]=='O' && matriz[2][2]=='O'){
		return true;
	}
	else if(matriz[0][0]=='O' && matriz[1][0]=='O' && matriz[2][0]=='O'){
		return true;
	}
	else if(matriz[0][1]=='O' && matriz[1][1]=='O' && matriz[2][1]=='O'){
		return true;
	}
	else if(matriz[0][2]=='O' && matriz[1][2]=='O' && matriz[2][2]=='O'){
		return true;
	}
	else{
		return false;
	}
}


void jogarMatriz(char matriz[3][3], int m, int n, int indic){
	switch(indic){
		case 1:
			matriz[m][n] = 'X';
			break;
	    case 2:
	    	matriz[m][n] = 'O';
	    	break;
	} 
}

void verificarValidade(int m, int n, char matriz[3][3], char nome[30], int indic){
	while(m>3 || m<1 || n>3 || n<1 || matriz[m-1][n-1]=='X' || matriz[m-1][n-1]=='O'){
		printf("%s, opcao invalida ou ja ocupada.. digite as posicoes de 1 a 3 e que estejam livres: ", nome);
		scanf("%d %d", &m, &n);	
	}
	
	jogarMatriz(matriz, m-1, n-1, indic);
}

bool deuVelha(char matriz[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matriz[i][j] == '-'){
				return false;
			}
		}
	}
	return true;
}


int main(){
	char matriz[3][3], nome1[30], nome2[30];
	int m, n, indic=1;
	bool t = true;
	
	printf("Digite o nome do Jogador 1: ");
	scanf("%s", &nome1);
	printf("Digite o nome do Jogador 2: ");
	scanf("%s", &nome2);
	
	criarMatriz(matriz);
	mostrarMatriz(matriz);
	
	while(t == true){
		if(indic==1){
			if(verificarSeGanhouO(matriz)){
				printf("%s Ganhou o Jogo!", nome2);
				break;
			}
			else if(deuVelha(matriz)){
				printf("Deu Velha...");
				break;
			}
			else{
				printf("%s escolha as posicoes onde voce quer jogar: ", nome1);
				scanf("%d %d", &m, &n);
				
				verificarValidade(m, n, matriz, nome1, indic);
				mostrarMatriz(matriz);
				indic = 2;	
			}
			
			
		}
		else{
			if(verificarSeGanhouX(matriz)){
				printf("%s Ganhou o Jogo!", nome1);
				break;
			}
			else if(deuVelha(matriz)){
				printf("Deu Velha...");
				break;
			}
			else{
				printf("%s escolha as posicoes onde voce quer jogar: ", nome2);
				scanf("%d %d", &m, &n);
				
				
				verificarValidade(m, n, matriz, nome2, indic);
				mostrarMatriz(matriz);
				indic = 1;	
			}
		}
		
	}
	
	
	return 0;
}