#ifndef RENDER_SCALING_H
#define RENDER_SCALING_H

#include <stdint.h>

#include "vector.h"

#define SCREEN_VIRTUAL_WIDTH (640)
#define SCREEN_VIRTUAL_HEIGHT (360)

// Yes, I know, the raylib already have a camera system but I want to make my own :)
// TODO: Where do I put this struct?

// TODO: Better name for `real` (this values holds the current screen width and height)
typedef struct {
	float_vector_t scale;
	uint16_vector_t start;
	uint16_vector_t end;
	uint16_vector_t real;
} camera_t;

// FIX: The `end` and `start` values are actually hard coded (by using SCREEN_VIRTUAL_X)

// FIX: And the `scale` is also hard coded (by using SCREEN_VIRTUAL_X)

void updateCamera(camera_t *pCamera);

void realUpdate(uint16_vector_t *pReal);

void scaleUpdate(float_vector_t *pScale, uint16_vector_t *pReal);

void positionUpdate(uint16_vector_t *pPosition, float_vector_t *pScale);

#endif // RENDER_SCALING_H
