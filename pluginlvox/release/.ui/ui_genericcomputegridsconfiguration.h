/********************************************************************************
** Form generated from reading UI file 'genericcomputegridsconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERICCOMPUTEGRIDSCONFIGURATION_H
#define UI_GENERICCOMPUTEGRIDSCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenericComputeGridsConfiguration
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBoxPredefinedCompute;
    QPushButton *pushButtonApplyPredefinedCompute;
    QPushButton *pushButtonAddPredefinedCompute;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *comboBoxOutGridToConfigure;
    QLabel *labelConfigureOutGrid;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEditComputeFormula;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidgetChecks;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAddCheck;
    QPushButton *pushButtonDeleteCheck;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidgetInGrid;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tableWidgetOutGrid;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonAddOutGrid;
    QPushButton *pushButtonDeleteOutGrid;

    void setupUi(QWidget *GenericComputeGridsConfiguration)
    {
        if (GenericComputeGridsConfiguration->objectName().isEmpty())
            GenericComputeGridsConfiguration->setObjectName(QStringLiteral("GenericComputeGridsConfiguration"));
        GenericComputeGridsConfiguration->resize(996, 557);
        GenericComputeGridsConfiguration->setMinimumSize(QSize(996, 557));
        verticalLayout_6 = new QVBoxLayout(GenericComputeGridsConfiguration);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        label_4 = new QLabel(GenericComputeGridsConfiguration);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_4);

        comboBoxPredefinedCompute = new QComboBox(GenericComputeGridsConfiguration);
        comboBoxPredefinedCompute->setObjectName(QStringLiteral("comboBoxPredefinedCompute"));

        horizontalLayout_4->addWidget(comboBoxPredefinedCompute);

        pushButtonApplyPredefinedCompute = new QPushButton(GenericComputeGridsConfiguration);
        pushButtonApplyPredefinedCompute->setObjectName(QStringLiteral("pushButtonApplyPredefinedCompute"));

        horizontalLayout_4->addWidget(pushButtonApplyPredefinedCompute);

        pushButtonAddPredefinedCompute = new QPushButton(GenericComputeGridsConfiguration);
        pushButtonAddPredefinedCompute->setObjectName(QStringLiteral("pushButtonAddPredefinedCompute"));

        horizontalLayout_4->addWidget(pushButtonAddPredefinedCompute);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(GenericComputeGridsConfiguration);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        comboBoxOutGridToConfigure = new QComboBox(GenericComputeGridsConfiguration);
        comboBoxOutGridToConfigure->setObjectName(QStringLiteral("comboBoxOutGridToConfigure"));

        verticalLayout_3->addWidget(comboBoxOutGridToConfigure);

        labelConfigureOutGrid = new QLabel(GenericComputeGridsConfiguration);
        labelConfigureOutGrid->setObjectName(QStringLiteral("labelConfigureOutGrid"));

        verticalLayout_3->addWidget(labelConfigureOutGrid);

        groupBox_2 = new QGroupBox(GenericComputeGridsConfiguration);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_7 = new QVBoxLayout(groupBox_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_7->addWidget(label_5);

        lineEditComputeFormula = new QLineEdit(groupBox_2);
        lineEditComputeFormula->setObjectName(QStringLiteral("lineEditComputeFormula"));

        verticalLayout_7->addWidget(lineEditComputeFormula);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(GenericComputeGridsConfiguration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tableWidgetChecks = new QTableWidget(groupBox);
        tableWidgetChecks->setObjectName(QStringLiteral("tableWidgetChecks"));

        verticalLayout_4->addWidget(tableWidgetChecks);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        pushButtonAddCheck = new QPushButton(groupBox);
        pushButtonAddCheck->setObjectName(QStringLiteral("pushButtonAddCheck"));

        horizontalLayout_3->addWidget(pushButtonAddCheck);

        pushButtonDeleteCheck = new QPushButton(groupBox);
        pushButtonDeleteCheck->setObjectName(QStringLiteral("pushButtonDeleteCheck"));

        horizontalLayout_3->addWidget(pushButtonDeleteCheck);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(GenericComputeGridsConfiguration);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        tableWidgetInGrid = new QTableWidget(GenericComputeGridsConfiguration);
        tableWidgetInGrid->setObjectName(QStringLiteral("tableWidgetInGrid"));

        verticalLayout->addWidget(tableWidgetInGrid);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(GenericComputeGridsConfiguration);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        tableWidgetOutGrid = new QTableWidget(GenericComputeGridsConfiguration);
        tableWidgetOutGrid->setObjectName(QStringLiteral("tableWidgetOutGrid"));

        verticalLayout_2->addWidget(tableWidgetOutGrid);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        pushButtonAddOutGrid = new QPushButton(GenericComputeGridsConfiguration);
        pushButtonAddOutGrid->setObjectName(QStringLiteral("pushButtonAddOutGrid"));

        horizontalLayout_2->addWidget(pushButtonAddOutGrid);

        pushButtonDeleteOutGrid = new QPushButton(GenericComputeGridsConfiguration);
        pushButtonDeleteOutGrid->setObjectName(QStringLiteral("pushButtonDeleteOutGrid"));

        horizontalLayout_2->addWidget(pushButtonDeleteOutGrid);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout);

        QWidget::setTabOrder(comboBoxPredefinedCompute, pushButtonApplyPredefinedCompute);
        QWidget::setTabOrder(pushButtonApplyPredefinedCompute, pushButtonAddPredefinedCompute);
        QWidget::setTabOrder(pushButtonAddPredefinedCompute, comboBoxOutGridToConfigure);
        QWidget::setTabOrder(comboBoxOutGridToConfigure, tableWidgetChecks);
        QWidget::setTabOrder(tableWidgetChecks, pushButtonAddCheck);
        QWidget::setTabOrder(pushButtonAddCheck, pushButtonDeleteCheck);
        QWidget::setTabOrder(pushButtonDeleteCheck, lineEditComputeFormula);
        QWidget::setTabOrder(lineEditComputeFormula, tableWidgetInGrid);
        QWidget::setTabOrder(tableWidgetInGrid, tableWidgetOutGrid);
        QWidget::setTabOrder(tableWidgetOutGrid, pushButtonAddOutGrid);
        QWidget::setTabOrder(pushButtonAddOutGrid, pushButtonDeleteOutGrid);

        retranslateUi(GenericComputeGridsConfiguration);

        QMetaObject::connectSlotsByName(GenericComputeGridsConfiguration);
    } // setupUi

    void retranslateUi(QWidget *GenericComputeGridsConfiguration)
    {
        GenericComputeGridsConfiguration->setWindowTitle(QApplication::translate("GenericComputeGridsConfiguration", "Configuration de(s) grille(s) de sortie", Q_NULLPTR));
        label_4->setText(QApplication::translate("GenericComputeGridsConfiguration", "Fonction pr\303\251d\303\251finie :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonApplyPredefinedCompute->setToolTip(QApplication::translate("GenericComputeGridsConfiguration", "Si vous appliquez la fonction pr\303\251d\303\251finie : toutes les grilles de sorties que vous avez mise en place jusqu'\303\240 pr\303\251sent seront supprim\303\251es et remplac\303\251es par celles de la fonction pr\303\251d\303\251finie.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonApplyPredefinedCompute->setText(QApplication::translate("GenericComputeGridsConfiguration", "Valider", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonAddPredefinedCompute->setToolTip(QApplication::translate("GenericComputeGridsConfiguration", "Si vous ajoutez une fonction pr\303\251d\303\251finie : toutes les grilles de sorties mise en place jusqu'\303\240 pr\303\251sent seront conserv\303\251es.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonAddPredefinedCompute->setText(QApplication::translate("GenericComputeGridsConfiguration", "Ajouter", Q_NULLPTR));
        label_3->setText(QApplication::translate("GenericComputeGridsConfiguration", "Variable de la grille de sortie", Q_NULLPTR));
        labelConfigureOutGrid->setText(QApplication::translate("GenericComputeGridsConfiguration", "<html><head/><body><p><span style=\" font-weight:600;\">Configuration de la grille de sortie</span></p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GenericComputeGridsConfiguration", " R\303\251sultat ", Q_NULLPTR));
        label_5->setText(QApplication::translate("GenericComputeGridsConfiguration", "Valeur de chaque case de la grille si aucune condition ci-dessous n'est satisfaite :", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEditComputeFormula->setToolTip(QApplication::translate("GenericComputeGridsConfiguration", "<html><head/><body><p><span style=\" font-weight:600;\">D\303\251finissez ici la formule finale</span></p><p>La formule finale est execut\303\251e seulement si aucune condition ci-dessus n'est satisfaite.</p><p><span style=\" text-decoration: underline;\">Pseudo code (exemple) :</span></p><p><span style=\" font-style:italic;\">Si condition[1] Alors<br/>&nbsp;&nbsp;&nbsp;case(i) = codeErreur[1]<br/>Sinon Si condition[2] Alors<br/>&nbsp;&nbsp;&nbsp;case(i) = codeErreur[2]<br/>Sinon<br/>&nbsp;&nbsp;&nbsp;case(i) = formuleFinal</span></p><p><span>Si vous voulez vous r\303\251f\303\251rer \303\240 la grille de sortie \303\251crivez dans la formule le mot cl\303\251 \"<b>this</b>\".</span><p>Exemple : <i>this + a*2</i></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("GenericComputeGridsConfiguration", " V\303\251rification et code d'erreur ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableWidgetChecks->setToolTip(QApplication::translate("GenericComputeGridsConfiguration", "<html><head/><body><p><span style=\" font-weight:600;\">D\303\251finissez ici des formules conditionnelles. </span></p><p>Elles seront execut\303\251es dans l'ordre dans lequel vous les avez d\303\251finies et si l'une d'entre elles est v\303\251rifi\303\251 ni les autres ni la formule finale ne seront ex\303\251cut\303\251s.</p><p><span style=\" text-decoration: underline;\">Pseudo code (exemple) :</span></p><p><span style=\" font-style:italic;\">Si condition[1] Alors<br/>&nbsp;&nbsp;&nbsp;case(i) = codeErreur[1]<br/>Sinon Si condition[2] Alors<br/>&nbsp;&nbsp;&nbsp;case(i) = codeErreur[2]<br/>Sinon<br/>&nbsp;&nbsp;&nbsp;case(i) = formuleFinal</span></p><p><span>Si vous voulez vous r\303\251f\303\251rer \303\240 la grille de sortie \303\251crivez dans la formule le mot cl\303\251 \"<b>this</b>\".</span><p>Exemple : <i>this &lt; -1</i></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonAddCheck->setText(QApplication::translate("GenericComputeGridsConfiguration", "Ajouter", Q_NULLPTR));
        pushButtonDeleteCheck->setText(QApplication::translate("GenericComputeGridsConfiguration", "Supprimer", Q_NULLPTR));
        label->setText(QApplication::translate("GenericComputeGridsConfiguration", "<html><head/><body><p><span style=\" font-weight:600;\">Grilles d'entr\303\251es</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("GenericComputeGridsConfiguration", "<html><head/><body><p><span style=\" font-weight:600;\">Grilles de sorties</span></p></body></html>", Q_NULLPTR));
        pushButtonAddOutGrid->setText(QApplication::translate("GenericComputeGridsConfiguration", "Ajouter", Q_NULLPTR));
        pushButtonDeleteOutGrid->setText(QApplication::translate("GenericComputeGridsConfiguration", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GenericComputeGridsConfiguration: public Ui_GenericComputeGridsConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERICCOMPUTEGRIDSCONFIGURATION_H
