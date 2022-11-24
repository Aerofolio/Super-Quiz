#pragma once
#include "sConfiguracoes.h"
#include "sPergunta.h"
#include "utils.h"
#include "impressao.h"
#include <stdio.h>

void RegraPediuDica(bool dicasAtivadas, bool* pediuDica);
int RetornaPontosObtidos(int tentativasRestantes, Configuracoes configuracoes, bool pediuDica);

void MenuOpcao1(Configuracoes configuracoes) {
	const int LimiteCaracterNomeDoJogador = 50;
	char nomeDoJogador[LimiteCaracterNomeDoJogador];
	int pontuacao = 0;

	for (int i = 0; i < configuracoes.NumeroDePerguntas; i++) {
		Pergunta pergunta;
		Dica dica;
		int tipoDePergunta = RetornaNumeroAleatorioEntre(0, 1);
		int tentativas = 0;
		bool pediuDica = false;

		if (configuracoes.PerguntasGeradas && tipoDePergunta == 1) {
			pergunta = GeradorDePerguntas();
			dica = GeradorDeDicas(pergunta);
		}
		else {
			dica.DicaPerguntaArquivo = (char*)"Esta � uma dica!";
			dica.PerguntaGerada = false;
			pergunta.Enunciado = (char*)"Este � o enunciado?";
			pergunta.PerguntaGerada = false;
			pergunta.OpcaoA = (char*)"Esta � a op��o A!";
			pergunta.OpcaoB = (char*)"Esta � a op��o B!";
			pergunta.OpcaoC = (char*)"Esta � a op��o C!";
			pergunta.OpcaoD = (char*)"Esta � a op��o D!";
			pergunta.OpcaoE = (char*)"Esta � a op��o E!";
			pergunta.Resposta = 'A';
			//pergunta do arquivo
			//fun��o que retorna a pergunta do arquivo
			//ao sortear a pergunta sera necessario escolher um numero entre 0 e o maximo de registros
		}

		do {
			int tentativasRestantes = configuracoes.NumeroDeTentativas - tentativas;
			ImprimeCabecalho((char*)NomeDoJogo);
			ImprimePergunta(i);
			if (configuracoes.DicasAtivadas && pediuDica) {
				ImprimeDica(dica);
			}
			ImprimeEnunciado(pergunta);
			ImprimeTentativasRestantes(tentativasRestantes);
			ImprimePontuacaoAcumulada(pontuacao);
			ImprimePedirResposta(configuracoes);

			if (pergunta.PerguntaGerada) {
				int respostaLida;
				scanf("%d", &respostaLida);
				system("CLS");

				if (respostaLida == pergunta.RespostaMatematica) {
					pontuacao += RetornaPontosObtidos(tentativasRestantes, configuracoes, pediuDica);
					break;
				}
				else if (respostaLida == 0) {
					ImprimePulouPergunta();
					break;
				}
				else if (respostaLida == 1) {
					RegraPediuDica(configuracoes.DicasAtivadas, &pediuDica);
					continue;
				}
				else {
					tentativas++;
					if (tentativas > configuracoes.NumeroDeTentativas)
						break;
					ImprimeRepostaErrada();
					continue;
				}
			}
			else {
				char respostaLida;
				fflush(stdin);
				respostaLida = getche();
				respostaLida = toupper(respostaLida);

				system("CLS");
				if (respostaLida == pergunta.Resposta) {
					pontuacao += RetornaPontosObtidos(tentativasRestantes, configuracoes, pediuDica);
					break;
				}
				else if (respostaLida == '0') {
					ImprimePulouPergunta();
					break;
				}
				else if (respostaLida == '1') {
					RegraPediuDica(configuracoes.DicasAtivadas, &pediuDica);
					continue;
				}
				else {
					tentativas++;
					if (tentativas > configuracoes.NumeroDeTentativas) {
						ImprimeAcabouAsTentativas();
						break;
					}
					ImprimeRepostaErrada();
					continue;
				}
			}
		} while (true);
	}

	do {
		system("CLS");
		ImprimeTelaFimDeJogo(pontuacao);

		fgets(nomeDoJogador, LimiteCaracterNomeDoJogador, stdin);
		if (strcmp(nomeDoJogador, "\n") == 0) {//erro no buffer devido ao uso de scanf
			continue;
		}
		else if (strcmp(nomeDoJogador, "0\n") == 0) {
			//volta ao menu principal

			break;
		}
		else {
			//registra nome do jogador
			//remover \n antes de botar o nome no arquivo
			break;
		}
	}while(true);

	system("CLS");
}

void RegraPediuDica(bool dicasAtivadas, bool *pediuDica) {
	if (dicasAtivadas) {
		*pediuDica = true;
	}
	else {
		ImprimeErroDicasDesativadas();
	}
}

int RetornaPontosObtidos(int tentativasRestantes, Configuracoes configuracoes, bool pediuDica) {
	const float MultiplicadorDePontuacao0Tentativas = 3;
	const float MultiplicadorDePontuacao1Tentativas = 1;
	const float MultiplicadorDePontuacao2Tentativas = 0.5;

	const float MultiplicadorDeDicas0Tentativas = 0.5;
	const float MultiplicadorDeDicas1Tentativas = 1;
	const float MultiplicadorDeDicas2Tentativas = 1.5;

	const int MultiplicadorDePontuacaoBase = 10;
	const int PontosBasePorDica = 5;

	int pontosObtidos = (tentativasRestantes + 1) * MultiplicadorDePontuacaoBase;
	/*if (configuracoes.DicasAtivadas && pediuDica)
		pontosObtidos -= PontosPorDica;*/

	switch (configuracoes.NumeroDeTentativas)
	{
	case 0:
		if (configuracoes.DicasAtivadas && pediuDica)
			pontosObtidos -= (int)(PontosBasePorDica * MultiplicadorDeDicas0Tentativas);
		pontosObtidos = (int)(pontosObtidos * MultiplicadorDePontuacao0Tentativas);
		break;
	case 1:
		if (configuracoes.DicasAtivadas && pediuDica)
			pontosObtidos -= (int)(PontosBasePorDica * MultiplicadorDeDicas1Tentativas);
		pontosObtidos = (int)(pontosObtidos * MultiplicadorDePontuacao1Tentativas);
		break;
	case 2:
		if (configuracoes.DicasAtivadas && pediuDica)
			pontosObtidos -= (int)(PontosBasePorDica * MultiplicadorDeDicas2Tentativas);
		pontosObtidos = (int)(pontosObtidos * MultiplicadorDePontuacao2Tentativas);
		break;
	}

	ImprimeRespostaCerta(pontosObtidos);
	return pontosObtidos;
}