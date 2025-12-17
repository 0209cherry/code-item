#include "mapwidget.h"

MapWidget::MapWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    init();
}

MapWidget::~MapWidget()
{
}

// 初始化地图显示相关设置，设置场景等基础属性
void MapWidget::init()
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    // 设置一些默认的显示相关属性，如缩放范围、初始缩放比例、交互模式等
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorViewCenter);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setMinimumSize(400, 300);
}

// 放大地图操作实现，改变视图的缩放比例来达到放大效果
void MapWidget::zoomIn()
{
    scale(1.2, 1.2);
}

// 缩小地图操作实现
void MapWidget::zoomOut()
{
    scale(1 / 1.2, 1 / 1.2);
}

// 移动地图操作实现，根据鼠标拖动等交互获取偏移量来移动地图显示区域
void MapWidget::moveMap()
{
    // 可以通过处理鼠标事件等获取相应的平移量来移动视图显示区域，代码省略详细鼠标事件处理部分（需结合 Qt 图形视图的事件处理机制完善）
}

// 在地图上展示最短路径函数实现，比如通过改变对应连线的颜色、样式等突出显示路径
void MapWidget::showShortestPath(const QList<QString>& shortestPath)
{
    // 假设之前在场景中已经添加了代表景点连线的图形元素（如 QGraphicsLineItem 等），并可以通过景点名称等标识进行查找
    // 遍历 shortestPath 列表获取对应的连线图形元素并改变其外观属性（颜色、粗细等）来突出显示最短路径
    // 具体实现需结合之前创建图形元素时的相关标识信息来准确操作，代码省略详细查找和修改图形元素外观部分
}
