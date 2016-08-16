#ifndef TIMESCALEDRAW_H
#define TIMESCALEDRAW_H

#include <QTime>

#include <Qwt/qwt_text.h>
#include <Qwt/qwt_scale_draw.h>
#include <Qwt/qwt_scale_div.h>
#include <Qwt/qwt_scale_engine.h>

#include <Qwt/qwt_text.h>


class TimeScaleDraw : public QwtScaleDraw//一个用于绘制刻度的类
{
public:
    TimeScaleDraw()
    {

    }
    TimeScaleDraw(const QTime & base ) :baseTime(base)
    {

    }

    virtual QwtText label(double v) const//这个v可能和数字类型的engine算出来的v不相同,   v相同，不同的是，v的基数为 QDateTime::currentDateTime().toTime_t()的返回值
    {
         QTime upTime = baseTime.addSecs(static_cast<int>(v));
         return upTime.toString("mm:ss");
    }

private:
    QTime baseTime;
};

class VScaleDraw:public QwtScaleDraw
{
public:
    VScaleDraw()
    {

    }

    virtual QwtText label(double v) const //这个v可能是由engine算出来的一个值。  这个v是engine自动算出的一个值，且这个值就是当前大间隔和下一个大间隔之间的差值。
    {
        return QwtText(QString::number(v));
    }
};


#endif // TIMESCALEDRAW_H
