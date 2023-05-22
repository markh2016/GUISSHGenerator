#include "dialog.h"
#include "ui_dialog.h"

#include <QByteArray>
#include <QKeyEvent>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    process= new QProcess(this) ;

    isLoaded =false ;


    // need a file path and  file  name to read setting from and  write to

    file_name = "/creedentials.ini" ; // this  is the file name
    file_path = QDir::currentPath() + file_name ;  // this is the file path

     // connect  buttons : click  signals to slots
    connect(ui->btnSaveDetails,&QPushButton::clicked,this,&Dialog::saveDetails) ;

    connect(ui->btnLoaddetails, &QPushButton::clicked ,this, &Dialog::loadDetials);

    connect(ui->btnGenSSH, &QPushButton::clicked,this,&Dialog::processStartProcess);

    connect(ui->btnOK,&QPushButton::clicked,this,&Dialog::writeCommands) ;

    connect(ui->btnAddSSH,&QPushButton::clicked,this,&Dialog::addKeyToAgent);

    connect(ui->btnPrintSSHkey,&QPushButton::clicked,this,&Dialog::showSSK_Key) ;

    connect(ui->btnShowGit,&QPushButton::clicked,this,&Dialog::addKeyToGit);


    //  handle  dialogs close  event dialog doesnt emit close  signal in qt
    //  so we use  teh finished signal instead
    connect(this, &QDialog::finished, this, &Dialog::handleClose);


     // signals and call backs for Qprocess

    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        output = process->readAllStandardOutput() ;
        ui->txtResponce->appendPlainText(output);

    });

    connect(process,&QProcess::readyReadStandardError , this, [this](){
        output = process->readAllStandardError() ;
        qDebug() << output ;
    });

    // Connect the finished signal to a lambda function
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
        // Process has finished executing

        qDebug() << "Process finished with exit code: " << exitCode;
        qDebug() << "Exit status: " << exitStatus;
        ui->txtResponce->appendPlainText("Process  ssh exited on with exit code of 1 " );
        // clear replies line edit
        ui->txtReplies->setText("");
        process->close();


    });

    // new process for add key to agent

   addProcess = new QProcess(this);

    // Set up the necessary connections for reading output and handling errors
    connect(addProcess, &QProcess::readyReadStandardOutput, this, [this]{
        QString output = addProcess->readAllStandardOutput();
        ui->txtResponce->appendPlainText(output);
    });

    connect(addProcess, &QProcess::readyReadStandardError, this, [this] {
        QString output = addProcess->readAllStandardError();
        ui->txtResponce->appendPlainText(output);
    });

    connect(addProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
        // Process has finished executing
        qDebug() << "Process finished with exit code: " << exitCode;
        qDebug() << "Exit status: " << exitStatus;
        // finally  close the process

        ui->txtResponce->appendPlainText("add key to  ssh agent succesfull") ;
          addProcess->close() ;
    });

    // new process for  cat sshkey.pub

    addProcess2 = new QProcess(this) ;
    // Set up the necessary connections for reading output and handling errors
    connect(addProcess2, &QProcess::readyReadStandardOutput, this, [this]{
        QString output = addProcess2->readAllStandardOutput();
        ui->txtResponce->appendPlainText(output);
    });

    connect(addProcess2, &QProcess::readyReadStandardError, this, [this] {
        QString output = addProcess2->readAllStandardError();
        ui->txtResponce->appendPlainText(output);
    });

    connect(addProcess2, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
        // Process has finished executing
        qDebug() << "Process finished with exit code: " << exitCode;
        qDebug() << "Exit status: " << exitStatus;
        // finally  close the process

        ui->txtResponce->appendPlainText("Key is  printed above.\nPlease select and copy \n You will need this for Git") ;
        addProcess2->close();
    });


    // new process for launching webpage

    process2 = new QProcess(this) ;


    // Set up the necessary connections for reading output and handling errors
    connect(process2, &QProcess::readyReadStandardOutput, this, [this]{
        QString output = process2->readAllStandardOutput();
        ui->txtResponce->appendPlainText(output);
    });

    connect(process2, &QProcess::readyReadStandardError, this, [this] {
        QString output = process2->readAllStandardError();
        ui->txtResponce->appendPlainText(output);
    });

    connect(process2, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
        // Process has finished executing
        qDebug() << "Process finished with exit code: " << exitCode;
        qDebug() << "Exit status: " << exitStatus;


        ui->txtResponce->appendPlainText("Hopefully  this took you to correct page\nand you added ssh correctly ") ;
        // finally  close the process
        process2->close();
    });


}



