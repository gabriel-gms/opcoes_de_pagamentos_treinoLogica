#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define N 2

//vari�veis globais
int Valor_gasto;
int op;

//fun��o
void opcao (){
	printf("---------------------------------------------------------------------------------------------\n");
	printf("Op��es de pagamentos\n\n");
	printf("1 - A vista com 10 porcento de desconto\n");
	printf("2 - Em duas vezes (pre�o de etiqueta)\n");
	printf("3 - de 3 at� 10 vezes com 3 porcento de juros ao m�s (somente para compras acima de R$ 100,00)\n\n");
	
	do{
	printf("Escolha uma op��o:\n");
	scanf("%d",&op);
		if(op<1 || op>3){
			printf("op��o n�o existe, digite novamente\n");
		}
			fflush(stdin);
				
				switch(op){
					case 1:
						system("cls");
						opEscolhidaUm();
						break;
					case 2:
						system("cls");
						opEscolhidaDois();
						break;
					case 3:
						system("cls");
						opEscolhidaTres();
						break;
				}
	}while(op<1 || op>3);
}



//fun��o
int opEscolhidaUm(int Resultado_op1){
	Resultado_op1 = Valor_gasto - (Valor_gasto * 0.1);
    printf("O valor fica: R$ %d\n", Resultado_op1);
    printf("Pressione qualquer letra e enter para continuar\n");
    scanf("%s");
    system("cls");
    return Resultado_op1;
}


//fun��o
int opEscolhidaDois(int Resultado_op2){
	Resultado_op2 = Valor_gasto / 2;
	printf("O valor fica: R$ %d\n", Resultado_op2);
	printf("Pressione qualquer letra e enter para continuar\n");
    scanf("%s");
    system("cls");
	return Resultado_op2;
}



//fun��o
int opEscolhidaTres(int parcelas, int Resultado_op3){
	if(Valor_gasto > 100){
		do{
			printf("Escolha um parcelamento de tr�s a dez vezes:\n");
			scanf("%d", &parcelas);
			if(parcelas<3 || parcelas>10){
				printf("valor incorreto, s� vale entre 3 e 10 (os incluindo).\n");
		    }
		}while(parcelas<3 || parcelas>10);
		
		Resultado_op3 = Valor_gasto / parcelas;
		Resultado_op3 = Resultado_op3 + (Resultado_op3 * 0.03);
		printf("O valor fica: R$ %d , incluindo os 3 porcento ao m�s\n", Resultado_op3);
		printf("Pressione qualquer letra e enter para continuar\n");
    	scanf("%s");
    	system("cls");
		
		
	}else{
		printf("A op��o 3 � v�lida apenas para valores acima de R$100,00 , tente outra.\n");
		printf("Pressione qualquer letra e enter para continuar\n");
    	scanf("%s");
    	system("cls");
    	opcao();
	}
}


//fun��o principal
int main() {
	
	typedef struct{
		char nome[50];
		int valor;
		int opcaoDePg;
	}relatorio;
	
	relatorio Relatorio[N];
	
	int i;
	
	setlocale(LC_ALL,"portuguese");
	
	for(i=0;i<N;i++){
		system("cls");
		printf("Digite o total gasto pelo cliente na loja:\n");
		scanf("%d", &Valor_gasto);
	
		opcao();
	}
	
	printf("Relat�rio de vendas\n");
	printf("---------------------------------------------------------------------------------------------\n");
	
	
	return 0;
}
