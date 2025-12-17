#include <iostream>
#include "raylib.h"
#include "Jugador.h"
#include "enemi.h"
#include "Global.h"

class Enemigo;
Color RGB = WHITE;

void rgb() {
	RGB = {
	(unsigned char)GetRandomValue(0, 255),
	(unsigned char)GetRandomValue(0, 255),
	(unsigned char)GetRandomValue(0, 255),
	255
	};
}

Jugador::Jugador(int px, int py, float sp) {
	
	speed = sp;
	pos = { (float)px, (float)py };

	p1 = LoadTexture("assets/img/pj.png");
	scala1 = fminf(50.0f / p1.width, 50.0f / p1.height);
}

void Jugador::DrawJugador() {

	l1 = { pos.x, pos.y };
	l2 = { pos.x + 30, pos.y };
	l3 = { pos.x + 15, pos.y - 30 };

	//DrawTriangle(l1,l2,l3, GREEN);
	Vector2 tp = { pos.x - 10, pos.y - 40 };
	DrawTextureEx(p1, tp, 0.0f, scala1, RGB);
}

void Jugador::UnDrawJugador() {
	UnloadTexture(p1);
}

void Jugador::MovJugador() {

	if (IsKeyDown(KEY_A))  pos.x -= speed ;
	if (IsKeyDown(KEY_D))  pos.x += speed ;
	if (IsKeyPressed(KEY_T)) { rgb(); };
	if (IsKeyPressed(KEY_R)) { RGB = WHITE; };

	if (pos.x <= 0) { pos.x += speed; }
	if (pos.x >= x-30) { pos.x -= speed; }

}
