#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rest_network.h"
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    rest_network dataTest;
public slots:
    void tele_op();
    void semi_auto();
    void full_auto();
    void stop();
    void update();
};

#endif // MAINWINDOW_H
