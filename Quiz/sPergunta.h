#pragma once
#include "utils.h"
#include "sDica.h"

typedef struct {
	char* Enunciado;
	char* OpcaoA;
	char* OpcaoB;
	char* OpcaoC;
	char* OpcaoD;
	char* OpcaoE;
	char* DicaPerguntaArquivo;
	char Resposta;
	int Numero1;
	int Numero2;
	int RespostaMatematica;
	char Operacao;
	bool PerguntaGerada;
}Pergunta;

Pergunta GeradorDePerguntas() {
	Pergunta perguntaGerada;
	do {
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

		if (perguntaGerada.RespostaMatematica == 0 || perguntaGerada.RespostaMatematica == 1)
			continue;
		else
			break;
		
	} while (true);

	return perguntaGerada;
}

bool NumeroPresenteEmArray(int vetor[], int numero) {
	for (int i = 0; i < sizeof(vetor); i++) {
		if (numero == vetor[i]) {
			return true;
		}
	}

	return false;
}

Pergunta RetornaPerguntaDoArquivo(int perguntasLidas[], int* numeroDePerguntasLidas) {
	const char* NomeArquivoPerguntas = "perguntas.txt";
	const int NumeroMaximoDeCaracterLinha = 500;
	const int NumeroDeInformacoesPorLinhaPerguntas = 8;

	Pergunta perguntaRetorno;
	int numeroDeLinhas = 0, linhaSorteada;
	char linhaLida[NumeroMaximoDeCaracterLinha];
	FILE* arqPerguntas;

	arqPerguntas = fopen(NomeArquivoPerguntas, "r");
	while (!feof(arqPerguntas)) {
		fgets(linhaLida, NumeroMaximoDeCaracterLinha, arqPerguntas);
		numeroDeLinhas++;
	}
	fclose(arqPerguntas);

	do {
		linhaSorteada = RetornaNumeroAleatorioEntre(1, numeroDeLinhas);
		if (NumeroPresenteEmArray(perguntasLidas, linhaSorteada)) {
			continue;
		}

		perguntasLidas[*numeroDePerguntasLidas] = linhaSorteada;
		*numeroDePerguntasLidas += 1;
		break;
	} while (true);

	arqPerguntas = fopen(NomeArquivoPerguntas, "r");//volta pro inicio da linha
	for (int i = 1; i <= linhaSorteada; i++) {
		fgets(linhaLida, NumeroMaximoDeCaracterLinha, arqPerguntas);
	}
	fclose(arqPerguntas);

	char* ptr;
	ptr = strtok(linhaLida, ";");
	for (int i = 0; i < NumeroDeInformacoesPorLinhaPerguntas; i++) {
		switch (i)
		{
		case 0:
			perguntaRetorno.Enunciado = strdup(ptr);
			break;
		case 1:
			perguntaRetorno.DicaPerguntaArquivo = strdup(ptr);
			break;
		case 2:
			perguntaRetorno.OpcaoA = strdup(ptr);
			break;
		case 3:
			perguntaRetorno.OpcaoB = strdup(ptr);
			break;
		case 4:
			perguntaRetorno.OpcaoC = strdup(ptr);
			break;
		case 5:
			perguntaRetorno.OpcaoD = strdup(ptr);
			break;
		case 6:
			perguntaRetorno.OpcaoE = strdup(ptr);
			break;
		case 7:
			perguntaRetorno.Resposta = ptr[0];//primeiraLetra
			break;
		}

		ptr = strtok(NULL, ";");
	}


	perguntaRetorno.PerguntaGerada = false;
	return perguntaRetorno;
}
