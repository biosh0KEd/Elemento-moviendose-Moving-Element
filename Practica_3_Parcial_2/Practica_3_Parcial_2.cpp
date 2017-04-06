//Efraín Girón Romero 15300102
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

//Función para pocicionarse en un lugar especifico de la pantalla.
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

class Elemento {
private:
	//Coordenadas
	int x, y;
public:
	//Función para asignar el valor inicial de x
	void setX(int a) {
		x = a;
	}
	//Función para asignar el valor inicial de y
	void setY(int b) {
		y = b;
	}
	//Función para mover el objeto
	void mover() {
		if (_kbhit()) {
			int tecla = _getch();
			//Condicionales para mover el objeto con las teclas
			switch (tecla)
			{
				//Derecha
			case 77:
				x++;
				break;
				//Izquierda
			case 75:
				x--;
				break;
				//Abajo
			case 80:
				y++;
				break;
				//Arriba
			case 72:
				y--;
				break;
			}
		}
		//Condicionales para definir el borde
		if (x > 78) {
			x--;
		}
		if (x < 0) {
			x++;
		}
		if (y > 25) {
			y--;
		}
		if (y < 0) {
			y++;
		}
		gotoxy(x, y);
		cout << ":)";
	}
	void borrar() {
		gotoxy(x, y);
		cout << "  ";
	}
};

int main() {
	Elemento Caracter;
	Caracter.setX(40);
	Caracter.setY(12);
	bool repetir = true;
	while (repetir) {
		Caracter.mover();
		Sleep(60);
		Caracter.borrar();
	}
	return 0;
}
