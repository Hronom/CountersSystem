#include "CountersSystem.h"

#include <QDebug>

CountersSystem* CountersSystem::m_instance = 0;

bool CountersSystem::initialize()
{
    qDebug()<<"Initialize:"<<"CountersSystem";
    m_instance = new CountersSystem();
    return true;
}

void CountersSystem::shutdown()
{
    qDebug()<<"Shutdown:"<<"CountersSystem";
    delete m_instance;
    m_instance = 0;
}

CountersSystem* CountersSystem::instance()
{
    return m_instance;
}

CountersSystem::CountersSystem()
{
}

CountersSystem::~CountersSystem()
{
    while(!m_counters.empty())
    {
        QHash<QString, Counter*>::Iterator iter;
        iter = m_counters.begin();
        delete iter.value();
        m_counters.erase(iter);
    }
}

void CountersSystem::addCounter(const QString &par_name)
{
    if(!m_counters.contains(par_name))
        m_counters.insert(par_name, new Counter());
}

void CountersSystem::removeCounter(const QString &par_name)
{
    Counter *counter;
    counter = m_counters.take(par_name);

    if(counter != 0)
        delete counter;
}

void CountersSystem::removeName(const QString &par_counterName, const QString &par_name)
{
    Counter *counter;
    counter = m_counters.value(par_counterName);

    if(counter != 0)
        counter->removeName(par_name);
}

QString CountersSystem::getNameWithSuffix(const QString &par_counterName, const QString &par_name)
{
    Counter *counter;
    counter = m_counters.value(par_counterName);

    if(counter != 0)
    {
        return counter->getNameWithSuffix(par_name);
    }
    else
    {
        counter = new Counter();
        m_counters.insert(par_counterName, counter);
        return counter->getNameWithSuffix(par_name);
    }
}
