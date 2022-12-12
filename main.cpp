#include "raylib.h"
const int screenWidth = 640;
const int screenHeight = 480;
const int playerSpeed = 2;

class Sprite {
	int X;
	int Y;
	Texture2D Texture;

	int SizeX;
	int SizeY;
public:
	void display(){
		DrawTexture(Texture,X,Y,WHITE);
	}
	void drawHitbox(Color tint){
		DrawRectangle(X,Y,SizeX,SizeY,tint);
	}
	Rectangle* getHitbox(){
		return nullptr;
	}
	Sprite(Texture2D Texture, int X, int Y, int SizeX, int SizeY){
		this->X = X;
		this->Y = Y;
		this->SizeX = SizeX;
		this->SizeY = SizeY;
		this->Texture = Texture;
	}
	void moveX(int move){
		int Xmax = screenWidth-SizeX;
		int Xmin = 0;
		move+=X;
		if(move>=Xmax){
			move=Xmax;
		}
		if(move<Xmin){
			move=Xmin;
		}
		X=move;
	}
	void moveY(int move){
		int Ymax = screenHeight-SizeY;
		int Ymin = 0;
		move+=Y;
		if(move>=Ymax){
			move=Ymax;
		}
		if(move<Ymin){
			move=Ymin;
		}
		Y=move;
	}
};

void movePlayer(Sprite *player){
	int speed = IsKeyDown(KEY_LEFT_SHIFT)?playerSpeed/2:playerSpeed;

	if(IsKeyDown(KEY_RIGHT))
		player->moveX(speed);
	if(IsKeyDown(KEY_LEFT))
		player->moveX(-speed);
	if(IsKeyDown(KEY_UP))
		player->moveY(-speed);
	if(IsKeyDown(KEY_DOWN))
		player->moveY(speed);
}
int main(){
	InitWindow(screenHeight,screenWidth,"AA");
	SetTargetFPS(60);
	int display = GetCurrentMonitor();
	ToggleFullscreen();
	Sprite player(LoadTexture("player.png"),240,240,32,32);
	
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

