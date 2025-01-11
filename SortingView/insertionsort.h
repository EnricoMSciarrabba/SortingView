#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "customgroupbox.h"

class InsertionSort : public CustomGroupBox
{
    Q_OBJECT
public:
    InsertionSort(QWidget* parent = nullptr);

    void sort() override;
};

#endif // INSERTIONSORT_H
