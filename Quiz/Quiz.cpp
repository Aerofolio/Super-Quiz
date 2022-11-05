#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

//Structs
typedef struct {
	int SegundosDeResposta;
	int NumeroDePerguntas;
	bool PerguntasGeradas;
}Configuracoes;

#pragma region Declaração de Funções

void ImprimeMenuPrincipal();

void ImprimeErroOpcaoInvalidaMenu();
void ImprimeErroSegundos();
void ImprimeCabecalho(char titulo[]);
void ImprimeErroPerguntas();
void ImprimeErroPerguntasMatematicas();

void ImprimeMenu3(Configuracoes configuracoes);
void ImprimeMenu3Segundos(int valorAntigo);
void ImprimeMenu3Perguntas(int valorAntigo);
void ImprimeMenu3PerguntasMatematica(bool valorAntigo);

void Continuar();
void MudaCorDoConsole(int codigoCor);

void MenuOpcao1();
void MenuOpcao2();
void MenuOpcao3(Configuracoes *configuracoes);

void AlteraSegundosDeResposta(Configuracoes *configuracoes);
void AlteraNumeroDePerguntas(Configuracoes *configuracoes);
void AlteraPerguntasGeradas(Configuracoes *configuracoes);

#pragma endregion

//Constantes Globais
#pragma region Constantes de Código de Cor

const int CodigoDeCorTexto = 15; //Branco
const int CodigoDeCorTituloECabecalho = 9; //Azul
const int CodigoCorOpcaoMenu = 9; //Azul
const int CodigoCorErro = 12; //Vermelho
const int CodigoCorDestaque = 10;//Verde

#pragma endregion

int main()
{
	setlocale(0, "portuguese");

	int opcaoMenu;
	Configuracoes configuracoes = { 30, 10, true };
	
	do {
		ImprimeMenuPrincipal();
		scanf("%d", &opcaoMenu);
		system("CLS");

		switch (opcaoMenu) {
			case 0:
				return 0;
			case 1:
				MenuOpcao1();
				break;
			case 2:
				MenuOpcao2();
				break;
			case 3:
				MenuOpcao3(&configuracoes);
				break;
			default:
				ImprimeErroOpcaoInvalidaMenu();
		}
	} while (true);
}

//Sempre que utilizar a função printf colocar a função nessa área
//Sempre que escrever qualquer coisa colocar nessa área
//Nunca imprimir algo no meio do código
#pragma region Funções que Imprimem no Dados no Console

void ImprimeMenuPrincipal() {
	ImprimeCabecalho((char*)"Super Quiz do Gustavo e do Paulo!");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("1");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Iniciar\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("2");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Scoreboard\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("3");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Configurações\n\n");
	
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Sair\n\n\n");
	printf("Digite uma opção para continuar: ");
}

void ImprimeErroOpcaoInvalidaMenu() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha uma opção disponível.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroSegundos() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha um valor maior ou igual a 10 segundos.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroPerguntas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha um valor maior ou igual a 5 perguntas.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroPerguntasMatematicas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha um valor entre os mostrados abaixo.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeCabecalho(char titulo[]) {
	MudaCorDoConsole(CodigoDeCorTituloECabecalho);
	printf("==================== ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("%s", titulo);
	MudaCorDoConsole(CodigoDeCorTituloECabecalho);
	printf(" ====================\n\n\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeMenu3(Configuracoes configuracoes) {
	ImprimeCabecalho((char*)"Configurações");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("1");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Tempo de resposta: ");
	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d segundos\n\n", configuracoes.SegundosDeResposta);


	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("2");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Número de perguntas: ");
	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d perguntas\n\n", configuracoes.NumeroDePerguntas);

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("3");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Ativar perguntas matemáticas: ");
	MudaCorDoConsole(CodigoCorDestaque);
	if(configuracoes.PerguntasGeradas)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Voltar\n\n\n");
	printf("Digite uma opção para continuar: ");
}

void ImprimeMenu3Segundos(int valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d segundos\n\n", valorAntigo);

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite o novo valor para os segundos: ");
}

void ImprimeMenu3Perguntas(int valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d perguntas\n\n", valorAntigo);

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite o novo valor para o número de perguntas: ");
}

void ImprimeMenu3PerguntasMatematica(bool valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	if (valorAntigo)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite se deseja ver perguntas matemáticas (V/F): ");
}

#pragma endregion

#pragma region Outras Funções

void MudaCorDoConsole(int codigoCor) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, codigoCor);
}

void Continuar() {
	printf("\nPressione qualquer tecla para continuar: ");
	getche();
	system("CLS");
}

#pragma endregion

#pragma region Funções das opções do menu

void MenuOpcao1() {
	printf("Opção escolhida: 1\n");
	Continuar();
}

void MenuOpcao2() {
	printf("Opção escolhida: 2\n");
	Continuar();
}

void MenuOpcao3(Configuracoes *configuracoes) {
	int opcaoMenu;

	do {
		ImprimeMenu3(*configuracoes);
		scanf("%d", &opcaoMenu);
		system("CLS");

		switch (opcaoMenu) {
		case 0:
			return;
		case 1:
			AlteraSegundosDeResposta(configuracoes);
			break;
		case 2:
			AlteraNumeroDePerguntas(configuracoes);
			break;
		case 3:
			AlteraPerguntasGeradas(configuracoes);
			break;
		default:
			ImprimeErroOpcaoInvalidaMenu();
		}
	} while (true);
}

#pragma endregion

#pragma region Funções do Menu 1

#pragma endregion

#pragma region Funções do Menu 2

#pragma endregion

#pragma region Funções do Menu 3

void AlteraSegundosDeResposta(Configuracoes *configuracoes) {
	const int ValorMinimoSegundos = 10;
	int novoValor;

	system("CLS");
	do{
		ImprimeMenu3Segundos(configuracoes->SegundosDeResposta);
		scanf("%d", &novoValor);
		system("CLS");
		if (novoValor < ValorMinimoSegundos) {
			ImprimeErroSegundos();
		}
		else {
			configuracoes->SegundosDeResposta = novoValor;
			return;
		}
	}while(true);
}

void AlteraNumeroDePerguntas(Configuracoes *configuracoes) {
	const int ValorMinimoPerguntas = 5;
	int novoValor;

	system("CLS");
	do {
		ImprimeMenu3Perguntas(configuracoes->NumeroDePerguntas);
		scanf("%d", &novoValor);
		system("CLS");
		if (novoValor < ValorMinimoPerguntas) {
			ImprimeErroPerguntas();
		}
		else {
			configuracoes->NumeroDePerguntas = novoValor;
			return;
		}
	} while (true);
}

void AlteraPerguntasGeradas(Configuracoes *configuracoes) {
	char valorLido;

	system("CLS");
	do {
		ImprimeMenu3PerguntasMatematica(configuracoes->PerguntasGeradas);
		fflush(stdin);
		valorLido = getche();
		valorLido = toupper(valorLido);
		system("CLS");
		if (valorLido != 'V' && valorLido != 'F') {
			ImprimeErroPerguntasMatematicas();
		}
		else {
			if(valorLido == 'V')
				configuracoes->PerguntasGeradas = true;
			else
				configuracoes->PerguntasGeradas = false;
			return;
		}
	} while (true);
}

#pragma endregion