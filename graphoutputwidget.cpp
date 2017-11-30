#include "graphoutputwidget.h"
#include <vtkCamera.h>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkInteractorStyleUser.h>
#include <vtkProperty.h>
#include <vtkCommand.h>
#include <vtkPointData.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkDoubleArray.h>
#include <vtkDataSetMapper.h>
#include <vtkClipDataSet.h>
#include <vtkPlane.h>
#include <vtkUnstructuredGrid.h>
#include <QFileDialog>
#include <QVector3D>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPlotLine.h>
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <vtkAxis.h>


GraphOutputWidget::GraphOutputWidget(QWidget *parent) : QVTKWidget(parent)
{
    setup_graph();
}


int GraphOutputWidget::graph_results(std::vector<double> volume,std::vector<double> pressure)
{
    // Create a table with some points in it
    vtkSmartPointer<vtkTable> table =
            vtkSmartPointer<vtkTable>::New();

    //labels columns
    vtkSmartPointer<vtkFloatArray> arrX =
            vtkSmartPointer<vtkFloatArray>::New();
    arrX->SetName("Volume");
    table->AddColumn(arrX);
    vtkSmartPointer<vtkFloatArray> arrC =
            vtkSmartPointer<vtkFloatArray>::New();
    arrC->SetName("Pressure");
    table->AddColumn(arrC);

    // Fill in the table with some example values
    table->SetNumberOfRows(volume.size()); //should be variable for each type of cycle
    for (int i = 0; i < volume.size(); ++i)
    {
        table->SetValue(i, 0, volume[i]);
        table->SetValue(i, 1, pressure[i]);
    }
    mChart->ClearPlots();
    vtkSmartPointer<vtkPlot> line = mChart->AddPlot(vtkChart::LINE);

    line->SetInputData(table,0,1);
    line->SetColor(0, 255, 0, 255);
    line->SetWidth(1.0);

   update();
}

//sets up the graph so that there is already plots and a "pipeline" set up
int GraphOutputWidget::setup_graph()
{
    // Set up the view
    vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
    view->SetInteractor(this->GetInteractor());
    this->SetRenderWindow(view->GetRenderWindow());

    // Add multiple line plots, setting the colors etc
    mChart =
            vtkSmartPointer<vtkChartXY>::New();
    view->GetScene()->AddItem(mChart);

    //!convert axes to log scale
    //! https://www.vtk.org/doc/nightly/html/classvtkAxis.html
    //!http://vtk.1045678.n5.nabble.com/Problem-with-logarithmic-scale-in-vtkChartXY-td5736564.html
    //sets up the x and y axis to be shown in the log-scale
    for (unsigned int i {0}; i < 2; i++)
    {
        vtkAxis *axis = mChart->GetAxis(i);
        axis->SetLogScale(true);
    }

    view->GetRenderWindow()->SetMultiSamples(0);

    return EXIT_SUCCESS;
}
