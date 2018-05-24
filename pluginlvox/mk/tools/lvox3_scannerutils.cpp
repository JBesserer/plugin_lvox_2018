#include <QDebug>
#include "lvox3_scannerutils.h"
#include "ct_itemdrawable/tools/scanner/ct_thetaphishootingpattern.h"
#include "ct_itemdrawable/tools/scanner/ct_shootingpatternfrompointcloud.h"
#include "ct_itemdrawable/tools/scanner/ct_parallelshootingpatternfrompointcloud.h"

const QVector<ScannerDefinitionStruct>
LVOX3_ScannerUtils::m_scannerDefinitions = {
    { ScannerSphericPointCloud, LVOX_SP_SPHERE_POINTCLOUD, QObject::tr("Tirs réels - Sphérique"), QObject::tr("La position du scanner représente l'origine des tirs. La direction d'un tir est orientée vers un point du nuage. Ceci pour chaque point du nuage.") },
    { ScannerPlanePointCloud, LVOX_SP_PLANE_POINTCLOUD,  QObject::tr("Tirs réels - Planaire"), QObject::tr("La position du scanner et la direction représentent respectivement un point du plan et son vecteur normal. L'origine d'un tir est le point du nuage projeté sur le plan, la direction est le point du nuage. Ceci pour chaque point du nuage.") },
    { ScannerSphericTheoreticScanner,  LVOX_SP_SPHERE_THEORETIC_SCANNER, QObject::tr("Tirs théoriques à partir du scanner - Sphérique"), QObject::tr("Les tirs sont générés à partir des données du scanner contenue dans chaque fichier chargé. En plus d'offrir un scanner forced pour générés tirs à partir des paramètres utilisateur renseignés.") },
    { ScannerSphericTheoreticCustom,  LVOX_SP_SPHERE_THEORETIC_CUSTOM, QObject::tr("Tirs théoriques - Sphérique customisé"), QObject::tr("Les tirs sont générés à partir des paramètres utilisateur renseignés ci-dessous.") }
};

LVOX3_ScannerUtils::LVOX3_ScannerUtils()
{
    f.registerType<CT_ShootingPatternFromPointCloud>(LVOX_SP_SPHERE_POINTCLOUD);
    f.registerType<CT_ParallelShootingPatternFromPointCloud>(LVOX_SP_PLANE_POINTCLOUD);
    f.registerType<CT_ThetaPhiShootingPattern>(LVOX_SP_SPHERE_THEORETIC_SCANNER);
    f.registerType<CT_ThetaPhiShootingPattern>(LVOX_SP_SPHERE_THEORETIC_CUSTOM);
}

const QVector<ScannerDefinitionStruct> &LVOX3_ScannerUtils::getScannerDefinitions()
{
    return m_scannerDefinitions;
}

const ScannerDefinitionStruct &LVOX3_ScannerUtils::getScannerDefinition(ScannerTypeEnum id)
{
    return m_scannerDefinitions[id];
}

const ScannerDefinitionStruct &LVOX3_ScannerUtils::getScannerDefinition(const QString &label)
{
    for (const ScannerDefinitionStruct &def: m_scannerDefinitions) {
        if (def.label == label) {
            return def;
        }
    }

    Q_ASSERT(false);

    // FIXME: is this the proper way to handle the case where the scanner label is not found?
    return m_scannerDefinitions.at(0);
}

/*OBSERVATION: I think that the options should be disabled, unless it's really custom, like theorical custom.
Mostly given that I don't see why the user would need to change the scanner coordinates when they are set in the .xyb file.*/
bool LVOX3_ScannerUtils::isCustomScannerConfiguration(ScannerTypeEnum id)
{
    return(id != ScannerSphericPointCloud && id != ScannerPlanePointCloud);
}
