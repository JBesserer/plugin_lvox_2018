#include "lvox3_stepaddgridtonext.h"

#include "ct_result/model/inModel/ct_inresultmodelgrouptocopy.h"
#include "ct_result/model/outModel/tools/ct_outresultmodelgrouptocopypossibilities.h"
#include "mk/tools/lvox3_gridtype.h"
#include "ct_result/ct_resultgroup.h"
#include "ct_view/ct_stepconfigurabledialog.h"

#define DEF_SearchInSourceResult      "rs"
#define DEF_SearchInSourceGroup       "gs"
#define DEF_SearchInSourceItem        "its"
#define DEF_SearchInTargetResult      "rt"
#define DEF_SearchInTargetGroup       "gt"
#define DEF_SearchInTargetItem        "itt"
#define DEF_SearchInGroup             "grp"
#define DEF_SearchInGrid              "grid"

LVOX3_StepAddGridToNext::LVOX3_StepAddGridToNext(CT_StepInitializeData &dataInit) : CT_AbstractStep(dataInit)
{
    m_gridType = tr("Ni");
    m_gridTypeCollection.insert(m_gridType, Ni);
    m_gridTypeCollection.insert(tr("Nt"), Nt);
    m_gridTypeCollection.insert(tr("Nb"), Nb);
}

QString LVOX3_StepAddGridToNext::getStepDescription() const
{
    return tr("Ajouter une grille 3D au résultat d'une étape précédente(Ni/Nt/Nb)");
}

// Step detailed description
QString LVOX3_StepAddGridToNext::getStepDetailledDescription() const
{
    return tr("Cette étape permet de rajouter une grille 3D au résultat d'un calcul de grilles. L'on peut ensuite s'en servir pour le calcul personnalisé des grilles. "
              "À noter que les paramètres devraient être les mêmes pour la grille importée et les grilles calculées présentement pour empêcher des résultats incohérents."
              "Il s'agit d'une étape en développement.");
}

CT_VirtualAbstractStep* LVOX3_StepAddGridToNext::createNewInstance(CT_StepInitializeData &dataInit)
{
    // Creates an instance of this step
    return new LVOX3_StepAddGridToNext(dataInit);
}

void LVOX3_StepAddGridToNext::createInResultModelListProtected()
{
    // We must have
    // - at least one grid
    CT_InResultModelGroupToCopy *inResultRefCopy = createNewInResultModelForCopy(DEF_SearchInSourceResult, tr("Étape d'entrée"), "", true);
    inResultRefCopy->setZeroOrMoreRootGroup();
    inResultRefCopy->addGroupModel("", DEF_SearchInSourceGroup, CT_AbstractItemGroup::staticGetType(), tr("Groupe de référence"), "", CT_InAbstractGroupModel::CG_ChooseOneIfMultiple);

    CT_InResultModelGroupToCopy *inResultAffCopy = createNewInResultModelForCopy(DEF_SearchInTargetResult, tr("Grille à affilier"), "", true);
    inResultAffCopy->setZeroOrMoreRootGroup();
    inResultAffCopy->addGroupModel("", DEF_SearchInTargetGroup);
    inResultAffCopy->addItemModel(DEF_SearchInTargetGroup, DEF_SearchInGrid, CT_AbstractGrid3D::staticGetType(), tr("Grille 3D"));
}

void LVOX3_StepAddGridToNext::createPostConfigurationDialog()
{

    CT_StepConfigurableDialog *configDialog = newStandardPostConfigurationDialog();

    configDialog->addStringChoice(tr("3D Grid Type"), "", m_gridTypeCollection.keys(), m_gridType);

}

void LVOX3_StepAddGridToNext::createOutResultModelListProtected()
{
    // create a new OUT result that is a copy of the IN result selected by the user
    CT_OutResultModelGroupToCopyPossibilities *resultModel = createNewOutResultModelToCopy(DEF_SearchInSourceResult);

    if (!resultModel)
        return;

    resultModel->addItemModel(DEF_SearchInSourceGroup, _grid_ModelName, new lvox::Grid3Di(), tr("Added 3D Grid"));
    //Gives the correct qualifier to make it visible in the merge grids step
    if(m_gridTypeCollection.value(m_gridType) == Ni){
        resultModel->addItemAttributeModel(_grid_ModelName, _NiFlag_ModelName, new CT_StdItemAttributeT<bool>("LVOX_GRD_NI"), tr("isNi"));
    }else if(m_gridTypeCollection.value(m_gridType) == Nt){
        resultModel->addItemAttributeModel(_grid_ModelName, _NtFlag_ModelName, new CT_StdItemAttributeT<bool>("LVOX_GRD_NT"), tr("isNt"));
    }else{
        resultModel->addItemAttributeModel(_grid_ModelName, _NbFlag_ModelName, new CT_StdItemAttributeT<bool>("LVOX_GRD_NB"), tr("isNb"));
    }


    CT_OutResultModelGroupToCopyPossibilities *inResultAffCopy = createNewOutResultModelToCopy(DEF_SearchInTargetResult);
}

void LVOX3_StepAddGridToNext::compute()
{
    QList<CT_ResultGroup*> resultList = getOutResultList();

    CT_ResultGroup *sourceRes = resultList.at(0);
    CT_ResultGroup *gridRes = resultList.at(1);

    CT_ResultGroupIterator itR(sourceRes, this, DEF_SearchInSourceGroup);
    CT_ResultGroupIterator itInR(gridRes, this, DEF_SearchInTargetGroup);
    lvox::Grid3Di* outGrid;

    QList<lvox::Grid3Di*> listGrids;

    //For every grid in the affilitated result add them to the source result
    while (itInR.hasNext() && !isStopped())
    {
        CT_StandardItemGroup *group = dynamic_cast<CT_StandardItemGroup*>((CT_AbstractItemGroup*)itR.next());
        CT_StandardItemGroup *groupGrid = dynamic_cast<CT_StandardItemGroup*>((CT_AbstractItemGroup*)itInR.next());

        lvox::Grid3Di* grid = dynamic_cast<lvox::Grid3Di*>(groupGrid->firstItemByINModelName(this, DEF_SearchInGrid));
        if(m_gridTypeCollection.value(m_gridType) == Ni){
            grid->addItemAttribute(new CT_StdItemAttributeT<bool>(_NiFlag_ModelName.completeName(), "LVOX_GRD_NI", sourceRes, true));
        }else if(m_gridTypeCollection.value(m_gridType) == Nt){
            grid->addItemAttribute(new CT_StdItemAttributeT<bool>(_NtFlag_ModelName.completeName(), "LVOX_GRD_NT", sourceRes, true));
        }else{
            grid->addItemAttribute(new CT_StdItemAttributeT<bool>(_NbFlag_ModelName.completeName(), "LVOX_GRD_NB", sourceRes, true));
        }

        if (grid != NULL)
        {
            outGrid = (lvox::Grid3Di*)grid->copy(_grid_ModelName.completeName(),sourceRes,CT_ResultCopyModeList());
            group->addItemDrawable(outGrid);
            listGrids.append(outGrid);
        }
    }

    for(int i = 0; i < listGrids.length();i++){
        listGrids.at(i)->computeMinMax();
    }
}


