/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: pá 5. června 2015 09:53:38                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 10:03:51                            **
*********************************************************************/




#ifndef STORAGEFORM_H
#define STORAGEFORM_H

#include <QWidget>

#include "ui_storageform.h"

class StorageForm : public QWidget , private Ui_StorageForm {
 public:
	StorageForm(QWidget * parent);
};

#endif


