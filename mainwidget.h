#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTimerEvent>

#include "timescaledraw.h"
#include "qwt/qwt_plot.h"
#include "qwt/qwt_legend.h"
#include "qwt/qwt_plot_panner.h"
#include "qwt/qwt_scale_widget.h"
#include "qwt/qwt_plot_layout.h"
#include"qwt/qwt_plot_curve.h"
#include "qwt/qwt_symbol.h"
#include "qwt/qwt_plot_zoomer.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

    void setAxisTick();
    void setTickStyle();
protected:
    void timerEvent(QTimerEvent *);
    
signals:
    
public slots:
private:
     QwtPlot * qwt;
     QwtPlotCurve * curve;
     QPolygonF points;
     double Current_time_t;
    
};

#endif // MAINWIDGET_H
