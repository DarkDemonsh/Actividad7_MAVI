#include <iostream>
#ifndef ENEMI_H
#define ENEMI_H
#include "raylib.h"

class Enemigo {
private:

	Texture2D e1;
	Texture2D e2;
	Texture2D e3;
	float scala1;
	float scala2;
	float scala3;

	int type;
	float g = 10.0f;
	bool ehit = false;
	float vy;

	Vector2 p;
	Vector2 v;
	Vector2 rec;
	Vector2 rec2;

public:
	Enemigo(int dx, int dy, int type, float speed);

	void DrawEnemi();
	void UnDrawEnemi();
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