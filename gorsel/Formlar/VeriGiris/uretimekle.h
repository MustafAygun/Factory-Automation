#ifndef URETIMEKLE_H
#define URETIMEKLE_H

#include <QDialog>
#include<VeriSiniflari/urun.h>
#include<VeriSiniflari/uretim.h>
#include<VeriSiniflari/calisan.h>

namespace Ui {
class uretimekle;
}

class uretimekle : public QDialog
{
    Q_OBJECT

public:
    explicit uretimekle(QWidget *parent = nullptr);
    ~uretimekle();

    bool degisiklikvarmi() const;
    void setDegisiklikvarmi(bool degisiklikvarmi);
    void gorselguncelle();
    void veriguncelle();
    void uruncomboboxdoldur();
    void calisancomboboxdoldur();

private slots:
    void reject() override;
    void degisti();
    void on_pbKaydet_clicked();

    void on_Calisanekle_linkActivated(const QString &link);

    void on_Urunekle_linkActivated(const QString &link);

private:


    Ui::uretimekle *ui;
    bool _degisiklikvarmi;
   Uretim ::Ptr _uretim;
   Urun::Ptr _urun;
   Calisan::Ptr _calisan;

};

#endif // URETIMEKLE_H
