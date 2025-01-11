#include "quicksort.h"

#include <QThread>

QuickSort::QuickSort(QWidget* parent)
    : CustomGroupBox(parent)
{
    setTitle("Quick Sort");
}

void QuickSort::sort()
{
    quickSort(m_data, 0, m_data.size()-1);
}

int QuickSort::partition(std::vector<int> &arr, int low, int high)
{
    // Scegli il pivot (prendiamo l'ultimo elemento)
    int pivot = std::move(arr[high]); // Usare std::move per spostare il pivot
    int i = low - 1; // Indice del più piccolo elemento

    for (int j = low; j < high; ++j)
    {
        // Se l'elemento corrente è minore o uguale al pivot
        if (arr[j] <= pivot)
        {
            ++i; // Incrementa l'indice del più piccolo elemento
            std::swap(arr[i], arr[j]); // Usa swap per scambiare
            emit pubValueChanged(i, j);
            QThread::usleep(1);
        }
    }
    std::swap(arr[i + 1], arr[high]); // Posiziona il pivot nella giusta posizione
    emit pubValueChanged(i+1, high);
    QThread::usleep(1);
    return i + 1; // Restituisci l'indice del pivot
}

void QuickSort::quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partiziona l'array
        int pi = partition(arr, low, high);

        // Ordinare gli elementi prima e dopo la partizione
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
