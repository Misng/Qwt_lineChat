#include <QApplication>


#include "mainwidget.h"



void setAxisTick(QwtPlot *);


int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
#if 0

    //图表属性设置
    QwtPlot * qwt = new QwtPlot();
    qwt->setTitle("same plot");
    qwt->setCanvasBackground(QBrush(Qt::white));
    qwt->insertLegend(new QwtLegend());//不明嚼栗
    qwt->setAxisScale(QwtPlot::yLeft,-10,10,1);
    //坐标轴

    //x轴
    qwt->setAxisScaleDraw(QwtPlot::xBottom,new TimeScaleDraw());//画刻度
    qwt->setAxisScale(QwtPlot::xBottom,
                      QDateTime::currentDateTime().toTime_t()-10,
                      QDateTime::currentDateTime().toTime_t()
                      );//设置刻度范围

    qwt->setAxisMaxMajor(QwtPlot::xBottom,10);//设置坐标轴的最大间隔为10，也就是将一屏的刻度分为10个大间隔。
    qwt->setAxisMaxMinor(QwtPlot::xBottom,0);//设置一个大间隔中显示5个小间隔。
    //如果没有设置最大间隔，坐标轴的值会由于拖动，缩放等原因间隔会发生变化。

    //y轴
    qwt->setAxisScaleDraw(QwtPlot::yLeft,new VScaleDraw());
    qwt->setAxisScale(QwtPlot::yLeft,0.0,100.0);
    setAxisTick(qwt);




    //拖动
    new QwtPlotPanner(qwt->canvas());//确定一拖动，坐标轴就变成原来的那种标尺。

    qwt->resize(500,500);
    qwt->show();


#endif

    MainWidget w;
    w.show();

//    for (int var = 0; var < 10; ++var) {
//        qDebug() << qrand()%10;
//        qDebug() << qrand()%10;
//    }

    return a.exec();
}

















