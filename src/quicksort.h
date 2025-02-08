#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "customgroupbox.h"

class QuickSort : public CustomGroupBox
{
public:
    QuickSort(QWidget* parent = nullptr);

    void sort() override;

private:
    int partition(std::vector<int>& arr, int low, int high);
    void quickSort(std::vector<int>& arr, int low, int high);
};

#endif // QUICKSORT_H
