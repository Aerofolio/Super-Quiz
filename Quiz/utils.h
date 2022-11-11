#pragma warning(disable : 6031)
#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>

void MudaCorDoConsole(int codigoCor) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, codigoCor);
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