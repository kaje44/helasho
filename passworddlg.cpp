/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 14:48:11                         **
**                                                                  **
**  Geändert am: Čt 04.čen.2015 15:41:22                            **
*********************************************************************/




#include "passworddlg.h"


PasswordDlg::PasswordDlg(QWidget * parent):QDialog(parent) {	
	setupUi(this);
	setWindowTitle("Heslo");
	lineEdit->setFocus();
}



