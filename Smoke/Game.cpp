#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){

    // Create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // Make the scene 800*600 instead of infinity*infinity
    setBackgroundBrush(QBrush(QImage(":/images/QA0DZf.jpg")));

    // Make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // Create the player
    player = new Player();
    player->setPos(scene->width()/2 - player->pixmap().width()/2,scene->height() - player->pixmap().height());
//    player->setRect(0,0,100,100);
//    player->setPos(scene->width()/2 - player->rect().width()/2,scene->height() - player->rect().height());

    // Make the player focusable and set it to current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // Add the player to the scene
    scene->addItem(player);

    // Create a score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // Spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // Play background music
    QMediaPlayer * bgmusic = new QMediaPlayer();
    bgmusic->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    bgmusic->setVolume(3);
    bgmusic->play();

    show();
}
