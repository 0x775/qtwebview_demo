#include "webdialog.h"

#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WebDialog w;
    //w.showFullScreen();
    w.show();
    return a.exec();
}

/*
 *
 *  https://github.com/qtwebkit/qtwebkit/releases
 *
 *  QtWebKit 5.212.0 Alpha 4
 *
 *
 *
 *
 *
 *
 *
 *
 */
