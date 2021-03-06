/*********************************** 
 * gy_platform.c 
 *
 * By Gigi Young
 **********************************/

#include "../../inc/gy_object.h"


void Platform::init() {
//   graphics = new LoadPlatform();
   graphics = new Graphics();

}

Platform::Platform(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {

    init();
    setPos(DEFAULT_PLAT_POS_X, DEFAULT_PLAT_POS_Y);
//    graphics->set(DEFAULT_PLAT_HEIGHT,DEFAULT_PLAT_WIDTH);
//    graphics->load_platform(this);

    graphics->load_platform(DEFAULT_PLAT_WIDTH,DEFAULT_PLAT_HEIGHT,this);
}

Platform::Platform(int x, int y, QGraphicsItem *parent): 
    QGraphicsPixmapItem(parent)
{
    init();

    setPos(x, y); 
//    graphics->set(DEFAULT_PLAT_HEIGHT,DEFAULT_PLAT_WIDTH);
//    graphics->load_platform(this);
    graphics->load_platform(DEFAULT_PLAT_WIDTH,DEFAULT_PLAT_HEIGHT,this);
}

Platform::Platform(int x, int y, int width, QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    init();

    setPos(x, y); 
//    graphics->set(DEFAULT_PLAT_HEIGHT,width);
//    graphics->load_platform(this);
    graphics->load_platform(width, DEFAULT_PLAT_HEIGHT,this);
}

