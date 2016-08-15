#ifndef CPUPLOT_H
#define CPUPLOT_H

#define HISTORY 60

#include "qwt/qwt_plot.h"
#include "qwt/qwt_plot_curve.h"

class CpuPlot : public QwtPlot
{
    Q_OBJECT

//public:
//    enum CpuData
//    {
//        User,
//        System,
//        Total,
//        Idle,

//        NCpuData
//    };
//public slots:
//private:
//    struct
//    {
//        QwtPlotCurve * curve;
//        double data[HISTORY];
//    }data[NCpuData];

//    double timeData[HISTORY];

//    int dataCount;
//    CpuStat cpuStart;
    
};

#endif // CPUPLOT_H
