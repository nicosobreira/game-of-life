#ifndef RENDER_SCALING_H
#define RENDER_SCALING_H

#include <stdint.h>

#include "vector.h"

#define SCREEN_VIRTUAL_WIDTH (640)
#define SCREEN_VIRTUAL_HEIGHT (360)

// Yes, I know, the raylib already have a camera system but I want to make my own :)
// TODO: Where do I put this struct?
typedef struct {
	float_vector_t scale;
	uint16_vector_t start;
	uint16_vector_t end;
	uint16_vector_t real;
} camera_t;

void updateCamera(camera_t *pCamera);

void screenUpdate(uint16_vector_t *pScreen);

void scaleUpdate(float_vector_t *pScale, uint16_vector_t *pScreen);

void realUpdate(uint16_vector_t *pReal, float_vector_t *pScale);

#endif // RENDER_SCALING_H
