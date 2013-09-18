#include "CountersSystem.h"

#include <QDebug>

CountersSystem* CountersSystem::m_instance = NULL;

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
    m_instance = NULL;
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

void CountersSystem::addCounter(QString par_name)
{
    if(!m_counters.contains(par_name))
        m_counters.insert(par_name, new Counter());
}

void CountersSystem::removeCounter(QString par_name)
{
    if(!m_counters.contains(par_name))
        delete m_counters.take(par_name);
}

void CountersSystem::removeName(QString par_counterName, QString par_name)
{
    if(m_counters.contains(par_counterName))
    {
        Counter *counter;
        counter = m_counters.value(par_counterName);
        counter->removeName(par_name);
    }
}

QString CountersSystem::getNameWithSuffix(QString par_counterName, QString par_name)
{
    if(m_counters.contains(par_counterName))
        return m_counters.value(par_counterName)->getNameWithSuffix(par_name);
    else
    {
        m_counters.insert(par_counterName, new Counter());
        return m_counters.value(par_counterName)->getNameWithSuffix(par_name);
    }
}
