#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Campusmap.h"  // 引入校园地图类头文件
#include <QLabel>  // 用于显示背景图片（可根据实际情况选择合适的显示控件）
#include "ui_mainwindow.h"
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setDistanceButtonClicked();  // 用于设置景点间距离按钮的点击响应函数
    void on_findShortestPathButtonClicked();  // 查找最短路径按钮点击响应函数
    void on_zoomInButtonClicked();  // 放大地图按钮点击响应函数
    void on_zoomOutButtonClicked();  // 缩小地图按钮点击响应函数
    void on_moveMapButtonClicked();  // 移动地图按钮点击响应函数
    void on_showPointInfoButtonClicked();  // 显示某点提示信息按钮点击响应函数

private:
    Ui::MainWindow *ui;
    CampusNavigator campusNavigator;  // 校园地图对象，处理地图数据与操作
    QLabel *backgroundLabel; // 用于显示中国石油大学地图背景图片的标签
 // 可以添加其他私有成员变量，比如记录当前选中的起点、终点等相关信息变量
};

#endif // MAINWINDOW_H