Dialog::~Dialog()
{


    // deleting  eml pointer in destructor as  we  may still need this  elsewhere in program

    qDebug() << "Now In destructor ";
    qDebug() << "Deleting pointer *eml";

    delete eml ;
    qDebug() << "Deleting pointer *paswrd " ;
    delete paswrd ;
    qDebug() << "Deleting pointer *ui" ;
    delete ui;


    qDebug() << "Deleting process pointer" ;

    delete process ;
    qDebug() << "Deleting AddProcess pointer  " ;
    delete  addProcess ;
    qDebug() << "Deleting AddProcess2 pointer  " ;

    delete addProcess2 ;

    qInfo() << "Deleting proccess2 pointer " ;



}





//  using pass by  reference   for arguments

void Dialog::showMessage(const QString &message, const QString &title, const int &msgtype)
{

     // create the qmessage box  pointer
    QMessageBox  *msg = new QMessageBox(this) ;
    msg->setText(message);
    msg->setWindowTitle(title);

    // switch case  is used to  select  which  icon to use
    switch(msgtype){

    case 1: // informations
        msg->setIcon(QMessageBox::Information);
        break ;

    case 2:
        msg->setIcon(QMessageBox::Warning);
        break ;
    case 3:
        msg->setIcon(QMessageBox::Critical);
        break ;
    case 4:
        msg->setIcon(QMessageBox::Question);
        break ;


    } // end switch

    msg->exec() ;



   //  we can delete the  msg pointer here as  we will only ever  call this
   // function  from other functions

   // avoid  memory leaks  make sure any pointers  create are deleted

    delete msg  ;

}

//  called from save details of  all field validated

void Dialog::saveSettings()
{
    QSettings  *m_settings  = new QSettings (file_path, QSettings::IniFormat);
    m_settings->setValue("email" , *eml);
    m_settings->setValue("pasv" , *paswrd );


    delete m_settings ;
    isLoaded = true ;
}

// save details to  poperties  file and check fields

void Dialog::saveDetails()
{

    // 1step is to check and make sure all field are  validated  as nearset we can


    static QRegularExpression regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    /* Regex patter for password  */

    static QRegularExpression regExp("^(.{0,7}|[^0-9]*|[^A-Z]*|[^a-z]*|[a-zA-Z0-9]*)$") ;

    if( regex.match(ui->lineEmail->text().trimmed()).hasMatch()){
       // we have a correct email formatted address
       // save this for later use

        // when using pointers in C++  you have use the  new  keyword to allocate memmory
        eml =  new QString(ui->lineEmail->text().trimmed()) ;

    }

    else {
       showMessage("Email incorrect\nPlease redo" ,"Error" ,4) ;
       ui->lineEmail->setText("");
       delete eml ;
       isLoaded = false ;
       return  ;

    } // end of else  for if( regex.match(ui->lineEmail->text().trimmed()).hasMatch())



    /* if we get this far then all well  now  check and  revalidate  this field

     check number charcters is not less that  1 */

    if(ui->linePassword->text().trimmed().length() > 3){

       // we  have what may be a valid  password

       // create a Qstring pointer to this
       paswrd = new QString(ui->linePassword->text().trimmed()) ;

       // validate this


       if(!(regExp.match(*paswrd).hasMatch())) {

           showMessage("Password not validated or incorrect\nPlease redo" ,"Error" ,3) ;
           ui->linePassword->setText("");
           delete paswrd ;
           isLoaded = false  ;
           return  ;
       }




    } // end if ui->linePassword->text().trimmed().length() > 3)


    /*****  Save this to file  *****/

    saveSettings() ;


    showMessage("Settings successfully saved","File Informations",3 ) ;

}



