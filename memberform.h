/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: st 3. června 2015 06:44:48                         **
**                                                                  **
**  Geändert am: Pá 05.čen.2015 06:59:28                            **
*********************************************************************/




#ifndef MEMBERFORM_H
#define MEMBERFORM_H

#include <QWidget>

#include "ui_memberform.h"

class MemberModel;


class MemberForm : public QWidget ,private Ui_MemberForm {

 private:
	MemberModel *m_mm;

 public:
	MemberForm(QWidget *p_parent);

};

#endif



