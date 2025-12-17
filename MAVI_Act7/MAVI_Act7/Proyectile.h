#include <iostream>
#ifndef PROYECTILE_H
#define PROYECTILE_H
#include "raylib.h"

class Jugador;
class Enemigo;

class Proyectile {
private:
	int px;
	int py;
	float speed;
	int size;

	bool shoot;
	bool per;

	Vector2 sp;
	Vector2 pos;
	Vector2 npos;
public:
	Proyectile(int px, int py, float speed, int size, Jugador& p);

	void DrawDisparo();
	void MovDisparo(Jugador& p);
	void Colision(Enemigo& e);
	void DrawInfo();

	Vector2 GetSp() const { return sp; }
	Vector2 GetPos() const { return pos; }
	Vector2 GetNpos() const { return npos; }
}; 
#endif