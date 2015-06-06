/*********************************************************************
**  KaJe															**
**																	**
**  Vytvořen: 05.02.2008 - 18:57:16									**
**																	**
**  Poslední úpravy: Pá 05.čen.2015 10:05:01                        **
**********************************************************************/

#include "kjsyslog.h"
#include "kjguilib.h" 
#include "kjmainwindow.h"
#include "memberform.h"
#include "buyform.h"
#include "reportform.h"
#include "storageform.h"

#include "mainform.h"


//-------------------------------------------------------------------------------------------------

MainForm::MainForm() : KjMainWindow() {
	setupUi(this);
		
//	createInfo("Helasho","$build v0.0.0$", ":img/munin-ikona.png");

	tabWidget->addTab(new BuyForm(this),QIcon(":img/help-donate.png"),"Prodej");
	tabWidget->addTab(new ReportForm(this),QIcon(":/img/edit-select-all.png"),"Přehled");
	tabWidget->addTab(new MemberForm(this),QIcon(":/img/system-users.png"),"Členové");
	tabWidget->addTab(new StorageForm(this),QIcon(":/img/kchart.png"),"Sklad");

//	connect( tabWidget, SIGNAL( currentChanged( int ) ), this, SLOT( tabChanged( int ))); 
//	connect( tabWidget, SIGNAL( tabCloseRequested (int) ), this ,SLOT( tabCloseRequested(int) )); 

//	updateAction();
//	changeStatus( false );

}

//-------------------------------------------------------------------------------------------------

MainForm::~MainForm() {

//	canSave();
//	saveConfig();	

}

//-----------------------------------------------------------------------------

/**
 * Nastavi barvy
 */

void MainForm::setColor() {
	
	QPalette palette;
	QColor colBack(160,160,160);
	palette.setColor(QPalette::Background,colBack);	
	palette.setColor(QPalette::Foreground,Qt::black);
	palette.setColor(QPalette::Button,colBack);	
	palette.setColor(QPalette::ButtonText,Qt::black);	
	QColor colBase(128,128,128);
 	palette.setColor(QPalette::Base,colBase);
	palette.setColor(QPalette::AlternateBase,colBack);
	palette.setColor(QPalette::Text,Qt::white);
	//QColor HiBack(192,164,192);
	QColor HiBack(136,89,9);			
	palette.setColor(QPalette::Highlight,HiBack);
	setPalette(palette);					  

}

