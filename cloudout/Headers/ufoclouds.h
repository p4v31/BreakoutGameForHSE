#pragma once
#include <QImage>
#include <QRect>

class UfoCloud {
  public:
    UfoCloud(int, int);
    ~UfoCloud();
    bool isCrashed();
    void setDestroyed(bool), setRect(QRect);
    QRect getRect();
    QImage & getImage();
  private:
    QImage image;
    QRect rect;
    bool crashed;
};
