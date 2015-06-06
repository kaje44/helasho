/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: čt 4. června 2015 10:38:08                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 12:54:13                            **
*********************************************************************/


#include <QStandardItem>

#include "customitem.h"


CustomItem::CustomItem( QString p_id, QString p_name, QString p_key, QString p_addr, QString p_phone, 
						QString p_email, QString p_permanent, QString p_buylist, QString p_credit ):QStandardItem( p_name ) {	
	setIcon(QIcon(":img/system-users.png"));
	setData( p_id,		  CP_ID    );
	setData( p_name,	  CP_NAME  );
	setData( p_key,		  CP_KEY   );
	setData( p_addr,	  CP_ADDR  );
	setData( p_phone,	  CP_PHONE );
	setData( p_email,	  CP_EMAIL );
	setData( p_permanent, CP_PERMANENT );
	setData( p_buylist,  CP_SHOPLIST  );
	setData( p_credit,   CP_CREDIT    );
}

//-------------------------------------------------------------------------------------------------
QString CustomItem::getId() const {

	return data(CP_ID).toString();

}

//-------------------------------------------------------------------------------------------------
QString CustomItem::getName() const {

	return data(CP_NAME).toString();

}

//-------------------------------------------------------------------------------------------------
QString CustomItem::getKey() const {

	return data(CP_KEY).toString();

}

//-------------------------------------------------------------------------------------------------
QString CustomItem::getAddr() const {

	return data(CP_ADDR).toString();

}

//-------------------------------------------------------------------------------------------------
QString CustomItem::getPhone() const {

	return data(CP_PHONE).toString();

}

//-------------------------------------------------------------------------------------------------
QString CustomItem::getEmail() const {

	return data(CP_EMAIL).toString();

}


//-------------------------------------------------------------------------------------------------
QString CustomItem::getPermanent() const {

	return data(CP_PERMANENT).toString();

}


//-------------------------------------------------------------------------------------------------
QString CustomItem::getShopList() const {

	return data(CP_SHOPLIST).toString();

}


//-------------------------------------------------------------------------------------------------
QString CustomItem::getCredit() const {		

	return data(CP_CREDIT).toString();

}

