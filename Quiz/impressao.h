#pragma once
#include "sConfiguracoes.h"
#include "sDica.h"
#include "sPergunta.h"
#include "utils.h"

const char* NomeDoJogo = "Jogo do Milhão";
const int CodigoDeCorTexto = 15; //Branco
const int CodigoDeCorTituloECabecalho = 9; //Azul
const int CodigoCorOpcaoMenu = 9; //Azul
const int CodigoCorErro = 12; //Vermelho
const int CodigoCorDestaque = 10;//Verde

void ImprimeCabecalho(char titulo[]) {
	MudaCorDoConsole(CodigoDeCorTituloECabecalho);
	printf("==================== ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("%s", titulo);
	MudaCorDoConsole(CodigoDeCorTituloECabecalho);
	printf(" ====================\n\n\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

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
	if (configuracoes.PerguntasGeradas)
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
		printf("%d %c %d = ??\n\n", dica.Numero1, dica.Operacao, dica.Numero2);
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