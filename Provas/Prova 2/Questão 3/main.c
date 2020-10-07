#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <locale.h>

int main() {
	int identidade, tamF, valId = 0, esc = 0;
	float peso;
	setlocale (LC_ALL, "Portuguese");
	printf ("Informe o tamanho da fila: ");
	scanf ("%d", &tamF);
	filaCont* armaz = criarArmazem(tamF);
	system("cls");
	
	do {
		printf ("--------------  UM NOVO CONTAINER ACABA DE CHEGAR AO PORTO  --------------\n");
		printf ("INFORME OS DADOS ABAIXO: \n");
		do {
			printf ("Identidade do container: ");
			scanf ("%d", &identidade);
			valId = validarIdentidade(armaz, identidade);
			if (valId != 1){
				printf ("Valor inv�lido! Tente novamente...\n");
			}
		} while (valId != 1);
		printf ("Peso do container: ");
		scanf ("%f", &peso);
		Container* cont = createContainer (identidade, peso);
		adicionar(armaz, cont);
		do {
			printf ("\nMAIS ALGUM CONTAINER IR� CHEGAR? (S = 1/N = 0) ");
			scanf("%d", &esc);
		} while ((esc != 1 && esc != 0));
	} while (esc != 0 && contar(armaz) < tamF);
	system("cls");
	imprimirArmazem (armaz);
	do {
		printf ("\n\nO QUE DESEJA FAZER? ");
		printf("\n1. Procurar por um container;");
		printf("\n2. Levar container para o transporte;");
		printf("\n3. Verificar se o armaz�m est� cheio;");
		printf("\n4. Verificar se o armaz�m est� vazio;");
		printf("\n5. Contar quantos containers h� no armaz�m;");
		printf("\n6. Esvaziar armaz�m;");
		printf("\n0. Sair.\n");
		do {
			scanf("%d", &esc);
			if (esc > 7 || esc < 0){
				printf("\nOp��o inv�lida!\n");
			}
		} while (esc > 7 || esc < 0);
		switch (esc){
			case 1: {
				system("cls");
				int id;
				printf("\nInforme a identidade do container a ser pesquisado: ");
				scanf("%d", &id);
				if (pesquisarIdentidade(armaz, id) != -1){
					printf("\nO container pesquisado est� na posi��o %d.\n\n", pesquisarIdentidade (armaz, id));
				}
				else {
					printf ("\nContainer n�o encontrado!\n\n");
				}
				break;
			}
			case 2: {
				system("cls");
				transportar(armaz);
				break;
			}
			case 3: {
				system("cls");
				if (estaCheio(armaz)){
					printf ("\nO armaz�m est� cheio.\n\n");
				}
				else {
					printf ("\nO armaz�m n�o est� cheio.\n\n");
				}
				break;
			}
			case 4: {
				system ("cls");
				if (estaVazio(armaz)){
					printf ("\nO armaz�m est� vazio.\n\n");
				}
				else {
					printf ("\nO armaz�m n�o est� vazio.\n\n");
				}
				break;
			}
			case 5: {
				system ("cls");
				printf ("\n%d containers foram recebidos. \n\n", contar(armaz));
				break;
			}
			case 6: {
				system ("cls");
				esvaziar(armaz);
				printf ("\nArmaz�m esvaziado!\n\n");
				break;
			}
			case 0: {
				break;
			}
		}
	} while (esc != 0); 
	
	return 0;
}
