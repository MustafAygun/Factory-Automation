#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 public slots:
    virtual void close();
private slots:
    void on_actionyeni_calisan_ekle_triggered();

    void on_actionurun_ekle_triggered();

    void on_actionvardiya_ekle_triggered();

    void on_actionuretim_ekle_triggered();

    void on_actionkaydet_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
