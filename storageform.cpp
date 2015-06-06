/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: pá 5. června 2015 09:53:38                         **
**                                                                  **
**  Geändert am: So 06.čen.2015 14:41:59                            **
*********************************************************************/
#include "storagemodel.h"

#include "storageform.h"


StorageForm::StorageForm(QWidget * parent):QWidget(parent) {	
	setupUi(this);
	m_sm = new StorageModel(this); 
	tableView->setModel(m_sm);
}



