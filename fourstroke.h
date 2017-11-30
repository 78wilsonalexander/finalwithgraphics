#ifndef FOURSTROKE_H
#define FOURSTROKE_H

#include "engine.h"

class Fourstroke : public Engine
{
public:
    Fourstroke();
    virtual~Fourstroke();

    virtual void set_AF(double af);
    virtual double get_AF();

    //sets and gets the heating value
    virtual void set_QLHV(double qlhv);
    virtual double get_QLHV();


    //sets and gets the specific heat
    virtual void set_Cp(double cp);
    virtual double get_Cp();

    //sets and gets the intake Pressure
    virtual void set_P_in(double p_in);
    virtual double get_P_in();

    //sets and gets the atmospheric pressure
    virtual void set_P_atm(double p_atm);
    virtual double get_P_atm();

    //sets and gets the exhaust pressure
    virtual void set_P_ex(double p_ex);
    virtual double get_P_ex();

    //sets and gets the atmospheric pressure
    virtual void set_T_atm(double t_atm);
    virtual double get_T_atm();

    //sets and gets the intake pressure
    virtual void set_T_in(double t_in);
    virtual double get_T_in();

    //sets an gets the residual mass fraction
    virtual void set_f_res(double f_res);
    virtual double get_f_res();

    //sets and gets the volume at *****position 1***
    virtual void set_V_1();
    virtual double get_V_1();

    //sets and gets the volume at position 2
    virtual void set_V_2();
    virtual double get_V_2();

    //sets the Weibe value in order to have variable heat addition
    virtual void set_Weibe();
    virtual std::vector<double> get_Wiebe();

    //gets the original mass
    virtual void get_mMassOne();

    //gets the mass of the fuel
    virtual void get_mMassFuel();

    //gets the temp at 540 crank angles
    virtual double get_T_540();

    //calculates the volume
    virtual void calculate_volume();
    virtual std::vector<double> get_volume();

    //calculates the pressure
    virtual void calculate_pressure();
    virtual std::vector<double> get_pressure();

    virtual std::vector<double> get_Mass();

    virtual std::vector<double> get_Temperature();



//    QString print();
//    QString delete_print();
protected:
    double mV1;
    double mV2;
    double mA_F;

    double mT_540;
    double mQ_lHV;
    double mP_in;
    double mP_atm;
    double mP_ex;
    double mT_atm;
    double mT_in;
    double mFRes;
    double mMassOne;
    double mMassFuel;

};

#endif // FOURSTROKE_H
