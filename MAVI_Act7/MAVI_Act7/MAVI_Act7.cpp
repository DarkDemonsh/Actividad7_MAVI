#include <iostream>
#include "raylib.h";
#include "enemi.h";
#include "Jugador.h";

int main()
{
	InitWindow(800,600,"act7");
	SetTargetFPS(60);

	Enemigo e(0,0,0, 40.0f);

	Enemigo e1(0, 0, 0, 40.0f);

	Enemigo e2(0, 600, 0, 100.0f);

	while (!WindowShouldClose()) {

		e.MovEnemi(1);
		e1.MovEnemi(2);
		e2.MovEnemi(3);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		e.DrawEnemi(1);
		e1.DrawEnemi(2);
		e2.DrawEnemi(3);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

