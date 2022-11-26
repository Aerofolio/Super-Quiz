#pragma once
#include <stdio.h>
#include "utils.h"
#include "impressao.h"

const char* NomeArquivoScoreboard = "scoreboard.txt";
const char* NomeArquivoScoreboardTemp = "scoreboardTemp.txt";
const int NumeroMaximoDeJogadoresScoreboard = 10;
const int LimiteCaracterLinhaScoreboard = 56;
const int NumeroDeInformacaoPorLinhaScoreboard = 2;

void MenuOpcao2() {
	FILE* arqScoreboard;
	char linhaLida[LimiteCaracterLinhaScoreboard];

	ImprimeCabecalho((char*)CabecalhoScoreboard);

	arqScoreboard = fopen(NomeArquivoScoreboard, "r");
	if (!arqScoreboard) {
		ImprimeErroSemRegistrosScoreboard();
		Continuar();
		return;
	}

	for (int i = 0; i < NumeroMaximoDeJogadoresScoreboard; i++) {
		fgets(linhaLida, LimiteCaracterLinhaScoreboard, arqScoreboard);

		if (feof(arqScoreboard))
			break;

		char* ptr;
		Player jogadorDaLinha;
		ptr = strtok(linhaLida, ";");
		for (int ii = 0; ii < NumeroDeInformacaoPorLinhaScoreboard; ii++) {
			if (ii == 0)
				jogadorDaLinha.NomeDoJogador = ptr;
			else
				jogadorDaLinha.Pontuacao = atoi(ptr);

			ptr = strtok(NULL, ";");
		}

		ImprimeLinhaDoScoreboard(jogadorDaLinha, i + 1);
	}

	Continuar();
	fclose(arqScoreboard);
}
