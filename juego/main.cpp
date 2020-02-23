#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    a.setStyle("fusion");
    w.show();
    return a.exec();
}
