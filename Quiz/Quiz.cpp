#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

//Structs
typedef struct {
	int SegundosDeResposta;
	int NumeroDePerguntas;
	bool PerguntasGeradas;
}Configuracoes;

typedef struct {
	char* Enunciado;
	char* Dica;
	char* OpcaoA;
	char* OpcaoB;
	char* OpcaoC;
	char* OpcaoD;
	char* OpcaoE;
	char Resposta;
	int Numero1;
	int Numero2;
	int RespostaMatematica;
	char Operacao;
	bool PerguntaGerada;
}Pergunta;

typedef struct {
	int Numero1;
	int Numero2;
	char Operacao;
}Dica;

#pragma region Declara��o de Fun��es

void ImprimeMenuPrincipal();

void ImprimeErroOpcaoInvalidaMenu();
void ImprimeErroSegundos();
void ImprimeCabecalho(char titulo[]);
void ImprimeErroPerguntas();
void ImprimeErroPerguntasMatematicas();
void ImprimePergunta(int numeroPergunta);
void ImprimeEnunciado(Pergunta pergunta);
void ImprimeDica(Pergunta pergunta);
void ImprimeRepostaErrada();
void ImprimeRespostaCerta();

void ImprimeMenu3(Configuracoes configuracoes);
void ImprimeMenu3Segundos(int valorAntigo);
void ImprimeMenu3Perguntas(int valorAntigo);
void ImprimeMenu3PerguntasMatematica(bool valorAntigo);

void Continuar();
void MudaCorDoConsole(int codigoCor);

void MenuOpcao1(Configuracoes configuracoes);
void MenuOpcao2();
void MenuOpcao3(Configuracoes *configuracoes);

Pergunta GeradorDePerguntas();
Dica GeradorDeDicas(Pergunta pergunta);

void AlteraSegundosDeResposta(Configuracoes *configuracoes);
void AlteraNumeroDePerguntas(Configuracoes *configuracoes);
void AlteraPerguntasGeradas(Configuracoes *configuracoes);

#pragma endregion

//Constantes Globais
const int ValorInicialSegundos = 30;
const int ValorInicialPerguntas = 10;
const bool ValorInicialPerguntasGeradas = true;
const char* NomeDoJogo = "Super Quiz do Gustavo e do Paulo";
#pragma region Constantes de C�digo de Cor

const int CodigoDeCorTexto = 15; //Branco
const int CodigoDeCorTituloECabecalho = 9; //Azul
const int CodigoCorOpcaoMenu = 9; //Azul
const int CodigoCorErro = 12; //Vermelho
const int CodigoCorDestaque = 10;//Verde

#pragma endregion

