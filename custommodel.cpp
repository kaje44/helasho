/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 18:07:58                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 12:55:23                            **
*********************************************************************/


#include "customitem.h"

#include "custommodel.h"


CustomModel::CustomModel(QObject * p_parent):QStandardItemModel( p_parent ) {	
}

//------------------------------------------------------------------------------------------------- 
 
void CustomModel::addCustom( QString p_key, QString p_id , QString p_name ) {
	QString name = ( p_id == "-1" ) ? QString("Zákazník ( %1 )").arg(p_key) : p_name;	
	appendRow(new CustomItem( p_id, name, p_key, name, "" ));	
	//reset();
	setHorizontalHeaderLabels(QStringList() << "Jméno" );
}


