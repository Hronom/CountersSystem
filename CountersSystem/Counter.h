#ifndef COUNTER_H
#define COUNTER_H

#include <QHash>
#include <qglobal.h>

class Counter
{
private:
    // Value - Key
    QHash<qint64, QString> m_values;

public:
    Counter();
    ~Counter();

    void removeName(const QString &par_name);
    QString getNameWithSuffix(const QString &par_name);
};

#endif
