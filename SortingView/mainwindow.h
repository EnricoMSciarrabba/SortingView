#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "customgroupbox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Q_SLOT void subCheckBoxUpdate(Qt::CheckState state);
    Q_SLOT void subStart();
    Q_SLOT void subEnd();

    Q_SLOT void subUpdateCharts();

private:
    Ui::MainWindow *ui;

    int m_threadIsRunning = 0;
    std::vector<int> m_startVector;

    QMap<QString, CustomGroupBox*> m_chartMap;
    QList<QThread*> m_threadList;
};

#endif // MAINWINDOW_H
