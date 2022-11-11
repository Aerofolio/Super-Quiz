#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <time.h>

#include "impressao.h"
#include "sConfiguracoes.h"
#include "menu1.h"
#include "menu2.h"
#include "menu3.h"

const int ValorInicialSegundos = 30;
const int ValorInicialPerguntas = 10;
const bool ValorInicialPerguntasGeradas = true;

int main()
{
	setlocale(0, "portuguese");
	srand(time(NULL));
	int opcaoMenu;
	Configuracoes configuracoes = { ValorInicialSegundos, ValorInicialPerguntas, ValorInicialPerguntasGeradas };
	
	do {
		ImprimeMenuPrincipal();
		scanf("%d", &opcaoMenu);
		system("CLS");

		switch (opcaoMenu) {
			case 0:
				return 0;
			case 1:
				MenuOpcao1(configuracoes);
				break;
			case 2:
				MenuOpcao2();
				break;
			case 3:
				MenuOpcao3(&configuracoes);
				break;
			default:
				ImprimeErroOpcaoInvalidaMenu();
		}
	} while (true);
}