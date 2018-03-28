#include <QEvent>
#include <QKeyEvent>
//#include <QObject>
#include <QCoreApplication>
//#include <QTimer>
//#include <QGraphicsScene>
//#include <QGraphicsItem>
#include <QDebug>

#include "../../inc/gy_autotest.h"
//#include "../../inc/gy_object.h"
#include "../../inc/gy_objecthandler.h"
#include "../../inc/hh_main_player.h"
#include "../../inc/kk_scenemanager.h"

//class SceneManager;
//class Main_player;

// add main player
//AutoTest::AutoTest(QObject *main_window, QGraphicsItem *object): 
//AutoTest::AutoTest(QGraphicsScene *scene, SceneManager *sm, QGraphicsItem *object): 
AutoTest::AutoTest(QGraphicsScene *scene, QGraphicsItem *object, SceneManager *sm): 
    QObject() 
{
    // init 
    this->object = object; 
    this->scene = scene;
    timer = new QTimer(this);
    obj_handler = new ObjectHandler(scene);

    list_pos = 0;
    dest = QPoint(-1,-1);

    // add test points
    add_point(QPoint(300,400));
    add_point(QPoint(500,0));
    add_point(QPoint(200,0));
    add_point(QPoint(100,60));
    add_point(QPoint(600,50));


    // if no player object passed, then create a demo level
    if(object == 0 && sm == 0)
        create_stress_level();

    else {
        connect(timer, SIGNAL(timeout()), this, SLOT(simulate_keypress()));
        timer->start(100);
    }
}

bool AutoTest::change_scene(QGraphicsScene *scene) {
    if( scene != NULL ) {
        this->scene = scene;
        return true;
    }
    return false;
}

void AutoTest::create_stress_level() {
    static Main_player *player;
/*    static Shark *shark1, *shark2, *shark3, *shark4, *shark5, *shark6,
                 *shark7, *shark8, *shark9, *shark10, *shark11, 
                 *shark12, *shark13, *shark14, *shark15;
    static Platform *plat1, *plat2, *plat3;
    static Banana *banana1;
    static Steam *steam1;
    static Exit *exit;
*/

    player = new Main_player(scene);
    scene->addItem(player);

    obj_handler->add_shark(30,30,5,5);
    obj_handler->add_shark(50,30,10,0);
    obj_handler->add_shark(100,30,3,7);
    obj_handler->add_shark(100,500,10,0);
    obj_handler->add_shark(300,30,10,0);
    obj_handler->add_shark(300,30,8,3);
    obj_handler->add_shark(300,30,10,3);
    obj_handler->add_shark(500,300,5,6);
    obj_handler->add_shark(500,300,8,4);
    obj_handler->add_shark(600,100,10,4);
    obj_handler->add_shark(600,100,9,3);
    obj_handler->add_shark(600,300,8,4);
    obj_handler->add_shark(600,300,10,5);
    obj_handler->add_shark(600,300,2,10);
    obj_handler->add_shark(600,300,10,5);

    obj_handler->add_platform(500,0,200);
    obj_handler->add_platform(800,200,400);
    obj_handler->add_platform(500,100,600);

    obj_handler->add_banana(300, 300);

    obj_handler->add_steam(500, 200);

    obj_handler->add_exit();
/*
    shark1 = new Shark(30,30,5,5);
    shark2 = new Shark(50,30,10,0);
    shark3 = new Shark(100,30,3,7);
    shark4 = new Shark(100,500,10,0);
    shark5 = new Shark(300,30,10,0);
    shark6 = new Shark(300,30,8,3);
    shark7 = new Shark(300,30,10,3);
    shark8 = new Shark(500,300,5,6);
    shark9 = new Shark(500,300,8,4);
    shark10 = new Shark(600,100,10,4);
    shark11 = new Shark(600,100,9,3);
    shark12 = new Shark(600,300,8,4);
    shark13 = new Shark(600,300,10,5);
    shark14 = new Shark(600,300,2,10);
    shark15 = new Shark(600,300,10,5);

    plat1 = new Platform(500,0,200);
    plat2 = new Platform(800,200,400);
    plat3 = new Platform(500,100,600);

    //banana1 = new Banana();
    //steam1 = new Steam();

    
    exit = new Exit();


    scene->addItem(shark1);
    scene->addItem(shark2);
    scene->addItem(shark3);
    scene->addItem(shark4);
    scene->addItem(shark5);
    scene->addItem(shark6);
    scene->addItem(shark7);
    scene->addItem(shark8);
    scene->addItem(shark9);
    scene->addItem(shark10);
    scene->addItem(shark11);
    scene->addItem(shark12);
    scene->addItem(shark13);
    scene->addItem(shark14);
    scene->addItem(shark15);

    scene->addItem(plat1);
    scene->addItem(plat2);
    scene->addItem(plat3);

    //scene->addItem(banana1);

    //scene->addItem(steam1);

    scene->addItem(exit);
*/

}

void AutoTest::restart_scene() {
    clear_scene();
    create_stress_level();
}

void AutoTest::clear_scene() {

}


void AutoTest::add_point(QPoint point) {
    points.append(point);
}

/*
void AutoTest::add_path(QList<QPoint> points) {
    QPoint *ptr = points;

    while( *ptr != NULL ) {
        this->points.append(*ptr++);
    }

    if( this->points == NULL ) {
        this->points = new <QPoint>QList();
    }
    (this->points)->append( (const QList<QPoint> *) points);
}
*/


void AutoTest::simulate_keypress() {
    //QKeyEvent key_event;
    int x = object->x();
    int y = object->y();
    
    //qDebug() << x << ", " << y;

    // init if self.points isn't empty
    if( (dest.x() == -1 && dest.y() == -1) && points.size() > 0 )
        dest = (points.at(list_pos));

    // wrap-around list if index is beyond array
    //if( list_pos >= points.size() )
    //    list_pos = 0;

    // move towards dest

    // left or right
    if( x != dest.x() ) {
        if( x < dest.x()-5 ) {
            //object->setPos(x+10, y);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
        else if( x > dest.x()+5 ) {
            //object->setPos(x-10, y);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
    }

   // up or down
    if( y != dest.y() ) {
        if( y < dest.y()-5 ) {
            //object->setPos(x, y+10);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
        else if( y > dest.y()+5 ) {
            //object->setPos(x, y-10);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
            
    }
        
    if( (x < dest.x()+10 && x > dest.x()-10) && 
        (y < dest.y()+10 && y > dest.y()-10) &&
        list_pos < points.size()-1 )
    {
        list_pos++;
        dest = points.at(list_pos);
    }

   
     
    // testing, just use up key
    //QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    //QCoreApplication::sendEvent(receiver, &event);
    //QCoreApplication::sendEvent(scene(), &event);
}

