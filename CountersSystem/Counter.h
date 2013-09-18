#ifndef COUNTER_H
#define COUNTER_H

#include <QHash>
#include <qglobal.h>

class Counter
{
private:
    // Value - Key
    QHash<qint32, QString> m_values;

public:
    Counter();
    ~Counter();

    void removeName(QString par_name);
    QString getNameWithSuffix(QString par_name);
};

#endif
