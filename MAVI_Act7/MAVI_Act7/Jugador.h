#include <iostream>
#ifndef JUGADOR_H
#define JUGADOR_H
#include "raylib.h"

class Enemigo;

class Jugador {
private:
	int px;
	int py;
	float speed = 20.0f;
	Vector2 pos;
	Vector2 l1;
	Vector2 l2;
	Vector2 l3;
public:
	Jugador(int px, int py, float speed);

	void DrawJugador();
	void MovJugador();
	void Colision(Enemigo& e);

	Vector2 GetPos() const { return pos; }
	Vector2 GetL1() const { return l1; }
	Vector2 GetL2() const { return l2; }
	Vector2 GetL3() const { return l3; }
};

#endif