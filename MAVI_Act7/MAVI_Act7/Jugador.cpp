#include <iostream>
#include "raylib.h"
#include "Jugador.h"

Jugador::Jugador(int px, int py, float sp) {
	
	speed = sp;
	pos = { (float)px, (float)py };
}

void Jugador::DrawJugador() {

	l1 = { pos.x, pos.y };
	l2 = { pos.x + 30, pos.y };
	l3 = { pos.x + 15, pos.y - 30 };

	DrawTriangle(l1,l2,l3, GREEN);
}

void Jugador::MovJugador() {

	if (IsKeyDown(KEY_A))  pos.x -= speed ;
	if (IsKeyDown(KEY_D))  pos.x += speed ;

}