#ifndef OPN_H
#define OPN_H

// GLEW
#define GLEW_STATIC
#define DGLEW_NO_GLU
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include "window_api/opnWindow.h"
#include "window_api/opnCamera.h"
#include "window_api/opnProfileCamera.h"
#include "window_api/opnFreeCamera.h"
#include "window_api/opnInput.h"


#include "drawable_objects/opnShader.h"
#include "drawable_objects/opnSprite.h"
#include "drawable_objects/opnBox.h"
#include "drawable_objects/opnQuad.h"
#include "drawable_objects/opnQuadF.h"
#include "drawable_objects/opnRectangle.h"


#endif
