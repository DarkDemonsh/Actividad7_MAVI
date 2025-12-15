#include <iostream>
#include "raylib.h";
#include  "enemi.h";

int x = 800, y = 600;
int rebote = 0;
bool salto = false;
float salto1 = 0.0f;

Enemigo::Enemigo(int px, int py, int t, float speed) {

	p = { (float)px, (float)py };
	p1 = { (float)px, (float)py };
	p2 = { (float)px, (float)py };
	v = { speed, 50.0f };
	v1 = { speed, 75.0f };
	v2 = { speed, 50.0f };

	type = t;

}

void Enemigo::DrawEnemi() {

	Vector2 rec = {40, 20};
	Vector2 rec2 = { 20, 20 };

	if (type == 1) {
		DrawRectangleV(p, rec, Color{ GREEN });
	}
	if (type == 2) {
		DrawRectangleV(p1, rec2, Color{ RED });
	}
	if (type == 3) {
		DrawCircleV(p2, 20, Color{ PURPLE });
	}
}

void Enemigo::MovEnemi() {
	float deltaTime = GetFrameTime();
	
	if (type == 1) {
	p.x += v.x * deltaTime;
		if (p.x <= 0) {
			p.x = 0;
			v.x = -v.x;
		}
	}
	
	if (type == 2) {
	p1.y += v1.y * deltaTime;
		if (p1.y <= 0 || p1.y >= 600) {
			v1.y = -v1.y;
		}
	}

	if (type == 3) {
	p2.x += v2.x * deltaTime;
		if (!salto) {
			salto = true;
			salto1 = s;
		}
		if (salto) {
			p2.y += salto1;
			salto1 += g;

			if (p2.y >= y - 10) {
				salto = false;
				salto1 = 0;
			}
		}
		if (p2.x >= x) {
			p2.x = x;
			v2.x = -v2.x;
		}
		else if (p2.x <= 0) {
			p2.x = 0;
			v2.x = -v2.x;
		}
	}

}

bool Enemigo::Out() {
	if(type == 1){ return p.y > 650 || p.x < -50 || p.x > 850; }
	if(type == 2){ return p1.y > 650 || p1.x < -50 || p1.x > 850; }
	if(type == 3){ return p2.y > 650 || p2.x < -50 || p2.x > 850; }
	return false;
}