/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *mainLabel;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QFormLayout *formLayout_3;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnSaveDetails;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnLoaddetails;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *linePassword;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEmail;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_9;
    QFrame *frame_2;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *txtResponce;
    QLabel *label_6;
    QLineEdit *txtReplies;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnGenSSH;
    QPushButton *btnAddSSH;
    QPushButton *btnPrintSSHkey;
    QPushButton *btnShowGit;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnOK;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(496, 586);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mainLabel = new QLabel(Dialog);
        mainLabel->setObjectName(QString::fromUtf8("mainLabel"));
        QFont font;
        font.setFamilies({QString::fromUtf8("NotoSerifTamilSlanted SemiBold")});
        font.setPointSize(11);
        mainLabel->setFont(font);
        mainLabel->setStyleSheet(QString::fromUtf8(""));
        mainLabel->setAlignment(Qt::AlignCenter);
        mainLabel->setMargin(6);

        horizontalLayout->addWidget(mainLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        formLayout_3 = new QFormLayout(frame);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnSaveDetails = new QPushButton(frame);
        btnSaveDetails->setObjectName(QString::fromUtf8("btnSaveDetails"));

        horizontalLayout_4->addWidget(btnSaveDetails);

        horizontalSpacer_5 = new QSpacerItem(51, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btnLoaddetails = new QPushButton(frame);
        btnLoaddetails->setObjectName(QString::fromUtf8("btnLoaddetails"));

        horizontalLayout_4->addWidget(btnLoaddetails);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        linePassword = new QLineEdit(frame);
        linePassword->setObjectName(QString::fromUtf8("linePassword"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(linePassword->sizePolicy().hasHeightForWidth());
        linePassword->setSizePolicy(sizePolicy);
        linePassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(linePassword);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineEmail = new QLineEdit(frame);
        lineEmail->setObjectName(QString::fromUtf8("lineEmail"));
        sizePolicy.setHeightForWidth(lineEmail->sizePolicy().hasHeightForWidth());
        lineEmail->setSizePolicy(sizePolicy);
        lineEmail->setEchoMode(QLineEdit::Normal);

        horizontalLayout_2->addWidget(lineEmail);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_4->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_4);


        formLayout_3->setLayout(0, QFormLayout::SpanningRole, formLayout);


        verticalLayout->addWidget(frame);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_7->addWidget(label_8);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_7);

        frame_2 = new QFrame(Dialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::WinPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        formLayout_2 = new QFormLayout(frame_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        txtResponce = new QPlainTextEdit(frame_2);
        txtResponce->setObjectName(QString::fromUtf8("txtResponce"));
        txtResponce->setOverwriteMode(true);

        verticalLayout_3->addWidget(txtResponce);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        txtReplies = new QLineEdit(frame_2);
        txtReplies->setObjectName(QString::fromUtf8("txtReplies"));

        verticalLayout_3->addWidget(txtReplies);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_7 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnGenSSH = new QPushButton(frame_2);
        btnGenSSH->setObjectName(QString::fromUtf8("btnGenSSH"));

        verticalLayout_2->addWidget(btnGenSSH);

        btnAddSSH = new QPushButton(frame_2);
        btnAddSSH->setObjectName(QString::fromUtf8("btnAddSSH"));

        verticalLayout_2->addWidget(btnAddSSH);

        btnPrintSSHkey = new QPushButton(frame_2);
        btnPrintSSHkey->setObjectName(QString::fromUtf8("btnPrintSSHkey"));

        verticalLayout_2->addWidget(btnPrintSSHkey);

        btnShowGit = new QPushButton(frame_2);
        btnShowGit->setObjectName(QString::fromUtf8("btnShowGit"));

        verticalLayout_2->addWidget(btnShowGit);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_3);

        btnOK = new QPushButton(frame_2);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        verticalLayout_4->addWidget(btnOK);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_6);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout_6);


        verticalLayout->addWidget(frame_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        mainLabel->setText(QCoreApplication::translate("Dialog", "SSH Key Generator  GUI  MD Harrington\n"
" London UK\n"
"22/05/23", nullptr));
        btnSaveDetails->setText(QCoreApplication::translate("Dialog", " Save Detials", nullptr));
        btnLoaddetails->setText(QCoreApplication::translate("Dialog", "&Load Detials", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Password", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Email Address", nullptr));
        lineEmail->setText(QString());
        label_4->setText(QCoreApplication::translate("Dialog", " Step 1  Please enter details  below ", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "Step 2 Generate SSH Key ", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Responces returned  for creating ssh key", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "SSH Key Gen Operations", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Use this field below for answer to responces", nullptr));
        btnGenSSH->setText(QCoreApplication::translate("Dialog", "Start SSH key Generation", nullptr));
        btnAddSSH->setText(QCoreApplication::translate("Dialog", "Add Key to SSH Agent", nullptr));
        btnPrintSSHkey->setText(QCoreApplication::translate("Dialog", "Show SSH Key", nullptr));
        btnShowGit->setText(QCoreApplication::translate("Dialog", "Launch Browser For GIt", nullptr));
        btnOK->setText(QCoreApplication::translate("Dialog", "Commit Answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
