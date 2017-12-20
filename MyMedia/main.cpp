#include "mymedia.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyMedia w;
	w.show();
	return a.exec();
}
