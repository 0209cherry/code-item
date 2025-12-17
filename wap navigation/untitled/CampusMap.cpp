#include "campusmap.h"
#include <QSet>

CampusMap::CampusMap(QObject *parent)
    : QObject(parent)
{
    // 可在这里进行一些初始的地图相关设置，比如初始化邻接矩阵大小等（假设已知景点数量为 numPoints）
    const int numPoints = 10;  // 示例数量，需根据实际中国石油大学的景点数量调整
    adjMatrix.resize(numPoints, std::vector<int>(numPoints, INT_MAX));
    for (int i = 0; i < numPoints; ++i) {
        adjMatrix[i][i] = 0;
    }
}

CampusMap::~CampusMap()
{
}

// 初始化校园地图函数实现，加载景点名称并建立名称与矩阵索引的映射等
void CampusMap::initMap()
{
    // 假设从文件或者硬编码等方式获取景点名称列表，示例简单硬编码几个景点
    QStringList pointNames = {"图书馆", "教学楼1", "体育馆", "食堂", "宿舍区"};
    int index = 0;
    for (const QString& point : pointNames) {
        pointIndexMap[point] = index;
        indexPointMap[index] = point;
        index++;
    }
    // 后续可以进一步完善，比如根据初始已知距离设置邻接矩阵对应元素值等
}

// 设置两点间距离函数实现，根据景点名称在邻接矩阵中设置对应距离值
void CampusMap::setDistance(const QString& point1, const QString& point2, int distance)
{
    int index1 = pointIndexMap.value(point1);
    int index2 = pointIndexMap.value(point2);
    adjMatrix[index1][index2] = distance;
    adjMatrix[index2][index1] = distance;  // 因为是无向图，对称设置
}

// 查找最短路径函数实现，这里以 Dijkstra 算法为例基于邻接矩阵查找最短路径
QList<QString> CampusMap::findShortestPath(const QString& startPoint, const QString& endPoint)
{
    QMap<QString, int> distances;
    QMap<QString, QString> predecessors;
    dijkstra(startPoint, distances, predecessors);
    QList<QString> shortestPath;
    QString current = endPoint;
    while (current!= startPoint) {
        shortestPath.prepend(current);
        current = predecessors.value(current);
    }
    shortestPath.prepend(startPoint);
    return shortestPath;
}

// Dijkstra 算法辅助函数实现，用于基于邻接矩阵计算最短路径相关信息
void CampusMap::dijkstra(const QString& start, QMap<QString, int>& distances, QMap<QString, QString>& predecessors)
{
    QSet<QString> visited;
    distances[start] = 0;
     QList<QString> allPoints = pointIndexMap.keys();
    for (const QString& point : allPoints) {
        if (point!= start) {
            distances[point] = INT_MAX;
        }
    }
    while (!allPoints.isEmpty()) {
        QString minPoint;
        int minDistance = INT_MAX;
        for (const QString& point : allPoints) {
            if (distances.value(point) < minDistance &&!visited.contains(point)) {
                minPoint = point;
                minDistance = distances.value(point);
            }
        }
        visited.insert(minPoint);
        allPoints.removeAll(minPoint);
        int indexMinPoint = pointIndexMap.value(minPoint);
        for (const QString& neighborPoint : allPoints) {
            int indexNeighbor = pointIndexMap.value(neighborPoint);
            int alt = distances.value(minPoint) + adjMatrix[indexMinPoint][indexNeighbor];
            if (alt < distances.value(neighborPoint)) {
                distances[neighborPoint] = alt;
                predecessors[neighborPoint] = minPoint;
            }
        }
    }
}

// 获取某景点提示信息函数实现，可从数据库、配置文件等获取对应信息，示例简单返回固定字符串
QString CampusMap::getPointInfo(const QString& pointName)
{
    if (pointName == "图书馆") {
        return "这里是学校的图书馆，拥有丰富的藏书，供师生借阅学习。";
    }
    return "";
}
