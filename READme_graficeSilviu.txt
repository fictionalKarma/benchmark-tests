Tot codul scris pt grafice necesita includerea in proiect a qcustomplot.h si a qcustomplot.cpp

Graficele reprezinta comparatia performantei intre doua firme. Axa y are limitele [0;135], deoarece consider ca afisarea trebuie sa decurga in felul urmator: etalonul reprezinta 100% din performanta si etalonul va fi reprezentat pe grafic cu bare de aceease "inaltime" 100; elementele pe care le vom compara vor avea afisarea prin bare care reprezinta x% din valoarea elementelor etalonului. Ex: daca pentru Criteriul_1 etalonul este 87 (nu conteaza unitatea de masura acum), iar performanta Firmei_1 pt Criteriul_1 este 65, pe grafic acestea nu vor aparea sub forma: bara etalon 87 langa bara firmei 65, ci bara etalon 100 langa bara firmei 6500/87 (x/100*87=65, x=6500/87). 
Poate nu arata prea interesant, avand in vedere ca etalonul va aparea doar ca niste bare de inaltime 100, insa consider ca in cazul comparatiei intre doua firme, va fi bun. Ma gandesc sa adaug si valoarea acelui element plotat deasupra barei.

/* Tot codul este scris in mainwindow.cpp si trebuie transformat intr-o clasa de sine statatoare. 

Voi adauga si un pieChart pentru muncitori si pentru costurile lunare, daca e cu rost. */ UPDATE: FACUT

In fisierul cu proiectul Qt (se termina in .pro) trebuie trecut aici:
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 
"printsupport" ->
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

COD GRAFICE

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