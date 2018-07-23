#ifndef GLOBALE_H
#define GLOBALE_H

#include <QString>


namespace Global
{

typedef struct
{
    QString ipAdd="192.168.0.100";
    int DB_Read=1;
    int DB_Len=100;
    byte DB_Buffer[DB_Len];// resize array before using
} st_PLC;

st_PLC PLC;

} // namespace Global

#endif // GLOBALE_H
