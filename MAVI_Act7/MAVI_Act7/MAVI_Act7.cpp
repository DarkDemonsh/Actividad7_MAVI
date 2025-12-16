#include <iostream>
#include "raylib.h"
#include "enemi.h"
#include "Jugador.h"
#include "Proyectile.h"
#include <vector>

float st = 0;
float ste = 0;
int z = 0;
int x = 800, y = 600;

int main()
{
	InitWindow(x,y,"act7");
	SetTargetFPS(60);

	std::vector<Enemigo> Enemi;

	Jugador player(x/2,y,4.0f);

	Proyectile proy(x/2,y,5.0f,5, player);

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();
		st += dt;
		ste += dt;
		if (st >= 2.0f) {
			z = GetRandomValue(1,2);
			if (z == 1) {
				Enemi.emplace_back(
					0,
					GetRandomValue(0,500),
					1,
					120.0f
				);
			}
			else if (z == 2) {
				Enemi.emplace_back(
					GetRandomValue(0,750),
					0,
					2,
					40.0f
				);
			}
			st = 0;
		}
		if (ste >= 17.0f) {
			Enemi.emplace_back(
				0,
				500,
				3,
				60.0f
			);
			ste = 0;
		}

		
		player.MovJugador();
		proy.MovDisparo(player);

		BeginDrawing();
		ClearBackground(BLACK);

		DrawText(TextFormat("Especial: %.2f", ste), 0, 10, 10, WHITE);
		DrawText(TextFormat("Tiempo: %.2f", st), 0, 0, 10, WHITE);

		player.DrawJugador();
		proy.DrawDisparo();

		for (Enemigo& e : Enemi) {
			e.MovEnemi();
			e.DrawEnemi();
		}

		for (int i = 0; i < Enemi.size(); i++) {
			if (Enemi[i].Out()) {
				Enemi.erase(Enemi.begin() + i);
				i--;
			}
		}

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

