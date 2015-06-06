/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: st 3. června 2015 06:44:48                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 06:59:38                            **
*********************************************************************/

#include "membermodel.h"

#include "memberform.h"


MemberForm::MemberForm(QWidget *p_parent):QWidget(p_parent) {	
	setupUi(this);
	m_mm = new MemberModel(this); 
	tableView->setModel(m_mm);
}




