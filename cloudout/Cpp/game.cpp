#include <QIcon>
#include "cloudout.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  CloudOut game;
  game.setWindowTitle("CloudOut");
  game.show();
  game.setFixedSize(300,400);
  game.setWindowIcon(QIcon("mainlogo.ico"));
  game.setStyleSheet("background-image:url(\"background.png\"); background-position: center; ");
  return app.exec();
}
