#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "customgroupbox.h"

class HeapSort : public CustomGroupBox
{
public:
    HeapSort(QWidget* parent = nullptr);

    void sort() override;

private:
    // Funzione che "affonda" il nodo per mantenere la proprietà di heap
    void heapify(std::vector<int>& arr, int n, int i);

    // Funzione principale per HeapSort
    void heapSort(std::vector<int>& arr);

};

#endif // HEAPSORT_H
