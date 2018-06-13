#include <math.h>
#include <cmath>
//#include <iostream>
#include "opencv2/core/cuda.hpp"
#include <QStack>
#include "mk/tools/lvox3_errorcode.h"
#include <Eigen/Dense>

void fit(double param[3], Eigen::Vector2d data, int Ndata){


    QVector <double> S(Ndata);
    S[0] = 0;
    double Sxsqr = 0;
    double SxS = 0;
    double SSksqr = 0;
    double Syx = 0;
    double SyS = 0;

    for(int i = 1;i<Ndata;++i){
        S[i] = S[i-1] - (data(i,1)-data(i-1,1))*(data(i,0)-data(i-1,0));
        Sxsqr += pow(data(i,0)-data(0,0),2);
        SxS += (data(i,0)-data(0,0))*S[i];
        SSksqr += pow(S[i],2);
        Syx += (data(i,0)-data(0,0))*(data(i,1)-data(0,1));
        SyS += S[i]*(data(i,1)-data(0,1));
    }

    cv::Mat out;
    cv::Mat L = (cv::Mat_<double>(2,2) << Sxsqr, SxS, SxS, SSksqr);
    cv::Mat R = (cv::Mat_<double>(2,1) << Syx, SyS);
    cv::solve(L,R,out);

    double c1 = out.at<double>(1);
    double theta = 0;
    double Stheta = 0;
    double Sytheta = 0;
    double Sy = 0;
    double Stheta2 = 0;

    for(int i = 0; i<Ndata;++i){
        theta = exp(c1*data(i,0));
        Stheta += theta;
        Sytheta += theta*data(i,1);
        Stheta2 += pow(theta,2);
        Sy += data(i,1);
    }

    cv::Mat out2;
    cv::Mat L2 = (cv::Mat_<double>(2,2) << Ndata, Stheta, Stheta, Stheta2);
    cv::Mat R2 = (cv::Mat_<double>(2,1) << Sy, Sytheta);

    cv::solve(L2,R2,out2);

    //std::cout << "a + b*e^cx" << out2.at<double>(0) << " + " << out2.at<double>(1) << "e^"<< c1 << "x" << std::endl;
    param[1] = out2.at<double>(1);
    param[0] = out2.at<double>(0);
    param[2] = c1;
}

