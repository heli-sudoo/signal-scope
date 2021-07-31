#ifndef _SIGNAL_DATA_H_
#define _SIGNAL_DATA_H_

#include <qrect.h>
#include <QVector>
class SignalData
{
public:

    SignalData();
    virtual ~SignalData();

    void appendSample(double x, double y);
    void appendSample(QVector<double>&x, QVector<double>&y); // overload appendSample to append QVector
    void updateValues();

    int size() const;
    QPointF value(int index) const;

    double lastSampleTime() const;

    QRectF boundingRect() const;

    void lock();
    void unlock();

    bool hasMessageError() const;
    void flagMessageError();

    void updateInterval(double minTime, double maxTime);

    static int getHistoryLength();
    static void setHistoryLength(int historyLength);

    void clear();

    // computes the min and max values.
    // Note, this function automatically calls lock and unlock.
    QRectF computeBounds();

    // New signal data points per second are calculated using
    // an exponential moving average with a 1 second time window.
    double messageFrequency() const;

private:

    Q_DISABLE_COPY(SignalData);

    class PrivateData;
    PrivateData *d_data;
};

#endif
