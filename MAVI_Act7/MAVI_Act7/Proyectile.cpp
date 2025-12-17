#include <iostream>
#include "raylib.h"
#include "Proyectile.h"
#include "Jugador.h"
#include "enemi.h"
#include "Global.h"

class Enemigo;
float t = 0;

Proyectile::Proyectile(int px, int py, float s, int t, Jugador& p) {

	pos = {(float)px, (float)py};

	size = t;

	speed = s;

	shoot = false;

	per = false;

	npos = { 0,0 };

}

void Proyectile::DrawDisparo() {
	DrawCircleV(pos, size, PINK);
}

void Proyectile::MovDisparo(Jugador& p) {
	if (!shoot) {

		//CONTROL DE DIRECCION	
		if (npos.x <= 3) {
			if (IsKeyPressed(KEY_UP)) {
				npos.x += 1;
			};
		}
		if (npos.x >= -3) {
			if (IsKeyPressed(KEY_DOWN)) {
				npos.x -= 1;
			};
		}

		//CONTROL DE VELOCIDAD
		if (speed <= 9) {
			if (IsKeyPressed(KEY_LEFT)) { speed += 1; };
		}
		if (speed >= 5) {
			if (IsKeyPressed(KEY_RIGHT)) { speed -= 1; };
		}
	}

//DISPARO
	if (IsKeyPressed(KEY_W) && !shoot) {
		sp = p.GetPos();
		pos = { sp.x + 15, sp.y - 30 };
		shoot = true;
	}

	 if (shoot) {
		pos.y -= speed;
		pos.x -= npos.x;
	}

	if (pos.y <= -1) { shoot = false;}

}

void Proyectile::Colision(Enemigo& e) {

	Rectangle r = { e.GetP().x, e.GetP().y,e.GetRec().x, e.GetRec().y };

	if (CheckCollisionCircleRec(pos, 10.0f, r)) {
		e.SetHit(true);
	}

}

void Proyectile::DrawInfo() {
	Vector2 pp = {0,y-75};
	Vector2 pt = { x,75};
	Vector2 pp1 = { 0,y-100 };
	Vector2 pt1 = { x,25 };

	float ti = GetFrameTime();
	t += ti;

	DrawRectangleV(pp1, pt1, LIGHTGRAY);
	DrawRectangleV(pp, pt, WHITE);
	DrawText(TextFormat("Posicion_X: %.2f", npos.x), 0, y-70, 20, BLACK);
	DrawText(TextFormat("Velocidad: %.2f", speed), 0, y-50, 20, BLACK);
	DrawText(TextFormat("FPS: %.d", GetFPS()), 0, y-30, 20, BLACK);
	DrawText(TextFormat("Tiempo: %.2f", t), 200, y-70, 20, BLACK);
	DrawText(TextFormat("Vida: %.d", vida), 200, y-50, 20, BLACK);
	DrawText(TextFormat("Puntos: %.d", puntos), 200, y-30, 20, BLACK);
}