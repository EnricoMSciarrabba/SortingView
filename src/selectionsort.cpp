#include "selectionsort.h"

#include <QThread>

SelectionSort::SelectionSort(QWidget* parent)
    : CustomGroupBox(parent)
{
    // Imposto il titolo
    setTitle("Selection Sort");
}

void SelectionSort::sort()
{
    int n = m_data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (m_data[j] < m_data[minIndex]) {
                minIndex = j;
            }
        }
        // Scambia l'elemento corrente con il minimo trovato
        std::swap(m_data[i], m_data[minIndex]);

        // Qui potresti richiamare un metodo per aggiornare il grafico
        emit pubValueChanged(i, minIndex);

        QThread::usleep(1);
    }
}
