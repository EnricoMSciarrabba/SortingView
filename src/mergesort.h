#ifndef MERGESORT_H
#define MERGESORT_H

#include "customgroupbox.h"

class MergeSort : public CustomGroupBox
{
public:
    MergeSort(QWidget* parent = nullptr);

    void sort() override;

private:
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void mergeSort(std::vector<int>& arr, int left, int right);
};

#endif // MERGESORT_H
