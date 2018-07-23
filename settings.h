#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QSettings>
#include <QDebug>
#include <QFile>

class Settings
{
public:
    Settings();
    QSettings *settings;
    int loadSettings();
    int saveSettings();
    int createDefaultSettings();

    QString PlcIpAddress;
    int NoDB;
    int BufferLen;
    //

private:
    QString PlcIpAddressDef="192.168.0.100";
    int NoDBdef=1;
    int BufferLendef=20;

    QString settingsFileName = "settings.ini";
};

#endif // SETTINGS_H
