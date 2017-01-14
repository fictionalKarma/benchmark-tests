#include "grafice.h"
#include "ui_grafice.h"

Grafice::Grafice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Grafice)
{
    ui->setupUi(this);
}

void Grafice::graficBare() {
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->grafic->setBackground(QBrush(gradient));

        // create empty bar chart objects:
    QCPBars *firma2 = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    QCPBars *firma1 = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    //QCPBars *firma2 = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    firma2->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    firma1->setAntialiased(false);
    //firma3->setAntialiased(false);
    firma2->setStackingGap(1);
    firma1->setStackingGap(1);
    //firma3->setStackingGap(1);
        // set names and colors:
    //firma3->setName("firma3");
    //firma3->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    //firma3->setBrush(QColor(111, 9, 176));
    firma1->setName("Firma1 cu Nume Foarte Interesant");
    firma1->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    firma1->setBrush(QColor(250, 170, 20));
    firma2->setName("Firma2 cu Nume mai Modern si Smecher Tare");
    firma2->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    firma2->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    //firma1->moveAbove(firma3);
    //firma2->moveAbove(firma1);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8;
    labels << "Crit1" << "Crit2" << "Crit3" << "CRITERIU 4" << "Crit5FoarteLung" << "Crit6" << "Crit7" << "Crit8_TEST";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->grafic->xAxis->setTicker(textTicker);
    ui->grafic->xAxis->setTickLabelRotation(30);
    ui->grafic->xAxis->setSubTicks(false);
    ui->grafic->xAxis->setTickLength(0, 7);
    ui->grafic->xAxis->setRange(0, 9);
    ui->grafic->xAxis->setBasePen(QPen(Qt::white));
    ui->grafic->xAxis->setTickPen(QPen(Qt::white));
    ui->grafic->xAxis->grid()->setVisible(true);
    ui->grafic->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->grafic->xAxis->setTickLabelColor(Qt::white);
    ui->grafic->xAxis->setLabelColor(Qt::white);
    ui->grafic->xAxis->setLabel("Criterii de comparatie");

    // prepare y axis:
    ui->grafic->yAxis->setRange(0, 135);
    ui->grafic->yAxis->setPadding(5); // a bit more space to the left border
    ui->grafic->yAxis->setLabel("Nivel performanta");
    ui->grafic->yAxis->setBasePen(QPen(Qt::white));
    ui->grafic->yAxis->setTickPen(QPen(Qt::white));
    ui->grafic->yAxis->setSubTickPen(QPen(Qt::white));
    ui->grafic->yAxis->grid()->setSubGridVisible(true);
    ui->grafic->yAxis->setTickLabelColor(Qt::white);
    ui->grafic->yAxis->setLabelColor(Qt::white);
    ui->grafic->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->grafic->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QCPBarsGroup *group1 = new QCPBarsGroup(ui->grafic);
    QVector<double> /*firma3Data,*/ firma1Data, firma2Data;
    //firma3Data  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    firma1Data << 87 << 78 << 89 << 95 << 99 << 65 << 105 << 45;
    firma2Data << 82 << 70 << 76 << 85 << 106 << 94 << 97 << firma1Data.last()+3;
    //firma3->setData(ticks, firma3Data);
    firma1->setData(ticks, firma1Data);
    firma1->setWidth(0.3);
    firma1->setBarsGroup(group1);
    firma2->setData(ticks, firma2Data);
    firma2->setWidth(0.3);
    firma2->setBarsGroup(group1);

    // setup legend:
    ui->grafic->legend->setVisible(true);
    ui->grafic->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    ui->grafic->legend->setBrush(QColor(255, 255, 255, 100));
    ui->grafic->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->grafic->legend->setFont(legendFont);
    ui->grafic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    /*QVector<double> datax = QVector<double>() << 1 << 2 << 3 << 4;
    QVector<double> datay1 = QVector<double>() << 0.6 << 0.5 << 0.3 << 0.15;
    QVector<double> datay2 = QVector<double>() << 0.3 << 0.28 << 0.2 << 0.1;
    QVector<double> datay3 = QVector<double>() << 0.33 << 0.31 << 0.27 << 0.13;
    QCPBarsGroup *group1 = new QCPBarsGroup(ui->grafic);
    QCPBars *bars = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    bars->setData(datax, datay1);
    bars->setBrush(QColor(0, 0, 255, 50));
    bars->setPen(QColor(0, 0, 255));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);
    bars = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    bars->setData(datax, datay2);
    bars->setBrush(QColor(180, 00, 120, 50));
    bars->setPen(QColor(180, 00, 120));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);
    bars = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    bars->setData(datax, datay3);
    bars->setBrush(QColor(255, 154, 0, 50));
    bars->setPen(QColor(255, 154, 0));
    bars->setWidth(0.15);
    bars->setBarsGroup(group1);
    ui->grafic->xAxis->setRange(0.1, 4.9);
    ui->grafic->yAxis->setRange(0, 0.7);*/
}

