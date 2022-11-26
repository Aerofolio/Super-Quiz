#pragma once
#include <stdio.h>

typedef struct {
	int NumeroDeTentativas;
	int NumeroDePerguntas;
	bool PerguntasGeradas;
	bool DicasAtivadas;
}Configuracoes;

typedef enum {
	NumeroDeTentativas = 0,
	NumeroDePerguntas = 1,
	PerguntasGeradas = 2,
	DicasAtivadas = 3
}EnumeradorDeConfiguracoes;

const int LimiteCaracterLinha = 2 + 2;
const int QuantidadeDeConfigs = 4;
const char* NomeArquivoConfig = "config.txt";
const char* NomeArquivoConfigTemp = "configTemp.txt";


void CriaArquivoComConfigsPadrao() {
	const int ValorInicialTentativas = 1;
	const int ValorInicialPerguntas = 10;
	const bool ValorInicialPerguntasGeradas = true;
	const bool ValorInicialDicasAtivadas = true;

	FILE* config;
	config = fopen(NomeArquivoConfig, "w");

	for (int i = 0; i < QuantidadeDeConfigs; i++) {
		switch ((EnumeradorDeConfiguracoes)i) {
		case NumeroDeTentativas:
			fprintf(config, "%d\n", ValorInicialTentativas);
			break;
		case NumeroDePerguntas:
			fprintf(config, "%d\n", ValorInicialPerguntas);
			break;
		case PerguntasGeradas:
			fprintf(config, "%d\n", ValorInicialPerguntasGeradas);
			break;
		case DicasAtivadas:
			fprintf(config, "%d\n", ValorInicialDicasAtivadas);
			break;
		}
	}

	fclose(config);
}

Configuracoes LeArquivoConfig() {
	FILE* config;
	char linha[LimiteCaracterLinha];
	int configsArray[QuantidadeDeConfigs];

	config = fopen(NomeArquivoConfig, "r");
	if (!config) {
		CriaArquivoComConfigsPadrao();
		config = fopen(NomeArquivoConfig, "r");
	}

	for (int i = 0; i < QuantidadeDeConfigs; i++) {
		fgets(linha, LimiteCaracterLinha, config);
		configsArray[i] = atoi(linha);
	}
	fclose(config);

	Configuracoes configRetorno;
	for (int i = 0; i < QuantidadeDeConfigs; i++) {
		switch ((EnumeradorDeConfiguracoes)i) {
		case NumeroDeTentativas:
			configRetorno.NumeroDeTentativas = configsArray[i];
			break;
		case NumeroDePerguntas:
			configRetorno.NumeroDePerguntas = configsArray[i];
			break;
		case PerguntasGeradas:
			configRetorno.PerguntasGeradas = configsArray[i];
			break;
		case DicasAtivadas:
			configRetorno.DicasAtivadas = configsArray[i];
			break;
		}
	}

	return configRetorno;
}