#include <iostream>
#include "cloud.h"

Cloud::Cloud() {

  dx = 0;
  image.load("cloud.png");

  rect = image.rect();
  restartSt();
}

Cloud::~Cloud() {

 std::cout << ("Cloud deleted") << std::endl;
}

void Cloud::gotDx(int x) {
  dx = x;
}

void Cloud::move() {

    int x = rect.x() + dx, y = rect.top();
    rect.moveTo(x, y);
}

void Cloud::restartSt() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect Cloud::getRect() {

  return rect;
}

QImage & Cloud::getImage() {

  return image;
}