void Grafice::graficCheltuieli() {
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->grafic->setBackground(QBrush(gradient));

        // create empty bar chart objects:
    QCPBars *firma1 = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    QCPBars *firma2 = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    QCPBars *firma3 = new QCPBars(ui->grafic->xAxis, ui->grafic->yAxis);
    firma2->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    firma1->setAntialiased(false);
    firma3->setAntialiased(false);
    firma2->setStackingGap(1);
    firma1->setStackingGap(1);
    firma3->setStackingGap(1);
        // set names and colors:
    firma3->setName("Cheltuiala 1");
    firma3->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    firma3->setBrush(QColor(111, 9, 176));
    firma1->setName("Cheltuiala Smechera");
    firma1->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    firma1->setBrush(QColor(250, 170, 20));
    firma2->setName("Cheltuiala pe bere");
    firma2->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    firma2->setBrush(QColor(0, 168, 140));
        // stack bars on top of each other:
    firma2->moveAbove(firma1);
    firma3->moveAbove(firma2);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2;
    labels << "Firma1" << "Firma2 Barosana";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->grafic->xAxis->setTicker(textTicker);
    ui->grafic->xAxis->setTickLabelRotation(30);
    ui->grafic->xAxis->setSubTicks(false);
    ui->grafic->xAxis->setTickLength(0, 7);
    ui->grafic->xAxis->setRange(0, 3);
    ui->grafic->xAxis->setBasePen(QPen(Qt::white));
    ui->grafic->xAxis->setTickPen(QPen(Qt::white));
    ui->grafic->xAxis->grid()->setVisible(true);
    ui->grafic->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->grafic->xAxis->setTickLabelColor(Qt::white);
    ui->grafic->xAxis->setLabelColor(Qt::white);
    ui->grafic->xAxis->setLabel("Cheltuieli pe an");

    // prepare y axis:
    //ui->grafic->yAxis->setRange(0, 265);
    ui->grafic->yAxis->setPadding(5); // a bit more space to the left border
    ui->grafic->yAxis->setLabel("Mii de lei");
    ui->grafic->yAxis->setBasePen(QPen(Qt::white));
    ui->grafic->yAxis->setTickPen(QPen(Qt::white));
    ui->grafic->yAxis->setSubTickPen(QPen(Qt::white));
    ui->grafic->yAxis->grid()->setSubGridVisible(true);
    ui->grafic->yAxis->setTickLabelColor(Qt::white);
    ui->grafic->yAxis->setLabelColor(Qt::white);
    ui->grafic->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->grafic->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    //QCPBarsGroup *group1 = new QCPBarsGroup(ui->grafic);
    QVector<double> firma1Data, firma2Data, firma3Data;
    firma1Data << 87 << 78;
    firma2Data << 82 << 70;
    firma3Data << firma1Data[0]-10 << 59;
    firma1->setData(ticks, firma3Data);
    firma2->setData(ticks, firma1Data);
    firma3->setData(ticks, firma1Data);
    firma1->setWidth(0.9);
    //firma1->setBarsGroup(group1);
    firma2->setWidth(0.9);
    firma3->setWidth(0.9);
    //firma2->setBarsGroup(group1);

    // setup legend:
    ui->grafic->legend->setVisible(true);
    ui->grafic->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    ui->grafic->legend->setBrush(QColor(255, 255, 255, 100));
    ui->grafic->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->grafic->legend->setFont(legendFont);
    ui->grafic->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

        // limitele axei y
    double limitay = *std::max_element(firma1Data.begin(), firma1Data.end()) + *std::max_element(firma2Data.begin(), firma2Data.end()) + *std::max_element(firma3Data.begin(), firma3Data.end());
    ui->grafic->yAxis->setRange(0, limitay+20);
}

Grafice::~Grafice()
{
    delete ui;
}
