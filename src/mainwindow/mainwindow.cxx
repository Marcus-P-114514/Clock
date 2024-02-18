#include "mainwindow.hxx"
#include "mainwindow.hxx"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent) {
    this->setObjectName("mainwindow");
    loadTheme(":/stylesheet/stylesheet/style.css");
}

mainwindow::~mainwindow() {}

void mainwindow::loadTheme(QString css) {
    QFile * cssPath = new QFile(css);
    cssPath->open(QFile::ReadOnly);

    if(cssPath->isOpen()) {
        QString style = QLatin1String(cssPath->readAll());
        this->setStyleSheet(style);
    }
    else {
        QMessageBox * errStyleSheetNotLoaded = new QMessageBox(QMessageBox::Warning, "读取失败", "加载样式表文件失败。", QMessageBox::Ok);
        errStyleSheetNotLoaded->show();
    }
}