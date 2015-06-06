/*********************************************************************
**  KaJe 2015                                                       **
**                                                                  **
**  Erstellt am: So 06.čen.2015 14:29:13                            **
**                                                                  **
**  Geändert am: So 06.čen.2015 14:29:38                            **
**********************************************************************/

#ifndef MAINFORM_H
#define MAINFORM_H


#include "ui_mainform.h"
#include "kjmainwindow.h"
//include "muexception.h"



class QAction;
class QLabel;
class EditWindow; 
class FindDialog; 
class QComboBox; 
class QFontComboBox; 
class QToolBar;


//--------------------------------------------

class MainForm : public KjMainWindow, private  Ui_MainWindow {
    Q_OBJECT
private:
/*
 	QAction *actNewFile, *actCloseFile, *actOpenFile, *actSaveFile,*actSaveAsFile;
	QAction *actFirstLastFile, *actSecondLastFile, *actThirdLastFile, *actFourthLastFile, *actFifthLastFile;
	QAction *actExit;
	
	QAction *actInsertImg;
    QAction *actTextTextBold, *actTextTextUnderline, *actTextTextItalic, *actTextTextColor, *actTextBackColor, *actTextAlignLeft, *actTextAlignCenter, *actTextAlignRight, *actTextAlignJustify;	
	QActionGroup *grpTextAlign;

    QLabel *m_fileStatus, *m_modStatus;
	QToolBar *m_mainToolBar;

	EditWindow *m_ed;

	// Vrací aktuální editor nebo null při chybě 
	void getCurrentEd(int p_tab = -1) throw (KjEdException &);
	void canSave();

	QString m_cfgFile;
	QStringList m_lastOpenFile;
	void loadConfig();
	void saveConfig();
	void createActions();
	void createStatusBar();
	void createToolBars();

private slots:
    void tabChanged( int p_index );
	void tabCloseRequested ( int index );
	
	//soubor
	void meCloseFile(int p_tab = -1);
	void meNewFile();
	void meOpenFile(QString p_file = "");
	void meFirstLastFile();
	void meSecondLastFile();
	void meThirdLastFile();
	void meFourthLastFile();
	void meFifthLastFile();

	void meSaveFile();
	void meSaveAsFile();		

    void meInsertImg();	 

	// reakce pro statusbar položka, pozice kurzoru + stav modifikace
	void changeStatus( bool p_modified, QString p_fname = "Nový" );
    
	 zkontroluje zda maji byt jednotlive akce pristupne 
	void updateAction();
	//změní akce podle naposledy otevřených souborů
	void updateFileMenu();
	// přidá soubor do seznamu naposledy otevrenych souborů
	void addFileToLastList(QString p_file);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
*/
public:
    MainForm();
	~MainForm();
    void setColor();
};

#endif   

