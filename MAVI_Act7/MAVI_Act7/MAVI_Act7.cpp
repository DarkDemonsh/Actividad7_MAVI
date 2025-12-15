#include <iostream>
#include "raylib.h";
#include "enemi.h";
#include "Jugador.h";
#include <vector>

float st = 0;
int z = 0;

int main()
{
	InitWindow(800,600,"act7");
	SetTargetFPS(60);

	std::vector<Enemigo> Enemi;

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();
		st += dt;
		if (st >= 2.0f) {
			z = GetRandomValue(1, 2);
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

		BeginDrawing();
		ClearBackground(RAYWHITE);

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

