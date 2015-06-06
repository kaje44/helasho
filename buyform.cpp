/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: st 3. června 2015 06:33:32                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 12:59:13                            **
*********************************************************************/

#include "loginanondlg.h"
#include "passworddlg.h"
#include "customitem.h"
#include "custommodel.h"

#include "buyform.h"

BuyForm::BuyForm(QWidget *p_parent):QWidget(p_parent) {	

	setupUi(this);
  
    QList<int> p_sizes;
    p_sizes << 100 << 400;
    splitter->setSizes(p_sizes);


	m_sm = new CustomModel(this);
	listView->setModel(m_sm);
	connect(listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), 
      							  this,   SLOT(listChanged(QItemSelection,QItemSelection)));


	actCountBuy = new QAction(QIcon(":img/help-donate.png"), "Zaplaceno", this);
	actCountBuy->setToolTip("Zaplatit");
	connect(actCountBuy, SIGNAL(triggered()), this, SLOT(meActCountBuy()));

	actDelBuy = new QAction(QIcon(":img/list-remove.png"), "Smazat", this);
	actDelBuy->setToolTip("Smazat položku");
	connect(actDelBuy, SIGNAL(triggered()), this, SLOT(meActDelBuy()));

	actAddBuy = new QAction(QIcon(":img/list-add.png"), "Koupit", this);
	actAddBuy->setToolTip("Koupit");
	connect(actAddBuy, SIGNAL(triggered()), this, SLOT(meActAddBuy()));

	actAddCredit = new QAction(QIcon(":img/go-down.png"), "+kredit", this);
	actAddCredit->setToolTip("Odečte kredit");
	connect(actAddCredit, SIGNAL(triggered()), this, SLOT(meActAddCredit()));

	actLoginStamm = new QAction(QIcon(":img/list-resource-add.png"), "Login", this);
	actLoginStamm->setToolTip("");
	connect(actLoginStamm, SIGNAL(triggered()), this, SLOT(meActLoginStamm()));

	actLoginAnon = new QAction(QIcon(":img/list-add-user.png"), "Login", this);
	actLoginAnon->setToolTip("");
	connect(actLoginAnon, SIGNAL(triggered()), this, SLOT(meActLoginAnon()));

	toolButton->setDefaultAction(actAddBuy);
	toolButton_2->setDefaultAction(actDelBuy);
	toolButton_3->setDefaultAction(actCountBuy);
	toolButton_4->setDefaultAction(actAddCredit);

	toolButton_5->setDefaultAction(actLoginStamm);
	toolButton_6->setDefaultAction(actLoginAnon);

}


//-------------------------------------------------------------------------------------------------
void BuyForm::meActAddCredit() {
}

//-------------------------------------------------------------------------------------------------
void BuyForm::meActAddBuy() {
}

//-------------------------------------------------------------------------------------------------
void BuyForm::meActDelBuy() {
	
	PasswordDlg dlg(this);
	if ( dlg.exec() ) {
		
	};

}

//-------------------------------------------------------------------------------------------------
void BuyForm::meActCountBuy() {
	
	PasswordDlg dlg(this);
	if ( dlg.exec() ) {	
	};

}

//-------------------------------------------------------------------------------------------------
void BuyForm::meActLoginStamm() {
}

//-------------------------------------------------------------------------------------------------
void BuyForm::meActLoginAnon() {
	
	LoginAnonDlg dlg(this);
	if ( dlg.exec() ) {
		QString skey = dlg.getKey();
		addLogin(skey);
	};

}

//------------------------------------------------------------------------------------------------- 
void BuyForm::addLogin( QString p_key, QString p_id ) {
	
	m_sm->addCustom(p_key,p_id);

}

//------------------------------------------------------------------------------------------------- 
 
void BuyForm::listChanged( QItemSelection *p_sel, QItemSelection *p_dsel ) {

	if( p_sel->indexes().isEmpty() ) {
		clearValue();	
	} else {
		QModelIndex mi = p_sel->indexes().first();	
		if ( mi.isValid()) {
			CustomItem *si = (CustomItem *) m_sm->itemFromIndex(mi);
			setValue(si);
		};//if
	};//if

}

//------------------------------------------------------------------------------------------------- 
void BuyForm::clearValue() {
}


//------------------------------------------------------------------------------------------------- 
void BuyForm::setValue(CustomItem *p_si) {

	lineEdit  ->setText(p_si->getName());
	lineEdit_2->setText(p_si->getAddr());
	lineEdit_5->setText(p_si->getPhone());
	lineEdit_6->setText(p_si->getEmail());
	lineEdit_7->setText(p_si->getKey());

	label_11->setText(p_si->getCredit());

}


 //------------------------------------------------------------------------------------------------- 
   

