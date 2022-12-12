#include "raylib.h"
const int screenWidth = 640;
const int screenHeight = 480;

int main(){
	InitWindow(screenHeight,screenWidth,"AA");
	SetTargetFPS(60);
	int display = GetCurrentMonitor();
	ToggleFullscreen();
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Press Alt + Enter to Toggle full screen!", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
}
