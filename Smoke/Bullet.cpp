#include "Bullet.h"
#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; // There is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));

    // Connect the rect to its slot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

void Bullet::move(){
    // Get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // If one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // Increase the score
            game->score->increase();

            // Remove them both from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // Deletion of the objects from the heap
            delete colliding_items[i];
            delete this;

            // Return to end the function
            return;
        }
    }

    // Move the bullet up
    setPos(x(),y()-pixmap().width());
    if (pos().y()+pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
//        qDebug() << "bullet deleted";
    }
}
