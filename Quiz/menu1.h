#pragma once
#include "sConfiguracoes.h"
#include "sPergunta.h"
#include "utils.h"
#include "impressao.h"

void MenuOpcao1(Configuracoes configuracoes) {
	const int MultiplicadorDePontuacao = 10;
	const int PontosPorDica = 5;
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
			dica.DicaPerguntaArquivo = (char*)"Esta é uma dica!";
			dica.PerguntaGerada = false;
			pergunta.Enunciado = (char*)"Este é o enunciado?";
			pergunta.PerguntaGerada = false;
			pergunta.OpcaoA = (char*)"Esta é a opção A!";
			pergunta.OpcaoB = (char*)"Esta é a opção B!";
			pergunta.OpcaoC = (char*)"Esta é a opção C!";
			pergunta.OpcaoD = (char*)"Esta é a opção D!";
			pergunta.OpcaoE = (char*)"Esta é a opção E!";
			pergunta.Resposta = 'A';
			//pergunta do arquivo
			//função que retorna a pergunta do arquivo
		}

		do {
			int tentativasRestantes = configuracoes.NumeroDeTentativas - tentativas;
			ImprimeCabecalho((char*)NomeDoJogo);
			ImprimePergunta(i);
			if (pediuDica) {
				ImprimeDica(dica);
			}
			ImprimeEnunciado(pergunta);
			ImprimeTentativasRestantes(tentativasRestantes);
			ImprimePedirResposta();

			if (pergunta.PerguntaGerada) {
				int respostaLida;
				scanf("%d", &respostaLida);
				system("CLS");

				if (respostaLida == pergunta.RespostaMatematica) {
					int pontosObtidos = (tentativasRestantes + 1) * MultiplicadorDePontuacao;
					if(pediuDica)
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
					pediuDica = true;
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
					if (pediuDica)
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
					pediuDica = true;
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
	system("CLS");

	printf("Pontos totais: %d", pontuacao);
}