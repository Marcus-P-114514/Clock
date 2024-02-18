#include "mainwindow.hxx"

mainwindow::mainwindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout * appView = new QVBoxLayout;

    QSpacerItem * topSpacer = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    appView->addSpacerItem(topSpacer);

    QHBoxLayout * clockView = new QHBoxLayout;

    QSpacerItem * leftSpacer = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    clockView->addSpacerItem(leftSpacer);

    QVBoxLayout * timeView = new QVBoxLayout;
    timeView->setSpacing(16);

    currentTime->setObjectName("currentTime");
    currentTime->setText("00:00:00 A.M.");
    timeView->addWidget(currentTime);

    QHBoxLayout * dateContainer = new QHBoxLayout;

    currentDayOfTheWeek->setObjectName("currentDayOfTheWeek");
    currentDayOfTheWeek->setText("周四");
    dateContainer->addWidget(currentDayOfTheWeek);

    currentDate->setObjectName("currentDate");
    currentDate->setText("1970年1月1日");
    dateContainer->addWidget(currentDate);

    QSpacerItem * dateSpacer = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Fixed);
    dateContainer->addSpacerItem(dateSpacer);

    timeView->addLayout(dateContainer);

    QWidget * sectionDivider = new QWidget;
    sectionDivider->setObjectName("sectionDivider");
    sectionDivider->setFixedHeight(3);
    timeView->addWidget(sectionDivider);

    QHBoxLayout * locationView = new QHBoxLayout;

    QSpacerItem * locationSpacer = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Fixed);
    locationView->addSpacerItem(locationSpacer);

    timeZone->setObjectName("timeZone");
    timeZone->setText("UTC+8");
    locationView->addWidget(timeZone);

    timeView->addLayout(locationView);

    clockView->addLayout(timeView);

    QSpacerItem * rightSpacer = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    clockView->addSpacerItem(rightSpacer);

    appView->addLayout(clockView);

    QSpacerItem * bottomSpacer = new QSpacerItem(16, 16, QSizePolicy::Expanding, QSizePolicy::Expanding);
    appView->addSpacerItem(bottomSpacer);

    QTimer * clockTimer = new QTimer;
    connect(clockTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    clockTimer->start(1000);

    this->setLayout(appView);
    this->setObjectName("mainwindow");
    this->setWindowTitle("时钟");
    this->resize(800, 600);
    this->setWindowIcon(QIcon(":/icon/icon/app.ico"));

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

void mainwindow::updateTime() {
    QDateTime currentTimer = QDateTime::currentDateTime();

    //处理十二小时制
    bool isAfternoon;
    QString currentHrsStr = currentTimer.toString("hh");
    int currentHrsInt = currentHrsStr.toInt();
    if(currentHrsInt > 12){
        currentHrsInt = currentHrsInt - 12;
        isAfternoon = true;
    }   //十二点后
    else{
        isAfternoon = false;
    }   //十二点前

    bool digitFilling;
    if(currentHrsInt < 10){
        digitFilling = true;
    }   //如果数字为一位数，则准备填充0
    else{
        digitFilling = false;
    }   //如数字为两位数，则不处理

    currentHrsStr = QString::number(currentHrsInt);
    if(digitFilling == true){
        currentHrsStr = "0" + currentHrsStr;
    }   //对于标记为一位数的数字填充0

    QString isAfternoonDesc;
    if(isAfternoon == true){
        isAfternoonDesc = "P.M.";
    }   //如果当前时间为下午
    else{
        isAfternoonDesc = "A.M.";
    }   //如果当前时间为早上

    //处理时区
    int timeZoneInt = currentTimer.timeZone().offsetFromUtc(currentTimer);
    timeZoneInt /= 60;
    timeZoneInt /= 60;
    QString timeZoneDesc = "UTC" + QString::number(timeZoneInt);

    //设置时间
    currentTime->setText(currentHrsStr + ":" + currentTimer.toString("mm") + " " + isAfternoonDesc);
    currentDayOfTheWeek->setText(currentTimer.toString("ddd"));
    currentDate->setText(currentTimer.toString("yyyy年M月dd日"));
    timeZone->setText(timeZoneDesc);
}
