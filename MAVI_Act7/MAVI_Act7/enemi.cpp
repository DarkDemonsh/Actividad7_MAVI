#include <iostream>
#include "raylib.h"
#include "enemi.h"
#include "Global.h"

bool salto = false;
float salto1 = 0.0f;

Enemigo::Enemigo(int dx, int dy, int t, float speed) {

	p = { (float)dx, (float)dy };
	v = { speed, 50.0f };

	type = t;

	rec2 = { 20, 20 };
	rec = { 40, 20 };
}

void Enemigo::DrawEnemi() {
//ENEMIGO HORIZONTAL
	if (type == 1) {
		DrawRectangleV(p, rec, Color{ ORANGE });
	}

//ENEMIGO VERTICAL
	if (type == 2) {
		DrawRectangleV(p, rec2, Color{ RED });
	}

//ENEMIGO CON REBOTE
	if (type == 3) {
		DrawCircleV(p, 20, Color{ PURPLE });
	}
}

void Enemigo::MovEnemi() {
	float deltaTime = GetFrameTime();
	
//ENEMIGO HORIZONTAL
	if (type == 1) {
	p.x += v.x * deltaTime;
		if (p.x <= 0) {
			p.x = 0;
			v.x = +v.x;
		}
	}

//ENEMIGO VERTICAL
	if (type == 2) {
	p.y += v.y * deltaTime;
		if (p.y <= 0 || p.y >= y-100) {
			v.y = +v.y;
		}
	}

//ENEMIGO CON REBOTE
	if (type == 3) {
	p.x += v.x * deltaTime;
		if (!salto) {
			salto = true;
			salto1 = s;
		}
		if (salto) {
			p.y += salto1;
			salto1 += g;

			if (p.y >= y-110) {
				salto = false;
				salto1 = 0;
			}
		}
	}

}

bool Enemigo::Out() {
	if(type == 1){ return p.y > y-90 || p.x < -50 || p.x > x+50; }
	if(type == 2){ return p.y > y-90 || p.x < -50 || p.x > x+50; }
	if(type == 3){ return p.y > y-90 || p.x < -50 || p.x > x+50; }
	return false;
}
