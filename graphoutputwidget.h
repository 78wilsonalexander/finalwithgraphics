#ifndef GRAPHOUTPUTWIDGET_H
#define GRAPHOUTPUTWIDGET_H

#include "QVTKWidget.h"
#include "vtkPlot.h"
#include "vtkSmartPointer.h"
#include <vtkChartXY.h>

class GraphOutputWidget : public QVTKWidget
{
public:
    GraphOutputWidget(QWidget *parent = 0);
    int graph_results(std::vector<double> volume, std::vector<double> pressure);

protected:
    vtkSmartPointer<vtkPlot> mLine;
    vtkSmartPointer<vtkChartXY> mChart;
    int setup_graph();
};

#endif // GRAPHOUTPUTWIDGET_H
