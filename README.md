# GUISSHGenerator Designed for debian linux only  MD Harrington London UK 20-05-2023 
GUI Tool  that saves on having to type out tons of  using bash shell
The code  consists of a header file dialog.h and its corresponding implementation file dialog.cpp. The code is a  Qt application and includes several Qt libraries for various functionalities. Let's go through the code and explain its purpose and structure.

dialog.h:

    The header file starts with include statements for various Qt libraries used in the code.
    It defines a class Dialog that inherits from QDialog, which is a Qt class representing a dialog window.
    Inside the Dialog class, there are private member variables, including pointers to the user interface (UI) and other necessary variables.
    The class also declares several private functions and private slots (slots are Qt's way of defining event handlers).
    At the end of the header file, there is an #endif directive to close the conditional compilation block.

dialog.cpp:

    The implementation file starts with include statements, including the corresponding header file and additional Qt libraries.
    The constructor Dialog::Dialog initializes the UI, sets up connections between UI elements and slots, and creates instances of QProcess for executing commands.
    The destructor Dialog::~Dialog deletes dynamically allocated variables and cleans up resources.
    The function Dialog::showMessage displays a message box with the provided message, title, and message type.
    The function Dialog::saveSettings saves user email and password details to a settings file.
    The function Dialog::saveDetails is called when the user clicks the "Save Details" button and validates and saves the user's email and password details.
    The function Dialog::loadDetails is called when the user clicks the "Load Details" button and loads email and password details from the settings file.
    The function Dialog::handleClose is a slot called when the dialog is closed, and it performs necessary cleanup tasks.
    The function Dialog::processStartProcess is called when the user clicks the "GenSSH" button and starts the process for generating an SSH key.
    The function Dialog::writeCommands is called when the user clicks the "OK" button and writes the entered commands to the process for execution.
    The function Dialog::addKeyToAgent is called when the user clicks the "AddSSH" button and adds the SSH key to the agent.

In more detail 

Sure! Let's go through the code and explain each function:

    Dialog::Dialog(QWidget *parent) - This is the constructor of the Dialog class, which is a subclass of QDialog. It initializes the dialog and sets up various connections between signals and slots. Here's what it does:
        Initializes the dialog and sets up the user interface by calling ui->setupUi(this).
        Creates a QProcess object named process and sets the isLoaded flag to false.
        Sets the file_name variable to "/creedentials.ini" and the file_path variable to the current directory concatenated with the file_name.
        Connects various buttons' click signals to their respective slots using the connect function.
        Handles the dialog's close event by connecting the finished signal to the handleClose slot.
        Sets up connections for the process object's signals, such as readyReadStandardOutput, readyReadStandardError, and finished.
        Creates additional QProcess objects (addProcess, addProcess2, process2) and sets up connections for their signals as well.
        Finally, this function is responsible for setting up the connections between signals and slots for various operations within the dialog.

    Dialog::~Dialog() - This is the destructor of the Dialog class. It is responsible for cleaning up dynamically allocated memory and resources used by the dialog, such as deleting pointers and closing processes.

    Dialog::showMessage(const QString &message, const QString &title, const int &msgtype) - This function displays a message box with a specified message, title, and message type. It creates a QMessageBox object, sets its properties based on the provided parameters, and executes it using the exec() function. After the message box is closed, it deletes the QMessageBox object to avoid memory leaks.

    Dialog::saveSettings() - This function saves the email and password entered in the dialog to a settings file. It creates a QSettings object with the specified file path and format, and then sets the values for "email" and "pasv" using the setValue function. After saving the settings, it deletes the QSettings object.

    Dialog::saveDetails() - This function is called when the "Save Details" button is clicked. It validates the email and password fields, and if they pass validation, it calls the saveSettings() function to save the details to the settings file. If any validation fails, an error message is displayed, and the corresponding fields are cleared.

    Dialog::loadDetials() - This function is called when the "Load Details" button is clicked. It loads the email and password from the settings file, updates the corresponding fields in the dialog, and sets the isLoaded flag to true. If the settings file doesn't exist, an error message is displayed.

    Dialog::handleClose() - This function is called when the dialog is closed. It is responsible for cleaning up resources and performing any necessary actions before the dialog is closed. In this case, it simply outputs a debug message.

    Dialog::processStartProcess() - This function is called when the "Generate SSH" button is clicked. It starts a new process to generate an SSH key pair using the ssh-keygen command. The email entered in the dialog is used as the comment for the key pair. The process's output and errors are captured using the readyReadStandardOutput and readyReadStandardError signals, respectively. After the process finishes, the output is




The project has been  compiled for Debain 12  and works extremley well  You may  need to recompile this  yourself  in which  case  after downloading 

open a  terminal and cd into  folder  build-SSHGEN-Desktop_Qt_6_3_0_GCC_64bit-Release
issue  the commands make clean 
then issue make 

Fingers  crossed all should work  ( Im a new to qt  and still learning  this via on;line tuts, websites and  more or less self taught ) 


