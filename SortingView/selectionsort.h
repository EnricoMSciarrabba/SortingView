#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "customgroupbox.h"

class SelectionSort : public CustomGroupBox
{
    Q_OBJECT
public:
    SelectionSort(QWidget* parent = nullptr);

    void sort() override;
};

#endif // SELECTIONSORT_H
