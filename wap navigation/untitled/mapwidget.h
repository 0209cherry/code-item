#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QGraphicsView>
#include <QList>
#include <QString>

class MapWidget : public QGraphicsView
{
    Q_OBJECT

public:
    MapWidget(QWidget *parent = nullptr);
    ~MapWidget();

    void init();  // 初始化地图显示相关设置，如创建场景、设置默认属性等
    void zoomIn();  // 实现地图放大操作
    void zoomOut();  // 实现地图缩小操作
    void moveMap();  // 实现地图移动操作
    void showShortestPath(const QList<QString>& shortestPath);  // 在地图上动态展示最短路径走法

private:
    QGraphicsScene* scene;  // 图形场景对象，用于管理地图图形元素展示
};

#endif // MAPWIDGET_H

