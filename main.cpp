#include "raylib.h"
const int screenWidth = 640;
const int screenHeight = 480;

class Sprite {
	int X;
	int Y;
	Texture2d Texture;

	int SizeX;
	int SizeY;

	void display(){
		DrawTexture(texture,X,Y,WHITE);
	}
	void drawHitbox(Color tint){
		DrawRectangle(X,Y,SizeX,SizeY,tint);
	}
	Rectangle getHitbox(){

	}

}

int main(){
	InitWindow(screenHeight,screenWidth,"AA");
	SetTargetFPS(60);
	int display = GetCurrentMonitor();
	ToggleFullscreen();
	
	Texture2D playerTexture = LoadTexture("player.png");
	
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);
			ClearBackground(BLACK);
			DrawText("Press Alt + Enter to Toggle full screen!", 190, 200, 20, LIGHTGRAY);
		        DrawTexture(playerTexture, posX, posY, WHITE);
		EndDrawing();
	}
	CloseWindow();
}

