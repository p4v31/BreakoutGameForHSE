#include <QIcon>
#include "cloudout.h"
#include <QApplication>

int main(int argc, char *argv[]) {   ///окно итоговое
  QApplication app(argc, argv);
  CloudOut game;
  game.setWindowTitle("CloudOut");   ///название окна
  game.show();
  game.setFixedSize(300,400);   ///размер окна
  game.setWindowIcon(QIcon("mainlogo.ico"));   ///лого игры
  game.setStyleSheet("background-image:url(\"background.png\"); background-position: center; ");   ///задний фон игры
  return app.exec();
}
