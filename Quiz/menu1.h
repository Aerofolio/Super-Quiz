#pragma once
#include "sConfiguracoes.h"
#include "sPergunta.h"
#include "utils.h"
#include "impressao.h"
#include <stdio.h>

void RegraPediuDica(bool dicasAtivadas, bool* pediuDica);

void MenuOpcao1(Configuracoes configuracoes) {
	const int MultiplicadorDePontuacao = 10;
	const int PontosPorDica = 5;
	const int LimiteCaracterNomeDoJogador = 50;
	char* nomeDoJogador = (char*)"teste123";
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
					int pontosObtidos = (tentativasRestantes + 1) * MultiplicadorDePontuacao;
					if(configuracoes.DicasAtivadas && pediuDica)
						pontosObtidos -= PontosPorDica;
					ImprimeRespostaCerta(pontosObtidos);
					pontuacao += pontosObtidos;
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
					int pontosObtidos = (tentativasRestantes + 1) * MultiplicadorDePontuacao;
					if (configuracoes.DicasAtivadas && pediuDica)
						pontosObtidos -= PontosPorDica;
					ImprimeRespostaCerta(pontosObtidos);
					pontuacao += pontosObtidos;
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

	//fim do numero de perguntas = fim de jogo
	system("CLS");
	do {
		ImprimeTelaFimDeJogo(pontuacao);
		break;
		//gets para ler o nome do jogador, se for s� "" continuar - n registra nome no arquivo
	}while(true);
	//printf("Pontos totais: %d\n", pontuacao);
}

void RegraPediuDica(bool dicasAtivadas, bool *pediuDica) {
	if (dicasAtivadas) {
		*pediuDica = true;
	}
	else {
		ImprimeErroDicasDesativadas();
	}
}