#include <iostream>
#include "raylib.h"
#include "enemi.h"
#include "Jugador.h"
#include "Proyectile.h"
#include "Global.h"
#include <vector>

float st = 0;
float ste = 0;
int z = 0;

int main()
{
	InitWindow(x,y,"act7");
	SetTargetFPS(60);

	std::vector<Enemigo> Enemi;
	
	Jugador player(x/2,y-100,4.0f);

	Proyectile proy(x/2,y,7.0f,5, player);

	while (!WindowShouldClose()) {

		float dt = GetFrameTime();
		st += dt;
		ste += dt;

//CREAR ENEMIGOS
		if (st >= 2.0f) {
			z = GetRandomValue(1,2);
			
		//HORIZONTAL
			if (z == 1) {
				Enemi.emplace_back(
					0,
					GetRandomValue(0,y-200),
					1,
					120.0f
				);
			}

		//VERTICAL
			else if (z == 2) {
				Enemi.emplace_back(
					GetRandomValue(0,x-50),
					0,
					2,
					40.0f
				);
			}
			st = 0;
		}

		//REBOTE
		if (ste >= 17.0f) {
			Enemi.emplace_back(
				0,
				y-200,
				3,
				60.0f
			);
			ste = 0;
		}

		
		player.MovJugador();
		proy.MovDisparo(player);

		for (Enemigo& e : Enemi) {
			proy.Colision(e);
		}

		BeginDrawing();
		ClearBackground(BLACK);

		player.DrawJugador();
		proy.DrawDisparo();

		for (Enemigo& e : Enemi) {
			e.MovEnemi();
			e.DrawEnemi();
		}

		proy.DrawInfo();

		//ELIMINAR ENEMIGOS Y QUITAR UNA VIDA SI SALEN DE LA PANTALLA
		for (int i = 0; i < Enemi.size(); i++) {
			if (Enemi[i].Out()) {
				Enemi.erase(Enemi.begin() + i);
				i--;
				vida--;
			}
		}

		//ELIMINAR Y DAR 10 PUNTOS SI SON IMPACTADOS
			for (int i = 0; i < Enemi.size(); i++) {
				if (Enemi[i].IsHit()) {
					Enemi.erase(Enemi.begin() + i);
					i--;
					puntos += 10;
				}
			}

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

