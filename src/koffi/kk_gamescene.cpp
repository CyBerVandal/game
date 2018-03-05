#include "inc/koffi/kk_gamescene.h"

GameScene::GameScene(QGraphicsScene *scene)
{
    gameScene = scene;
}

void GameScene::addGameObject(QGraphicsItem *gameObject, QString imagePath, int scaledWidth, int scaledHeight)
{
    QPixmap gameImage(imagePath);
    gameScene->setBackgroundBrush(gameImage.scaled(scaledHeight,scaledHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gameScene->addItem(gameObject);
}

void GameScene::removeGameObject(QGraphicsItem *gameObject)
{

}

void GameScene::setBackground(QString imagePath)
{
    int sceneHeight = gameScene->height();
    int sceneWidth = gameScene->width();

    QPixmap backgrounImage(imagePath);
    gameScene->setBackgroundBrush(backgrounImage.scaled(sceneWidth,
                                         sceneHeight,
                                         Qt::IgnoreAspectRatio,
                                         Qt::SmoothTransformation));
}
