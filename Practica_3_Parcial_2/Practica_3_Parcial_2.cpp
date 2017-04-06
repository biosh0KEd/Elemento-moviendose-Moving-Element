//Efraín Girón Romero 15300102
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

//Función para pocicionarse en un lugar especifico de la pantalla.
//Function to move us somewhere in the console
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
	//Coodinates
	int x, y;
public:
	//Función para asignar el valor inicial de x
	//Function to assign the value to the x coordinate
	void setX(int a) {
		x = a;
	}
	//Función para asignar el valor inicial de y
	//Function to assign the value to the y coordinate
	void setY(int b) {
		y = b;
	}
	//Función para mover el objeto
	//Function to move the element
	void mover() {
		if (_kbhit()) {
			int tecla = _getch();
			//Condicionales para mover el objeto con las teclas
			//Conditions to move the object with the keyboard
			switch (tecla)
			{
				//Derecha
				//Right
			case 77:
				x++;
				break;
				//Izquierda
				//Left
			case 75:
				x--;
				break;
				//Abajo
				//Down
			case 80:
				y++;
				break;
				//Arriba
				//Up
			case 72:
				y--;
				break;
			}
		}
		//Condicionales para definir el borde
		//Conditions to define the limit
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
	//Función para borrar el elemento de la pantalla
	//Function to delete the element of the display
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
