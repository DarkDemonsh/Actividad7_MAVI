#include <iostream>
#include "raylib.h"
#include "Proyectile.h"
#include "Jugador.h"
#include "enemi.h"
#include "Global.h"

Proyectile::Proyectile(int px, int py, float s, int t, Jugador& p) {

	pos = {(float)px, (float)py};

	size = t;

	speed = s;

	shoot = false;

	npos = { 0,0 };

	g = 10.0f;
	vel = { 0.0f,0.0f };

	pro = LoadTexture("assets/img/disp.png");
	scala1 = fminf(10.0f / pro.width, 10.0f / pro.height);

}

void Proyectile::DrawDisparo() {
	//DrawCircleV(pos, size, PINK);
	Vector2 tp = { pos.x - 5, pos.y - 5 };
	DrawTextureEx(pro, tp, 0.0f, scala1, WHITE);
}

void Proyectile::UnDrawDisp() {
	UnloadTexture(pro);
}

void Proyectile::MovDisparo(Jugador& p) {
	if (!shoot) {

		//CONTROL DE DIRECCION	
		if (npos.x <= 1) {
			if (IsKeyPressed(KEY_UP)) {
				npos.x += 0.25f;
			};
		}
		if (npos.x >= -1) {
			if (IsKeyPressed(KEY_DOWN)) {
				npos.x -= 0.25f;
			};
		}

		//CONTROL DE VELOCIDAD
		if (speed <= 19) {
			if (IsKeyPressed(KEY_LEFT)) { speed += 2; };
		}
		if (speed >= 3) {
			if (IsKeyPressed(KEY_RIGHT)) { speed -= 2; };
		}
	}

//DISPARO
	if (IsKeyPressed(KEY_W) && !shoot) {
		sp = p.GetPos();
		pos = { sp.x + 15, sp.y - 30 };

		vel.x = -npos.x * speed * 60;
		vel.y = -speed * 120;

		shoot = true;
	}

	 if (shoot) {
		 float dt = GetFrameTime();

		 vel.y += g * dt;
		 pos.y += vel.y * dt;
		 pos.x += vel.x * dt;
	}

	if (pos.y <= -10) {
		shoot = false;
	}

}

void Proyectile::Colision(Enemigo& e) {

	Rectangle r = { e.GetP().x, e.GetP().y,e.GetRec().x, e.GetRec().y };

	if (CheckCollisionCircleRec(pos, 10.0f, r)) {
		e.SetHit(true);
		pos = { -100, -100 };
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
	DrawText(TextFormat("Posicion_X: %.2f", npos.x), 5, y-70, 20, BLACK);
	DrawText(TextFormat("Velocidad: %.2f", speed), 5, y-50, 20, BLACK);
	DrawText(TextFormat("FPS: %.d", GetFPS()), 5, y-30, 20, BLACK);
	DrawText(TextFormat("Tiempo: %.2f", t), x-400, y-70, 20, BLACK);
	DrawText(TextFormat("Vida: %.d", vida), x-400, y-50, 20, BLACK);
	DrawText(TextFormat("Puntos: %.d", puntos), x-400, y-30, 20, BLACK);
}