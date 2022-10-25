#ifndef DS3231_H
#define DS3231_H

#include <iostream> 
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <errno.h>              // Error integer and strerror() function
#include <cerrno>
#include <cstring>
#include <clocale>
#include <chrono>
 
#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

typedef uint8_t byte;

class DS3231
{
    public:
    DS3231();
    ~DS3231();

    void getlocalTime_setDS3231();

    private:
    bool openDS3231();
    bool setDevAdr(byte addr);
    bool writeData(byte reg, byte value);
    byte readData(byte reg);
    void getlocalTime();


    int _devI2C;
    bool _open;
};


#endif