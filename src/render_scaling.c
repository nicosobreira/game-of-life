#include "render_scaling.h"

#include "raylib.h"

void updateCamera(camera_t *pCamera)
{
	realUpdate(& pCamera->real);
	scaleUpdate(& pCamera->scale, & pCamera->real);

	positionUpdate(& pCamera->end, & pCamera->scale);
}

void realUpdate(uint16_vector_t *pReal)
{
	if (! IsWindowResized())
	{
		pReal->x = (uint16_t)GetScreenWidth();
		pReal->y = (uint16_t)GetScreenHeight();
		return;
	}

	pReal->x = (uint16_t)GetScreenWidth();
	pReal->y = (uint16_t)GetScreenHeight();

	// TODO: This logic should STOP the user from RESIZING the Window inside, just outside
	if (pReal->x < SCREEN_VIRTUAL_WIDTH)
	{
		pReal->x = SCREEN_VIRTUAL_WIDTH;
	}

	if (pReal->y < SCREEN_VIRTUAL_HEIGHT)
	{
		pReal->y = SCREEN_VIRTUAL_HEIGHT;
	}
}

// TODO: The scale should only updatee when `WindowResized`, but it should work on start up `gameDraw` from main.c
void scaleUpdate(float_vector_t *pScale, uint16_vector_t *pReal)
{
	pScale->x = (float)pReal->x / (float)SCREEN_VIRTUAL_WIDTH;
	pScale->y = (float)pReal->y / (float)SCREEN_VIRTUAL_HEIGHT;
}

void positionUpdate(uint16_vector_t *pPosition, float_vector_t *pScale)
{
	if (! IsWindowResized())
		return;

	pPosition->x = (uint16_t)((float)SCREEN_VIRTUAL_WIDTH * pScale->x);
	pPosition->y = (uint16_t)((float)SCREEN_VIRTUAL_HEIGHT * pScale->y);
}
