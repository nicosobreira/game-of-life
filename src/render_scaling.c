#include "render_scaling.h"

#include "raylib.h"

void updateCamera(camera_t *pCamera)
{
	screenUpdate(& pCamera->end);
	scaleUpdate(& pCamera->scale, & pCamera->end);

	realUpdate(& pCamera->real, & pCamera->scale);
}

void screenUpdate(uint16_vector_t *pScreen)
{
	if (! IsWindowResized())
	{
		pScreen->x = (uint16_t)GetScreenWidth();
		pScreen->y = (uint16_t)GetScreenHeight();
		return;
	}

	pScreen->x = (uint16_t)GetScreenWidth();
	pScreen->y = (uint16_t)GetScreenHeight();

	// TODO: This logic should STOP the user from RESIZING the Window inside, just outside
	if (pScreen->x < SCREEN_VIRTUAL_WIDTH)
	{
		pScreen->x = SCREEN_VIRTUAL_WIDTH;
	}

	if (pScreen->y < SCREEN_VIRTUAL_HEIGHT)
	{
		pScreen->y = SCREEN_VIRTUAL_HEIGHT;
	}
}

// TODO: The scale should only updatee when `WindowResized`, but it should work on start up `gameDraw` from main.c
void scaleUpdate(float_vector_t *pScale, uint16_vector_t *pScreen)
{
	pScale->x = pScreen->x / (float)SCREEN_VIRTUAL_WIDTH;
	pScale->y = pScreen->y / (float)SCREEN_VIRTUAL_HEIGHT;
}

void realUpdate(uint16_vector_t *pReal, float_vector_t *pScale)
{
	pReal->x = (uint16_t)((float)SCREEN_VIRTUAL_WIDTH * pScale->x);
	pReal->y = (uint16_t)((float)SCREEN_VIRTUAL_HEIGHT * pScale->y);
}
