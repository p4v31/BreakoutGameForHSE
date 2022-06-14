#pragma once
#include <QImage>
#include <QRect>

class Cloud {
  public:
    Cloud();
    ~Cloud();
    void restartSt(), move(), gotDx(int);
    QRect getRect();
    QImage & getImage();
  private:
    QImage image;
    QRect rect;
    int dx;
    static const int INITIAL_X = 150, INITIAL_Y = 390;
};
