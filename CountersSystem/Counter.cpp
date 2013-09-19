#include "Counter.h"

#include <QString>

Counter::Counter()
{
    m_values.insert(0, "");
}

Counter::~Counter()
{

}

void Counter::removeName(const QString &par_name)
{
    QHash<qint64, QString>::Iterator iter;
    iter = m_values.begin();
    while(iter != m_values.end())
    {
        if(iter.value() == par_name)
        {
            iter.value() = "";
            break;
        }

        ++iter;
    }
}

QString Counter::getNameWithSuffix(const QString &par_name)
{
    QHash<qint64, QString>::Iterator iter;
    iter = m_values.begin();
    while(iter != m_values.end())
    {
        if(iter.value() == "")
        {
            QString nameWithSuffix;
            nameWithSuffix = par_name + QString::number(iter.key());
            iter.value() = nameWithSuffix;
            return nameWithSuffix;
        }

        ++iter;
    }

    qint64 value;
    value = m_values.size();
    QString nameWithSuffix;
    nameWithSuffix = par_name + QString::number(value);
    m_values.insert(value, nameWithSuffix);
    return nameWithSuffix;
}
