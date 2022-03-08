#ifndef CALISANEKLE_H
#define CALISANEKLE_H
#include <VeriSiniflari/calisan.h>
#include <QDialog>

namespace Ui {
class calisanekle;
}

class calisanekle : public QDialog
{
    Q_OBJECT

public:
    explicit calisanekle(QWidget *parent = nullptr);
    ~calisanekle();

    bool degisiklikvar() const;
    void setDegisiklikvar(bool degisiklikvar);
public slots:
    void gorseldegisti();
    void reject() override;
private slots:
    void on_kaydet_clicked();

private:
    void gorselGuncelle();
    void veriGuncelle();
    Ui::calisanekle *ui;
    Calisan::Ptr _calisan;

    bool _degisiklikvar;
};

#endif // CALISANEKLE_H
