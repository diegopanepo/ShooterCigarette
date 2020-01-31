#include "Score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    // Initialise the score to 0
    score = 0;

    // Draw the text
    setPlainText(QString("Score: "+ QString::number(score))); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase() {
    score++;
    setPlainText(QString("Score: "+ QString::number(score))); // Score: ++
}

int Score::getScore() {
    return score;
}
