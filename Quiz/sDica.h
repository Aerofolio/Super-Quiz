#pragma once
#include "sPergunta.h"
#include "utils.h"

typedef struct {
	int Numero1;
	int Numero2;
	char Operacao;
	char* DicaPerguntaArquivo;
	bool PerguntaGerada;
}Dica;

Dica GeradorDeDicas(Pergunta pergunta) {
	Dica dica;
	const int LimitadorDeOperacao = 2;
	int LimitadorDeNumeros = pergunta.RespostaMatematica - 1;

	dica.PerguntaGerada = true;
	dica.Operacao = RetornaNumeroAleatorioEntre(0, 1);
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