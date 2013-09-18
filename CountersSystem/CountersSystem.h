#ifndef COUNTERSSYSTEM_H
#define COUNTERSSYSTEM_H

#include "Counter.h"

#include <QHash>
#include <QString>

class CountersSystem
{
private:
    static CountersSystem* m_instance;

    QHash<QString, Counter*> m_counters;

public:
    static bool initialize();
    static void shutdown();
    static CountersSystem* instance();

private:
    CountersSystem();
    ~CountersSystem();

public:
    void addCounter(QString par_name);
    void removeCounter(QString par_name);

    void removeName(QString par_counterName, QString par_name);
    QString getNameWithSuffix(QString par_counterName, QString par_name);
};

#endif
