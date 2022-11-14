#pragma once
#include "sConfiguracoes.h"
#include "sPergunta.h"
#include "utils.h"
#include "impressao.h"

void MenuOpcao1(Configuracoes configuracoes) {
	for (int i = 0; i < configuracoes.NumeroDePerguntas; i++) {
		Pergunta pergunta;
		int tipoDePergunta = RetornaNumeroAleatorioEntre(0, 1);
		int tentativas = 0;

		if (configuracoes.PerguntasGeradas && tipoDePergunta == 1) {
			pergunta = GeradorDePerguntas();

			//pegunta gerada
			//Funcao que gera a pergunta, manda a pergunta pointer como paramentro 
		}
		else {
			pergunta.Dica = (char*)"Esta � uma dica!";
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
			ImprimeCabecalho((char*)NomeDoJogo);
			ImprimePergunta(i);
			if (tentativas > 0) {
				ImprimeDica(pergunta);
			}
			ImprimeEnunciado(pergunta);
			ImprimeTentativasRestantes(configuracoes.NumeroDeTentativas - tentativas);
			ImprimePedirResposta();

			if (pergunta.PerguntaGerada) {
				int respostaLida;
				scanf("%d", &respostaLida);
				system("CLS");

				if (respostaLida == pergunta.RespostaMatematica) {
					tentativas = 0;
					ImprimeRespostaCerta();
					break;
				}
				else if (respostaLida == 0) {
					//n�o soma nada a pontua��o
					break;
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
					tentativas = 0;
					ImprimeRespostaCerta();
					break;
				}
				else if (respostaLida == '0') {

					break;
				}
				else {
					tentativas++;
					if (tentativas > configuracoes.NumeroDeTentativas)
						break;
					ImprimeRepostaErrada();
					continue;
				}
			}
		} while (true);
	}
	system("CLS");
}