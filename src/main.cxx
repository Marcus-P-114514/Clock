#include "QApplication"
#include "mainwindow/mainwindow.hxx"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    mainwindow * mainwindowHelper = new mainwindow;
    mainwindowHelper->show();

    return QApplication::exec();
}