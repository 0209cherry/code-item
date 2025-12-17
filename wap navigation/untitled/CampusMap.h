#ifndef CAMPUSMAP_H
#define CAMPUSMAP_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>
#include <vector>  // 用于实现邻接矩阵（可根据实际用 C++ 标准库容器来存储地图数据）

class CampusMap : public QObject
{
    Q_OBJECT

public:
    CampusMap(QObject *parent = nullptr);
    ~CampusMap();

    void initMap();  // 初始化校园地图，加载景点名称等信息，初始化邻接矩阵
    QList<QString> findShortestPath(const QString& startPoint, const QString& endPoint);  // 使用合适算法基于邻接矩阵查找最短路径
    void setDistance(const QString& point1, const QString& point2, int distance);  // 在邻接矩阵中设置两点间距离
    QString getPointInfo(const QString& pointName);  // 获取某景点的提示信息

private:
    std::vector<std::vector<int>> adjMatrix;  // 邻接矩阵存储景点间距离，初始化为较大值表示不可达，对角元素设为 0
    QMap<QString, int> pointIndexMap;  // 景点名称到矩阵索引的映射，方便操作邻接矩阵
    QMap<int, QString> indexPointMap;  // 矩阵索引到景点名称的反向映射
    // 其他可能的私有成员变量，比如存储景点坐标信息（如果需要在界面准确绘制）等
    // 辅助函数声明，比如用于实现最短路径算法的辅助函数等
    void dijkstra(const QString& start, QMap<QString, int>& distances, QMap<QString, QString>& predecessors);
};

#endif // CAMPUSMAP_H
