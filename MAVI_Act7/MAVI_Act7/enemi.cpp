#include <iostream>
#include "raylib.h"
#include "enemi.h"
#include "Global.h"

Enemigo::Enemigo(int dx, int dy, int t, float speed) {

	p = { (float)dx, (float)dy };
	v = { speed, 50.0f };

	type = t;
	vy = 0.0f;

	rec2 = { 20, 20 };
	rec = { 40, 20 };

	e1 = LoadTexture("assets/img/e1.png");
	scala1 = fminf(40.0f / e1.width, 40.0f / e1.height);

	e2 = LoadTexture("assets/img/e2.png");
	scala2 = fminf(20.0f / e2.width, 20.0f / e2.height);

	e3 = LoadTexture("assets/img/e3.png");
	scala3 = fminf(40.0f / e3.width, 40.0f / e3.height);

}

void Enemigo::DrawEnemi() {
//ENEMIGO HORIZONTAL
	if (type == 1) {
		//DrawRectangleV(p, rec, Color{ RED });
		DrawTextureEx(e1,p,0.0f,scala1,WHITE);
	}

//ENEMIGO VERTICAL
	if (type == 2) {
		//DrawRectangleV(p, rec2, Color{ ORANGE });
		DrawTextureEx(e2, p, 0.0f, scala2, WHITE);
	}

//ENEMIGO CON REBOTE
	if (type == 3) {
		//DrawCircleV(p, 20, Color{ PURPLE });
		Vector2 tp = { p.x, p.y - 30 };
		DrawTextureEx(e3, tp, 45.0f, scala3, WHITE);
	}
}

void Enemigo::MovEnemi() {
	float deltaTime = GetFrameTime();
	
//ENEMIGO HORIZONTAL
	if (type == 1) {
	p.x += v.x * deltaTime;
		if (p.x <= 0) {
			p.x = 0;
			v.x = -v.x;
		}
	}

//ENEMIGO VERTICAL
if (type == 2) {
	vy += g * deltaTime;
	p.y += vy * deltaTime;

	if (p.y <= 0) {
		p.y = 0;
		vy = -vy;
	}
}

//ENEMIGO CON REBOTE
	if (type == 3) {

	vy += g * deltaTime;
	p.y += vy * deltaTime;

	if (p.y >= y-110) {
		p.y = y -110;
		vy = -vy * 0.8f;
	}

	p.x += v.x * deltaTime;

	if (p.x <= 0) {
		p.x = 0;
		v.x += v.x;
	}
}
}

void Enemigo::UnDrawEnemi() {
	UnloadTexture(e1);
	UnloadTexture(e2);
	UnloadTexture(e3);
}

bool Enemigo::Out() {
	if(type == 1){ return p.y > y-90 || p.x < -50 || p.x > x+50; }
	if(type == 2){ return p.y > y-90 || p.x < -50 || p.x > x+50; }
	if(type == 3){ return p.y > y-90 || p.x < -50 || p.x > x+50; }
	return false;
}
