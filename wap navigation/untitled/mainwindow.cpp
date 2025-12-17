#include "mainwindow.h"
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 连接按钮点击信号和对应的槽函数
    connect(ui->setDistanceButton, SIGNAL(clicked()), this, SLOT(on_setDistanceButtonClicked()));
    connect(ui->findShortestPathButton, SIGNAL(clicked()), this, SLOT(on_findShortestPathButtonClicked()));
    connect(ui->zoomInButton, SIGNAL(clicked()), this, SLOT(on_zoomInButtonClicked()));
    connect(ui->zoomOutButton, SIGNAL(clicked()), this, SLOT(on_zoomOutButtonClicked()));
    connect(ui->moveMapButton, SIGNAL(clicked()), this, SLOT(on_moveMapButtonClicked()));
    connect(ui->showPointInfoButton, SIGNAL(clicked()), this, SLOT(on_showPointInfoButtonClicked()));

    // 设置背景图片
    backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap("qrc:/shida.png");  // 替换为实际的中国石油大学地图图片路径
    backgroundLabel->setPixmap(backgroundPixmap);

    ui->mapWidget->setStyleSheet("QWidget {"
                                 "background: rgba(0,0,0,0);"
                                 "border: 0px;"
                                 "background-image: url(:/shida.png);"
                                 "background-repeat: no-repeat;"
                                 "background-position: center;"
                                 "background-size: 3000px 2000px; /* 设置具体的宽度和高度 */"
                                 "}");


    // 假设在界面布局中有个名为 backgroundLayout 的布局用于放置背景图片

    campusMap.initMap();  // 初始化校园地图对象，比如加载景点等数据
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 设置景点间距离按钮点击响应函数实现
void MainWindow::on_setDistanceButtonClicked()
{
    QString point1 = ui->point1Input->text();  // 获取第一个景点输入框内容
    QString point2 = ui->point2Input->text();  // 获取第二个景点输入框内容
    bool ok;
    int distance = ui->distanceInput->text().toInt(&ok);  // 获取距离输入框内容并转换为整数
    if (ok) {
        campusMap.setDistance(point1, point2, distance);  // 调用校园地图对象方法设置距离
    } else {
        QMessageBox::warning(this, tr("提示"), tr("请输入有效的距离数值。"));
    }
}

// 查找最短路径按钮点击响应函数实现
void MainWindow::on_findShortestPathButtonClicked()
{
    QString startPoint = ui->startPointInput->text();
    QString endPoint = ui->endPointInput->text();
    QList<QString> shortestPath = campusMap.findShortestPath(startPoint, endPoint);
    if (!shortestPath.isEmpty()) {
        ui->mapWidget->showShortestPath(shortestPath);  // 在地图显示部件上展示最短路径，假设存在名为 mapWidget 的部件用于显示地图
    } else {
        QMessageBox::warning(this, tr("提示"), tr("未找到有效路径，请检查输入的起点和终点是否正确。"));
    }
}

// 放大地图按钮点击响应函数实现
void MainWindow::on_zoomInButtonClicked()
{
   ui->mapWidget->zoomIn();
}

// 缩小地图按钮点击响应函数实现
void MainWindow::on_zoomOutButtonClicked()
{
    ui->mapWidget->zoomOut();
}

// 移动地图按钮点击响应函数实现
void MainWindow::on_moveMapButtonClicked()
{
    ui->mapWidget->moveMap();
}

// 显示某点提示信息按钮点击响应函数实现
void MainWindow::on_showPointInfoButtonClicked()
{
    QString pointName = ui->point2Input_2->text();
    QString info = campusMap.getPointInfo(pointName);
    if (!info.isEmpty()) {
        QMessageBox::information(this, tr("提示"), info);
    } else {
        QMessageBox::warning(this, tr("提示"), tr("未找到该点相关信息，请检查输入的点名称是否正确。"));
    }
}
