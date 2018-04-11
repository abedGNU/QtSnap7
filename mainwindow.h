#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include "ui_mainwindow.h"
#include "snap7.h"
#include "plc_siemens.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    PLC_Siemens *plcSiemens;

    QTimer *timer ;

   void byteCastingtest();
#pragma pack(push, 1)
    typedef struct
    {
        int32_t counterDint;
        uint8_t counterByte;
        int16_t cInt;
        uint16_t cWord;
        uint32_t cDWord;
        float_t cReal;
        uint8_t cByte18;
        uint8_t cByte19;
        uint8_t cByte20;
        uint8_t cByte21;
        uint8_t cByte22;
    } testStruct_t, *PtestStruct_t;
#pragma pack(pop)

private slots:
    void on_pbWrite_clicked();

    void update();

    void on_pbTestCasting_clicked();
};

#endif // MAINWINDOW_H
