#include<stdio.h>
#include <stdlib.h>
//Funçao para exibir MENU.
void Mensagem(int cont){
	cont = cont % 2 + 1;
	system("cls");
	printf("JOGO DA VELHA");
	printf("\nJOGADOR 1 = X\nJOGADOR 2 = O\n");
	printf("\nJOGADOR %d SELECIONE UM NUMERO NA TABELA E APERTE ENTER.\n", cont);	
}
//mostrar a tabela do jogo.
void MostrarTabela(char tabela [][3]){
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(j<2){
				printf("%c", tabela[i][j]);
				printf("|");
			}else{
				printf("%c", tabela[i][j]);
			}
		}
		printf("\n");
	}
}
//Verificar e Gravar a jogada.
int GravandoJogada(char tabela[][3], int x, int c){
	char num = x+48;
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(num == tabela[i][j]){
				if(c % 2 == 0){
					tabela[i][j] = 'X';
					return 1;
				}else{
					tabela[i][j] = 'O';
					return 1;
				}
			}
		}
	}
	printf("\nPosicao ja preenchida, ou numero invalido.\nSELECIONE OUTRA POSICAO NA TABELA E APERTE ENTER.\n");
	
	return 0;
}

//verificar a sequência ganhadora.
char Ganhador(char tabela[][3]){
	char ganhador = '0';
	int i, j;
//Verificar na horizontal	
	for(i = j = 0; i<3; i++){
			if(tabela[i][j] == tabela[i][j+1] && tabela[i][j+1] == tabela[i][j+2]){
				ganhador = tabela [i][j];
				return ganhador;
			}
	}
//Verificar na vertical
	for(i= j =0; j<3; j++){
		if(tabela[i][j] == tabela[i+1][j] && tabela[i+1][j] == tabela[i+2][j]){
			ganhador = tabela [i][j];
			return ganhador;
		}			
	}
	j = i = 0;
//Verificar as diagonais.
	if(tabela[i][j] == tabela[i+1][j+1] && tabela[i+1][j+1] == tabela[i+2][j+2]){
		ganhador = tabela [i][j];
		return ganhador;
	}else if(tabela[i+2][j] == tabela[i+1][j+1] && tabela[i+1][j+1] == tabela[i][j+2] && tabela[i+2][j] == tabela[i][j+2]){
				ganhador = tabela [i+2][j];
				return ganhador;
	}
	
	return ganhador;
}

// Mostrar o vencedor ou empate.
int Final(char ganhador, int c){
	system("cls");
	if(ganhador == 'X'){
		printf("\nVENCEDOR PLAYER 1 = X !!!\n\n");
		return c = 10;
	}else if(ganhador == 'O'){
		printf("\nVENCEDOR PLAYER 2 = O !!!\n\n");
		return c = 10;
	}else if(c == 8){
			printf("\n##VELHA##. NINGUEM GANHOU!!\n\n");
			return c;
	}else{	
		return c;
	}
}

int main(){
	char tabela[3][3] = {'7','8','9','4','5','6','1','2','3'};
	int cont, player, retorno;
	char ganha = '0';
	cont = retorno = 0;
	while(cont < 9){
		Mensagem(cont);
		MostrarTabela(tabela);		
		while(retorno != 1){
			scanf("%d", &player);			
			retorno = GravandoJogada(tabela, player, cont);
		}
		if(cont >= 4){
			ganha = Ganhador(tabela);
			cont = Final(ganha, cont);
		}
		cont++;
		retorno = 0;		
	}
	MostrarTabela(tabela);
	return 0;
}