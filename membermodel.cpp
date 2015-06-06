/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 18:55:31                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 06:58:58                            **
*********************************************************************/




#include "membermodel.h"


MemberModel::MemberModel(QObject * p_parent):QStandardItemModel( p_parent ) {	
	appendRow( QList<QStandardItem *>() << new QStandardItem("Novák ") << new QStandardItem("Adresa") 
									  << new QStandardItem("123456789") << new QStandardItem("email@email.cz"));
	setHorizontalHeaderLabels(QStringList() << "Jméno" << "Adresa" << "Telefon" << "E-mail" );
}



