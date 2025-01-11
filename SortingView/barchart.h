#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>

class BarChartWidget : public QWidget
{
    Q_OBJECT
public:
    BarChartWidget(QWidget *parent = nullptr);
    virtual ~BarChartWidget(){};

    // Set
    void setData(std::vector<int>* data);

    // Swap di due barre
    Q_SLOT void subUpdateBar(const int& index1, const int& index2);

protected:
    // Override
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<int>* m_data;
};

#endif // BARCHART_H