int main()
{
	setlocale(0, "portuguese");
	srand(time(NULL));//Ajusta o seed dos n�meros aleat�rios de acordo com a hora
	int opcaoMenu;
	Configuracoes configuracoes = { ValorInicialSegundos, ValorInicialPerguntas, ValorInicialPerguntasGeradas };
	
	do {
		ImprimeMenuPrincipal();
		scanf("%d", &opcaoMenu);
		system("CLS");

		switch (opcaoMenu) {
			case 0:
				return 0;
			case 1:
				MenuOpcao1(configuracoes);
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

//Sempre que utilizar a fun��o printf colocar a fun��o nessa �rea
//Sempre que escrever qualquer coisa no console colocar nessa �rea
//Nunca imprimir algo no meio do c�digo
#pragma region Fun��es que Imprimem no Dados no Console

void ImprimeMenuPrincipal() {
	ImprimeCabecalho((char*)NomeDoJogo);

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
	printf(" - Configura��es\n\n");
	
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Sair\n\n\n");
	printf("Digite uma op��o para continuar: ");
}

void ImprimeErroOpcaoInvalidaMenu() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Op��o inv�lida! Por favor escolha uma op��o dispon�vel.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroSegundos() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Op��o inv�lida! Por favor escolha um valor maior ou igual a 10 segundos.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroPerguntas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Op��o inv�lida! Por favor escolha um valor maior ou igual a 5 perguntas.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroPerguntasMatematicas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Op��o inv�lida! Por favor escolha um valor entre os mostrados abaixo.\n");
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
	ImprimeCabecalho((char*)"Configura��es");

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
	printf(" - N�mero de perguntas: ");
	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d perguntas\n\n", configuracoes.NumeroDePerguntas);

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("3");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Ativar perguntas matem�ticas: ");
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
	printf("Digite uma op��o para continuar: ");
}

void ImprimeMenu3Segundos(int valorAntigo) {
	ImprimeCabecalho((char*)"Configura��es");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d segundos\n\n", valorAntigo);

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite o novo valor para os segundos: ");
}

void ImprimeMenu3Perguntas(int valorAntigo) {
	ImprimeCabecalho((char*)"Configura��es");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d perguntas\n\n", valorAntigo);

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite o novo valor para o n�mero de perguntas: ");
}

void ImprimeMenu3PerguntasMatematica(bool valorAntigo) {
	ImprimeCabecalho((char*)"Configura��es");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	if (valorAntigo)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite se deseja ver perguntas matem�ticas (V/F): ");
}

void ImprimePergunta(int numeroPergunta) {
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("Pergunta");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" %d", numeroPergunta + 1);
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf(":\n\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeEnunciado(Pergunta pergunta) {
	if (pergunta.PerguntaGerada) {
		printf("%d %c %d = ??", pergunta.Numero1, pergunta.Operacao, pergunta.Numero2);
	}
	else {
		printf(pergunta.Enunciado);
	}
	printf("\n\nDigite a resposta ou 0 para pular: ");
}

void ImprimeDica(Pergunta pergunta) {
	MudaCorDoConsole(CodigoCorDestaque);
	printf("Dica: ");
	MudaCorDoConsole(CodigoDeCorTexto);
	if (pergunta.PerguntaGerada) {
		Dica dica = GeradorDeDicas(pergunta);
		printf("%d %c %d = ??\n\n", dica.Numero1, dica.Operacao, dica.Numero2 );
	}
	else {
		printf("%s\n\n", pergunta.Dica);
	}
}

void ImprimeRepostaErrada() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Resposta errada! Tente Novamente.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeRespostaCerta() {
	MudaCorDoConsole(CodigoCorDestaque);
	printf("Resposta correta! Parab�ns!\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

#pragma endregion

#pragma region Outras Fun��es

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

#pragma region Fun��es das op��es do menu

void MenuOpcao1(Configuracoes configuracoes) {
	for (int i = 0; i < configuracoes.NumeroDePerguntas; i++) {
		Pergunta pergunta;
		int tipoDePergunta = rand() % 2;
		bool errou = false;
		
		if (configuracoes.PerguntasGeradas && 1 == 1) {
			pergunta = GeradorDePerguntas();
			
			//pegunta gerada
			//Funcao que gera a pergunta, manda a pergunta pointer como paramentro 
		}
		else {
			//pergunta do arquivo
			//func��o que pega a pergunta do arquivo, manda a pergunta como pointer 
		}

		do {
			ImprimeCabecalho((char*)NomeDoJogo);
			ImprimePergunta(i);
			if (errou) {
				ImprimeDica(pergunta);
			}
			ImprimeEnunciado(pergunta);

			if (pergunta.PerguntaGerada) {
				int respostaLida;
				scanf("%d", &respostaLida);
				system("CLS");

				if (respostaLida == pergunta.RespostaMatematica) {
					errou = false;
					ImprimeRespostaCerta();
					break;
				}
				else if (respostaLida == 0) {
					//n�o soma nada a pontua��o
					break;
				}
				else {
					errou = true;
					ImprimeRepostaErrada();
					continue;
				}
			}
			else {
				char respostaLida;
				//respota do arquivo
			}
		} while (true);
		//bool pra erros, caso true imprime a dica
	}
}

void MenuOpcao2() {
	printf("Op��o escolhida: 2\n");
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

#pragma region Fun��es do Menu 1

Pergunta GeradorDePerguntas() {
	const int LimitadorNumeros = 100;
	Pergunta perguntaGerada;
	int operacao = rand() % 3;

	perguntaGerada.PerguntaGerada = true;
	perguntaGerada.Numero1 = 1 + rand() % LimitadorNumeros;
	perguntaGerada.Numero2 = 1 + rand() % LimitadorNumeros;

	switch (operacao) {
	case 0:
		perguntaGerada.Operacao = '*';
		perguntaGerada.RespostaMatematica = perguntaGerada.Numero1 * perguntaGerada.Numero2;
		break;
	case 1:
		perguntaGerada.Operacao = '+';
		perguntaGerada.RespostaMatematica = perguntaGerada.Numero1 + perguntaGerada.Numero2;
		break;
	case 2:
		perguntaGerada.Operacao = '-';
		perguntaGerada.RespostaMatematica = perguntaGerada.Numero1 - perguntaGerada.Numero2;
		break;
	}

	return perguntaGerada;
}

Dica GeradorDeDicas(Pergunta pergunta) {
	const int LimitadorDeOperacao = 2;
	Dica dica;
	int LimitadorDeNumeros = pergunta.RespostaMatematica - 1;
	
	dica.Operacao = rand() % LimitadorDeOperacao;
	dica.Numero1 = rand() % LimitadorDeNumeros;

	if (dica.Operacao == 1) {
		dica.Operacao = '+';
		dica.Numero2 = pergunta.RespostaMatematica - dica.Numero1;
	}
	else {
		dica.Operacao = '-';
		dica.Numero2 = pergunta.RespostaMatematica + dica.Numero1;
	}

	return dica;
}

#pragma endregion

#pragma region Fun��es do Menu 2

#pragma endregion

#pragma region Fun��es do Menu 3

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