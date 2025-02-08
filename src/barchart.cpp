#include "barchart.h"

#include <QPainter>

BarChartWidget::BarChartWidget(QWidget *parent)
    : QWidget(parent)
{
    // SizePolicy
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

void BarChartWidget::setData(std::vector<int>* data)
{
    m_data = data;
    update();
}

void BarChartWidget::subUpdateBar(const int& index1, const int& index2)
{
    // Controlla se gli indici sono validi
    if (index1 >= 0 && index1 < static_cast<int>(m_data->size()) &&
        index2 >= 0 && index2 < static_cast<int>(m_data->size()))
    {
        update();
    }
}

void BarChartWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    double barWidth = static_cast<double>(size().width()) / static_cast<double>(m_data->size()); // Larghezza di ogni barra
    double maxValue = *std::max_element(m_data->begin(), m_data->end()); // Trova il valore massimo

    for (size_t i = 0; i < m_data->size(); ++i)
    {
        // Calcola l'altezza della barra
        double barHeight = static_cast<double>((*m_data)[i]) / maxValue * static_cast<double>(size().height());

        // Disegna la barra
        painter.setBrush(Qt::white); // Colore della barra
        painter.drawRect(static_cast<double>(i) * barWidth,
                         static_cast<double>(size().height()) - barHeight,
                         barWidth - 2.,
                         barHeight);
    }
}
