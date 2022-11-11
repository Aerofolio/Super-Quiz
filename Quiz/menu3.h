#pragma once
#include "sConfiguracoes.h"
#include "impressao.h"

void AlteraSegundosDeResposta(Configuracoes* configuracoes) {
	const int ValorMinimoSegundos = 10;
	int novoValor;

	system("CLS");
	do {
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
	} while (true);
}

void AlteraNumeroDePerguntas(Configuracoes* configuracoes) {
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

void AlteraPerguntasGeradas(Configuracoes* configuracoes) {
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
			if (valorLido == 'V')
				configuracoes->PerguntasGeradas = true;
			else
				configuracoes->PerguntasGeradas = false;
			return;
		}
	} while (true);
}

void MenuOpcao3(Configuracoes* configuracoes) {
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