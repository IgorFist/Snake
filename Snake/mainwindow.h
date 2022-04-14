#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fieldview.h"
#include "fieldmodel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QSettings;
class QLCDNumber;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateBestScore(int);
private:
    QSettings *m_setting;
    QLCDNumber *m_lcdBestScore;
    int m_bestScore;

};
#endif // MAINWINDOW_H
