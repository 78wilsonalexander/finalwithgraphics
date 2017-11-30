#include "fourstroke.h"
#include "engine.h"
#include <cmath>
#include <sstream>

Fourstroke::Fourstroke() : Engine::Engine()
{

}

Fourstroke::~Fourstroke()
{

}

void Fourstroke::set_AF(double af)
{
    mA_F=af;
}

double Fourstroke::get_AF()
{
    return mA_F;
}


void Fourstroke::set_QLHV(double qlhv)
{
    mQ_lHV=qlhv;
}

double Fourstroke::get_QLHV()
{
    return mQ_lHV;
}

void Fourstroke::set_Cp(double cp)
{
    mCp=cp;
}

double Fourstroke::get_Cp()
{
    return mCp;
}

void Fourstroke::set_P_in(double p_in)
{
    mP_in=p_in;
}

double Fourstroke::get_P_in()
{
    return mP_in;
}

void Fourstroke::set_P_atm(double p_atm)
{
    mP_atm=p_atm;
}

double Fourstroke::get_P_atm()
{
    return mP_atm;
}

void Fourstroke::set_P_ex(double p_ex)
{
    mP_ex=p_ex;
}

double Fourstroke::get_P_ex()
{
    return mP_ex;
}

void Fourstroke::set_T_atm(double t_atm)
{
    mT_atm=t_atm;
}

double Fourstroke::get_T_atm()
{
    return mT_atm;
}

void Fourstroke::set_T_in(double t_in)
{
    mT_in=t_in;
}

double Fourstroke::get_T_in()
{
    return mT_in;
}

void Fourstroke::set_f_res(double f_res)
{
    mFRes=f_res;
}

double Fourstroke::get_f_res()
{
    return mFRes;
}

void Fourstroke::set_V_2()
{
    mV2=get_displacement_volume()/(get_compression_ratio()-1);
}

double Fourstroke::get_V_2()
{
    return mV2;
}

void Fourstroke::set_Weibe()
{
    for(int i{-180};i<541;i++)
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

std::vector<double> Fourstroke::get_Wiebe()
{
    return mWeibe;
}

void Fourstroke::get_mMassOne()
{
    set_V_1();
    mMassOne=mP_in*mV1/.287/mT_1;
}

void Fourstroke::get_mMassFuel()
{
    get_mMassOne();
    mMassFuel=(mMassOne-mFRes*mMassOne)/(mA_F+1);
}

void Fourstroke::set_V_1()
{
    mV1=mDisplacementVolume+mV2;
}

double Fourstroke::get_V_1()
{
    return mV1;
}

void Fourstroke::calculate_volume()
{
    set_V_2();
    for(int i=-180;i<541;i++)
    {
        mVolume.push_back(mV2*(1+.5*(mR_c-1)*(mA+1-cos(i*M_PI/180)-sqrt(pow(mA,2)-pow(sin(i*M_PI/180),2)))));
    }
    //mVolume.push_back(mV2);

}

std::vector<double> Fourstroke::get_volume()
{

    return mVolume;
}

void Fourstroke::calculate_pressure()
{

    get_mMassFuel();
    set_Weibe();
    //if statement depending on crank angle
    for(double i=-180;i<541;i++)
    {
        //between -180 and 180 calculated
        if(i==-180)
        {
            mTemperature.push_back(mT_1);
            mPressure.push_back(mP_in);
            mMass.push_back(mPressure[i+180]*mVolume[i+180]/.287/mTemperature[i+180]);
        }
        //between 181 and 0 Pressure
        else if(i>-180 && i<=0)
        {
            mMass.push_back(mMass[i+179]);
            mTemperature.push_back((mTemperature[i+179]*pow((mVolume[i+179]/mVolume[i+180]),((mCp/(mCp-.287))-1)))+((mWeibe[i+180]-mWeibe[i+179])*(mMassFuel*mQ_lHV)/(mMass[i+179]*(mCp-.287))));
            mPressure.push_back((mMass[i+180]*.287)*(mTemperature[i+180]/mVolume[i+180]));
        }
        //between 0 and 180
        else if(i>0 && i<=180)
        {
            mMass.push_back(mMass[i+179]);
            mTemperature.push_back(mTemperature[i+179]*pow((mVolume[i+179]/mVolume[i+180]),((mCp/(mCp-.287))-1))+(mWeibe[i+180]-mWeibe[i+179])*(mMassFuel*mQ_lHV)/(mMass[i+180]*(mCp-.287)));
            mPressure.push_back((mMass[i+180]*.287)*(mTemperature[i+180]/mVolume[i+180]));
        }
        //181 Pressure
        else if(i==181)
        {
            mPressure.push_back(mP_ex);
            mTemperature.push_back(mTemperature[i+179]*pow((mPressure[i+180]/mPressure[i+179]),(((mCp/(mCp-.287))-1)/(mCp/(mCp-.287)))));
            mMass.push_back(mPressure[i+180]*mVolume[i+180]/.287/mTemperature[i+180]);
        }
        //between 181 and 360
        else if(i>181 && i<=360)
        {
            mPressure.push_back(mP_ex);
            mTemperature.push_back(mTemperature[i+179]);
            mMass.push_back(mPressure[i+180]*mVolume[i+180]/.287/mTemperature[i+180]);
        }
        //361 Pressure
        else if(i==361)
        {
            mPressure.push_back(mP_in);
            mTemperature.push_back(mTemperature[i+179]*pow((mPressure[i+180]/mPressure[i+179]),(((mCp/(mCp-.287))-1)/(mCp/(mCp-.287)))));
            mMass.push_back(mPressure[i+180]*mVolume[i+180]/.287/mTemperature[i+180]);
        }
        //between 361 and 540
        else
        {
            mPressure.push_back(mP_in);
            mT_540=mCp*mT_in/mCp*(1-mMass[539]/mMass[0])+mMass[539]/mMass[0]*mCp/mCp*mTemperature[539]+mMass[539]/mMass[0]*(.287)*mTemperature[539]/mCp/mP_ex*(mP_in-mP_ex);
            mTemperature.push_back(mTemperature[540]+((mVolume[i+180]-mVolume[539])/(mVolume[719]-mVolume[539]))*(mT_540-mTemperature[540]));
            mMass.push_back(mPressure[i+180]*mVolume[i+180]/.287/mTemperature[i+180]);
        }
    }
    mPressure.push_back(mT_540);

}

std::vector<double> Fourstroke::get_pressure()
{
    return mPressure;
}
std::vector<double> Fourstroke::get_Temperature()
{
    return mTemperature;
}
std::vector<double> Fourstroke::get_Mass()
{
    return mMass;
}

double Fourstroke::get_T_540()
{

    return mT_540;
}



