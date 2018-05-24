/********************************************************************************
** Form generated from reading UI file 'loadfileconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADFILECONFIGURATION_H
#define UI_LOADFILECONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadFileConfiguration
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxReaderType;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxFilterPointsOrigin;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidgetFiles;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAddFile;
    QPushButton *pushButtonModifyFile;
    QPushButton *pushButtonImportFile;
    QPushButton *pushButtonExportFiles;
    QPushButton *pushButtonDeleteFile;
    QPushButton *pushButtonDeleteAllFile;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelFilepath;
    QLabel *label_3;
    QComboBox *comboBoxScannerType;
    QGroupBox *groupBoxPosition;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBoxZPos;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxXPos;
    QDoubleSpinBox *doubleSpinBoxYPos;
    QGroupBox *groupBoxAngles;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *checkBoxScannerClockwise;
    QCheckBox *checkBoxAngleInRadians;
    QLabel *label_8;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBoxHRes;
    QDoubleSpinBox *doubleSpinBoxVRes;
    QLabel *label_10;
    QLabel *label_11;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBoxStartTheta;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBoxEndTheta;
    QLabel *label_12;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *doubleSpinBoxStartPhi;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBoxEndPhi;
    QGroupBox *groupBoxDirection;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *doubleSpinBoxZDir;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBoxYDir;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBoxXDir;
    QPushButton *pushButtonApplyConfigurationToNextFile;
    QPushButton *pushButtonApplyConfigurationToAll;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoadFileConfiguration)
    {
        if (LoadFileConfiguration->objectName().isEmpty())
            LoadFileConfiguration->setObjectName(QStringLiteral("LoadFileConfiguration"));
        LoadFileConfiguration->resize(832, 839);
        horizontalLayout_2 = new QHBoxLayout(LoadFileConfiguration);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(LoadFileConfiguration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBoxReaderType = new QComboBox(groupBox);
        comboBoxReaderType->setObjectName(QStringLiteral("comboBoxReaderType"));

        horizontalLayout->addWidget(comboBoxReaderType);


        verticalLayout_6->addWidget(groupBox);

        groupBox_4 = new QGroupBox(LoadFileConfiguration);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBoxFilterPointsOrigin = new QCheckBox(groupBox_4);
        checkBoxFilterPointsOrigin->setObjectName(QStringLiteral("checkBoxFilterPointsOrigin"));
        checkBoxFilterPointsOrigin->setEnabled(false);

        verticalLayout_2->addWidget(checkBoxFilterPointsOrigin);


        verticalLayout_6->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(LoadFileConfiguration);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        listWidgetFiles = new QListWidget(groupBox_2);
        listWidgetFiles->setObjectName(QStringLiteral("listWidgetFiles"));
        listWidgetFiles->setSortingEnabled(false);

        horizontalLayout_3->addWidget(listWidgetFiles);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonAddFile = new QPushButton(groupBox_2);
        pushButtonAddFile->setObjectName(QStringLiteral("pushButtonAddFile"));

        verticalLayout->addWidget(pushButtonAddFile);

        pushButtonModifyFile = new QPushButton(groupBox_2);
        pushButtonModifyFile->setObjectName(QStringLiteral("pushButtonModifyFile"));

        verticalLayout->addWidget(pushButtonModifyFile);

        pushButtonImportFile = new QPushButton(groupBox_2);
        pushButtonImportFile->setObjectName(QStringLiteral("pushButtonImportFile"));

        verticalLayout->addWidget(pushButtonImportFile);

        pushButtonExportFiles = new QPushButton(groupBox_2);
        pushButtonExportFiles->setObjectName(QStringLiteral("pushButtonExportFiles"));

        verticalLayout->addWidget(pushButtonExportFiles);

        pushButtonDeleteFile = new QPushButton(groupBox_2);
        pushButtonDeleteFile->setObjectName(QStringLiteral("pushButtonDeleteFile"));

        verticalLayout->addWidget(pushButtonDeleteFile);

        pushButtonDeleteAllFile = new QPushButton(groupBox_2);
        pushButtonDeleteAllFile->setObjectName(QStringLiteral("pushButtonDeleteAllFile"));

        verticalLayout->addWidget(pushButtonDeleteAllFile);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(groupBox_2);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_3 = new QGroupBox(LoadFileConfiguration);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(280, 0));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        labelFilepath = new QLabel(groupBox_3);
        labelFilepath->setObjectName(QStringLiteral("labelFilepath"));

        verticalLayout_9->addWidget(labelFilepath);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_9->addWidget(label_3);

        comboBoxScannerType = new QComboBox(groupBox_3);
        comboBoxScannerType->setObjectName(QStringLiteral("comboBoxScannerType"));

        verticalLayout_9->addWidget(comboBoxScannerType);

        groupBoxPosition = new QGroupBox(groupBox_3);
        groupBoxPosition->setObjectName(QStringLiteral("groupBoxPosition"));
        verticalLayout_8 = new QVBoxLayout(groupBoxPosition);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        doubleSpinBoxZPos = new QDoubleSpinBox(groupBoxPosition);
        doubleSpinBoxZPos->setObjectName(QStringLiteral("doubleSpinBoxZPos"));
        doubleSpinBoxZPos->setDecimals(6);
        doubleSpinBoxZPos->setMinimum(-1e+9);
        doubleSpinBoxZPos->setMaximum(1e+9);

        gridLayout->addWidget(doubleSpinBoxZPos, 2, 1, 1, 1);

        label_6 = new QLabel(groupBoxPosition);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_5 = new QLabel(groupBoxPosition);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(groupBoxPosition);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        doubleSpinBoxXPos = new QDoubleSpinBox(groupBoxPosition);
        doubleSpinBoxXPos->setObjectName(QStringLiteral("doubleSpinBoxXPos"));
        doubleSpinBoxXPos->setDecimals(6);
        doubleSpinBoxXPos->setMinimum(-1e+9);
        doubleSpinBoxXPos->setMaximum(1e+9);

        gridLayout->addWidget(doubleSpinBoxXPos, 0, 1, 1, 1);

        doubleSpinBoxYPos = new QDoubleSpinBox(groupBoxPosition);
        doubleSpinBoxYPos->setObjectName(QStringLiteral("doubleSpinBoxYPos"));
        doubleSpinBoxYPos->setDecimals(6);
        doubleSpinBoxYPos->setMinimum(-1e+9);
        doubleSpinBoxYPos->setMaximum(1e+9);

        gridLayout->addWidget(doubleSpinBoxYPos, 1, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout);


        verticalLayout_9->addWidget(groupBoxPosition);

        groupBoxAngles = new QGroupBox(groupBox_3);
        groupBoxAngles->setObjectName(QStringLiteral("groupBoxAngles"));
        verticalLayout_7 = new QVBoxLayout(groupBoxAngles);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        checkBoxScannerClockwise = new QCheckBox(groupBoxAngles);
        checkBoxScannerClockwise->setObjectName(QStringLiteral("checkBoxScannerClockwise"));

        verticalLayout_7->addWidget(checkBoxScannerClockwise);

        checkBoxAngleInRadians = new QCheckBox(groupBoxAngles);
        checkBoxAngleInRadians->setObjectName(QStringLiteral("checkBoxAngleInRadians"));

        verticalLayout_7->addWidget(checkBoxAngleInRadians);

        label_8 = new QLabel(groupBoxAngles);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_7->addWidget(label_8);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_9 = new QLabel(groupBoxAngles);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        doubleSpinBoxHRes = new QDoubleSpinBox(groupBoxAngles);
        doubleSpinBoxHRes->setObjectName(QStringLiteral("doubleSpinBoxHRes"));
        doubleSpinBoxHRes->setDecimals(6);
        doubleSpinBoxHRes->setMaximum(360);

        gridLayout_2->addWidget(doubleSpinBoxHRes, 0, 1, 1, 1);

        doubleSpinBoxVRes = new QDoubleSpinBox(groupBoxAngles);
        doubleSpinBoxVRes->setObjectName(QStringLiteral("doubleSpinBoxVRes"));
        doubleSpinBoxVRes->setDecimals(6);
        doubleSpinBoxVRes->setMaximum(360);

        gridLayout_2->addWidget(doubleSpinBoxVRes, 1, 1, 1, 1);

        label_10 = new QLabel(groupBoxAngles);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);

        label_11 = new QLabel(groupBoxAngles);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_7->addWidget(label_11);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_17 = new QLabel(groupBoxAngles);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_5->addWidget(label_17, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        doubleSpinBoxStartTheta = new QDoubleSpinBox(groupBoxAngles);
        doubleSpinBoxStartTheta->setObjectName(QStringLiteral("doubleSpinBoxStartTheta"));
        doubleSpinBoxStartTheta->setDecimals(6);
        doubleSpinBoxStartTheta->setMinimum(-360);
        doubleSpinBoxStartTheta->setMaximum(360);

        gridLayout_3->addWidget(doubleSpinBoxStartTheta, 0, 0, 1, 1);

        label_18 = new QLabel(groupBoxAngles);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 0, 1, 1, 1);

        doubleSpinBoxEndTheta = new QDoubleSpinBox(groupBoxAngles);
        doubleSpinBoxEndTheta->setObjectName(QStringLiteral("doubleSpinBoxEndTheta"));
        doubleSpinBoxEndTheta->setDecimals(6);
        doubleSpinBoxEndTheta->setMinimum(-360);
        doubleSpinBoxEndTheta->setMaximum(360);

        gridLayout_3->addWidget(doubleSpinBoxEndTheta, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 0, 1, 1);

        label_12 = new QLabel(groupBoxAngles);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        doubleSpinBoxStartPhi = new QDoubleSpinBox(groupBoxAngles);
        doubleSpinBoxStartPhi->setObjectName(QStringLiteral("doubleSpinBoxStartPhi"));
        doubleSpinBoxStartPhi->setDecimals(6);
        doubleSpinBoxStartPhi->setMinimum(-360);
        doubleSpinBoxStartPhi->setMaximum(360);

        gridLayout_4->addWidget(doubleSpinBoxStartPhi, 0, 0, 1, 1);

        label_16 = new QLabel(groupBoxAngles);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(10, 16777215));

        gridLayout_4->addWidget(label_16, 0, 1, 1, 1);

        doubleSpinBoxEndPhi = new QDoubleSpinBox(groupBoxAngles);
        doubleSpinBoxEndPhi->setObjectName(QStringLiteral("doubleSpinBoxEndPhi"));
        doubleSpinBoxEndPhi->setDecimals(6);
        doubleSpinBoxEndPhi->setMinimum(-360);
        doubleSpinBoxEndPhi->setMaximum(360);

        gridLayout_4->addWidget(doubleSpinBoxEndPhi, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 3, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout_5);


        verticalLayout_9->addWidget(groupBoxAngles);

        groupBoxDirection = new QGroupBox(groupBox_3);
        groupBoxDirection->setObjectName(QStringLiteral("groupBoxDirection"));
        verticalLayout_4 = new QVBoxLayout(groupBoxDirection);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, -1, -1, 0);
        doubleSpinBoxZDir = new QDoubleSpinBox(groupBoxDirection);
        doubleSpinBoxZDir->setObjectName(QStringLiteral("doubleSpinBoxZDir"));
        doubleSpinBoxZDir->setDecimals(6);
        doubleSpinBoxZDir->setMinimum(-1e+9);
        doubleSpinBoxZDir->setMaximum(1e+9);

        gridLayout_6->addWidget(doubleSpinBoxZDir, 2, 1, 1, 1);

        label_13 = new QLabel(groupBoxDirection);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_6->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(groupBoxDirection);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_6->addWidget(label_14, 1, 0, 1, 1);

        doubleSpinBoxYDir = new QDoubleSpinBox(groupBoxDirection);
        doubleSpinBoxYDir->setObjectName(QStringLiteral("doubleSpinBoxYDir"));
        doubleSpinBoxYDir->setDecimals(6);
        doubleSpinBoxYDir->setMinimum(-1e+9);
        doubleSpinBoxYDir->setMaximum(1e+9);

        gridLayout_6->addWidget(doubleSpinBoxYDir, 1, 1, 1, 1);

        label_15 = new QLabel(groupBoxDirection);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(20, 16777215));

        gridLayout_6->addWidget(label_15, 0, 0, 1, 1);

        doubleSpinBoxXDir = new QDoubleSpinBox(groupBoxDirection);
        doubleSpinBoxXDir->setObjectName(QStringLiteral("doubleSpinBoxXDir"));
        doubleSpinBoxXDir->setDecimals(6);
        doubleSpinBoxXDir->setMinimum(-1e+9);
        doubleSpinBoxXDir->setMaximum(1e+9);

        gridLayout_6->addWidget(doubleSpinBoxXDir, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_6);


        verticalLayout_9->addWidget(groupBoxDirection);

        pushButtonApplyConfigurationToNextFile = new QPushButton(groupBox_3);
        pushButtonApplyConfigurationToNextFile->setObjectName(QStringLiteral("pushButtonApplyConfigurationToNextFile"));

        verticalLayout_9->addWidget(pushButtonApplyConfigurationToNextFile);

        pushButtonApplyConfigurationToAll = new QPushButton(groupBox_3);
        pushButtonApplyConfigurationToAll->setObjectName(QStringLiteral("pushButtonApplyConfigurationToAll"));

        verticalLayout_9->addWidget(pushButtonApplyConfigurationToAll);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(LoadFileConfiguration);

        QMetaObject::connectSlotsByName(LoadFileConfiguration);
    } // setupUi

    void retranslateUi(QWidget *LoadFileConfiguration)
    {
        LoadFileConfiguration->setWindowTitle(QApplication::translate("LoadFileConfiguration", "Chargement de fichiers pour LVOX", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("LoadFileConfiguration", " Type de fichier ", Q_NULLPTR));
        label->setText(QApplication::translate("LoadFileConfiguration", "Choix du lecteur :", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("LoadFileConfiguration", "Options", Q_NULLPTR));
        checkBoxFilterPointsOrigin->setText(QApplication::translate("LoadFileConfiguration", "Supprimer les points dont les coordonn\303\251es sont (0,0,0)", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("LoadFileConfiguration", " Chemin des fichiers ", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoadFileConfiguration", "Ajouter les chemins de fichiers \303\240 charger :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        listWidgetFiles->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>- <span style=\" font-weight:600;\">Ajouter</span> un chemin de fichier en cliquant sur le bouton &quot;Ajouter&quot;.</p><p>- <span style=\" font-weight:600;\">Modifier</span> un chemin de fichier en s\303\251lectionnant la ligne et en appuyant sur le bouton &quot;Modifier&quot;</p><p>- <span style=\" font-weight:600;\">Supprimer</span> un chemin de fichier en s\303\251lectionnant la ligne et en appuyant sur le bouton &quot;Supprimer&quot;</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonAddFile->setText(QApplication::translate("LoadFileConfiguration", "Ajouter .xyb", Q_NULLPTR));
        pushButtonModifyFile->setText(QApplication::translate("LoadFileConfiguration", "Modifier .xyb", Q_NULLPTR));
        pushButtonImportFile->setText(QApplication::translate("LoadFileConfiguration", "Importer .in", Q_NULLPTR));
        pushButtonExportFiles->setText(QApplication::translate("LoadFileConfiguration", "Exporter en .in", Q_NULLPTR));
        pushButtonDeleteFile->setText(QApplication::translate("LoadFileConfiguration", "Supprimer", Q_NULLPTR));
        pushButtonDeleteAllFile->setText(QApplication::translate("LoadFileConfiguration", "Tout supprimer", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("LoadFileConfiguration", "Configuration du scanner", Q_NULLPTR));
        labelFilepath->setText(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p><span style=\" font-style:italic;\">Aucun fichier s\303\251lectionn\303\251</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoadFileConfiguration", "Type de scanner :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        comboBoxScannerType->setToolTip(QApplication::translate("LoadFileConfiguration", "Type de scanner", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBoxPosition->setTitle(QApplication::translate("LoadFileConfiguration", "Position (m)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxZPos->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la coordonn\303\251e Z du centre du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("LoadFileConfiguration", "Z", Q_NULLPTR));
        label_5->setText(QApplication::translate("LoadFileConfiguration", "Y", Q_NULLPTR));
        label_4->setText(QApplication::translate("LoadFileConfiguration", "X", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxXPos->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la coordonn\303\251e X du centre du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxYPos->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la coordonn\303\251e Y du centre du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBoxAngles->setTitle(QApplication::translate("LoadFileConfiguration", "Angles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBoxScannerClockwise->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Cochez la case si votre appareil scanne la sc\303\250ne dans le sens des aiguilles d'une montre (\303\240 cocher lors de l'utilisation d'un scanner FARO ou Z+F).</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxScannerClockwise->setText(QApplication::translate("LoadFileConfiguration", "Angles dans le sens horaire", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBoxAngleInRadians->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Cochez la case si vous souhaitez \303\251crire les r\303\251solutions et angles en radians</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxAngleInRadians->setText(QApplication::translate("LoadFileConfiguration", "Valeurs en radians", Q_NULLPTR));
        label_8->setText(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>R\303\251solution angulaire</p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("LoadFileConfiguration", "Horizontale", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxHRes->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la r\303\251solution angulaire horizontale du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxVRes->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la r\303\251solution angulaire verticale du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("LoadFileConfiguration", "Verticale", Q_NULLPTR));
        label_11->setText(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Angles d'ouverture</p></body></html>", Q_NULLPTR));
        label_17->setText(QApplication::translate("LoadFileConfiguration", "Horizontaux", Q_NULLPTR));
        label_18->setText(QApplication::translate("LoadFileConfiguration", "\303\240", Q_NULLPTR));
        label_12->setText(QApplication::translate("LoadFileConfiguration", "Verticaux", Q_NULLPTR));
        label_16->setText(QApplication::translate("LoadFileConfiguration", "\303\240", Q_NULLPTR));
        groupBoxDirection->setTitle(QApplication::translate("LoadFileConfiguration", "Direction", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxZDir->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la coordonn\303\251e Z du centre du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("LoadFileConfiguration", "Z", Q_NULLPTR));
        label_14->setText(QApplication::translate("LoadFileConfiguration", "Y", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxYDir->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la coordonn\303\251e Y du centre du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("LoadFileConfiguration", "X", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxXDir->setToolTip(QApplication::translate("LoadFileConfiguration", "<html><head/><body><p>Indiquez la coordonn\303\251e X du centre du scanner</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonApplyConfigurationToNextFile->setText(QApplication::translate("LoadFileConfiguration", "Appliquer au fichier suivant", Q_NULLPTR));
        pushButtonApplyConfigurationToAll->setText(QApplication::translate("LoadFileConfiguration", "Appliquer \303\240 tous les fichiers", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadFileConfiguration: public Ui_LoadFileConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADFILECONFIGURATION_H
