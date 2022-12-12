#include "raylib.h"
const int screenWidth = 640;
const int screenHeight = 480;

class Sprite {

	int SizeX;
	int SizeY;
public:
	int X;
	int Y;
	Texture2D Texture;
	void display(){
		DrawTexture(Texture,X,Y,WHITE);
	}
	void drawHitbox(Color tint){
		DrawRectangle(X,Y,SizeX,SizeY,tint);
	}
	Rectangle* getHitbox(){
		return nullptr;
	}
	Sprite(Texture2D Texture, int X, int Y){
		this->X = X;
		this->Y = Y;
		this->Texture = Texture;
	}
};

void movePlayer(Sprite*player){
	if(IsKeyPressed(KEY_RIGHT))
		player->X++;
	if(IsKeyPressed(KEY_LEFT))
		player->X--;
	if(IsKeyPressed(KEY_UP))
		player->Y--;
	if(IsKeyPressed(KEY_DOWN))
		player->Y++;
}
int main(){
	InitWindow(screenHeight,screenWidth,"AA");
	SetTargetFPS(60);
	int display = GetCurrentMonitor();
	ToggleFullscreen();
	Sprite player(LoadTexture("player.png"),240,240);
	
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
			ClearBackground(BLACK);
			movePlayer(&player);
			player.display();
			player.drawHitbox(WHITE);
		EndDrawing();
	}
	CloseWindow();
}

