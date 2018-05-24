/********************************************************************************
** Form generated from reading UI file 'predefinedmapperconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDEFINEDMAPPERCONFIGURATION_H
#define UI_PREDEFINEDMAPPERCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PredefinedMapperConfiguration
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxMapperVar;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetVar;
    QGroupBox *groupBoxMapperNameAndType;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetNameAndType;
    QLabel *label;

    void setupUi(QWidget *PredefinedMapperConfiguration)
    {
        if (PredefinedMapperConfiguration->objectName().isEmpty())
            PredefinedMapperConfiguration->setObjectName(QStringLiteral("PredefinedMapperConfiguration"));
        PredefinedMapperConfiguration->resize(950, 292);
        PredefinedMapperConfiguration->setMinimumSize(QSize(950, 0));
        PredefinedMapperConfiguration->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(PredefinedMapperConfiguration);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 0, 0, 6);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        groupBoxMapperVar = new QGroupBox(PredefinedMapperConfiguration);
        groupBoxMapperVar->setObjectName(QStringLiteral("groupBoxMapperVar"));
        verticalLayout_2 = new QVBoxLayout(groupBoxMapperVar);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidgetVar = new QTableWidget(groupBoxMapperVar);
        if (tableWidgetVar->columnCount() < 2)
            tableWidgetVar->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetVar->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetVar->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetVar->setObjectName(QStringLiteral("tableWidgetVar"));
        tableWidgetVar->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetVar->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableWidgetVar);


        horizontalLayout_2->addWidget(groupBoxMapperVar);

        groupBoxMapperNameAndType = new QGroupBox(PredefinedMapperConfiguration);
        groupBoxMapperNameAndType->setObjectName(QStringLiteral("groupBoxMapperNameAndType"));
        verticalLayout = new QVBoxLayout(groupBoxMapperNameAndType);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetNameAndType = new QTableWidget(groupBoxMapperNameAndType);
        if (tableWidgetNameAndType->columnCount() < 2)
            tableWidgetNameAndType->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetNameAndType->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetNameAndType->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidgetNameAndType->setObjectName(QStringLiteral("tableWidgetNameAndType"));
        tableWidgetNameAndType->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetNameAndType->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidgetNameAndType);


        horizontalLayout_2->addWidget(groupBoxMapperNameAndType);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label = new QLabel(PredefinedMapperConfiguration);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);


        retranslateUi(PredefinedMapperConfiguration);

        QMetaObject::connectSlotsByName(PredefinedMapperConfiguration);
    } // setupUi

    void retranslateUi(QWidget *PredefinedMapperConfiguration)
    {
        PredefinedMapperConfiguration->setWindowTitle(QApplication::translate("PredefinedMapperConfiguration", "Mettre en correspondance les entr\303\251es", Q_NULLPTR));
        groupBoxMapperVar->setTitle(QApplication::translate("PredefinedMapperConfiguration", " Par nom de variable ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetVar->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PredefinedMapperConfiguration", "Grille(s) disponible(s)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetVar->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PredefinedMapperConfiguration", "Issu de la fonction pr\303\251d\303\251finie", Q_NULLPTR));
        groupBoxMapperNameAndType->setTitle(QApplication::translate("PredefinedMapperConfiguration", " Par nom et type ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetNameAndType->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("PredefinedMapperConfiguration", "Grille(s) disponible(s)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetNameAndType->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("PredefinedMapperConfiguration", "Issu de la fonction pr\303\251d\303\251finie", Q_NULLPTR));
        label->setText(QApplication::translate("PredefinedMapperConfiguration", "<html><head/><body><p><span style=\" font-style:italic;\">Veuillez mettre en correspondances les grilles de la fonction pr\303\251d\303\251finie avec les grilles d'entr\303\251es disponibles.</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PredefinedMapperConfiguration: public Ui_PredefinedMapperConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDEFINEDMAPPERCONFIGURATION_H
