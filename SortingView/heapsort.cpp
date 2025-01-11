#include "heapsort.h"

#include <QThread>

HeapSort::HeapSort(QWidget* parent)
    : CustomGroupBox(parent)
{
    setTitle("Heap Sort");
}

void HeapSort::sort()
{
    heapSort(m_data);
}

void HeapSort::heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i; // Inizialmente assumiamo che il nodo corrente sia il più grande
    int left = 2 * i + 1; // Figlio sinistro
    int right = 2 * i + 2; // Figlio destro

    // Se il figlio sinistro è più grande del nodo corrente
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Se il figlio destro è più grande del nodo corrente
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Se il più grande non è il nodo corrente
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]); // Scambio ottimizzato con move
        emit pubValueChanged(i, largest); // Emissione del segnale per tracciare lo scambio
        QThread::usleep(1);

        // Ricorsivamente heapify il sottoalbero
        heapify(arr, n, largest);
    }
}

void HeapSort::heapSort(std::vector<int> &arr)
{
    int n = arr.size();

    // Costruisci l'heap (ristruttura l'array in un heap)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Estrai gli elementi uno alla volta dall'heap
    for (int i = n - 1; i > 0; i--)
    {
        // Sposta la radice corrente alla fine (array ordinato)
        std::swap(arr[0], arr[i]);
        emit pubValueChanged(0, i); // Emissione del segnale per tracciare lo scambio
        QThread::usleep(1);

        // Richiama heapify sull'heap ridotto
        heapify(arr, i, 0);
    }
}
