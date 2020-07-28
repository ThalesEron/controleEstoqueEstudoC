#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define SIZE 200 
char nome[200] [50]; // matris 200x 50 max-49 caracteres no fim tem que ter /0
int quantidade [50];
char tipo[SIZE] [50];
char fornecedor[SIZE] [50];
int peso [50];
int op;
void cadastro();
void lista();
int main(void) {
	do{
		system("cls"); //system permite executar o prompt dentro do programa
	    printf("\n--menu--\n1 - Cadastrar\n2 - Listar todos \n4 - Sair\n\n");
	    scanf("%d", &op);
	    switch(op){
	    	case 1:
	    		cadastro(); //chama função cadastro
	    		break;
	    	case 2:
	    		lista();
	    		break;
	    	case 4:
	    		system("exit"); //fecha janela
	    	    break;
	    	default:
	    		printf("opcao invalida");
	    		break;
		}
	    
	}while(op!=4); //se opção for diferente de 4 ( c n quiser sair) igual a 4 sai do prog
}
void lista() {
	int i;
	for(i=0;i<SIZE;i++) {
		if(quantidade[i]>0){
			printf("\nNome: %s\nquantidade: %d\ntipo: %s\nfornecedor: %s\npeso: %d", nome[i], quantidade[i], tipo[i], fornecedor[i], peso[i]);
		}else{
			break;
		}
			
	}
	getchar();
	getchar();
}

void cadastro() {
	static int linha;
	do{
		printf("\nDigite o nome: ");
		scanf("%s", &nome[linha]);
		printf("\nDigite a quantidade do produto: ");
		scanf("%d", &quantidade [linha]); //%d pq é do tipo int (numero)
		printf ("\ndigite o tipo do produto: ");
		scanf("%s", &tipo[linha]); //%s pq é do tipo string (texto)
		printf("\ndigite o fornecedor:");
		scanf("%s", &fornecedor [linha]); //%d pq é do tipo int (numero)
		printf("\nDigite o peso do produto: ");
		scanf("%d", &peso [linha]); //%d pq é do tipo int (numero)
		printf("\nDigite 1 para continuar ou outro valor para sair");
		scanf("%d",&op);
		linha++; //proxima execição muda para proxima linha ou (linha=linha+1)
	}while(op==1);
} //fimm do castro


