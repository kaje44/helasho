/*********************************************************************
**  KaJe                                                            **
**                                                                  **
**  Vytvořen: 05.02.2008 - 18:57:16                                 **
**                                                                  **
**  Poslední úpravy: Pá 05.čen.2015 06:38:16                        **
**********************************************************************/

#include <QSplashScreen>
#include <QTextCodec>
#include <QTimer>

#include "mainform.h"

int main( int argc, char **argv ) {
    QApplication app( argc, argv );	
//	QTextCodec::setCodecForCStrings( QTextCodec::codecForName("utf8") );
	QPixmap pixmap(":/img/munin.png");
	QSplashScreen *splash = new QSplashScreen(pixmap);
	app.processEvents();
	app.setWindowIcon(QIcon(":img/munin-ikona.png"));
	MainForm mf;
	splash->showMessage( mf.windowTitle(),Qt::AlignRight|Qt::AlignTop);	
	splash->show();
	app.processEvents();

	QTimer::singleShot(2500, splash, SLOT(close()));
	QTimer::singleShot(2500, &mf, SLOT(show()));

	mf.setColor();
	
	return app.exec();
}


