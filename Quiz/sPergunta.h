#pragma once
#include "utils.h"

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