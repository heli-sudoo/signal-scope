#ifndef _PYTHONSIGNALHANDLER_H_
#define _PYTHONSIGNALHANDLER_H_

#include "signalhandler.h"
#include "signaldescription.h"
#include "signaldata.h"
#include <QVector>
#include <PythonQt.h>

class SignalData;
class SignalDescription;

class PythonSignalHandler : public SignalHandler
{
  Q_OBJECT

public:
  PythonSignalHandler(SignalDescription *signalDescription, PythonQtObjectPtr callback) : SignalHandler(signalDescription)
  {
    mCallback = callback;
  }

  virtual QString description()
  {
    return mDescription.mFieldName;
  }

  void onNewMessage(const QVariant &message)
  {
    double timeNow;
    double signalValue;
    QVector<double> timeSeq;
    QVector<double> signalSeq;

    if (!mDescription.mSignalSeq) // if a signal, append it to the list
    {
      bool valid = this->extractSignalData(message, timeNow, signalValue);
      if (valid)
      {
        mSignalData->appendSample(timeNow, signalValue);
      }
      else
      {
        mSignalData->flagMessageError();
      }
    }
    else // if a signal sequence, clear the original list and append the new one
    {
      bool valid = this->extractSignalData(message, timeSeq, signalSeq);
      if (valid)
      {
        mSignalData->clear();
        mSignalData->appendSample(timeSeq, signalSeq);
      }
      else
      {
        mSignalData->flagMessageError();
      }
      
    }

  }

  virtual bool extractSignalData(const QVariant &message, double &timeNow, double &signalValue)
  {
    QVariantList args;
    args << message;

    QVariant result = PythonQt::self()->call(mCallback, args);
    QList<QVariant> values = result.toList();
    if (values.size() == 2)
    {
      timeNow = SignalHandlerFactory::instance().getOffsetTime(static_cast<int64_t>(values[0].toDouble() * 1e6));
      signalValue = values[1].value<double>();
      //std::cout << timeNow << ", " << signalValue << std::endl;
      return true;
    }
    else
    {
      return false;
    }

    return true;
  }

  // Overload extractSignalData to hold signal sequence
  virtual bool extractSignalData(const QVariant &message, QVector<double> &timeSeq, QVector<double> &signalSeq)
  {
    QVariantList args;
    args << message; // message includes the LCM-type info

    QVariant result = PythonQt::self()->call(mCallback, args);
    QList<QVariant> values = result.toList();

    if (values.size() == 2)
    {
      QList<QVariant> timeList = values[0].toList();
      QList<QVariant> signalList = values[1].toList();
      if (timeList.length() != signalList.length())
      {
        printf("length of timeSeq and signalSeq doesn't match \n");
        return false;
      }

      for (int i = 0; i < timeList.length(); i++)
      {
        timeSeq.append(SignalHandlerFactory::instance().getOffsetTime(static_cast<int64_t>(timeList[i].toDouble() * 1e6)));
        signalSeq.append(signalList[i].value<double>());
      }

      return true;
    }
    else
    {
      return false;
    }

    return true;
  }

  virtual bool extractSignalData(const lcm::ReceiveBuffer *rbuf, double &timeNow, double &signalValue)
  {
    return false;
  }

protected:
  PythonQtObjectPtr mCallback;
};

#endif
