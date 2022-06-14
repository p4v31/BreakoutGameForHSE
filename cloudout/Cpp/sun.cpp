#include <iostream>
#include "sun.h"

Sun::Sun() {

  xdir = 1;
  ydir = -1;


  image.load("sun.png");



  rect = image.rect();
  restartSt();
}

Sun::~Sun() {

  std::cout << ("Sun deleted") << std::endl;

}

void Sun::autoMove() {

  rect.translate(xdir, ydir);

  if (rect.left() == 0) {
    xdir = 1;
  }

  if (rect.right() == RIGHT_EDGE) {
    xdir = -1;
  }

  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Sun::restartSt() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Sun::setXDir(int x) {

  xdir = x;
}

void Sun::setYDir(int y) {

  ydir = y;
}

int Sun::getXDir() {

  return xdir;
}

int Sun::getYDir() {

  return ydir;
}

QRect Sun::getRect() {

  return rect;
}

QImage & Sun::getImage() {

  return image;
}
