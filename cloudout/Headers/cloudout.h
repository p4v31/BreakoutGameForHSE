#include <QWidget>
#include <QKeyEvent>
#include "ufoclouds.h"
#include "sun.h"
#include "cloud.h"
#pragma once

class CloudOut : public QWidget {   ///главный заголовочный файл
  public:
    CloudOut(QWidget *parent = 0);
    ~CloudOut();
  protected:
    void paintEvent(QPaintEvent *), drawObjects(QPainter *), scoreGame(QPainter *, QString), finishGame(QPainter *, QString), keyReleaseEvent(QKeyEvent *), keyPressEvent(QKeyEvent *), moveObjects(), timerEvent(QTimerEvent *);
    void helpGame(QPainter *, QString), startGame(), pauseGame(),stopGame(), victory(), menu(), checkCollision();

  private:
    int x,timerId;
    static const int CountOfUfoClouds = 30, TimeOfGame = 5, EDGE = 400;   ///управление локацией игры
    Sun * sun;
    Cloud * cloud;
    UfoCloud *ufoclouds[CountOfUfoClouds];
    bool gameMenu, gameOver, gameWon, gameStarted, paused;   ///управление состояние игры соотв:меню, проигрыш, выигрыш, начало, пауза
};
