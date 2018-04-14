#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    ipLabel->setText("PLC IP address"+settings.PlcIpAddress);

    plcSiemens = new PLC_Siemens(settings.PlcIpAddress,settings.NoDB, settings.BufferLen);
    plcSiemens->start();

    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

}

void MainWindow::byteCastingtest()
{
   // uint8_t pBuff = { 0x11 , 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19 };
    PtestStruct_t pStruct = (PtestStruct_t)plcSiemens->DB_Buffer;
    qDebug()<< "Test casting";
}


void MainWindow::on_pbWrite_clicked()
{
    int dbNo, offset;
    dbNo=1;
    offset=20;
    plcSiemens->WriteVal(plcSiemens->eByte,dbNo,offset,(byte)spinBox->value());
}

void MainWindow::update()
{
    if (plcSiemens->connect()  )
    {
        QString txt = "counter 0: " + QString::number( plcSiemens->getUInt32(0)) + "\n\n";
        txt = txt + "counterByte 4: "+ QString::number( plcSiemens->DB_Buffer[4]) + "\n\n";
        txt = txt + "cInt 6: " + QString::number( plcSiemens->getInt16(plcSiemens->DB_Buffer,6 )) + "\n\n";
        txt = txt + "cWord 8: " + QString::number( plcSiemens->getUInt16(plcSiemens->DB_Buffer,8 )) + "\n\n";
        txt = txt + "cDword 10: " + QString::number( plcSiemens->getUInt32(plcSiemens->DB_Buffer,10 )) + "\n\n";
        txt = txt + "cReal 14: " + QString::number( plcSiemens->getReal(plcSiemens->DB_Buffer,14 )) + "\n\n";

        for(int i=18;i<30;i++)
        {
            txt = txt + "Byte "+ QString::number(i) +" : " + QString::number( plcSiemens->DB_Buffer[i]) + "\n";
        }
        label->setText(txt );
    }
}



void MainWindow::on_pbTestCasting_clicked()
{
    byteCastingtest();
}
