#include "mainwidget.h"

static float sCOMData = 0;

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *vBox = new QVBoxLayout(this);

    isKillTimer = false;

    //图表属性设置
    qwt  = new QwtPlot();
    qwt->setTitle("same plot");
    qwt->setCanvasBackground(QBrush(Qt::white));
    qwt->setAutoReplot();
    qwt->insertLegend(new QwtLegend());//不明嚼栗
    //坐标轴

    //x轴
    qwt->setAxisScaleDraw(QwtPlot::xBottom,new TimeScaleDraw());//画刻度

    qwt->setAxisMaxMajor(QwtPlot::xBottom,10);//设置坐标轴的最大间隔为10，也就是将一屏的刻度分为10个大间隔。
    qwt->setAxisMaxMinor(QwtPlot::xBottom,5);//设置一个大间隔中显示1个小间隔，即不显示小刻度线。
    //如果没有设置最大间隔，坐标轴的值会由于拖动，缩放等原因间隔会发生变化。

    qwt->setAxisLabelRotation( QwtPlot::xBottom, -50.0 );
    qwt->setAxisLabelAlignment( QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom );

    //y轴
    qwt->setAxisScaleDraw(QwtPlot::yLeft,new VScaleDraw());//画刻度
    setAxisTick();

    //曲线
    curve = new QwtPlotCurve();
    curve->attach(qwt);
    //网格标记
    QwtSymbol * symbol = new QwtSymbol(
                QwtSymbol::Rect,
                QBrush(QColor("red")),
                QPen(QColor("blue")),
                QSize(10,10)
                );
    curve->setSymbol(symbol);//设置标记与曲线中，和表格无关系，与你填充的数据点有关

    //拖动
    new QwtPlotPanner(qwt->canvas());//一拖动，坐标轴就变成原来的那种标尺。原因没有设置坐标轴的大间隔和小间隔
//    new QwtPlotZoomer(qwt->canvas()); //缩放


    //计时器
    startTimer(1000);
    Current_time_t = QDateTime::currentDateTime().toTime_t();
    //添加图表
    vBox->addWidget(qwt);

    btn_open = new QPushButton("Open");
    connect(btn_open,SIGNAL(clicked()),this,SLOT(OpenCOMSlot()));
    btn_close = new QPushButton("Close");
    connect(btn_close,SIGNAL(clicked()),this,SLOT(CloseCOMSlot()));

    vBox->addWidget(btn_open);
    vBox->addWidget(btn_close);


    btn_close->setEnabled(false);

}

void MainWidget::timerEvent(QTimerEvent *e)
{
    if(isKillTimer){
       killTimer(e->timerId());
    }

    //设置刻度范围
    qwt->setAxisScale(QwtPlot::xBottom,Current_time_t-50,Current_time_t,5);

    //填充曲线数据

    static QPolygonF points;
#if 0
    points << QPointF(Current_time_t-10,qrand()%10);
#elif 1
    if(!(points.size() == 0) ) {
        qDebug() << points.last() << sCOMData;
        if(points.last().y() == (double)sCOMData){
           return;
        }else{

        }
    }
    points << QPointF(Current_time_t-10,sCOMData);
#endif
    curve->setSamples(points);

    //更新时间数据
    ++Current_time_t;
}

//打开串口槽
void MainWidget::OpenCOMSlot( )
{
   serialThread = new SerialThread("/dev/ttyS1");
   connect(serialThread,SIGNAL(sendData(float)),this,SLOT(recvData(float)));

   serialThread->start();

   btn_open->setEnabled(false);
   btn_close->setEnabled(true);
}

//关闭串口槽
void MainWidget::CloseCOMSlot()
{
    serialThread->deleteLater();
    isKillTimer = true;

    btn_open->setEnabled(true);
    btn_close->setEnabled(false);
}

//接受串口数据槽
void MainWidget::recvData(float data)
{
    qDebug() << data;
    sCOMData = data/20;
}

//设置轴刻度
void MainWidget::setAxisTick()
{
    QList<double> ticks[QwtScaleDiv::NTickTypes];
    ticks[QwtScaleDiv::MajorTick] << 0 << 10;
    for (int i = 0; i < 10; ++i) {
        ticks[QwtScaleDiv::MajorTick] << i;
    }
    QwtScaleDiv scaleDiv(
                ticks[QwtScaleDiv::MajorTick].first(),
            ticks[QwtScaleDiv::MajorTick].last()+1 ,
            ticks
            );
//    qDebug() << ticks << ticks[QwtScaleDiv::MajorTick] << ticks[QwtScaleDiv::MediumTick]<< ticks[QwtScaleDiv::MinorTick];
    qwt->setAxisMaxMajor(QwtPlot::yLeft,10);
    qwt->setAxisMaxMinor(QwtPlot::yLeft,0);
    qwt->setAxisScaleDiv(QwtPlot::yLeft,scaleDiv);
//    setTickStyle();
}

//设置轴刻度的风格
void MainWidget::setTickStyle()
{
    for (int i = 0; i < QwtPlot::axisCnt; ++i) {
        QwtScaleWidget * scaleWidget = qwt->axisWidget(i); //QwtScaleWidget : A Widget which contains a scale  axisWidget : Scale widget of the specified axis, or NULL if axisId is invalid.
        if(scaleWidget){
            scaleWidget->setMargin(10);//用于设置刻度的横线与坐标轴的距离。
        }
        QwtScaleDraw * scaleDraw = qwt->axisScaleDraw(i);

        if ( scaleDraw ){
            scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, true ); //设置刻度值样式   true表示禁用 false表示可用
            /*
             *三种格式设置了默认的刻度值样式
*/
        }
    }
    //设置对齐画布、坐标轴、刻度
    qwt->plotLayout()->setAlignCanvasToScales( true );


    /**
      axisWidget返回一个刻度的
*/
}






















