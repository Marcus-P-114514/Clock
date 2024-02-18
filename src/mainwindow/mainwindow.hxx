#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include "QWidget"
#include "QVBoxLayout"
#include "QSpacerItem"
#include "QHBoxLayout"
#include "QLabel"
#include "QTimer"
#include "QFile"
#include "QDateTime"
#include "QTimeZone"
#include "QMessageBox"

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private:
    QLabel * currentTime = new QLabel;

    QLabel * currentDayOfTheWeek = new QLabel;

    QLabel * currentDate = new QLabel;

    QLabel * timeZone = new QLabel;

    void loadTheme(QString css);

private slots:
    void updateTime();
};


#endif //MAINWINDOW_HXX
