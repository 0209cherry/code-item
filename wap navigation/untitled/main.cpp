#include "mainwindow.h"

#include <QApplication>
#include <Windows.h>
#include <WinUser.h>
#include <wingdi.h>

int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);


    DEVMODE NewDevMode;
    //获取屏幕设置中的分辨率
    EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
    qreal  cx = NewDevMode.dmPelsWidth;
    qreal scale = 1;

    qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
