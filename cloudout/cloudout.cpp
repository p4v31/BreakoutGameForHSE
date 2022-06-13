#include <QPainter>
#include <QApplication>
#include "cloudout.h"

CloudOut::CloudOut(QWidget *parent)
    : QWidget(parent) {

  x = 0;
  sun = new Sun();
  cloud = new Cloud();
  gameStarted = false;
  gameMenu= true;
  gameOver = false;
  gameWon = false;
  paused = false;




  int k = 0;

  for (int i=0; i<5; i++) {
    for (int j=0; j<6; j++) {
      ufoclouds[k] = new UfoCloud(j*40+30, i*10+50);
      k++;
    }
  }
}

CloudOut::~CloudOut() {

 delete sun;
 delete cloud;

 for (int i=0; i<CountOfUfoClouds; i++) {
   delete ufoclouds[i];
 }
}

void CloudOut::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  QPainter painter(this);

  if (gameMenu) {
    helpGame(&painter, "Press Space for start");}
  else {
  if (gameOver) {
    finishGame(&painter, "The sun is lost");}
  else if(gameWon) {
    finishGame(&painter, "The sun has Victory");}
  else {
    drawObjects(&painter);
    scoreGame(&painter, "Score N");}
    }
}
void CloudOut::scoreGame(QPainter *painter, QString message) {

  QFont font("Courier", 15, QFont::Bold);
  QFontMetrics fm(font);
  painter->setPen("white");
  int textWidth = fm.width(message), h = height(), w = width();
  painter->setFont(font);
  painter->translate(QPoint(w/2, h/2));
  painter->drawText(-textWidth/2+90, -170, message);
}

void CloudOut::finishGame(QPainter *painter, QString message) {

  QFont font("Courier", 15, QFont::DemiBold);
  QFontMetrics fm(font);
  painter->setPen("white");
  int textWidth = fm.width(message), h = height(), w = width();
  painter->setFont(font);
  painter->translate(QPoint(w/2, h/2));
  painter->drawText(-textWidth/2, 0, message);
}

void CloudOut::helpGame(QPainter *painter, QString message) {

  QFont font("Courier", 10, QFont::DemiBold);
  QFontMetrics fm(font);
  int textWidth = fm.width(message), h = height(), w = width();
  painter->setPen("white");
  painter->setFont(font);
  painter->translate(QPoint(w/2, h/2));
  painter->drawText(-textWidth/2,0, message);
}

void CloudOut::drawObjects(QPainter *painter) {

  painter->drawImage(sun->getRect(), sun->getImage());
  painter->drawImage(cloud->getRect(), cloud->getImage());

  for (int i=0; i<CountOfUfoClouds; i++) {
    if (!ufoclouds[i]->isCrashed()) {
      painter->drawImage(ufoclouds[i]->getRect(), ufoclouds[i]->getImage());
    }
  }
}

void CloudOut::timerEvent(QTimerEvent *e) {

  Q_UNUSED(e);
  moveObjects();
  checkCollision();
  repaint();
}

void CloudOut::moveObjects() {

  sun->autoMove();
  cloud->move();
}

void CloudOut::keyReleaseEvent(QKeyEvent *e) {

    int dx = 0;

    switch (e->key()) {
        case Qt::Key_Left:
            dx = 0;
            cloud->gotDx(dx);
            break;

        case Qt::Key_Right:
            dx = 0;
            cloud->gotDx(dx);
            break;
    }
}

void CloudOut::keyPressEvent(QKeyEvent *e) {

    int dx = 0;

    switch (e->key()) {

    case Qt::Key_Left:
        dx = -1;
        cloud->gotDx(dx);
        break;

    case Qt::Key_Right:
        dx = 1;
        cloud->gotDx(dx);
        break;

    case Qt::Key_P:
        pauseGame();
        break;

    case Qt::Key_Space:
        startGame();
        break;

    case Qt::Key_Escape:
        qApp->exit();
        break;

    default:
        QWidget::keyPressEvent(e);
    }
}

void CloudOut::startGame() {

  if (!gameStarted) {
    sun->restartSt();
    cloud->restartSt();

    for (int i=0; i<CountOfUfoClouds; i++) {
      ufoclouds[i]->setDestroyed(false);
    }
    gameMenu = false;
    gameOver = false;
    gameWon = false;
    gameStarted = false;
    timerId = startTimer(TimeOfGame);
  }
}

void CloudOut::pauseGame() {

  if (paused) {
    timerId = startTimer(TimeOfGame);
    paused = false;
  }
  else {
    paused = true;
    killTimer(timerId);
  }
}

void CloudOut::stopGame() {
  killTimer(timerId);
  gameMenu = false;
  gameOver = true;
  gameStarted = false;
}

void CloudOut::victory() {

  killTimer(timerId);
  gameMenu = false;
  gameWon = true;
  gameStarted = false;
}

void CloudOut::menu() {

  killTimer(timerId);
  gameMenu = false;
  gameWon = false;
  gameStarted = false;
}

void CloudOut::checkCollision() {

  if (sun->getRect().bottom() > EDGE) {
    stopGame();
  }

  for (int i=0, j=0; i<CountOfUfoClouds; i++) {

    if (ufoclouds[i]->isCrashed()) {
      j++;
    }

    if (j == CountOfUfoClouds) {
      victory();
    }
  }

  if ((sun->getRect()).intersects(cloud->getRect())) {

    int CloudLPos = cloud->getRect().left(), SunLPos = sun->getRect().left();

    int first = CloudLPos + 8, second = CloudLPos + 16, third = CloudLPos + 24, fourth = CloudLPos + 32;

    if (SunLPos < first) {
      sun->setXDir(-1);
      sun->setYDir(-1);
    }

    if (SunLPos >= first && SunLPos < second) {
      sun->setXDir(-1);
      sun->setYDir(-1*sun->getYDir());
    }

    if (SunLPos >= second && SunLPos < third) {
       sun->setXDir(0);
       sun->setYDir(-1);
    }

    if (SunLPos >= third && SunLPos < fourth) {
       sun->setXDir(1);
       sun->setYDir(-1*sun->getYDir());
    }

    if (SunLPos > fourth) {
      sun->setXDir(1);
      sun->setYDir(-1);
    }
  }

  for (int i=0; i<CountOfUfoClouds; i++) {

    if ((sun->getRect()).intersects(ufoclouds[i]->getRect())) {

      int SunLeft = sun->getRect().left(), SunHeight = sun->getRect().height(), SunWidth = sun->getRect().width(), SunTop = sun->getRect().top();

      QPoint pointRight(SunLeft + SunWidth + 1, SunTop), pointLeft(SunLeft - 1, SunTop), pointTop(SunLeft, SunTop -1), pointBottom(SunLeft, SunTop + SunHeight + 1);

      if (!ufoclouds[i]->isCrashed()) {
        if(ufoclouds[i]->getRect().contains(pointRight)) {
           sun->setXDir(-1);
        }

        else if(ufoclouds[i]->getRect().contains(pointLeft)) {
           sun->setXDir(1);
        }

        if(ufoclouds[i]->getRect().contains(pointTop)) {
           sun->setYDir(1);
        }

        else if(ufoclouds[i]->getRect().contains(pointBottom)) {
           sun->setYDir(-1);
        }

        ufoclouds[i]->setDestroyed(true);
      }
    }
  }
}
