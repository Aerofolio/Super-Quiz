#pragma once
#include "sConfiguracoes.h"
#include "sDica.h"
#include "sPergunta.h"
#include "utils.h"
#include "sPlayer.h"

const char* NomeDoJogo = "Super Quiz";
const char* CabecalhoScoreboard = "Scoreboard";
const int CodigoDeCorTexto = 15; //Branco
const int CodigoDeCorTextoOpaco = 7; //Branco Opaco
const int CodigoDeCorTituloECabecalho = 9; //Azul
const int CodigoCorOpcaoMenu = 9; //Azul
const int CodigoCorOpcaoMenuOpaco = 1; //Azul Opaco
const int CodigoCorErro = 12; //Vermelho
const int CodigoCorErroOpaco = 4; //Vermelho Opaco
const int CodigoCorDestaque = 10;//Verde


void ImprimeCabecalho(char titulo[]) {
	MudaCorDoConsole(CodigoDeCorTituloECabecalho);
	printf("==================== ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("%s", titulo);
	MudaCorDoConsole(CodigoDeCorTituloECabecalho);
	printf(" ====================\n\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeMenuPrincipal() {
	ImprimeCabecalho((char*)NomeDoJogo);

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("1");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Iniciar\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("2");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Scoreboard\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("3");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Configurações\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Sair\n\n\n");
	printf("Digite uma opção para continuar: ");
}

void ImprimeErroOpcaoInvalidaMenu() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha uma opção disponível.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroPerguntas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha um valor entre 5 e 99.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroTentativas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha um valor entre 0 e 2.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroPerguntasVerdadeiroEFalso() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! Por favor escolha um valor entre os mostrados abaixo.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroDicasDesativadas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Opção inválida! As dicas estão desativadas, caso queira mudar isso acesse o menu de configurações.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeErroSemRegistrosScoreboard() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Parece que ninguém registrou seu nome aqui ainda!\nPara ter seu nome entre os melhores finalize uma partida e insira seu nome.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeMenu3(Configuracoes configuracoes) {
	ImprimeCabecalho((char*)"Configurações");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("1");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Número de tentativas por pergunta: ");
	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d tentativas\n\n", configuracoes.NumeroDeTentativas);

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("2");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Número de perguntas: ");
	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d perguntas\n\n", configuracoes.NumeroDePerguntas);

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("3");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Ativar perguntas matemáticas: ");
	MudaCorDoConsole(CodigoCorDestaque);
	if (configuracoes.PerguntasGeradas)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("4");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Ativar dicas: ");
	MudaCorDoConsole(CodigoCorDestaque);
	if (configuracoes.DicasAtivadas)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("5");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Voltar as configurações para o padrão\n\n");

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" - Voltar\n\n\n");
	printf("Digite uma opção para continuar: ");
}

void ImprimeInformacaoSobrePontos() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Atenção! ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("A alteração dessa opção mudará os multiplicadores de pontos.\n\n");
}

void ImprimeMenu3Perguntas(int valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d perguntas\n\n", valorAntigo);

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite o novo valor para o número de perguntas: ");
}

void ImprimeMenu3PerguntasMatematica(bool valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	if (valorAntigo)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite se deseja ver perguntas matemáticas (V/F): ");
}

void ImprimeMenu3DicasAtivadas(bool valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	if (valorAntigo)
		printf("Verdadeiro\n\n");
	else
		printf("Falso\n\n");

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite se deseja habilitar as dicas (V/F): ");
}

void ImprimeMenu3Tentativas(int valorAntigo) {
	ImprimeCabecalho((char*)"Configurações");
	ImprimeInformacaoSobrePontos();
	printf("Valor atual: ");

	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d tentativas\n\n", valorAntigo);

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite o novo valor para as tentativas: ");
}

void ImprimePergunta(int numeroPergunta) {
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("Pergunta");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(" %d", numeroPergunta + 1);
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf(":\n\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeEnunciado(Pergunta pergunta) {
	if (pergunta.PerguntaGerada) {
		printf("%d %c %d = ??\n\n", pergunta.Numero1, pergunta.Operacao, pergunta.Numero2);
	}
	else {
		printf(pergunta.Enunciado);
		printf("\n\n");

		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("A");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoA);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("B");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoB);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("C");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoC);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("D");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s", pergunta.OpcaoD);

		printf("\n");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("E");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("%s\n\n", pergunta.OpcaoE);
	}
}

