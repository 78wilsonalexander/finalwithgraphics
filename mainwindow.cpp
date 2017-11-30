#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "engine.h"
#include "diesel.h"
#include "otto.h"
#include "fourstroke.h"
#include <math.h>
#include <sstream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set the decimal values for the spin boxes
    ui->BoreDiesel->setDecimals(4);
    ui->StrokeDiesel->setDecimals(4);
    ui->BoreOtto->setDecimals(4);
    ui->StrokeOtto->setDecimals(4);
    ui->BoreFourStroke->setDecimals(4);
    ui->StrokeFourStroke->setDecimals(4);
    ui->ConnectingRodDiesel->setDecimals(4);
    ui->ConnectingRodFourStroke->setDecimals(4);
    ui->ConnectingRodOtto->setDecimals(4);
    ui->LowerHeatingValueqFourStroke->setDecimals(4);
    ui->ExhaustPressureFourStroke->setDecimals(4);
    ui->CpDiesel->setDecimals(4);
    ui->CpFourStroke->setDecimals(4);
    ui->CpOtto->setDecimals(4);
    ui->TemperatureOneDiesel->setDecimals(4);
    ui->TemperatureOneFourStroke->setDecimals(4);
    ui->TemperatureOneOtto->setDecimals(4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    //Gives the data in 'About'
    QMessageBox::about(this,"About","Final Project\n"
                                    "Created by: Alexander Wilson and Jaymes Walters");
}

void MainWindow::on_actionExit_triggered()
{
    //Closes the application
    QApplication::quit();
}

