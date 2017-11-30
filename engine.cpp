#include "engine.h"
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <cmath>

Engine::~Engine()
{

}

//Calculate the displacement volume
void Engine::set_displacement_volume(double bore, double stroke)
{
    double radius;

    radius=bore/2;

    mDisplacementVolume=radius*radius*M_PI*stroke;
}

void Engine::set_q_in(double Qin)
{
    mQ_in=Qin;
}

double Engine::get_q_in()
{
    return mQ_in;
}

double Engine::get_displacement_volume()
{
    return mDisplacementVolume;
}

void Engine::set_A(double stroke)
{
      mA=2*(mCon_rod/stroke);
}


double Engine::get_A() //also known as A in eqt 5.34
{

    return mA;
}

void Engine::set_Con_Rod(double conrod)
{
    mCon_rod=conrod;
}

double Engine::get_Con_Rod()
{
    return mCon_rod;
}

void Engine::set_comression_ratio(double comp_ratio)
{
    mR_c=comp_ratio;
}

double Engine::get_compression_ratio()
{
    return mR_c;
}

void Engine::set_P_1(double p_1)
{
    mP_1=p_1;
}

double Engine::get_P_1()
{
    return mP_1;
}


void Engine::set_T_1(double t_1)
{
    mT_1=t_1;
}

double Engine::get_T_1()
{
    return mT_1;
}

void Engine::set_Theta_Start(int theta_start)
{
    mThetaStart=theta_start;
}

double Engine::get_T_Theta_Start()
{
    return mThetaStart;
}

void Engine::set_Theta_Duration(int theta_duration)
{
    mThetaDuration=theta_duration;
}

double Engine::get_Theta_Duration()
{
    return mThetaDuration;
}

void Engine::set_n_Form_factor(double n_form_factor)
{
    mnFormFactor=n_form_factor;
}

double Engine::get_n_Form_Factor()
{
    return mnFormFactor;
}

void Engine::set_a_Efficiency_Form_Factor(double a_efficiency)
{
    maEfficiencyFactor=a_efficiency;
}

double Engine::get_a_Efficiency_Form_Factor()
{
    return maEfficiencyFactor;
}

QString Engine::print(Engine *engine)
{
    int size=engine->get_volume().size();
    std::ostringstream stream;
    stream<<"Displacment Volume: "<<get_displacement_volume()<<std::endl;

    for(int j{0};j<size;j++)
    {
        stream<<j-180<<" ";
        stream<<"Volume: "<<engine->get_volume()[j];
        stream<<"  "<<"Pressure: "<<engine->get_pressure()[j];
        stream<<"  "<<"Temperature: "<<engine->get_Temperature()[j];
        stream<<"  "<<"Weibe: " <<engine->get_Wiebe()[j];
        stream<<"  "<<"Mass: "<<engine->get_Mass()[j]<<std::endl;

    }
       //stream<<" "<<"mT_540: "<<engine->get_pressure()[i+1]<<std::endl;

   //stream<<"V2: "<<engine->get_volume()[0]<<std::endl;
    return QString::fromStdString(stream.str());
}