//------------------------------------------------------------------------------------------------- 
/*
void MainForm::createToolBars() {

	m_mainToolBar = addToolBar("Main");
	m_mainToolBar->addAction( actNewFile );
	m_mainToolBar->addAction( actOpenFile ); 
	m_mainToolBar->addAction( actSaveFile ); 
	m_mainToolBar->addAction( actCloseFile );		
	updateFileMenu();

}

//------------------------------------------------------------------------------------------------- 

void MainForm::tabChanged( int p_index ) {

	try {
		getCurrentEd(p_index);
		m_ed->getStatus();
	} catch (KjEdException &ex) {
		changeStatus(false,"");	
	};//try
	updateAction();

}

//------------------------------------------------------------------------------------------------

void MainForm::createActions() {

	actCloseFile = getAction( "Zavřít soubor", "Zavře aktuální soubor", SLOT( meCloseFile() ), "/usr/share/icons/oxygen/32x32/actions/document-close.png");
	actCloseFile->setShortcut(QKeySequence(tr("Ctrl+X")));

	actOpenFile = getAction( "Otevřít soubor","Otevře soubor", SLOT( meOpenFile() ),"/usr/share/icons/oxygen/32x32/actions/document-open.png");
	actOpenFile->setShortcut(QKeySequence(tr("Ctrl+O")));

	actNewFile = getAction( "Nový soubor", "Vytvoří nový soubor", SLOT( meNewFile() ), "/usr/share/icons/oxygen/32x32/actions/document-new.png");
	actNewFile->setShortcut(QKeySequence(tr("Ctrl+N")));

	actSaveFile = getAction( "Uložit soubor", "Uloží soubor", SLOT( meSaveFile() ),"/usr/share/icons/oxygen/32x32/actions/document-save.png");
	actSaveFile->setShortcut(QKeySequence(tr("Ctrl+S")));

	actSaveAsFile = getAction( "Uložit jako ...","Uloží soubor pod jiným jménem",SLOT(meSaveAsFile()),"/usr/share/icons/oxygen/32x32/actions/document-save-as.png");

	actFindText = getAction( "Najdi text", "Najde text", SLOT(meFindText()), "/usr/share/icons/oxygen/32x32/actions/edit-find.png");
	actFindText->setShortcut(QKeySequence(tr("Ctrl+F")));

	actReplaceText = getAction( "Nahraď text","Nahradí text", SLOT(meReplaceText()),"/usr/share/icons/oxygen/32x32/actions/edit-find-replace.png");
	actReplaceText->setShortcut(QKeySequence(tr("Ctrl+R")));

	actInsertImg = getAction( "Nahraď položku", "Nahradí položky", SLOT(meInsertImg()), "/usr/share/icons/oxygen/32x32/actions/edit-find-replace.png");
	actInsertImg->setShortcut(QKeySequence(tr("Ctrl+H")));
	
	
}

//------------------------------------------------------------------------------------------------- 

void MainForm::getCurrentEd( int p_tab ) throw (KjEdException &) {
   
   int idx = ( p_tab == -1 ) ? tabWidget->currentIndex() : p_tab;
   	
   if ( (idx < 0) || (tabWidget->count() <= 0)) {

	  m_ed = NULL;		 	   
	  throw KjEdException(QString(EDNOEDIT));

   } else {

	  m_ed = (EditWindow *) tabWidget->widget(idx);

   };//if

   return;

} 

//------------------------------------------------------------------------------------------------

void MainForm::createStatusBar() {

	QStatusBar *sb = Ui_MainWindow::statusBar;
	m_modStatus = new QLabel( " Připraven " );
	m_modStatus->setFrameShape(QFrame::StyledPanel);
	m_fileStatus = new QLabel( " - " );
	m_fileStatus->setFrameShape(QFrame::Box);
	sb->addWidget(m_modStatus);
	sb->addWidget(m_fileStatus,1);

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::changeStatus( bool p_modified, QString p_fname ) {

	m_modStatus->setText( ( p_modified ) ? " Neuložené změny " : " Připraven " );
	int ci = tabWidget->currentIndex();
	if ( p_modified ) {
		tabWidget->setTabIcon(ci,QIcon(":/img/document-save.png"));
	} else {
		tabWidget->setTabIcon(ci,QIcon());
	};
	m_fileStatus->setText( p_fname );
	updateAction();
}

//-------------------------------------------------------------------------------------------------


void MainForm::meOpenFile(QString p_file)  {
	
	QStringList fileNames;
	
	if ( p_file != "" ) {

		fileNames << p_file;	

	} else {	

		QFileDialog *dlg = new QFileDialog(this,"Otevři soubor",QDir::homePath()+"/Dokumenty");
		dlg->setFileMode(QFileDialog::ExistingFile); 
		QStringList filters;
		filters << "Munin soubory (*.mun)"
        		<< "Vše (*)";
		dlg->setNameFilters(filters);
		if (dlg->exec()) {
			fileNames = dlg->selectedFiles();			
		}

		delete dlg;
	};//if

	if ( fileNames.count() > 0 ) {
		foreach( QString sfile, fileNames	) {
			addFileToLastList(sfile);
	  		createEd(sfile);
		};//for
	};//for	

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::addFileToLastList(QString p_file) {

	int idx = m_lastOpenFile.indexOf(p_file);
	
	if ( idx > -1 )
   		m_lastOpenFile.removeAt(idx);
	m_lastOpenFile << p_file;		

	if (m_lastOpenFile.size() > 5 ) 
		m_lastOpenFile.removeFirst();	

}

//-------------------------------------------------------------------------------------------------

void MainForm::meCloseFile(int p_tab) {
	
	int idx = ( p_tab == -1 ) ? tabWidget->currentIndex() : p_tab;
	try {

		getCurrentEd( idx );
		if (m_ed->isChanged())  {

			if ( quest("Uložit","Uložit změny v souboru ?") ) {	

				meSaveFile();

			};//if

		};//if
		tabWidget->removeTab(idx);

	} catch (KjEdException &ex) {
		error("Munin", QString(ex.what()));
	};//try
	
	updateAction();
	updateFileMenu();

}

//-------------------------------------------------------------------------------------------------

void MainForm::meNewFile() {

	createEd();	
	updateAction();

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::meSaveFile() {

	try {	
		getCurrentEd();
		if (m_ed->hasName()) {
			m_ed->saveToFile();		
		} else {
			 meSaveAsFile();
		};
	} catch (KjEdException &ex) {
		error("Munin", QString(ex.what()));
	};//try
	updateAction();
}

//------------------------------------------------------------------------------------------------- 

void MainForm::meSaveAsFile() {
	
	try {	
		getCurrentEd();
		QFileDialog *dlg = new QFileDialog(this,"Uložit jako...",QDir::homePath()+"/Dokumenty");
		dlg->setFileMode(QFileDialog::AnyFile); 
		dlg->setAcceptMode(QFileDialog::AcceptSave);
		QStringList filters;
		filters << "Munin soubory (*.mun)"
				<< "Vše (*)";
		dlg->setNameFilters(filters);
		if (dlg->exec()) {
			QStringList fileNames;
			fileNames = dlg->selectedFiles();				
			QString fileName = fileNames[0];		 
			if (!fileName.endsWith(".mun")) {
				fileName += ".mun";
			}
			if (fileName.isEmpty()) {
					return ;
			} else {
				addFileToLastList(fileName);
				m_ed->saveToFile(fileName);		
				QString name = QFileInfo(fileName).baseName(); 
				tabWidget->setTabText(tabWidget->currentIndex(),name);</widget>

			}//else
		};//if
	} catch (KjEdException &ex) {
		error("Munin", QString(ex.what()));
	};//try
	updateAction();

}
	
//------------------------------------------------------------------------------------------------- 

void MainForm::canSave() {
	
	if (tabWidget->count() > 0 ) {
		EditWindow *ed;
		bool chng = false;
		for(int i = 0; i < tabWidget->count();i++) {
			ed = (EditWindow *) tabWidget->widget(i);
			if (ed->isChanged()) {
			    chng = true;
				break;
			};//if
		}//for
		if ((chng) && (quest("Munin", "Obsahuje neuložené změny, uložit ?",this))) {
			for(int i = 0; i < tabWidget->count();i++) {
				ed = (EditWindow *) tabWidget->widget(i);
				ed->saveToFile();
			}//for;	
		};//if
	};//if	

};

//------------------------------------------------------------------------------------------------- 

void MainForm::updateAction() { 	

	bool notEmpty = (tabWidget->count() > 0); 	
	actSaveFile->setEnabled(notEmpty);	
	actSaveAsFile->setEnabled(notEmpty);	
	actCloseFile->setEnabled(notEmpty);  	
	actInsertImg->setEnabled(notEmpty);
	if (notEmpty) {
		try {

			getCurrentEd();
			actSaveAsFile->setEnabled(!(m_ed->hasName()));		
			actSaveFile->setEnabled(m_ed->isChanged());						

		} catch (KjEdException &ex) {

			error("Munin", QString(ex.what()));

		};//try
	};//if

}

//-------------------------------------------------------------------------------------------------

void MainForm::createEd(QString p_fileName) {

	QString name;
	EditWindow *ed;
	if (p_fileName.isEmpty()) {		
			ed = new EditWindow(this);
		name = trUtf8("Nový");
	} else {	
		  ed = new EditWindow(this,p_fileName);
	  name = QFileInfo(p_fileName).baseName(); 
	}
	connect(ed, SIGNAL( changeStatus( bool , QString )), this ,SLOT( changeStatus( bool , QString ))); 
	tabWidget->addTab(ed,name);
	tabWidget->setCurrentIndex(tabWidget->count()-1);
	changeStatus( false , p_fileName );
}


//------------------------------------------------------------------------------------------------- 

void MainForm::meInsertImg() {
	
	QString fileName = QFileDialog::getOpenFileName(this,"Vložit obrázek", "/home/karl", "Image Files (*.png *.jpg *.bmp *.gif)");
	if (!fileName.isEmpty()) {
	  getCurrentEd();
	  m_ed->inputImage(fileName);	
	};//if

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::dragEnterEvent(QDragEnterEvent *event) {
	
	foreach(QUrl url, event->mimeData()->urls()) {
		if (QFileInfo(url.toLocalFile()).suffix().toUpper()=="MUN") {
			event->acceptProposedAction();
			return;
		} else {
			event->ignore();
		}
	}	

} 

//------------------------------------------------------------------------------------------------- 
 
void MainForm::dropEvent(QDropEvent *event)	{
	
	foreach(QUrl url, event->mimeData()->urls()) {
		QString filename = url.toLocalFile();
		QString suffix = QFileInfo(filename).suffix().toUpper();
		if(suffix=="MUN") {
			event->acceptProposedAction();
			meOpenFile();
			continue;
		} else {
			event->ignore();
		};//if
	};//foreach

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::tabCloseRequested ( int index ) {
	
	meCloseFile(index);	

};

//------------------------------------------------------------------------------------------------- 

   
void MainForm::loadConfig() {
   
   m_cfgFile = QDir::homePath()+"/.muninrc";
   m_lastOpenFile.clear();
   QFile data(m_cfgFile);
   if (data.exists()) {
   	if (data.open(QFile::ReadOnly)) {
	 		QTextStream in(&data);
   		QString line;
   		do {
   		    line = in.readLine().trimmed();
   			if ((line != "") && (QFile::exists(line))) {
   				m_lastOpenFile.insert(0,line);
   			};//if	
   		} while (!line.isNull());
  		};//if
   };//if

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::saveConfig() {
    
	QFile data(m_cfgFile);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
   		QTextStream out(&data);
	   	foreach( QString str, m_lastOpenFile ) {
   			str = str.trimmed();
   			if (str!="")
   				out << str << endl;
	   	}
    };//if

}

//------------------------------------------------------------------------------------------------- 
  
void MainForm::meFirstLastFile() {

 	meOpenFile(m_lastOpenFile[0]); 

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::meSecondLastFile() {

	meOpenFile(m_lastOpenFile[1]);

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::meThirdLastFile() {

	meOpenFile(m_lastOpenFile[2]);

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::meFourthLastFile() {

	meOpenFile(m_lastOpenFile[3]);

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::meFifthLastFile() {

	meOpenFile(m_lastOpenFile[4]);

}

//------------------------------------------------------------------------------------------------- 
 
void MainForm::updateFileMenu() {

	if (actFirstLastFile!=NULL) {
		delete actFirstLastFile;
		delete actSecondLastFile;
		delete actThirdLastFile;
		delete actFourthLastFile;
		delete actFifthLastFile;
	}	

	int i = 0;
	QString str = ( i < m_lastOpenFile.size() ) ? QFileInfo(m_lastOpenFile[i]).baseName() : "";
	actFirstLastFile = getAction( str, str, SLOT( meFirstLastFile() ), ":img/address-book-new.png");

	i++;
	str = ( i < m_lastOpenFile.size() ) ? QFileInfo(m_lastOpenFile[i]).baseName() : "";
	actSecondLastFile = getAction( str, str, SLOT( meSecondLastFile() ), ":img/address-book-new.png");

	i++;
	str = ( i < m_lastOpenFile.size() ) ? QFileInfo(m_lastOpenFile[i]).baseName() : "";
	actThirdLastFile = getAction( str, str, SLOT( meThirdLastFile() ), ":img/address-book-new.png");
	
	i++;
	str = ( i < m_lastOpenFile.size() ) ? QFileInfo(m_lastOpenFile[i]).baseName() : "";
	actFourthLastFile = getAction( str, str, SLOT( meFourthLastFile() ), ":img/address-book-new.png");	

	i++;
	str = ( i < m_lastOpenFile.size() ) ? QFileInfo(m_lastOpenFile[i]).baseName() : "";
	actFifthLastFile = getAction( str, str, SLOT( meFifthLastFile() ), ":img/address-book-new.png");	

	if (m_lastOpenFile.size() > 0 ) {
		m_mainToolBar->addSeparator();
		for(int i = 0; i < m_lastOpenFile.size();i++) {
			switch ( i ) {
				case 0 : m_mainToolBar->addAction(actFirstLastFile);
						 break;
				case 1 : m_mainToolBar->addAction(actSecondLastFile);
						 break;
				case 2 : m_mainToolBar->addAction(actThirdLastFile);
						 break;
				case 3 : m_mainToolBar->addAction(actFourthLastFile);
						 break;
				case 4 : m_mainToolBar->addAction(actFifthLastFile);
						 break;
				default: break;			 
			}//switch 
		};//for
	};//if
	
}

*/
//------------------------------------------------------------------------------------------------- 
 
