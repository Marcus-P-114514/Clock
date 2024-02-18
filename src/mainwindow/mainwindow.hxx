#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QWidget"
#include "QFile"
#include "QMessageBox"

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private:
    void loadTheme(QString css);
};


#endif //MAINWINDOW_HXX
