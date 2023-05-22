#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog> // required for the dialog from
#include <QDir>   // for obtaining info about current  working directories or  setting these
#include <QDebug> //  fro debug   output
#include <QHash> // this is for key value pairs
#include <QMessageBox>  // eny message that  we wanty to display
#include <QRegularExpression>  // for  regex expressions
#include <QSettings>
#include <QFile>
#include <QProcess>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;  // the UI  xml file itself
    QString *eml ; // Pointer to email address
    QString *paswrd ; // Pointer to  password
    QString file_path , file_name;
    QProcess *process , *addProcess, *addProcess2, *process2 ; // for creating ssh process ;
    QString commands ;  // for  sending commands to underlying terminal
    QString output ;  //  for  anyoutput obtained from  signal slot defininition of
    // connect(process,&QProcess::readyReadStandardError

    QString homedir ; // for setting home directory

    bool isLoaded ; // flag for ensuring we have either saved details or loaded details from INI  file

     //  create so that we dont have to  continously use  QMessagebox in every function where required

    void showMessage(const QString &message , const QString &title , const int &msgtype) ;

    void saveSettings () ; // save  settings of pass and user email

    bool checkSSHKeyFilesExist() ;



private slots :
    void saveDetails() ;
    void loadDetials() ;
    void handleClose () ;
    void processStartProcess() ;
    void writeCommands() ;
    void addKeyToAgent() ;
    void showSSK_Key() ;
    void addKeyToGit();

};
#endif // DIALOG_H
