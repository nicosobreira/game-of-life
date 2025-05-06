#include "raylib.h"

#include <stdbool.h>
#include <stdint.h>

#include "render_scaling.h"
#include "vector.h"
#include "math_utils.h"

#define FPS (60)

#define FONT_SIZE (20)

typedef struct Game
{
	camera_t camera;
	uint16_t cellSize;
} game_state_t;

uint8_t resizeFont(uint8_t fontSize, float scale);

void drawGrid(uint16_t cellSize, const camera_t *pCamera);

void gameInit(game_state_t *pGame);
void gameInput(void);
void gameUpdate(game_state_t *pGame);
void gameDraw(game_state_t *pGame);

int main(void)
{
	game_state_t game;
	game_state_t *pGame = &game;
	gameInit(pGame);

	while (!WindowShouldClose())
	{
		gameInput();
		gameUpdate(pGame);
		gameDraw(pGame);
	}

	CloseWindow();

	return 0;
}

void gameInit(game_state_t *pGame)
{
	// Window Setup
	InitWindow(SCREEN_VIRTUAL_WIDTH, SCREEN_VIRTUAL_HEIGHT, "Game of Life");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowState(FLAG_WINDOW_MAXIMIZED);
	MaximizeWindow();

	SetTargetFPS(FPS);

	// Game
	*pGame = (game_state_t)
		{
			.cellSize = 10,
		};
}

void gameUpdate(game_state_t *pGame)
{
}

void gameDraw(game_state_t *pGame)
{
	updateCamera(& pGame->camera);

	BeginDrawing();
	ClearBackground(BLACK);

	drawGrid(pGame->cellSize, & pGame->camera);

	EndDrawing();
}

void gameInput(void)
{
}

// TODO: The `drawGrid` should RESIZE the grid according to the `pCamera` values, but instead it is showing more or less grids
void drawGrid(uint16_t cellSize, const camera_t *pCamera)
{
	Color defaultColor = (Color){ 200, 200, 200, 50 };

	// Horizontal lines
	uint16_t height = (pCamera->end.y - pCamera->start.y);
	uint16_t cellSizePerLine = (uint16_t)((float)(cellSize * pCamera->scale.y));
	uint16_t currentLine = 0;
	while (currentLine < height)
	{
		DrawLine(pCamera->start.x, currentLine, pCamera->end.x, currentLine, defaultColor);
		currentLine += cellSizePerLine;
	}
}

uint8_t resizeFont(uint8_t fontSize, float scale)
{
	uint8_t fontResized = (uint8_t)((float)fontSize * scale);
	if (! isDivisibleBy(fontResized, 2))
		fontResized++;

	return fontResized;
}
