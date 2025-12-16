#include <iostream>
#include "raylib.h"
#include "Proyectile.h"
#include "Jugador.h"
#include "enemi.h"

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

		if (speed <= 6) {
			if (IsKeyPressed(KEY_LEFT)) { speed += 1; };
		}
		if (speed >= 3) {
			if (IsKeyPressed(KEY_RIGHT)) { speed -= 1; };
		}
	}

	if (IsKeyPressed(KEY_W) && !shoot) {
		sp = p.GetPos();
		pos = { sp.x + 15, sp.y - 30 };
		shoot = true;
	}

	 if (shoot) {
		pos.y -= speed;
		pos.x -= npos.x;
	}

	if (pos.y <= 1) { shoot = false;}

	DrawText(TextFormat("Posicion_X: %.2f", npos.x), 0, 50, 20, WHITE);
	DrawText(TextFormat("Velocidad: %.2f", speed), 0, 30, 20, WHITE);
}
