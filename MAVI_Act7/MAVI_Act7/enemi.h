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

	Vector2 p;
	Vector2 p1;
	Vector2 p2;

	Vector2 v;
	Vector2 v1;
	Vector2 v2;
public:
	Enemigo(int dx, int dy, int type, float speed);

	void DrawEnemi();
	void MovEnemi();
	bool Out();

	Vector2 GetP() const { return p; }
	Vector2 GetP1() const { return p1; }
	Vector2 GetP2() const { return p2; }

	Vector2 GetV() const { return v; }
	Vector2 GetV1() const { return v1; }
	Vector2 GetV2() const { return v2; }
};
#endif