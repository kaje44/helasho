/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: pá 5. června 2015 10:06:23                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 10:45:08                            **
*********************************************************************/




#include "storagemodel.h"


StorageModel::StorageModel(QObject * p_parent):QStandardItemModel(p_parent) {	


	appendRow( QList<QStandardItem *>() << new QStandardItem("Nápoj") << new QStandardItem("Káva") 
		<< new QStandardItem("30,0 Kč") << new QStandardItem("4 Ks")
		<< new QStandardItem("21%") << new QStandardItem("69,40 Kč") 
		<< new QStandardItem("84,00 Kč")  
		);	

	appendRow( QList<QStandardItem *>() << new QStandardItem("Doplňky výživy") << new QStandardItem("Isobeef       ") << new QStandardItem("50,00 Kč") << new QStandardItem("5  Ks") << new QStandardItem("21%") << new QStandardItem("206,60 Kč  ") << new QStandardItem("247,90 Kč"));
	appendRow( QList<QStandardItem *>() << new QStandardItem("Doplňky výživy") << new QStandardItem("BCAA xpress   ") << new QStandardItem("20,00 Kč") << new QStandardItem("5  Ks") << new QStandardItem("21%") << new QStandardItem("82,60  Kč  ") << new QStandardItem("17,40  Kč"));
	appendRow( QList<QStandardItem *>() << new QStandardItem("Doplňky výživy") << new QStandardItem("IONT 2013     ") << new QStandardItem("15,00 Kč") << new QStandardItem("6  Ks") << new QStandardItem("21%") << new QStandardItem("74,40  Kč  ") << new QStandardItem("250,00 Kč"));
	appendRow( QList<QStandardItem *>() << new QStandardItem("Doplňky výživy") << new QStandardItem("Assault       ") << new QStandardItem("25,00 Kč") << new QStandardItem("3  Ks") << new QStandardItem("21%") << new QStandardItem("62,00  Kč  ") << new QStandardItem("100,00 Kč"));
	appendRow( QList<QStandardItem *>() << new QStandardItem("Doplňky výživy") << new QStandardItem("Weider protein") << new QStandardItem("40,00 Kč") << new QStandardItem("6  Ks") << new QStandardItem("21%") << new QStandardItem("198,30 Kč  ") << new QStandardItem("90,00  Kč"));
	appendRow( QList<QStandardItem *>() << new QStandardItem("Doplňky výživy") << new QStandardItem("BCAA xpress   ") << new QStandardItem("20,00 Kč") << new QStandardItem("5  Ks") << new QStandardItem("21%") << new QStandardItem("57,90  Kč  ") << new QStandardItem("75,00  Kč"));

	setHorizontalHeaderLabels(QStringList() << "Druh" << "Název výrobku" << "Cena" << "Kusů" << "DPH" << "Cena bez DPH" << "Cena celkem"  );




}



