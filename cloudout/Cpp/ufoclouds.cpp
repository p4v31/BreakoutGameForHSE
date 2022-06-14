#include <iostream>
#include "ufoclouds.h"

UfoCloud::UfoCloud(int x, int y) {

  image.load("ufoclouds.png");
  crashed = false;
  rect = image.rect();
  rect.translate(x, y);
}

UfoCloud::~UfoCloud() {

  std::cout << ("UfoCloud deleted:(") << std::endl;
}

QRect UfoCloud::getRect() {

  return rect;
}

void UfoCloud::setRect(QRect rct) {

  rect = rct;
}

QImage & UfoCloud::getImage() {

  return image;
}

bool UfoCloud::isCrashed() {

  return crashed;
}

void UfoCloud::setDestroyed(bool crash) {

  crashed = crash;
}