void MainWindow::on_CalculateResults_clicked()
{
    Engine *results;
    double bore{0};
    double stroke{0};

    //Calculates the information in each of the 3 possible engine types

    //Ideal Otto Cycle
    if(ui->TypeOfEngine->currentIndex()==0)
    {
        //create a new otto cycle
        Otto *otto = new Otto();

        //pulling data from GUI-----------------------------------------------------------------------
        //these are setting the M-variables by
        bore=ui->BoreOtto->value();
        stroke=ui->StrokeOtto->value();
        otto->set_comression_ratio(ui->CompressionRatioOtto->value());
        otto->set_displacement_volume(bore,stroke);
        otto->set_Cp(ui->CpOtto->value());
        otto->set_q_in(ui->QinOtto->value());
        otto->set_Con_Rod(ui->ConnectingRodOtto->value());
        otto->set_A(stroke);
        otto->set_T_1(ui->TemperatureOneOtto->value());
        otto->set_P_1(ui->PressureOneOtto->value());
        otto->set_a_Efficiency_Form_Factor(ui->aEfficiencyFactorOtto->value());
        otto->set_n_Form_factor(ui->nFormFactorOtto->value());
        otto->set_Theta_Duration(ui->ThetaDurationOtto->value());
        otto->set_Theta_Start(ui->ThetaStartOtto->value());        
        //pulling data from GUI------------------------------------------------------------------------

        //Calculating Volume and pressure
        otto->calculate_volume();
        otto->calculate_pressure();

        //sets data to the results in order to be printed
        results=otto;

        //displays a QMessage box if the displacement volume is 0
        double displacement_volume = otto->get_displacement_volume();
        if(displacement_volume <= 0)
        {
            //sends a warning to the user when the file does not open
                   QMessageBox::warning(this, tr("My Application"),
                                        tr("The Displacement volume cannot be 0"));
                   return;
        }
    }
    //Ideal Diesel Engine Cycle
    else if(ui->TypeOfEngine->currentIndex()==1)
    {
        Diesel *diesel = new Diesel();

        //pulling data from GUI-----------------------------------------------------------------------
        bore=ui->BoreDiesel->value();
        stroke=ui->StrokeDiesel->value();
        diesel->set_displacement_volume(bore,stroke);
        diesel->set_Con_Rod(ui->ConnectingRodDiesel->value());
        diesel->set_A(stroke);
        diesel->set_T_1(ui->TemperatureOneDiesel->value());
        diesel->set_P_1(ui->PressureOneDiesel->value());
        diesel->set_a_Efficiency_Form_Factor(ui->aEfficiencyFactorDiesel->value());
        diesel->set_n_Form_factor(ui->nFormFactorDiesel->value());
        diesel->set_Theta_Duration(ui->ThetaDurationDiesel->value());
        diesel->set_Theta_Start(ui->ThetaStartDiesel->value());
        //pulling data from GUI-----------------------------------------------------------------------


        //Calculating Volume and pressure
        diesel->calculate_volume();
        diesel->calculate_pressure();

        //sets data to the results in order to be printed
        results=diesel;

        //displays a QMessage box if the displacement volume is 0
        double displacement_volume = diesel->get_displacement_volume();
        if(displacement_volume <= 0)
        {
            //sends a warning to the user when the file does not open
                   QMessageBox::warning(this, tr("My Application"),
                                        tr("The Displacement volume cannot be 0"));
                   return;
        }

    }
    else if(ui->TypeOfEngine->currentIndex()==2)
    {
        Fourstroke *fourstroke = new Fourstroke();

        //pulling data from GUI-----------------------------------------------------------------------
        bore=ui->BoreFourStroke->value();
        stroke=ui->StrokeFourStroke->value();
        fourstroke->set_displacement_volume(bore,stroke);
        fourstroke->set_Con_Rod(ui->ConnectingRodFourStroke->value());
        fourstroke->set_comression_ratio(ui->CompressionRatioFourStroke->value());
        fourstroke->set_Cp(ui->CpFourStroke->value());
        fourstroke->set_A(stroke);
        fourstroke->set_T_1(ui->TemperatureOneFourStroke->value());
        fourstroke->set_P_1(ui->PressureOneFourStroke->value());
        fourstroke->set_a_Efficiency_Form_Factor(ui->aEfficiencyFactorFourStroke->value());
        fourstroke->set_n_Form_factor(ui->nFormFactorFourStroke->value());
        fourstroke->set_Theta_Duration(ui->ThetaDurationFourStroke->value());
        fourstroke->set_Theta_Start(ui->ThetaStartFourStroke->value());
        fourstroke->set_AF(ui->AirFuelFourStroke->value());
        fourstroke->set_P_atm(ui->AtmosphericPressureFourStroke->value());
        fourstroke->set_f_res(ui->fResFourStroke->value());
        fourstroke->set_P_ex(ui->ExhaustPressureFourStroke->value());
        fourstroke->set_P_in(ui->IntakePressureFourStroke->value());
        fourstroke->set_QLHV(ui->LowerHeatingValueqFourStroke->value());
        fourstroke->set_T_atm(ui->AtmosphericTemperatureFourStroke->value());
        fourstroke->set_T_in(ui->IntakeTemperatureFourStroke->value());        
        //pulling data from GUI-----------------------------------------------------------------------

        //Calculating Volume and pressure
        fourstroke->calculate_volume();
        fourstroke->calculate_pressure();

        //sets data to the results in order to be printed
        results=fourstroke;

        //displays a QMessage box if the displacement volume is 0
        double displacement_volume = fourstroke->get_displacement_volume();
        if(displacement_volume <= 0)
        {
            //sends a warning to the user when the file does not open
                   QMessageBox::warning(this, tr("My Application"),
                                        tr("The Displacement volume cannot be 0"));
                   return;
        }
    }

    //uses the print function in the children in order to show the results
    ui->Results->setPlainText(results->print(results));

    //uses VTK in order to graph the PV diagram showing the cycle
    ui->Graph_Output->graph_results(results->get_volume(),results->get_pressure());

    //makes sure the memory is properly deleted
    delete results;
}


void MainWindow::on_actionOpen_triggered()
{
    //Gives the data in 'About'
    QMessageBox::about(this,"About","Final Project\n"
                                    "This doesn't do anything yet");
}

void MainWindow::on_actionSave_triggered()
{
    //Gives the data in 'About'
    QMessageBox::about(this,"About","Final Project\n"
                                    "This doesn't do anything yet");
}

void MainWindow::on_actionSave_As_triggered()
{
    //Gives the data in 'About'
    QMessageBox::about(this,"About","Final Project\n"
                                    "This doesn't do anything yet");
}





