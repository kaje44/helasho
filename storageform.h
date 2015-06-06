/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: pá 5. června 2015 09:53:38                         **
**                                                                  **
**  Geändert am: So 06.čen.2015 14:41:43                            **
*********************************************************************/




#ifndef STORAGEFORM_H
#define STORAGEFORM_H

#include <QWidget>

#include "ui_storageform.h"

class StorageModel;


class StorageForm : public QWidget , private Ui_StorageForm {
 private:
	StorageModel *m_sm;

 public:
	StorageForm(QWidget * parent);
};

#endif


