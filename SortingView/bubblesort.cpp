#include "bubblesort.h"

#include <QThread>

BubbleSort::BubbleSort(QWidget* parent)
    : CustomGroupBox(parent)
{
    // Imposto il titolo
    setTitle("Bubble Sort");
}

void BubbleSort::sort()
{
    int size = m_data.size();
    bool swapped;

    // Ciclo attraverso tutti gli elementi
    for (int index_i = 0; index_i < size - 1; ++index_i)
    {
        swapped = false;

        // Ultimi i elementi già ordinati
        for (int index_j = 0; index_j < size - index_i - 1; ++index_j)
        {
            // Usa std::move per scambiare i valori
            if (m_data[index_j] > m_data[index_j + 1])
            {
                std::swap(m_data[index_j], m_data[index_j + 1]);
                swapped = true;

                emit pubValueChanged(index_j, index_j + 1);

                QThread::usleep(1);
            }
        }

        // Se non ci sono stati scambi, l'array è già ordinato
        if (!swapped) {
            break;
        }
    }
}
