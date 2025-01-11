#include "insertionsort.h"

#include <QThread>

InsertionSort::InsertionSort(QWidget* parent)
    : CustomGroupBox(parent)
{
    // Imposto il titolo
    setTitle("Insertion Sort");
}

void InsertionSort::sort()
{
    for (size_t i = 1; i < m_data.size(); ++i)
    {
        // Usare std::move per trasferire l'elemento invece di copiarlo
        int temp = std::move(m_data[i]);
        size_t j = i;

        // Spostare gli elementi che sono maggiori di temp verso destra
        while (j > 0 && m_data[j - 1] > temp)
        {
            m_data[j] = std::move(m_data[j - 1]); // Usare std::move per spostare gli elementi
            --j;

            emit pubValueChanged(j, j-1);

            QThread::usleep(1);
        }

        // Posizionare temp nella sua posizione corretta
        m_data[j] = std::move(temp);
    }
}
