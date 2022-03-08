#ifndef URUNEKLE_H
#define URUNEKLE_H
#include<VeriSiniflari/urun.h>
#include <QDialog>

namespace Ui {
class urunekle;
}

class urunekle : public QDialog
{
    Q_OBJECT

public:
    explicit urunekle(QWidget *parent = nullptr);
    ~urunekle();

    bool degisiklikvarmi() const;
    void gorselGuncelle();
    void veriGuncelle();

private slots:
    void on_Kaydet_clicked();
    void setDegisiklikvarmi(bool degisiklikvarmi);
    void degisti();

    void reject() override;
private:
    Ui::urunekle *ui;
    bool _degisiklikvarmi;
   Urun::Ptr _Urun;
};

#endif // URUNEKLE_H
