#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    // Initialise the score to 0
    health = 3;

    // Draw the text
    setPlainText(QString("Health: "+ QString::number(health))); // Health: 3
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Health::decrease() {
    health--;
    if (health < 2) setDefaultTextColor(Qt::red);
    setPlainText(QString("Health: "+ QString::number(health))); // Health: --
}

int Health::getHealth() {
    return health;
}
