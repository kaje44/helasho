/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 18:55:31                         **
**                                                                  **
**  Geändert am: Čt 04.čen.2015 19:06:53                            **
*********************************************************************/




#ifndef MEMBERMODEL_H
#define MEMBERMODEL_H

#include <QStandardItemModel>

class MemberModel : public QStandardItemModel {
 private:
 public:
	MemberModel(QObject * parent);
};

#endif


