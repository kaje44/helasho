/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 18:07:58                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 12:54:49                            **
*********************************************************************/




#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QStandardItemModel>

class CustomModel : public QStandardItemModel {
 private:
 public:
	CustomModel(QObject * p_parent);
	void addCustom( QString p_key, QString p_id, QString p_name = "Zákazník" );
};

#endif


