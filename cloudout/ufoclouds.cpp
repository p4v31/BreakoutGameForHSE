#include <iostream>
#include "ufoclouds.h"

UfoCloud::UfoCloud(int x, int y) {   ///загрузка айтема

  image.load("ufoclouds.png");
  crashed = false;
  rect = image.rect();
  rect.translate(x, y);
}

UfoCloud::~UfoCloud() {

  std::cout << ("UfoCloud deleted:(") << std::endl;   /// уничтожение облачка
}

QRect UfoCloud::getRect() {

  return rect;
}

void UfoCloud::setRect(QRect rct) {

  rect = rct;
}

QImage & UfoCloud::getImage() {   ///изображение

  return image;
}

bool UfoCloud::isCrashed() {   ///проверка на разрушение до этого

  return crashed;
}

void UfoCloud::setDestroyed(bool crash) {   ///разрушение

  crashed = crash;
}
