#ifndef OTTO_H
#define OTTO_H

#include "engine.h"

class Otto : public Engine
{
public:
    Otto();
    virtual~Otto();

    //
    virtual void set_Cp(double cp);
    virtual double get_Cp();

    virtual void calculate_pressure();
    virtual std::vector<double> get_pressure();

    virtual void calculate_volume();
    virtual std::vector<double> get_volume();

    //Get Temperature
    virtual std::vector<double> get_Temperature();

    //Get Mass
    virtual std::vector<double> get_Mass();

    virtual void set_Weibe();
    virtual std::vector<double> get_Wiebe();

//    QString print();
//    QString delete_print();

protected:

};

#endif // OTTO_H
