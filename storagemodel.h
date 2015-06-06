/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: pá 5. června 2015 10:06:23                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 10:29:40                            **
*********************************************************************/




#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H

#include <QStandardItemModel>

class StorageModel : public QStandardItemModel {
 private:
 public:
	StorageModel(QObject * p_parent);
};

#endif


