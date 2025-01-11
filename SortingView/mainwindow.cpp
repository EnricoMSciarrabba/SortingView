#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"

#include <algorithm>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inizializzo il vettore
    subUpdateCharts();

    // Connect pulsante start e stop
    connect(ui->start_pushButton, &QPushButton::clicked, this, &MainWindow::subStart);

    // Connect per aggiornamento dimensione array
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::subUpdateCharts);

    // Connect checkBox
    connect(ui->bubblesort,    &QCheckBox::checkStateChanged, this, &MainWindow::subCheckBoxUpdate);
    connect(ui->selectionsort, &QCheckBox::checkStateChanged, this, &MainWindow::subCheckBoxUpdate);
    connect(ui->insertionsort, &QCheckBox::checkStateChanged, this, &MainWindow::subCheckBoxUpdate);
    connect(ui->quicksort,     &QCheckBox::checkStateChanged, this, &MainWindow::subCheckBoxUpdate);
    connect(ui->mergesort,     &QCheckBox::checkStateChanged, this, &MainWindow::subCheckBoxUpdate);
    connect(ui->heapsort,      &QCheckBox::checkStateChanged, this, &MainWindow::subCheckBoxUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::subCheckBoxUpdate(Qt::CheckState state)
{
    QString key = sender()->objectName();
    CustomGroupBox* widget = nullptr;

    // Se è stato selezionato un widget
    if(state == Qt::CheckState::Checked)
    {
        // Controllo quale widget è stato selezionato
        if(key == "bubblesort")
        {
            widget = new BubbleSort(this);
        }
        else if(key == "selectionsort")
        {
            widget = new SelectionSort(this);
        }
        else if(key == "insertionsort")
        {
            widget = new InsertionSort(this);
        }
        else if(key == "quicksort")
        {
            widget = new QuickSort(this);
        }
        else if(key == "mergesort")
        {
            widget = new MergeSort(this);
        }
        else if(key == "heapsort")
        {
            widget = new HeapSort(this);
        }
        else
        {
            return;
        }

        // Inizializzo il vettore
        widget->setData(m_startVector);

        // Nascondo la label
        ui->notice_label->setVisible(false);

        // Aggiungo il widget alla mappa
        m_chartMap.insert(key, widget);

        // Aggiungo il widget al layout
        ui->charts->layout()->addWidget(widget);
    }

    // Altrimenti è stato deselezionato
    else
    {
        // Recupero il widget
        widget = m_chartMap.take(key);

        // Rimuovo il widget dal layout
        ui->charts->layout()->removeWidget(widget);

        // Elimino il widget
        delete widget;

        // Se non ci sono più widget selezionati
        if(m_chartMap.size() == 0)
        {
            ui->notice_label->setVisible(true);
        }
    }
}

void MainWindow::subStart()
{
    // Disabilito la box
    ui->groupBox_2->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);

    // Gestione pulsanti
    ui->start_pushButton->setEnabled(false);

    // Avvio i vari algoritmi su thread diversi
    QList<QString> keys = m_chartMap.keys();
    QThread* thread_t;
    for(const QString& key : keys)
    {
        // Eseguo il sort su un Thread
        thread_t = QThread::create([=]{
            m_chartMap.value(key)->sort();
        });

        // Aggiungo il thread alla lista
        m_threadList.append(thread_t);

        // Connect per quando il thread termina
        connect(thread_t, &QThread::finished, this,     &MainWindow::subEnd);
        connect(thread_t, &QThread::finished, thread_t, &QThread::deleteLater);

        // Avvio il Thread
        thread_t->start();

        m_threadIsRunning++;
    }
}

void MainWindow::subEnd()
{
    m_threadIsRunning--;

    if(m_threadIsRunning == 0)
    {
        // Abilito la box
        ui->groupBox_2->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);

        // Gestione pulsanti
        ui->start_pushButton->setEnabled(true);
    }
}

void MainWindow::subUpdateCharts()
{
    // Clear dell'array attuale
    m_startVector.clear();

    // Recupero la nuova dimensione
    int newSize = ui->horizontalSlider->value();

    // Riempio con i nuovi valori
    for(int index=0; index<newSize; index++)
    {
        m_startVector.push_back(index+1);
    }

    // Inizializzo un generatore casuale
    std::random_device rd;
    std::mt19937 g(rd());

    // Mescolo il vettore
    std::shuffle(m_startVector.begin(), m_startVector.end(), g);

    // Aggiorno tutti i Charts
    QList<QString> keys = m_chartMap.keys();
    for(const QString& key : keys)
    {
        m_chartMap.value(key)->setData(m_startVector);
        m_chartMap.value(key)->updateChart();
    }
}
