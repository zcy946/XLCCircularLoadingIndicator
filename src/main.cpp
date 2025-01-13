#include <QApplication>
#include "Test.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Test *t = new Test();
    t->show();

    app.exec();
    return 0;
}