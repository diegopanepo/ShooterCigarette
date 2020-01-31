#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QMovie>
#include <QLabel>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/shot.mp3"));
    bulletSound->setVolume(5);

    // Set image
    //setPixmap(QPixmap(":/images/player.png"));
    QMovie * gifo = new QMovie(":/images/giphy.gif");
    QLabel * labo = new QLabel();
    labo->setMovie(gifo);
    gifo->start();
}

void Player::keyPressEvent(QKeyEvent *event){
    // Move left
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0) setPos(x()-10,y());
    }
    // Move right
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + pixmap().width() < 800) setPos(x()+10,y());
    }
//    else if (event->key() == Qt::Key_Up){
//        setPos(x(),y()-10);
//    }
//    else if (event->key() == Qt::Key_Down){
//        setPos(x(),y()+10);
//    }

    // Shoot a bullet with spacebar
    else if (event->key() == Qt::Key_Space){
        // Create a bullet
        Bullet * bulletL = new Bullet();
        Bullet * bulletR = new Bullet();
//        qDebug() << "bullet created";
        bulletL->setPos(x(),y());
        bulletR->setPos(x()+pixmap().width()-10,y());
        scene()->addItem(bulletL);
        scene()->addItem(bulletR);

        // Play the bullet sound
        if (bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }
    }
}

void Player::spawn()
{
    // Create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
