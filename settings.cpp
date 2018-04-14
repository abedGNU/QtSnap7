#include "settings.h"

Settings::Settings()
{
    int res =-1;
    /* If settings file doesn't exist in the default directory
     * create new one with default value Or select one
     **/
    settings = new QSettings(settingsFileName, QSettings::IniFormat);
    //createDefaultSettings();
    //qDebug() << "Creating default setting in: " << "done " << res;


    /* Load settings from file
     **/
    res=loadSettings();
    qDebug() << "Loading setting from: " << "done " << res;
}

int Settings::loadSettings()
{
    settings->beginGroup("PLC");
    PlcIpAddress = settings->value("PlcAddress").toString();
    NoDB = settings->value("DBNumber").toInt();
    BufferLen = settings->value("Bufferlength").toInt();
    settings->endGroup();
    return 0;
}

int Settings::saveSettings()
{
    settings->beginGroup("PLC");
    settings->setValue("PlcAddress", PlcIpAddress);
    settings->setValue("DBNumber",NoDB );
    settings->setValue("Bufferlength", BufferLen);
    settings->endGroup();
    return 0;
}

int Settings::createDefaultSettings()
{
    settings->beginGroup("PLC");
    settings->setValue("PlcAddress", PlcIpAddressDef);
    settings->setValue("DBNumber",NoDBdef);
    settings->setValue("Bufferlength", BufferLendef);
    settings->endGroup();
    return 0;
}
