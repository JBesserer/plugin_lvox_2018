#include "lvox3_interpolatekriging.h"

#include "mk/tools/lvox3_errorcode.h"

#include "mk/tools/traversal/propagation/lvox3_grid3dpropagationalgorithm.h"
#include "mk/tools/traversal/propagation/visitor/lvox3_trustinterpolationvisitor.h"
#include "mk/tools/traversal/propagation/expfit.h"

LVOX3_InterpolateKriging::LVOX3_InterpolateKriging(const lvox::Grid3Df* originalDensityGrid,
                                                   const lvox::Grid3Di* beforeGrid,
                                                   const lvox::Grid3Di* theoriticalsGrid,
                                                   lvox::Grid3Df* const outDensityGrid,
                                                   double radius)
{
    m_originalDensityGrid = (lvox::Grid3Df*)originalDensityGrid;
    m_outDensityGrid = (lvox::Grid3Df*)outDensityGrid;
    m_beforeGrid = (lvox::Grid3Di*)beforeGrid;
    m_theoriticalsGrid = (lvox::Grid3Di*)theoriticalsGrid;
    m_radius = radius;
}

void LVOX3_InterpolateKriging::doTheJob()
{
    krigepointBinomial();
}

void LVOX3_InterpolateKriging::krigepointBinomial()
{
    for(int ref = 0; ref < m_originalDensityGrid->nCells(); ref++)
    {
    if(m_originalDensityGrid->valueAtIndex(ref) == -1 || m_originalDensityGrid->valueAtIndex(ref) == -3 )
    {
        Eigen::Vector3d coordsBefore;
        m_originalDensityGrid->getCellCenterCoordinates(ref,coordsBefore);

        int num_points = 0;

        Eigen::Vector2d temppoints(m_originalDensityGrid->nCells(),5);

        for(int p = 0; p < m_originalDensityGrid->nCells(); p++)
        {
            Eigen::Vector3d coordsLocal;
            m_originalDensityGrid->getCellCenterCoordinates(p,coordsLocal);

            //qDebug() << " x=" << coordsBefore[0] << " y=" << coordsBefore[1] << " z=" << coordsBefore[2];
            //qDebug() << " x=" << coordsLocal[0] << " y=" << coordsLocal[1] << " z=" << coordsLocal[2];

            double dx = coordsBefore[0]- coordsLocal[0];
            double dy = coordsBefore[1]- coordsLocal[1];
            double dz = coordsBefore[2]- coordsLocal[2];

            double distance = sqrt(dx*dx + dy*dy + dz*dz);

            if((distance < m_radius)&&(m_originalDensityGrid->valueAtIndex(p)>=0)&&m_originalDensityGrid->valueAtIndex(p)<=1)
            {
                temppoints(num_points,0) = coordsLocal[0];
                temppoints(num_points,1) = coordsLocal[1];
                temppoints(num_points,2) = coordsLocal[2];
                temppoints(num_points,3) = m_originalDensityGrid->valueAtIndex(p);
                temppoints(num_points,4) = m_theoriticalsGrid->valueAtIndex(p) - m_beforeGrid->valueAtIndex(p);
                num_points++;
            }
        }

        Eigen::Vector2d points(num_points+1,5);

        //new matrice with the right size
        for(int j = 0; j<num_points; j++)
        {
            points(j,0) = temppoints(j,0);
            points(j,1) = temppoints(j,1);
            points(j,2) = temppoints(j,2);
            points(j,3) = temppoints(j,3);
            points(j,4) = temppoints(j,4);
        }

        points(num_points,0) = coordsBefore[0];
        points(num_points,1) = coordsBefore[1];
        points(num_points,2) = coordsBefore[2];
        points(num_points,3) = m_originalDensityGrid->valueAtIndex(ref);
        points(num_points,4) = m_theoriticalsGrid->valueAtIndex(ref) - m_beforeGrid->valueAtIndex(ref);

        if(num_points == 0)
        {
            m_outDensityGrid->setValueAtIndex(ref,0);
        }
        else
        {
            double sum = 0;
            for(int i = 0; i<num_points;i++)
            {
                sum += points(i,3);
            }
            if(sum ==0)
            {
                m_outDensityGrid->setValueAtIndex(ref,0);
            }
            else
            {
                double pi = 0;
                double sigma = 0;
                sum = 0;
                for(int i=0; i<num_points; i++)
                {
                    if(points(i,4) > 15&points(i,3)>=0)
                    {
                        pi += points(i,3);
                        sum++;//fit(param, Vgexp, ndistances);
                    }
                }
                pi /= sum;

                sum =0;
                for(int i=0; i<num_points; i++)
                {
                    if(points(i,4) > 15&&points(i,3)>=0)
                    {
                        sigma += pow(points(i,3),2);
                        sum++;
                    }
                }
                sigma = sigma/sum - pow(pi,2);

                int ndistances = 0;
                bool flag;

                QVector <double> tempdistances(num_points*2);
                for(int i =0; i<num_points*2;i++)
                {
                    tempdistances[i]= -1;
                }
                for(int i = 0; i<num_points; i++)
                {
                    if(points(i,3) >=0 && points(i,4) > 15)
                    {
                        for(int j = 0; j<num_points; j++)
                        {
                            if(points(j,3) >=0 && points(j,4) > 15)
                            {
                                flag = 0;
                                double dx = points(i,0) - points(j,0);
                                double dy = points(i,1) - points(j,1);
                                double dz = points(i,2) - points(j,2);
                                double distance = sqrt(dx*dx + dy*dy + dz*dz);
                                for(int k=0;k<num_points*2&&flag==0&&distance<m_radius;++k)
                                {
                                    if(tempdistances[k] == distance)
                                    {
                                        flag = 1;
                                    }
                                }
                                if(flag==0&&distance<m_radius)
                                {
                                    tempdistances[ndistances] = distance;
                                    ++ndistances;
                                }
                            }
                        }
                    }
                }
                //qDebug() << "ndistances = " << ndistances;
                if(ndistances <= 1)
                {
                    m_outDensityGrid->setValueAtIndex(ref,0);
                }
                else
                {
                    QVector <double> distances(ndistances);
                    for(int i =0; i<ndistances;i++)
                    {
                        distances[i]= -1;
                    }
                    Eigen::Vector2d gamma(ndistances,2);
                    for(int i =0; i<ndistances;i++)
                    {
                        gamma(i,0)=0;
                        gamma(i,1)=0;
                    }
                    int lastDistanceLocation = 0;
                    for(int i = 0; i<num_points; i++)
                    {
                        if(points(i,3) >=0 && points(i,4) > 15)
                        {
                            for(int j = 0; j<num_points; j++)
                            {
                                if(points(j,3) >=0 && points(j,4) > 15)
                                {
                                    flag = 0;
                                    double dx = points(i,0) - points(j,0);
                                    double dy = points(i,1) - points(j,1);
                                    double dz = points(i,2) - points(j,2);
                                    double distance = sqrt(dx*dx + dy*dy + dz*dz);
                                    for(int k=0;k<ndistances&&flag==0&&distance<m_radius;++k)
                                    {
                                        if(distances[k] == distance)
                                        {
                                            gamma(k,0) += (points(i,4)*points(j,4))/(points(i,4)+points(j,4))*pow(points(j,3)-points(i,3),2) - pi*(1-pi) + sigma;
                                            gamma(k,1) += (points(i,4)*points(j,4))/(points(i,4)+points(j,4));
                                            flag = 1;

                                        }
                                    }
                                    if(flag==0&&distance<m_radius)
                                    {
                                        distances[lastDistanceLocation] = distance;
                                        gamma(lastDistanceLocation,0) += (points(i,4)*points(j,4))/(points(i,4)+points(j,4))*pow(points(j,3)-points(i,3),2) - pi*(1-pi) + sigma;
                                        gamma(lastDistanceLocation,1) += (points(i,4)*points(j,4))/(points(i,4)+points(j,4));
                                        ++lastDistanceLocation;
                                    }
                                }
                            }
                        }
                    }
                    Eigen::Vector2d Vgexp(ndistances,2);

                    for(int i=0; i<ndistances; i++)
                    {

                        Vgexp(i,1) = gamma(i,0)/(gamma(i,1));
                        Vgexp(i,0) = distances[i];
                        //qDebug() << Vgexp(i,0) << Vgexp(i,0);
                    }

                    //sort the vg
                    //auto vg = (std::pair<double,double>*) Vgexp;
                    //std::sort(vg, vg+ndistances);

                    std::sort(Vgexp.data(),Vgexp.data()+Vgexp.size(),std::less<double>());

                    //std::sort(Vgexp, Vgexp +ndistances);

                    double sumd =0;
                    for(int i = 0; i<ndistances;i++)
                    {
                        //qDebug() << Vgexp(i,0) << Vgexp(i,0);
                        sumd += Vgexp(i,1);
                    }
                    if(sumd == 0)
                    {
                        m_outDensityGrid->setValueAtIndex(ref,0);
                    }
                    else
                    {
                        double param[3];
                        fit(param, Vgexp, ndistances);
                        double range = -1/param[2];
                        double sill = -param[1];
                        double nugget = param[0]-sill;

                        //Fill V matrix
                        cv::Mat V = cv::Mat(num_points+1,num_points+1,CV_64F);
                        for(int c = 0; c < num_points; c++)
                        {
                            for(int d = 0; d < num_points; d++)
                            {
                                if(c!=d)
                                {
                                    V.at<double>(c,d) = variogram(points, c, d, nugget, sill, range);
                                }
                                else if(c==d)
                                {
                                    V.at<double>(c,d) = variogram(points, c, d, nugget, sill, range) + (pi*(1-pi)-sigma)/points(c,4);
                                }
                            }
                        }
                        for(int c = 0;c<num_points+1;++c)
                        {
                            V.at<double>(num_points,c) = 1;
                            V.at<double>(c,num_points) = 1;
                        }
                        V.at<double>(num_points,num_points) = 0;

                        //Fill v
                        QVector <double> v(num_points+1);
                        for(int c = 0; c < num_points; c++)
                        {
                            v[c] = variogram(points, num_points, c, nugget, sill, range);
                        }
                        v[num_points] = 1;

                        cv::Mat v1 = cv::Mat(num_points+1,1,CV_64F, v.data());
                        cv::Mat out;

                        cv::solve(V,v1,out);

                        double output = 0;
                        for(int c = 0; c < num_points; c++)
                        {
                            output += points(c,3) * out.at<double>(c);
                        }
                        //qDebug() << ref << " with value " << output;
                        m_outDensityGrid->setValueAtIndex(ref,output);
                    }
                }
            }
        }
    }}
}

double LVOX3_InterpolateKriging::variogram(Eigen::Vector2d points, int a, int b, double nugget, double sill, double range){
  double d = anisotropic_distance(points, a, b);

  double r = nugget + sill*(1 - exp(-(d/range)));
  return r;
}

double LVOX3_InterpolateKriging::anisotropic_distance(Eigen::Vector2d points, int a, int b){
  double dx = points(a,0)- points(b,0);
  double dy = points(a,1)- points(b,1);
  double dz = points(a,2)- points(b,2);

  return sqrt(dx*dx + dy*dy + dz*dz);
}
