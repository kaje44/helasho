/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: st 3. června 2015 06:33:32                         **
**                                                                  **
**  Geändert am: So 06.čen.2015 14:42:15                            **
*********************************************************************/




#ifndef SHOPFORM_H
#define SHOPFORM_H

#include <QWidget>

class BuyModel;
class CustomModel;
class CustomItem;

#include "ui_buyform.h"

class BuyForm : public QWidget , private Ui_BuyForm {
 	Q_OBJECT
 private:
	BuyModel  *m_bm;
	CustomModel  *m_cm;
	QAction *actLoginStamm,*actLoginAnon;
	QAction *actAddCredit, *actAddBuy, *actDelBuy, *actCountBuy;

	void addLogin( QString p_key, QString p_id = "-1" );
	void clearValue();
	void setValue(CustomItem *p_si);
 private slots:
	//
	void meActLoginStamm();
	void meActLoginAnon();
	void meActAddCredit();
	void meActAddBuy();
	void meActDelBuy();
	void meActCountBuy();

	void listChanged( QItemSelection *p_sel, QItemSelection *p_dsel );

 public:
	BuyForm(QWidget * parent);

};

#endif




