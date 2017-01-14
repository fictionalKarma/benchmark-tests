#ifndef GRAFICE_H
#define GRAFICE_H

#include <QMainWindow>

namespace Ui {
class Grafice;
}

class Grafice : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grafice(QWidget *parent = 0);
    ~Grafice();

    void graficBare();
    // graficBare creeaza graficul de comparatie a performantelor intre etalon si o firma sau intre doua firme
    void graficCheltuieli();
    // graficCheltuieli creeaza graficul de comparatie a cheltuielilor dintre doua firme

private:
    Ui::Grafice *ui;
};

#endif // GRAFICE_H
