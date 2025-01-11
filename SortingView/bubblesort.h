#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "customgroupbox.h"

class BubbleSort : public CustomGroupBox
{
    Q_OBJECT
public:
    BubbleSort(QWidget* parent = nullptr);

    void sort() override;
};

#endif // BUBBLESORT_H
