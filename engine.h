#ifndef SHAPE_H
#define SHAPE_H
#include <QString>

class Engine
{
public:
    //made virtual so that the child will be deleted along with the parent
    virtual ~Engine();

    //constructor
    //Engine();

    //Calculate the displacement volume
    virtual void set_displacement_volume(double bore, double stroke);
    virtual double get_displacement_volume();

    //sets and gets the stroke
    virtual void set_A(double stroke);
    virtual double get_A(); //equation 5.34

    //connecting rod length
    virtual void set_Con_Rod(double conrod);
    virtual double get_Con_Rod();

    //Compression Ratio
    virtual void set_comression_ratio(double comp_ratio);
    virtual double get_compression_ratio();

    //sets and gets the added heat
    virtual void set_q_in(double Qin);
    virtual double get_q_in();

    //sets and gets pressure at position 1 (crank angle -180)
    virtual void set_P_1(double p_1);
    virtual double get_P_1();

    //iterated value of temperature at position 1 (crank angle -180)
    virtual void set_T_1(double t_1);
    virtual double get_T_1();

    //sets an gets the starting crank angle for the burn duration
    virtual void set_Theta_Start(int theta_start);
    virtual double get_T_Theta_Start();

    //sets and gets the burn duration
    virtual void set_Theta_Duration(int theta_duration);
    virtual double get_Theta_Duration();


    virtual void set_n_Form_factor(double n_form_factor);
    virtual double get_n_Form_Factor();

    virtual void set_a_Efficiency_Form_Factor(double a_efficiency);
    virtual double get_a_Efficiency_Form_Factor();

    //Calculate Volume
    virtual void calculate_volume()=0;
    virtual std::vector<double> get_volume()=0;

    //Calculate Pressure
    virtual void calculate_pressure()=0;
    virtual std::vector<double> get_pressure()=0;

    //Get Temperature
    virtual std::vector<double> get_Temperature()=0;

    //Get Mass
    virtual std::vector<double> get_Mass()=0;

    virtual void set_Weibe()=0;
    virtual std::vector<double> get_Wiebe()=0;


    //allows for other print functions to be made in child functions

    QString print(Engine *engine);



protected:
    double mDisplacementVolume;
    std::vector<double> mVolume;
    std::vector<double> mPressure;
    std::vector<double> mTemperature;

    double mA;

    //connecting rod
    double mCon_rod;

    //compression ratio
    double mR_c;

    //Specific heat
    double mCp;

    double mP_1;

    double mT_1;
    std::vector<double> mMass;
    std::vector<double> mWeibe;
    double mThetaStart;
    double mThetaDuration;
    double mnFormFactor;
    double maEfficiencyFactor;
    double mQ_in;

};

#endif // ENGINE_H
