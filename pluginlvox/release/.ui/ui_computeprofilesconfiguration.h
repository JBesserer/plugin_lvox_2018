/********************************************************************************
** Form generated from reading UI file 'computeprofilesconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTEPROFILESCONFIGURATION_H
#define UI_COMPUTEPROFILESCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComputeProfilesConfiguration
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QComboBox *comboBoxGen;
    QLabel *label_6;
    QCheckBox *checkBoxZValuesInPourcent;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_22;
    QLabel *label_3;
    QCheckBox *checkBoxPersonalized;
    QDoubleSpinBox *doubleSpinBoxMinValue;
    QComboBox *comboBoxOrdonnee;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxMaxValue;
    QLabel *label_10;
    QLabel *label_9;
    QPushButton *pushButtonDefaultConfiguration;
    QLabel *label_12;
    QRadioButton *radioButtonAllGrid;
    QLabel *label_11;
    QRadioButton *radioButtonPersonalized;
    QCheckBox *checkBoxXYValuesInPourcent;
    QLabel *label_4;
    QComboBox *comboBoxUnitType;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBoxMinZ;
    QDoubleSpinBox *doubleSpinBoxMaxZ;
    QDoubleSpinBox *doubleSpinBoxMinY;
    QDoubleSpinBox *doubleSpinBoxMaxY;
    QDoubleSpinBox *doubleSpinBoxMinX;
    QDoubleSpinBox *doubleSpinBoxMaxX;
    QDoubleSpinBox *doubleSpinBoxGenStep;
    QWidget *widget;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *ComputeProfilesConfiguration)
    {
        if (ComputeProfilesConfiguration->objectName().isEmpty())
            ComputeProfilesConfiguration->setObjectName(QStringLiteral("ComputeProfilesConfiguration"));
        ComputeProfilesConfiguration->resize(570, 650);
        ComputeProfilesConfiguration->setMinimumSize(QSize(570, 650));
        ComputeProfilesConfiguration->setMaximumSize(QSize(570, 650));
        verticalLayout = new QVBoxLayout(ComputeProfilesConfiguration);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(ComputeProfilesConfiguration);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        comboBoxGen = new QComboBox(ComputeProfilesConfiguration);
        comboBoxGen->setObjectName(QStringLiteral("comboBoxGen"));
        comboBoxGen->setEnabled(false);

        gridLayout->addWidget(comboBoxGen, 3, 1, 1, 3);

        label_6 = new QLabel(ComputeProfilesConfiguration);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 8, 2, 1, 1);

        checkBoxZValuesInPourcent = new QCheckBox(ComputeProfilesConfiguration);
        checkBoxZValuesInPourcent->setObjectName(QStringLiteral("checkBoxZValuesInPourcent"));
        checkBoxZValuesInPourcent->setEnabled(false);

        gridLayout->addWidget(checkBoxZValuesInPourcent, 7, 0, 1, 4);

        label_8 = new QLabel(ComputeProfilesConfiguration);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 3);

        label_2 = new QLabel(ComputeProfilesConfiguration);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_22 = new QLabel(ComputeProfilesConfiguration);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_22, 13, 2, 1, 1);

        label_3 = new QLabel(ComputeProfilesConfiguration);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        checkBoxPersonalized = new QCheckBox(ComputeProfilesConfiguration);
        checkBoxPersonalized->setObjectName(QStringLiteral("checkBoxPersonalized"));
        checkBoxPersonalized->setEnabled(false);

        gridLayout->addWidget(checkBoxPersonalized, 10, 0, 1, 4);

        doubleSpinBoxMinValue = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMinValue->setObjectName(QStringLiteral("doubleSpinBoxMinValue"));
        doubleSpinBoxMinValue->setMinimum(-999999);
        doubleSpinBoxMinValue->setMaximum(999999);

        gridLayout->addWidget(doubleSpinBoxMinValue, 1, 1, 1, 1);

        comboBoxOrdonnee = new QComboBox(ComputeProfilesConfiguration);
        comboBoxOrdonnee->setObjectName(QStringLiteral("comboBoxOrdonnee"));

        gridLayout->addWidget(comboBoxOrdonnee, 2, 1, 1, 3);

        label_5 = new QLabel(ComputeProfilesConfiguration);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        doubleSpinBoxMaxValue = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMaxValue->setObjectName(QStringLiteral("doubleSpinBoxMaxValue"));
        doubleSpinBoxMaxValue->setMinimum(-999999);
        doubleSpinBoxMaxValue->setMaximum(999999);
        doubleSpinBoxMaxValue->setValue(999999);

        gridLayout->addWidget(doubleSpinBoxMaxValue, 1, 3, 1, 1);

        label_10 = new QLabel(ComputeProfilesConfiguration);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        label_9 = new QLabel(ComputeProfilesConfiguration);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 12, 0, 1, 1);

        pushButtonDefaultConfiguration = new QPushButton(ComputeProfilesConfiguration);
        pushButtonDefaultConfiguration->setObjectName(QStringLiteral("pushButtonDefaultConfiguration"));

        gridLayout->addWidget(pushButtonDefaultConfiguration, 0, 3, 1, 1);

        label_12 = new QLabel(ComputeProfilesConfiguration);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 12, 2, 1, 1);

        radioButtonAllGrid = new QRadioButton(ComputeProfilesConfiguration);
        buttonGroup = new QButtonGroup(ComputeProfilesConfiguration);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButtonAllGrid);
        radioButtonAllGrid->setObjectName(QStringLiteral("radioButtonAllGrid"));
        radioButtonAllGrid->setChecked(true);

        gridLayout->addWidget(radioButtonAllGrid, 5, 0, 1, 4);

        label_11 = new QLabel(ComputeProfilesConfiguration);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 13, 0, 1, 1);

        radioButtonPersonalized = new QRadioButton(ComputeProfilesConfiguration);
        buttonGroup->addButton(radioButtonPersonalized);
        radioButtonPersonalized->setObjectName(QStringLiteral("radioButtonPersonalized"));

        gridLayout->addWidget(radioButtonPersonalized, 6, 0, 1, 4);

        checkBoxXYValuesInPourcent = new QCheckBox(ComputeProfilesConfiguration);
        checkBoxXYValuesInPourcent->setObjectName(QStringLiteral("checkBoxXYValuesInPourcent"));
        checkBoxXYValuesInPourcent->setEnabled(false);

        gridLayout->addWidget(checkBoxXYValuesInPourcent, 11, 0, 1, 1);

        label_4 = new QLabel(ComputeProfilesConfiguration);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        comboBoxUnitType = new QComboBox(ComputeProfilesConfiguration);
        comboBoxUnitType->setObjectName(QStringLiteral("comboBoxUnitType"));

        gridLayout->addWidget(comboBoxUnitType, 4, 1, 1, 3);

        label_21 = new QLabel(ComputeProfilesConfiguration);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 4, 0, 1, 1);

        doubleSpinBoxMinZ = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMinZ->setObjectName(QStringLiteral("doubleSpinBoxMinZ"));
        doubleSpinBoxMinZ->setEnabled(false);
        doubleSpinBoxMinZ->setMinimum(-1.1e+7);
        doubleSpinBoxMinZ->setMaximum(1.1e+7);
        doubleSpinBoxMinZ->setValue(-100);

        gridLayout->addWidget(doubleSpinBoxMinZ, 8, 1, 1, 1);

        doubleSpinBoxMaxZ = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMaxZ->setObjectName(QStringLiteral("doubleSpinBoxMaxZ"));
        doubleSpinBoxMaxZ->setEnabled(false);
        doubleSpinBoxMaxZ->setMinimum(-1.1e+7);
        doubleSpinBoxMaxZ->setMaximum(1.1e+7);
        doubleSpinBoxMaxZ->setValue(100);

        gridLayout->addWidget(doubleSpinBoxMaxZ, 8, 3, 1, 1);

        doubleSpinBoxMinY = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMinY->setObjectName(QStringLiteral("doubleSpinBoxMinY"));
        doubleSpinBoxMinY->setEnabled(false);
        doubleSpinBoxMinY->setMinimum(-1.1e+7);
        doubleSpinBoxMinY->setMaximum(1.1e+7);
        doubleSpinBoxMinY->setValue(-100);

        gridLayout->addWidget(doubleSpinBoxMinY, 12, 1, 1, 1);

        doubleSpinBoxMaxY = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMaxY->setObjectName(QStringLiteral("doubleSpinBoxMaxY"));
        doubleSpinBoxMaxY->setEnabled(false);
        doubleSpinBoxMaxY->setMinimum(-1.1e+7);
        doubleSpinBoxMaxY->setMaximum(1.1e+7);
        doubleSpinBoxMaxY->setValue(100);

        gridLayout->addWidget(doubleSpinBoxMaxY, 12, 3, 1, 1);

        doubleSpinBoxMinX = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMinX->setObjectName(QStringLiteral("doubleSpinBoxMinX"));
        doubleSpinBoxMinX->setEnabled(false);
        doubleSpinBoxMinX->setMinimum(-1.1e+7);
        doubleSpinBoxMinX->setMaximum(1.1e+7);
        doubleSpinBoxMinX->setValue(-100);

        gridLayout->addWidget(doubleSpinBoxMinX, 13, 1, 1, 1);

        doubleSpinBoxMaxX = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxMaxX->setObjectName(QStringLiteral("doubleSpinBoxMaxX"));
        doubleSpinBoxMaxX->setEnabled(false);
        doubleSpinBoxMaxX->setMinimum(-1.1e+7);
        doubleSpinBoxMaxX->setMaximum(1.1e+7);
        doubleSpinBoxMaxX->setValue(100);

        gridLayout->addWidget(doubleSpinBoxMaxX, 13, 3, 1, 1);

        doubleSpinBoxGenStep = new QDoubleSpinBox(ComputeProfilesConfiguration);
        doubleSpinBoxGenStep->setObjectName(QStringLiteral("doubleSpinBoxGenStep"));
        doubleSpinBoxGenStep->setEnabled(false);
        doubleSpinBoxGenStep->setMinimum(1);
        doubleSpinBoxGenStep->setMaximum(999999);
        doubleSpinBoxGenStep->setValue(999999);

        gridLayout->addWidget(doubleSpinBoxGenStep, 9, 1, 1, 3);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(ComputeProfilesConfiguration);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 400, 301));
        label->setMaximumSize(QSize(400, 500));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/computeprofiles.png")));
        label->setScaledContents(true);
        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(80, 20, 181, 16));
        label_13->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(360, 190, 211, 20));
        label_14->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_15 = new QLabel(widget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 200, 61, 20));
        label_15->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(150, 320, 51, 20));
        label_17 = new QLabel(widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(76, 300, 51, 20));
        label_18 = new QLabel(widget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(240, 300, 51, 20));
        label_19 = new QLabel(widget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(330, 270, 51, 20));
        label_20 = new QLabel(widget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(266, 10, 131, 20));

        verticalLayout->addWidget(widget);


        retranslateUi(ComputeProfilesConfiguration);

        comboBoxOrdonnee->setCurrentIndex(2);
        comboBoxUnitType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ComputeProfilesConfiguration);
    } // setupUi

    void retranslateUi(QWidget *ComputeProfilesConfiguration)
    {
        ComputeProfilesConfiguration->setWindowTitle(QApplication::translate("ComputeProfilesConfiguration", "Configuration de la g\303\251n\303\251ration de profils", Q_NULLPTR));
        label_7->setText(QApplication::translate("ComputeProfilesConfiguration", "Pas entre deux profils", Q_NULLPTR));
        comboBoxGen->clear();
        comboBoxGen->insertItems(0, QStringList()
         << QApplication::translate("ComputeProfilesConfiguration", "X", Q_NULLPTR)
         << QApplication::translate("ComputeProfilesConfiguration", "Y", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("ComputeProfilesConfiguration", "et <", Q_NULLPTR));
        checkBoxZValuesInPourcent->setText(QApplication::translate("ComputeProfilesConfiguration", "Valeurs en pourcentage", Q_NULLPTR));
        label_8->setText(QApplication::translate("ComputeProfilesConfiguration", "<html><head/><body><p><span style=\" font-style:italic;\">La configuration par d\303\251faut calcule le profil sur toute la grille suivant l'axe Z</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("ComputeProfilesConfiguration", "Axe principal", Q_NULLPTR));
        label_22->setText(QApplication::translate("ComputeProfilesConfiguration", "et <", Q_NULLPTR));
        label_3->setText(QApplication::translate("ComputeProfilesConfiguration", "N'utiliser que les cellules dont la valeur est >=", Q_NULLPTR));
        checkBoxPersonalized->setText(QApplication::translate("ComputeProfilesConfiguration", "Restreindre le calcul sur une portion de la grille", Q_NULLPTR));
        comboBoxOrdonnee->clear();
        comboBoxOrdonnee->insertItems(0, QStringList()
         << QApplication::translate("ComputeProfilesConfiguration", "X", Q_NULLPTR)
         << QApplication::translate("ComputeProfilesConfiguration", "Y", Q_NULLPTR)
         << QApplication::translate("ComputeProfilesConfiguration", "Z", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("ComputeProfilesConfiguration", "Axe de g\303\251n\303\251ration", Q_NULLPTR));
        label_10->setText(QApplication::translate("ComputeProfilesConfiguration", "Borne de l'axe de g\303\251n\303\251ration                    >=", Q_NULLPTR));
        label_9->setText(QApplication::translate("ComputeProfilesConfiguration", "Bornes de l'axe des ordonn\303\251es                 >=", Q_NULLPTR));
        pushButtonDefaultConfiguration->setText(QApplication::translate("ComputeProfilesConfiguration", "D\303\251faut (RAZ)", Q_NULLPTR));
        label_12->setText(QApplication::translate("ComputeProfilesConfiguration", "et <", Q_NULLPTR));
        radioButtonAllGrid->setText(QApplication::translate("ComputeProfilesConfiguration", "Sur toute la grille", Q_NULLPTR));
        label_11->setText(QApplication::translate("ComputeProfilesConfiguration", "Bornes de l'axe des abscisses                   >=", Q_NULLPTR));
        radioButtonPersonalized->setText(QApplication::translate("ComputeProfilesConfiguration", "Personnalis\303\251e", Q_NULLPTR));
        checkBoxXYValuesInPourcent->setText(QApplication::translate("ComputeProfilesConfiguration", "Valeurs en pourcentage", Q_NULLPTR));
        label_4->setText(QApplication::translate("ComputeProfilesConfiguration", "et <=", Q_NULLPTR));
        comboBoxUnitType->clear();
        comboBoxUnitType->insertItems(0, QStringList()
         << QApplication::translate("ComputeProfilesConfiguration", "Coordonn\303\251es", Q_NULLPTR)
         << QApplication::translate("ComputeProfilesConfiguration", "Voxel", Q_NULLPTR)
        );
        comboBoxUnitType->setCurrentText(QApplication::translate("ComputeProfilesConfiguration", "Coordonn\303\251es", Q_NULLPTR));
        label_21->setText(QApplication::translate("ComputeProfilesConfiguration", "Unit\303\251 de calcul", Q_NULLPTR));
        label->setText(QString());
        label_13->setText(QApplication::translate("ComputeProfilesConfiguration", "Axe principal du profil (ordonn\303\251e)", Q_NULLPTR));
        label_14->setText(QApplication::translate("ComputeProfilesConfiguration", "Axe de g\303\251n\303\251ration des profils (normal)", Q_NULLPTR));
        label_15->setText(QApplication::translate("ComputeProfilesConfiguration", "Axe abscisses", Q_NULLPTR));
        label_16->setText(QApplication::translate("ComputeProfilesConfiguration", "Inf\303\251rieure", Q_NULLPTR));
        label_17->setText(QApplication::translate("ComputeProfilesConfiguration", "Sup\303\251rieure", Q_NULLPTR));
        label_18->setText(QApplication::translate("ComputeProfilesConfiguration", "Inf\303\251rieure", Q_NULLPTR));
        label_19->setText(QApplication::translate("ComputeProfilesConfiguration", "Sup\303\251rieure", Q_NULLPTR));
        label_20->setText(QApplication::translate("ComputeProfilesConfiguration", "Pas entre deux profils", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ComputeProfilesConfiguration: public Ui_ComputeProfilesConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTEPROFILESCONFIGURATION_H
