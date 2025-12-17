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

	Proyectile proy(x/2,y,6.0f,5, player);

	while (!WindowShouldClose()) {

		//PANTALLA INICIAL
		if (scp == 0) {
			float recX1 = 200, recY1 = 100;

			Rectangle rec11 = { x / 2.5, y - 200, recX1, recY1 };
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				Vector2 mouse1 = GetMousePosition();
				if (CheckCollisionPointRec(mouse1, rec11)) {
					scp++;
				}
			}

			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("INFO", x / 2.5, y / 2 - 200, 50, WHITE);
			DrawText("Presiona Arriba y Abajo para cambiar la direccion de disparo", 5, y / 2.5, 20, WHITE);
			DrawText("Persiona Izquierda y Derecha para cambiar la velocidad de disparo",5, (y / 2.5) + 30, 20, WHITE);
			DrawText("Persiona W para disparar", 5, (y / 2.5) + 60, 20, WHITE);
			DrawText("Persiona A y D para moverte", 5, (y / 2.5) + 90, 20, WHITE);
			DrawText("Persiona T para cambiar el color de la nave", 5, (y / 2.5) + 120, 20, WHITE);
			DrawText("Persiona R para reiniciar el color de la nave", 5, (y / 2.5) + 150, 20, WHITE);
			DrawRectangle(x / 2.5, y - 200, 200, 100, GREEN);
			DrawText("Jugar", x / 2.3, y - 175, 50, WHITE);

			EndDrawing();
		}

		float dt = GetFrameTime();
		st += dt;
		ste += dt;

		//PANTALLA DE JUEGO
		if (scp == 1) {
			//CREAR ENEMIGOS
			if (st >= 3.0f) {
				z = GetRandomValue(1,3);

				//HORIZONTAL
				if (z == 1) {
					Enemi.emplace_back(
						0,
						GetRandomValue(0, y - 200),
						1,
						120.0f
					);
				}

				//VERTICAL
				else if (z == 2) {
					Enemi.emplace_back(
						GetRandomValue(0, x - 50),
						0,
						2,
						40.0f
					);
				}
				//REBOTE
				else if (z == 3) {
					Enemi.emplace_back(
						0,
						y - 200,
						3,
						60.0f
					);
				}
				st = 0;
			}

			player.MovJugador();
			

			for (Enemigo& e : Enemi) {
				proy.Colision(e);
			}

			BeginDrawing();
			ClearBackground(BLACK);

			player.DrawJugador();
			proy.MovDisparo(player);

			if (proy.IsShoot()) {
				proy.DrawDisparo();
			}

			for (Enemigo& e : Enemi) {
				e.MovEnemi();
				e.DrawEnemi();
			}

			proy.DrawInfo();

			//ELIMINAR ENEMIGOS Y QUITAR UNA VIDA SI SALEN DE LA PANTALLA
			for (int i = 0; i < Enemi.size(); i++) {
				if (Enemi[i].Out()) {
					Enemi.erase(Enemi.begin() + i);
					//Enemi[i].UnDrawEnemi();
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
					proy.SetShoot(false);
					break;
				}
			}
			if (vida == 0) { scp++; }
			EndDrawing();
		}
		
		//PANTALLA FINAL
		if (scp == 2) {

			float recX1 = 200, recY1 = 100;

			Rectangle rec11 = { x / 2.5, y -200, recX1, recY1 };
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				Vector2 mouse1 = GetMousePosition();
				if (CheckCollisionPointRec(mouse1, rec11)) {

					for (int i = 0; i < Enemi.size(); i++) {
						Enemi.erase(Enemi.begin() + i);
						i--;
					}

					scp = 0;
					vida = 10;
					puntos = 0;
					t = 0;
					st = 0;
					ste = 0;
				}
			}

			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("FIN DEL JUEGO", x / 4, y / 2 - 200, 50, WHITE);
			DrawText(TextFormat("Tiempo: %.2f", t), x/3.5, y/2, 30, WHITE);
			DrawText(TextFormat("Puntos: %.d", puntos), x/3.5, (y/2)+30, 30, WHITE);
			DrawRectangle(x / 2.5, y -200, 200, 100, GREEN);
			DrawText("Jugar", x / 2.3, y-175, 50, WHITE);

			EndDrawing();
		}
	}
	CloseWindow();
	for (Enemigo& e : Enemi) {
		e.UnDrawEnemi();
	}
	proy.UnDrawDisp();
	player.UnDrawJugador();
	return 0;
}

