#include "diesel.h"
#include "engine.h"
#include <sstream>

//constructor - derived from Parent Class
Diesel::Diesel() : Engine::Engine()
{

}

Diesel::~Diesel()
{

}

void Diesel::calculate_pressure()
{
    //place holder
    mPressure.push_back(0.0);

}

std::vector<double> Diesel::get_pressure()
{
    return mPressure;
}


void Diesel::calculate_volume()
{
    //    for(int i{-180};i<180;i++)
    //    {
    //        if(i<=-90)
    //        {
    //            mVolume.push_back();
    //        }
    //        else if(i>-90 && i<=0)
    //        {
    //            mVolume.push_back();
    //        }
    //        else if(i>0 && i<=90)
    //        {
    //            mVolume.push_back();
    //        }
    //        else
    //        {
    //            mVolume.push_back();
    //        }
    //    }
    //place holder
     mVolume.push_back(8);

}

std::vector<double> Diesel::get_volume()
{
    return mVolume;
}

std::vector<double> Diesel::get_Mass()
{
    //place holder
    std::vector<double> temp {8};
    return temp;

}

std::vector<double> Diesel::get_Temperature()
{
    //place holder
    std::vector<double> temp {8};
    return temp;
}

void Diesel::set_Weibe()
{

}

std::vector<double> Diesel::get_Wiebe()
{
    //place holder
    std::vector<double> temp {8};
    return temp;
}

////Prints out all the box data
//QString Diesel::print()
//{
//    std::ostringstream stream;
//    stream<<"Volume "<<get_displacement_volume();<<std::endl;

//    return QString::fromStdString(stream.str());
//}

//QString Diesel::delete_print()
//{
//    std::ostringstream stream;
//    stream<<"Volume "<<get_displacement_volume();<<std::endl;

//    return QString::fromStdString(stream.str());
//}
