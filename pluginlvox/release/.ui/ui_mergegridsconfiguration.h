/********************************************************************************
** Form generated from reading UI file 'mergegridsconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGEGRIDSCONFIGURATION_H
#define UI_MERGEGRIDSCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MergeGridsConfiguration
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxMergeMethod;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxIgnoreZero;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBoxEffectiveRaysThreshold;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MergeGridsConfiguration)
    {
        if (MergeGridsConfiguration->objectName().isEmpty())
            MergeGridsConfiguration->setObjectName(QStringLiteral("MergeGridsConfiguration"));
        MergeGridsConfiguration->resize(525, 297);
        verticalLayout_3 = new QVBoxLayout(MergeGridsConfiguration);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(MergeGridsConfiguration);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBoxMergeMethod = new QComboBox(groupBox_2);
        comboBoxMergeMethod->setObjectName(QStringLiteral("comboBoxMergeMethod"));

        horizontalLayout_2->addWidget(comboBoxMergeMethod);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(MergeGridsConfiguration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBoxIgnoreZero = new QCheckBox(groupBox);
        checkBoxIgnoreZero->setObjectName(QStringLiteral("checkBoxIgnoreZero"));

        verticalLayout->addWidget(checkBoxIgnoreZero);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxEffectiveRaysThreshold = new QSpinBox(groupBox);
        spinBoxEffectiveRaysThreshold->setObjectName(QStringLiteral("spinBoxEffectiveRaysThreshold"));

        horizontalLayout->addWidget(spinBoxEffectiveRaysThreshold);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(MergeGridsConfiguration);

        QMetaObject::connectSlotsByName(MergeGridsConfiguration);
    } // setupUi

    void retranslateUi(QWidget *MergeGridsConfiguration)
    {
        MergeGridsConfiguration->setWindowTitle(QApplication::translate("MergeGridsConfiguration", "Form", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MergeGridsConfiguration", "Merge method", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MergeGridsConfiguration", "Options", Q_NULLPTR));
        checkBoxIgnoreZero->setText(QApplication::translate("MergeGridsConfiguration", "Ignore zero density voxel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MergeGridsConfiguration", "Minimum effective rays (nt - nb):", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MergeGridsConfiguration: public Ui_MergeGridsConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGEGRIDSCONFIGURATION_H
