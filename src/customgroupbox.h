#ifndef CUSTOMGROUPBOX_H
#define CUSTOMGROUPBOX_H

#include <QGroupBox>

#include "algointerface.h"
#include "barchart.h"

class CustomGroupBox : public QGroupBox, public AlgoInterface
{
    Q_OBJECT
public:
    CustomGroupBox(QWidget* parent = nullptr);
    virtual ~CustomGroupBox(){};

    // Segnale da lanciare quando vengono aggiornati gli array
    Q_SIGNAL void pubValueChanged(const int& index1, const int& index2);

    void updateChart();

protected:
    BarChartWidget* m_chart;
};

#endif // CUSTOMGROUPBOX_H
