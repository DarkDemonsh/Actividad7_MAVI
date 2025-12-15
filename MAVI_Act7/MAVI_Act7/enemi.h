#include <iostream>
#include "raylib.h";

class Enemigo {
private:
	int px;
	int py;
	int type;
	float speed = 250.0f;
	const float g = 0.4f;
	const float s = -12.0f;
	Vector2 p;
	Vector2 p1;
	Vector2 p2;
	Vector2 v;
	Vector2 v1;
	Vector2 v2;
public:
	Enemigo(int px, int py, int type, float speed);

	void DrawEnemi(int type);
	void MovEnemi(int type);

	Vector2 GetP() const { return p; }
	Vector2 GetP1() const { return p1; }
	Vector2 GetP2() const { return p2; }
	Vector2 GetV() const { return v; }
	Vector2 GetV1() const { return v1; }
	Vector2 GetV2() const { return v2; }
};