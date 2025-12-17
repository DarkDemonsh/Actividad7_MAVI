#include <iostream>
#ifndef PROYECTILE_H
#define PROYECTILE_H
#include "raylib.h"

class Jugador;
class Enemigo;

class Proyectile {
private:
	float speed;
	int size;
	float g;
	bool shoot;

	Texture2D pro;
	float scala1;

	Vector2 sp;
	Vector2 pos;
	Vector2 npos;
	Vector2 vel;
public:
	Proyectile(int px, int py, float speed, int size, Jugador& p);

	void DrawDisparo();
	void MovDisparo(Jugador& p);
	void Colision(Enemigo& e);
	void DrawInfo();
	void UnDrawDisp();
	
	bool IsShoot() const { return shoot; }
	void SetShoot(bool value) { shoot = value; }

	Vector2 GetVel() const { return vel; }
	Vector2 GetSp() const { return sp; }
	Vector2 GetPos() const { return pos; }
	Vector2 GetNpos() const { return npos; }
}; 
#endif