void ImprimePedirResposta(Configuracoes configuracoes) {
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf(" - ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Pular\n");

	if (configuracoes.DicasAtivadas) {
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("[");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("1");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenu);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTexto);
		printf("Dica\n");
	}
	else {
		MudaCorDoConsole(CodigoCorOpcaoMenuOpaco);
		printf("[");
		MudaCorDoConsole(CodigoCorErroOpaco);
		printf("1");
		MudaCorDoConsole(CodigoCorOpcaoMenuOpaco);
		printf("]");
		MudaCorDoConsole(CodigoCorOpcaoMenuOpaco);
		printf(" - ");
		MudaCorDoConsole(CodigoDeCorTextoOpaco);
		printf("Dica\n");
	}

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Enter");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("]");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf(" - ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Resposta\n");
}

void ImprimeDica(Dica dica) {
	MudaCorDoConsole(CodigoCorDestaque);
	printf("Dica: ");
	MudaCorDoConsole(CodigoDeCorTexto);
	if (dica.PerguntaGerada) {
		if (dica.Numero2 > dica.Numero1) {
			printf("%d %c %d = ??\n\n", dica.Numero2, dica.Operacao, dica.Numero1);
		}
		else {
			printf("%d %c %d = ??\n\n", dica.Numero1, dica.Operacao, dica.Numero2);
		}
	}
	else {
		printf("%s\n\n", dica.DicaPerguntaArquivo);
	}
}

void ImprimePontuacaoAcumulada(int pontuacaoAcumulada) {
	const int CodigoCorPontuacao = 10;//Verde

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Pontuação: ");
	MudaCorDoConsole(CodigoCorPontuacao);
	printf("%d\n\n", pontuacaoAcumulada);
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeRepostaErrada() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Resposta errada! Tente Novamente.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeRespostaCerta(int pontosObtidos) {
	MudaCorDoConsole(CodigoCorDestaque);
	printf("Resposta correta! Parabéns! Você ganhou ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("%d", pontosObtidos);
	MudaCorDoConsole(CodigoCorDestaque);
	printf(" pontos.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimePulouPergunta() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Você pulou a pergunta. Você ganhou ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorErro);
	printf(" pontos.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeAcabouAsTentativas() {
	MudaCorDoConsole(CodigoCorErro);
	printf("Acabaram suas tentativas. Você ganhou ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorErro);
	printf(" pontos.\n");
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeTentativasRestantes(int tentativasRestantes) {
	const int CodigoCor0Tentativas = 12;//Vermelho
	const int CodigoCor1Tentativas = 14;//Amarelo
	const int CodigoCorPadraoTentativas = 10;//Verde
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Tentativas restantes: ");
	
	switch (tentativasRestantes) {
	case 0:
		MudaCorDoConsole(CodigoCor0Tentativas);
		break;
	case 1:
		MudaCorDoConsole(CodigoCor1Tentativas);
		break;
	default:
		MudaCorDoConsole(CodigoCorPadraoTentativas);
	}

	printf("%d\n", tentativasRestantes);
	MudaCorDoConsole(CodigoDeCorTexto);
}

void ImprimeTelaFimDeJogo(int pontuacao) {
	ImprimeCabecalho((char*)"Fim de Jogo!");

	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Pontuação Obtida: ");
	MudaCorDoConsole(CodigoCorDestaque);
	printf("%d\n\n", pontuacao);

	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("0");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("] - ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Continuar\n");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("[");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Nome");
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("] - ");
	MudaCorDoConsole(CodigoDeCorTexto);
	printf("Digite seu nome para salvar sua pontuação e pressione enter\n");
}

void ImprimeLinhaDoScoreboard(Player jogador, int posicao) {
	const int InicioNumerosVerdes = 3;
	const int InicioNumerosVermelhos = 7;
	const int CodigoCorTop3 = 10;//Verde
	const int CodigoCorPadrao = 14;//Amarelo
	const int CodigoCorPiores3 = 12;//Vermelho

	if (posicao <= InicioNumerosVerdes) {
		MudaCorDoConsole(CodigoCorTop3);
	}
	else if (posicao <= InicioNumerosVermelhos) {
		MudaCorDoConsole(CodigoCorPadrao);
	}
	else {
		MudaCorDoConsole(CodigoCorPiores3);
	}

	printf("%dº", posicao);
	MudaCorDoConsole(CodigoDeCorTexto);
	printf(": %s ", jogador.NomeDoJogador);
	MudaCorDoConsole(CodigoCorOpcaoMenu);
	printf("-");

	if (posicao <= InicioNumerosVerdes) {
		MudaCorDoConsole(CodigoCorTop3);
	}
	else if (posicao <= InicioNumerosVermelhos) {
		MudaCorDoConsole(CodigoCorPadrao);
	}
	else {
		MudaCorDoConsole(CodigoCorPiores3);
	}

	printf(" %d\n", jogador.Pontuacao);
	MudaCorDoConsole(CodigoDeCorTexto);
}
