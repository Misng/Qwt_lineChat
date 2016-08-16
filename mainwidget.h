#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTimerEvent>
#include <QPushButton>

#include "timescaledraw.h"
#include <Qwt/qwt_plot.h>
#include <Qwt/qwt_legend.h>
#include <Qwt/qwt_plot_panner.h>
#include <Qwt/qwt_scale_widget.h>
#include <Qwt/qwt_plot_layout.h>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_symbol.h>
#include <Qwt/qwt_plot_zoomer.h>

#include "COM/serialthread.h"

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
    void OpenCOMSlot();
    void CloseCOMSlot();
    void recvData(float);
private:
     QwtPlot * qwt;
     QwtPlotCurve * curve;
     QPolygonF points;
     double Current_time_t;

     SerialThread * serialThread;

     bool isKillTimer;

     QPushButton * btn_open;
     QPushButton * btn_close;

};

#endif // MAINWIDGET_H
