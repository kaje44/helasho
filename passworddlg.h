/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 14:48:11                         **
**                                                                  **
**  Geändert am: Čt 04.čen.2015 14:55:53                            **
*********************************************************************/




#ifndef PASSWORDDLG_H
#define PASSWORDDLG_H

#include <QDialog>

#include "ui_passworddlg.h"

class PasswordDlg : public QDialog , private Ui_PasswordDlg {
 public:
	PasswordDlg(QWidget * parent);
};

#endif


