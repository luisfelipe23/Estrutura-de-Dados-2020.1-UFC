#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "compras.h"
#include "repositorio.h"

int main() {
	int codigo, valC = 0, tamR, esc = 0;
	float valor;
	setlocale (LC_ALL, "Portuguese");
	printf ("Informe o tamanho do repositório: ");
	scanf ("%d", &tamR);
	system ("cls");
	Rep* rep1 = criarRepositorio(tamR);
	do {
		printf ("--------------  CADASTRAMENTO DE COMPRAS  --------------\n");
		printf ("INFORME OS DADOS ABAIXO: \n");
		do{
			printf ("Código da compra: ");
			scanf ("%d", &codigo);
			valC = validarCodigo(rep1, codigo);
			if (valC != 1){
				printf ("Valor inválido! Tente novamente...\n");
			}
		}
		while (valC != 1);	
		printf ("Valor da compra: ");
		scanf ("%f", &valor);
		Compra* compra1 = createCompra(codigo, valor);
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
		printf("\n1. Pesquisar um produto;");
		printf("\n2. Tratar produto;");
		printf("\n3. Verificar se o repositório está cheio;");
		printf("\n4. Verificar se o repositório está vazio;");
		printf("\n5. Esvazia repositório;");
		printf("\n0. Sair.\n");
		do {
			scanf("%d", &esc);
			if (esc > 6 || esc < 0){
				printf("\nOpção inválida!\n");
			}
		} while (esc > 6 || esc < 0);
		switch (esc){
			case 1: {
				system("cls");
				int v;
				printf("\nInforme o valor a ser pesquisado: ");
				scanf("%d", &v);
				if (pesquisar(rep1, v) != -1){
					printf("\nO produto está na posição %d.\n\n", pesquisar(rep1, v));
				}
				else {
					printf("\nProduto não encontrado.\n\n");
				}
				break;
			}
			case 2: {
				system("cls");
				int v;
				printf("\nInforme um valor a ser tratado: ");
				scanf("%d", &v);
				if (tratar(rep1, v)){
					tratar(rep1, v);
				} 
				else {
					printf("\nValor inválido!\n\n");
				}
				break;
			}
			case 3: {
				system("cls");
				if (estaCheio(rep1)){
					printf("\n\nREPOSITÓRIO CHEIO.\n\n");
				}
				else {
					printf("\n\nREPOSITÓRIO NÃO ESTÁ CHEIO.\n\n");
				}
				break;
			}
			case 4: {
				system("cls");
				if (estaVazio(rep1)){
					printf("\n\nREPOSITÓRIO VAZIO.\n\n");
				}
				else {
					printf("\n\nREPOSITÓRIO NÃO ESTÁ VAZIO.\n\n");
				}
				break;
			}
			case 5: {
				system("cls");
				esvaziar(rep1);
				printf("\n\nREPOSITÓRIO ESVAZIADO.\n\n");
				break;
			}
			case 0: {
				break;
			}
		}
	} while (esc != 0);
}
