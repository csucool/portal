#pragma once
#include "Box2D/Box2D.h"
#include "log.h"
#include "ppm.h"
#include "render.h"
#include "physics.h"
#include "const.h"
#include "contains.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

extern Display * dpy;
extern Window win;
extern GLXContext glc;
extern const float M2P;
extern const float P2M;
extern b2Body * myPlayer;
extern int xres;
extern int yres;
extern b2Body * p1;
extern b2Body * p2;
extern int p_isleft;
extern b2Vec2 p_vel;
extern b2Body * p_obj;
extern b2Vec2 p1_dir;
extern b2Vec2 p2_dir;
extern b2Vec2 p_pos;
extern float p_angle;
extern Ppmimage * mineImage;
extern GLuint mineTexture;
extern GLuint silhouetteTexture;

void render(void);
void drawPlayer();
void drawPortal(b2Body * p);
void drawFoot();
void drawSquare(b2Vec2* points, b2Vec2 center, float angle, int & color);
void camera();