//  load details from a properties file and populate fields
void Dialog::loadDetials()
{
    QSettings  *m_settings  = new QSettings (file_path, QSettings::IniFormat);
    if (QFile(file_path).exists()) {

       // update  fields on form
       ui->lineEmail->setText(m_settings->value("email", "").toString());


         eml =  new QString(ui->lineEmail->text().trimmed()) ;


        ui->linePassword->setText(m_settings->value("pasv","").toString());




        paswrd = new QString(ui->linePassword->text().trimmed());
        isLoaded = true ;

    } else {

       showMessage("Ini file  needs to be created\nPlease complete email and password fields\nthen click save"
                   ,"Settings File Missing", 1);
         isLoaded = false  ;
   }

    delete m_settings ;

}

void Dialog::handleClose()
{
    qDebug() << " Exiting programe  calling destructor ,  deleting any pointers etc"  ;
}

void Dialog::processStartProcess()
{

    if(isLoaded) {


    homedir = QDir::homePath() ;


    QString command = QString("ssh-keygen -t ed25519 -C \"%1\"").arg(ui->lineEmail->text().trimmed());




    process->start("bash", QStringList() << "-c" << command);

    process->setProcessChannelMode(QProcess::MergedChannels);
    process->setWorkingDirectory(homedir);

    process->start("bash", QStringList() << "-c" << command);

    //debugging purposes , to check this is not null

    qDebug()<< "email is " << *eml  << "password used was " << paswrd ;

    }

    else {
     showMessage("No settings for email saved\nOr  loaded " , "Major error", 3);
    }
}



void Dialog::writeCommands()
{



    ui->txtResponce->clear();
    QString reply = ui->txtReplies->text();

    process->write(reply.toUtf8());
    process->write("\n");

    if(process->waitForBytesWritten()){
       qDebug()<<  "Bytes have been  written " << "Commands sent were " << reply ;

    }

}

void Dialog::addKeyToAgent()
{

    QString command = "ssh-add ~/.ssh/id_ed25519" ;


    addProcess->setProcessChannelMode(QProcess::MergedChannels);
    addProcess->setWorkingDirectory(homedir);

    addProcess->start("bash", QStringList() << "-c" << command);
    // Start the process to execute the command



}

bool Dialog:: checkSSHKeyFilesExist()
{
    QString sshDirPath = QDir::homePath() + "/.ssh";
    QString privateKeyFilePath = sshDirPath + "/id_ed25519";
    QString publicKeyFilePath = sshDirPath + "/id_ed25519.pub";

    QFile privateKeyFile(privateKeyFilePath);
    QFile publicKeyFile(publicKeyFilePath);

    bool privateKeyExists = privateKeyFile.exists();
    bool publicKeyExists = publicKeyFile.exists();

    if (privateKeyExists && publicKeyExists) {
       qDebug() << "Both key files exist.";
       return true;
    } else {
       if (!privateKeyExists) {
           qDebug() << "Private key file does not exist.";
       }
       if (!publicKeyExists) {
           qDebug() << "Public key file does not exist.";
       }
       return false;
    }
}


void Dialog::showSSK_Key()


{
    if(checkSSHKeyFilesExist())
    {

        QString command = "cat ~/.ssh/id_ed25519.pub" ;
        addProcess2->setProcessChannelMode(QProcess::MergedChannels);
        addProcess2->setWorkingDirectory(homedir);

        addProcess2->start("bash", QStringList() << "-c" << command);
        // Start the process to execute the command
    }
    else {
         showMessage("You have not created  ssh keys\nAnd added these to ssh agent ","Keys Not Created",3);
    }
}

void Dialog::addKeyToGit()
{
    if(checkSSHKeyFilesExist())
    {
         QString command = "xdg-open https://github.com/settings/keys" ;
         process2->setProcessChannelMode(QProcess::MergedChannels);
         process2->setWorkingDirectory(homedir);

         process2->start("bash", QStringList() << "-c" << command);
         // Start the process to execute the command


    }

}


