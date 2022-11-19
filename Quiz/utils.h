#pragma warning(disable : 6031)
#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>

unsigned char GetColorCode(unsigned char colorBackground, unsigned char colorForeground);

void MudaCorDoConsole(int codigoCor, int codigoFundo = 0) {
	unsigned char CodigoCorBackGround = codigoFundo; //preto
	unsigned char CodigoCorForeground = codigoCor; //preto
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char colorCode = GetColorCode(CodigoCorBackGround, CodigoCorForeground);

	SetConsoleTextAttribute(hConsole, colorCode);
}

void Continuar() {
	printf("\nPressione qualquer tecla para continuar: ");
	fflush(stdin);
	getche();
	system("CLS");
}

int RetornaNumeroAleatorioEntre(int min, int max) {
	max += 1;
	return min + rand() % (max - (min));
}

unsigned char GetColorCode(unsigned char colorBackground, unsigned char colorForeground)
{
	return (colorBackground << 4) + colorForeground;
}