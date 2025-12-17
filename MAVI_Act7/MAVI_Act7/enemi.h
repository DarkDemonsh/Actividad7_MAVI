#include <iostream>
#ifndef ENEMI_H
#define ENEMI_H
#include "raylib.h"

class Enemigo {
private:
	int dx;
	int dy;
	int type;
	float speed = 250.0f;
	float g = 0.4f;
	float s = -12.0f;
	bool ehit = false;

	Vector2 p;
	Vector2 v;
	Vector2 rec;
	Vector2 rec2;

public:
	Enemigo(int dx, int dy, int type, float speed);

	void DrawEnemi();
	void MovEnemi();
	bool Out();

	void SetHit(bool v) { ehit = v; }
	bool IsHit() const { return ehit; }

	Vector2 GetP() const { return p; }
	Vector2 GetV() const { return v; }
	Vector2 GetRec() const { return rec; }
	Vector2 GetRec2() const { return rec2; }
};
#endif