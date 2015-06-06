/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 10:38:08                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 12:54:09                            **
*********************************************************************/




#ifndef CUSTORITEM_H
#define CUSTOMITEM_H

#include <QStandardItem>

class CustomItem : public QStandardItem {
 private:
 public:
	CustomItem( QString p_id, QString p_name, QString p_key,  QString p_buylist, QString p_permanent = "", QString p_addr="", QString p_phone="", 
				QString p_email = "", QString p_credit ="" );   	

	QString getId() const;
	QString getName() const;
	QString getKey() const;
	QString getAddr() const;
	QString getPhone() const;
	QString getEmail() const;
	QString getPermanent() const;
	QString getShopList() const;
	QString getCredit() const;

};


#define CP_ID   	 Qt::UserRole +  2
#define CP_NAME 	 Qt::UserRole +  3
#define CP_KEY 		 Qt::UserRole +  4
#define CP_ADDR 	 Qt::UserRole +  5
#define CP_PHONE 	 Qt::UserRole +  6
#define CP_EMAIL 	 Qt::UserRole +  7
#define CP_PERMANENT Qt::UserRole +  8
#define CP_SHOPLIST  Qt::UserRole +  9
#define CP_CREDIT    Qt::UserRole + 10


#endif


