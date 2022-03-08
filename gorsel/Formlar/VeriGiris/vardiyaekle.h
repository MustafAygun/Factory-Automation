#ifndef VARDIYAEKLE_H
#define VARDIYAEKLE_H

#include <QDialog>

namespace Ui {
class vardiyaekle;
}

class vardiyaekle : public QDialog
{
    Q_OBJECT

public:
    explicit vardiyaekle(QWidget *parent = nullptr);
    ~vardiyaekle();

private:
    Ui::vardiyaekle *ui;
};

#endif // VARDIYAEKLE_H
