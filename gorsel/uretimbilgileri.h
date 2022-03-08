#ifndef URETIMBILGILERI_H
#define URETIMBILGILERI_H

#include <QDialog>

namespace Ui {
class uretimBilgileri;
}

class uretimBilgileri : public QDialog
{
    Q_OBJECT

public:
    explicit uretimBilgileri(QWidget *parent = nullptr);
    ~uretimBilgileri();

private:
    Ui::uretimBilgileri *ui;
};

#endif // URETIMBILGILERI_H
