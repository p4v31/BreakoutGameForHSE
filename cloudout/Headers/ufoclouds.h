#pragma once
#include <QImage>
#include <QRect>

class UfoCloud { ///отвечает за облака, в которые мы стреляем солнцем
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
