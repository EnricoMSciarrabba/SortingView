#include "customgroupbox.h"

#include <QBoxLayout>

CustomGroupBox::CustomGroupBox(QWidget *parent)
    : QGroupBox(parent)
{
    // Inizializzo il BarChart
    m_chart = new BarChartWidget(this);

    // Inserisco il grafico dentro
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::Direction::TopToBottom, this);
    layout->addWidget(m_chart);

    // Aggancio i dati al grafico
    m_chart->setData(&m_data);

    // Imposto una size minima
    setMinimumSize(500, 200);

    // Connect per aggiornamento grafico
    connect(this, &CustomGroupBox::pubValueChanged, m_chart, &BarChartWidget::subUpdateBar);
}

void CustomGroupBox::updateChart()
{
    m_chart->update();
}
