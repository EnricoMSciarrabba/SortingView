#include "mergesort.h"

#include <QThread>

MergeSort::MergeSort(QWidget* parent)
    : CustomGroupBox(parent)
{
    setTitle("Merge Sort");
}

void MergeSort::sort()
{
    mergeSort(m_data, 0, m_data.size()-1);
}

void MergeSort::merge(std::vector<int> &arr, int left, int mid, int right)
{
    // Creare i vettori temporanei per le due metà
    std::vector<int> leftVec(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightVec(arr.begin() + mid + 1, arr.begin() + right + 1);

    // Indici per il traversamento dei vettori temporanei
    size_t i = 0, j = 0, k = left;

    // Unire gli array temporanei
    while (i < leftVec.size() && j < rightVec.size())
    {
        if (leftVec[i] <= rightVec[j])
        {
            arr[k] = std::move(leftVec[i]); // Usare std::move per spostare
            ++i;
        }
        else
        {
            arr[k] = std::move(rightVec[j]); // Usare std::move per spostare
            emit pubValueChanged(k, rightVec[j]);
            QThread::usleep(1);
            ++j;
        }
        ++k;
    }

    // Copiare gli elementi rimanenti da leftVec, se ce ne sono
    while (i < leftVec.size())
    {
        arr[k] = std::move(leftVec[i]); // Usare std::move per spostare
        ++i;
        ++k;
    }

    // Copiare gli elementi rimanenti da rightVec, se ce ne sono
    while (j < rightVec.size())
    {
        arr[k] = std::move(rightVec[j]); // Usare std::move per spostare
        emit pubValueChanged(k, rightVec[j]);
        QThread::usleep(1);
        ++j;
        ++k;
    }
}

void MergeSort::mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Calcolare il punto medio

        // Ordinare la prima e la seconda metà
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Unire le due metà
        merge(arr, left, mid, right);
    }
}
