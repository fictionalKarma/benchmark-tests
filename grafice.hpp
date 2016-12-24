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
    /* 
	graficBare afiseaza graficele comparand performanta produsului firmei cu etalonul/alta firma
    */
    void graficCheltuieli();
    /*
	graficCheltuieli afiseaza graficele cheltuielilor a doua firme, asezate in comparatie
    */

private:
    Ui::Grafice *ui;
};

#endif // GRAFICE_H
