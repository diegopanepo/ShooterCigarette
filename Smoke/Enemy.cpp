#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // Set random position
    int randomX = rand() % 700;
    setPos(randomX,0);

    // Drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));

    // Connect the rect to its slot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // Move the enemy down
    setPos(x(),y()+5);

    // Destroy enemy when out of the screen
    if (pos().y() > 600) {
        // Decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
//        qDebug() << "enemy deleted";
    }
}
