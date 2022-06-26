#include <iostream>
#include "cloud.h"

Cloud::Cloud() {

  dx = 0;
  image.load("cloud.png");   ///загрузка изображений

  rect = image.rect();
  restartSt();
}

Cloud::~Cloud() {   ///удаление облака

 std::cout << ("Cloud deleted") << std::endl;
}

void Cloud::gotDx(int x) {
  dx = x;
}

void Cloud::move() {   ///перемещение

    int x = rect.x() + dx, y = rect.top();
    rect.moveTo(x, y);
}

void Cloud::restartSt() {  ///перезапуск состояний

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect Cloud::getRect() {

  return rect;
}

QImage & Cloud::getImage() {   ///изображение

  return image;
}
