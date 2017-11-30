#ifndef Diesel_H
#define Diesel_H
#include <QString>
#include "engine.h"

class Diesel : public Engine
{
public:
    Diesel();
    virtual~Diesel();



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



protected:

};

#endif // Diesel_H
