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

#pragma region Declaração de Funções

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
int RetornaNumeroAleatorioEntre(int min, int max);

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
const char* NomeDoJogo = "Super Quiz do Gustavo e do Paulo!";
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
	srand(time(NULL));//Ajusta o seed dos números aleatórios de acordo com a hora
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

//Sempre que utilizar a função printf colocar a função nessa área
//Sempre que escrever qualquer coisa no console colocar nessa área
//Nunca imprimir algo no meio do código
#pragma region Funções que Imprimem no Dados no Console

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
		printf("\n\n");

		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("A");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoA);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("B");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoB);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("C");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoC);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("D");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoD);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("E");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoE);
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
	printf("Resposta correta! Parabéns!\n");
	MudaCorDoConsole(CodigoDeCorTexto);
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

int RetornaNumeroAleatorioEntre(int min, int max) {
	max += 1;
	return min + rand() % (max - (min));
}

#pragma endregion

#pragma region Funções das opções do menu

void MenuOpcao1(Configuracoes configuracoes) {
	for (int i = 0; i < configuracoes.NumeroDePerguntas; i++) {
		Pergunta pergunta;
		int tipoDePergunta = RetornaNumeroAleatorioEntre(0,1);
		bool errou = false;
		
		if (configuracoes.PerguntasGeradas && tipoDePergunta == 1) {
			pergunta = GeradorDePerguntas();
			
			//pegunta gerada
			//Funcao que gera a pergunta, manda a pergunta pointer como paramentro 
		}
		else {
			pergunta.Dica = (char*)"Esta é uma dica!";
			pergunta.Enunciado = (char*)"Este é o enunciado?";
			pergunta.PerguntaGerada = false;
			pergunta.OpcaoA = (char*)"Esta é a opção A!";
			pergunta.OpcaoB = (char*)"Esta é a opção B!";
			pergunta.OpcaoC = (char*)"Esta é a opção C!";
			pergunta.OpcaoD = (char*)"Esta é a opção D!";
			pergunta.OpcaoE = (char*)"Esta é a opção E!";
			pergunta.Resposta = 'A';
			//pergunta do arquivo
			//função que retorna a pergunta do arquivo
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
					//não soma nada a pontuação
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
				respostaLida = getche();
				respostaLida = toupper(respostaLida);

				system("CLS");
				if (respostaLida == pergunta.Resposta) {
					errou = false;
					ImprimeRespostaCerta();
					break;
				}
				else if (respostaLida == '0') {

					break;
				}
				else {
					errou = true;
					ImprimeRepostaErrada();
					continue;
				}
			}
		} while (true);
	}
	system("CLS");
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

Pergunta GeradorDePerguntas() {
	Pergunta perguntaGerada;
	int operacao = RetornaNumeroAleatorioEntre(0, 3);

	perguntaGerada.PerguntaGerada = true;
	perguntaGerada.Numero1 = RetornaNumeroAleatorioEntre(1, 150);
	perguntaGerada.Numero2 = RetornaNumeroAleatorioEntre(1, 150);

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
	case 3:
		while (perguntaGerada.Numero1 % perguntaGerada.Numero2 != 0) {
			perguntaGerada.Numero1 = RetornaNumeroAleatorioEntre(1, 150);
			perguntaGerada.Numero2 = RetornaNumeroAleatorioEntre(1, 150);
		}

		perguntaGerada.Operacao = '/';
		perguntaGerada.RespostaMatematica = perguntaGerada.Numero1 / perguntaGerada.Numero2;

		break;
	}

	return perguntaGerada;
}

Dica GeradorDeDicas(Pergunta pergunta) {
	Dica dica;
	const int LimitadorDeOperacao = 2;
	int LimitadorDeNumeros = pergunta.RespostaMatematica - 1;
	
	dica.Operacao = RetornaNumeroAleatorioEntre(0 ,1);
	dica.Numero1 = RetornaNumeroAleatorioEntre(0, LimitadorDeNumeros);

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