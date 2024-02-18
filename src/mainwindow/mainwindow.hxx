#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QWidget"

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private:
};


#endif //MAINWINDOW_HXX
