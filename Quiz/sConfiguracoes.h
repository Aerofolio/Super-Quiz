#pragma once
#include <stdio.h>

typedef struct {
	int NumeroDePerguntas;
	int NumeroDeTentativas;
	bool PerguntasGeradas;
}Configuracoes;

const int LimiteCaracterLinha = 2 + 2;//\n
const int QuantidadeDeConfigs = 3;
const char* NomeDoArquivo = "config.txt";

Configuracoes LeArquivoConfig() {
	FILE* config;
	char linha[LimiteCaracterLinha];
	int configsArray[QuantidadeDeConfigs];

	//verificiar existencia do arquivo, se n existiar criar um com configs padrão
	config = fopen(NomeDoArquivo , "r");

	for (int i = 0; i < QuantidadeDeConfigs; i++) {
		if (feof(config)) {
			//erro?
			//criar o arquivo padrao
			//break
		}

		fgets(linha, LimiteCaracterLinha, config);
		configsArray[i] = atoi(linha);
	}
	fclose(config);
	return Configuracoes{configsArray[0], configsArray[1], (bool)configsArray[2]};
}