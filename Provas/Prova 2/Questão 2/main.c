#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include "repositorio.h"

int main() {
	int codigo, tamR, valC = 0, esc = 0;
	float valor;
	setlocale (LC_ALL, "Portuguese");
	printf ("Informe o tamanho do repositório: ");
	scanf ("%d", &tamR);
	Rep* rep1 = criarRepositorio(tamR);
	system("cls");
	
	do {
		printf ("--------------  CADASTRAMENTO DE COMPRAS  --------------\n");
		printf ("INFORME OS DADOS ABAIXO: \n");
		do {
			printf ("Código da compra: ");
			scanf ("%d", &codigo);
			valC = validarCodigo(rep1, codigo);
			if (valC != 1){
				printf ("Valor inválido! Tente novamente...\n");
			}
		} while (valC != 1);
		printf ("Valor da compra: ");
		scanf ("%f", &valor);
		Compra* compra1 = createCompra (codigo, valor);
		adicionar(rep1, compra1);
		do {
			printf ("\nDESEJA CADASTRAR UMA NOVA COMPRA? (S = 1/N = 0) ");
			scanf("%d", &esc);
		} while ((esc != 1 && esc != 0));
	} while (esc != 0 && tamanho(rep1) < tamR);
	system("cls");
	printRepositorio(rep1);
	do {
		printf ("\n\nO QUE DESEJA FAZER? ");
		printf("\n1. Pesquisar um produto pelo valor;");
		printf("\n2. Pesquisar um produto pelo código;");
		printf("\n3. Tratar produto;");
		printf("\n4. Verificar se o repositório está cheio;");
		printf("\n5. Verificar se o repositório está vazio;");
		printf("\n6. Verificar quantas compras foram cadastradas;");
		printf("\n7. Esvazia repositório;");
		printf("\n0. Sair.\n");
		do {
			scanf("%d", &esc);
			if (esc > 7 || esc < 0){
				printf("\nOpção inválida!\n");
			}
		} while (esc > 7 || esc < 0);
		switch (esc){
			case 1: {
				system("cls");
				float v;
				printf("\nInforme o valor do produto a ser pesquisado: ");
				scanf("%f", &v);
				if (pesquisarValor(rep1, v) != -1){
					printf("\nO produto pesquisado está na posição %d.\n\n", pesquisarValor (rep1, v));
				}
				else {
					printf ("\nProduto não encontrado!\n\n");
				}
				break;
			}
			case 2: {
				system("cls");
				int v;
				printf("\nInforme o código do produto a ser pesquisado: ");
				scanf("%d", &v);
				if (pesquisarCodigo(rep1, codigo) != -1){
					printf("\nO produto pesquisado está na posição %d.\n\n", pesquisarCodigo (rep1, v));
				}
				else {
					printf ("\nProduto não encontrado!\n\n");
				}
				break;
			}
			case 3: {
				system("cls");
				tratar(rep1);
				break;
			}
			case 4: {
				system("cls");
				if (estaCheio(rep1)){
					printf ("\nO repositório está cheio.\n\n");
				}
				else {
					printf ("\nO repositório não está cheio.\n\n");
				}
				break;
			}
			case 5: {
				system ("cls");
				if (estaVazio(rep1)){
					printf ("\nO repositório está vazio.\n\n");
				}
				else {
					printf ("\nO repositório não está vazio.\n\n");
				}
				break;
			}
			case 6: {
				system ("cls");
				printf ("\n%d compras foram cadastradas. \n\n", tamanho(rep1));
				break;
			}
			case 7: {
				system ("cls");
				esvazia(rep1);
				printf ("\nRepositório esvaziado!\n\n");
				break;
			}
			case 0: {
				break;
			}
		}
	} while (esc != 0); 
	
	return 0;
}
