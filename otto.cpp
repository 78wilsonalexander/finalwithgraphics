#include "otto.h"
#include "engine.h"
#include <sstream>
#include <cmath>

Otto::Otto() : Engine::Engine()
{

}

Otto::~Otto()
{

}

void Otto::set_Cp(double cp)
{
    mCp=cp;
}

double Otto::get_Cp()
{
    return mCp;
}
void Otto::set_Weibe()
{
    for(int i=-180;i<181;i++)
    {
        if((i-mThetaStart)<=0)
        {
            mWeibe.push_back(0);
        }
        else
        {
            mWeibe.push_back(1-exp((-maEfficiencyFactor)*pow(((i-mThetaStart)/mThetaDuration),mnFormFactor)));
        }
    }
}

std::vector<double> Otto::get_Wiebe()
{

    return mWeibe;
}

void Otto::calculate_volume()
{
    for(int i{-180};i<181;i++)
    {
            mVolume.push_back((mDisplacementVolume/(mR_c-1))*(1+0.5*(mR_c-1)*(mA+1-cos(i*M_PI/180)-sqrt(pow(mA,2)-pow(sin(i*M_PI/180),2)))));
    }

}

void Otto::calculate_pressure()
{
    set_Weibe();
    for(int i{-180};i<181;i++)
    {
        if(i==-180)
        {
            mPressure.push_back(mP_1);
            mTemperature.push_back(mT_1);
            mMass.push_back((mPressure[i+180]*mVolume[i+180])/(.287*mTemperature[i+180]));
        }
        else
        {
           mMass.push_back(mMass[i+179]);
           mTemperature.push_back((mTemperature[i+179]*pow((mVolume[i+179]/mVolume[i+180]),(mCp/(mCp-.287)-1))+(mWeibe[i+180]-mWeibe[i+179])*mQ_in/(mMass[i+180]*(mCp-.287))));
           mPressure.push_back((mMass[i+180]*.287*mTemperature[i+180])/mVolume[i+180]);
        }
    }

    //mPressure.push_back(0);
}

std::vector<double> Otto::get_pressure()
{
    return mPressure;
}



std::vector<double> Otto::get_volume()
{
        return mVolume;
}

std::vector<double> Otto::get_Temperature()
{
    return mTemperature;
}

std::vector<double> Otto::get_Mass()
{
    return mMass;
}




