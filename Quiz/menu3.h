#pragma once
#include "sConfiguracoes.h"
#include "impressao.h"
#include <stdio.h>

void GravaOpcaoAlterada(int novoValor, EnumeradorDeConfiguracoes enumerador) {
	char linha[LimiteCaracterLinha];
	FILE *config, *configTemp;
	config = fopen(NomeArquivoConfig, "r");
	configTemp = fopen(NomeArquivoConfigTemp, "w");

	for (int i = 0; i < QuantidadeDeConfigs; i++) {
		fgets(linha, LimiteCaracterLinha, config);
		if ((EnumeradorDeConfiguracoes)i == enumerador) {
			fprintf(configTemp, "%d\n", novoValor);
		}
		else {
			fprintf(configTemp, "%s", linha);
		}
	}

	fclose(config);
	fclose(configTemp);
	remove(NomeArquivoConfig);
	rename(NomeArquivoConfigTemp, NomeArquivoConfig);
}

void AlteraNumeroDePerguntas(Configuracoes* configuracoes) {
	const int ValorMinimoPerguntas = 5;
	const int ValorMaximoPerguntas = 99;
	int novoValor;

	system("CLS");
	do {
		ImprimeMenu3Perguntas(configuracoes->NumeroDePerguntas);
		scanf("%d", &novoValor);
		system("CLS");
		if (novoValor < ValorMinimoPerguntas || novoValor > ValorMaximoPerguntas) {
			ImprimeErroPerguntas();
		}
		else {
			configuracoes->NumeroDePerguntas = novoValor;

			GravaOpcaoAlterada(novoValor, NumeroDePerguntas);
			return;
		}
	} while (true);
}

void AlteraNumeroDeTentativas(Configuracoes* configuracoes) {
	const int ValorMinimoTentativas = 0;
	const int ValorMaximoTentativas = 2;
	int novoValor;

	system("CLS");
	do {
		ImprimeMenu3Tentativas(configuracoes->NumeroDeTentativas);
		scanf("%d", &novoValor);
		system("CLS");
		if (novoValor < ValorMinimoTentativas || novoValor > ValorMaximoTentativas) {
			ImprimeErroTentativas();
		}
		else {
			configuracoes->NumeroDeTentativas = novoValor;
			GravaOpcaoAlterada(novoValor, NumeroDeTentativas);
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
			ImprimeErroPerguntasVerdadeiroEFalso();
		}
		else {
			configuracoes->PerguntasGeradas = valorLido == 'V';
			GravaOpcaoAlterada(valorLido == 'V', PerguntasGeradas);
			return;
		}
	} while (true);
}

void AlteraDicasAtivadas(Configuracoes* configuracoes) {
	char valorLido;

	system("CLS");
	do {
		ImprimeMenu3DicasAtivadas(configuracoes->DicasAtivadas);
		fflush(stdin);
		valorLido = getche();
		valorLido = toupper(valorLido);
		system("CLS");
		if (valorLido != 'V' && valorLido != 'F') {
			ImprimeErroPerguntasVerdadeiroEFalso();
		}
		else {
			configuracoes->DicasAtivadas = valorLido == 'V';
			GravaOpcaoAlterada(valorLido == 'V', DicasAtivadas);
			return;
		}
	} while (true);
}

void AlteraAsConfiguracoesDeVoltaAoPadrao(Configuracoes* configuracoes) {
	CriaArquivoComConfigsPadrao();
	*configuracoes = LeArquivoConfig();
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
			AlteraNumeroDeTentativas(configuracoes);
			break;
		case 2:
			AlteraNumeroDePerguntas(configuracoes);
			break;
		case 3:
			AlteraPerguntasGeradas(configuracoes);
			break;
		case 4:
			AlteraDicasAtivadas(configuracoes);
			break;
		case 5:
			AlteraAsConfiguracoesDeVoltaAoPadrao(configuracoes);
			break;
		default:
			ImprimeErroOpcaoInvalidaMenu();
		}
	} while (true);
}