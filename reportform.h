/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: st 3. června 2015 06:44:57                         **
**                                                                  **
**  Geändert am: Čt 04.čen.2015 19:05:51                            **
*********************************************************************/




#ifndef REPORTFORM_H
#define REPORTFORM_H

#include <QWidget>

#include "ui_reportform.h"


class ReportModel;

class ReportForm : public QWidget , private Ui_ReportForm {
 private:
	ReportModel *m_rm;   
 public:
	ReportForm(QWidget * parent);
};

#endif


