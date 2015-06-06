/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 14:43:33                         **
**                                                                  **
**  Geändert am: Čt 04.čen.2015 18:28:50                            **
*********************************************************************/




#ifndef LOGINANONDLG_H
#define LOGINANONDLG_H

#include <QDialog>

#include "ui_loginanondlg.h"

class LoginAnonDlg : public QDialog , private Ui_LoginAnonDlg {
 public:
	LoginAnonDlg(QWidget * parent);
	QString getKey() const;
};

#endif


