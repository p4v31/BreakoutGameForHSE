#pragma once
#include <QImage>
#include <QRect>

class Sun {
  public:
    Sun();
    ~Sun();
    void restartSt(), autoMove(), setXDir(int), setYDir(int);
    int getXDir(), getYDir();
    QRect getRect();
    QImage & getImage();
  private:
    int xdir, ydir;
    QImage image;
    QRect rect;
    static const int INITIAL_X = 150, INITIAL_Y = 390, RIGHT_EDGE = 300;
};
