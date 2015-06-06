/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: st 3. června 2015 06:44:57                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 06:37:39                            **
*********************************************************************/


#include "reportmodel.h"

#include "reportform.h"


ReportForm::ReportForm(QWidget * parent):QWidget(parent) {	
	setupUi(this);
	m_rm = new ReportModel(this); 
	tableView->setModel(m_rm);
}



