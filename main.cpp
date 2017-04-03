#include "clubtenispadel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClubTenisPadel w;
    w.show();

    return a.exec();
}
