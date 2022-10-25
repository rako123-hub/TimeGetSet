
#include "DS3231.h"

const std::string strdevice                = "/dev/i2c-2";


DS3231::DS3231()
{
    if(openDS3231())
    {
        setDevAdr(0x68);
    }

}

DS3231::~DS3231()
{
    if(_devI2C >= 0)
    {
        close(_devI2C);
    }
}

bool DS3231::setDevAdr(byte addr)
{
    bool result = true;
    bool force = false;
    if (ioctl(_devI2C, force ? I2C_SLAVE_FORCE : I2C_SLAVE, addr) < 0) 
    {
        printf("Failed to acquire bus access and/or talk to slave addr %0x\n", addr);
        result = false;
    }
    else
    {
        printf("SetDevAddress:: %0x\n", addr);
    }
    return result;
}

bool DS3231::openDS3231()
{
    printf("+++Open I2C device\n");
    _open = false;
	_devI2C = open(strdevice.c_str(), O_RDWR);
	if (_devI2C < 0 ) 
    {
		if (errno == ENOENT) 
        {
			printf("Error: Could not open file: %s  : %s\n", strdevice.c_str(), strerror(ENOENT));
		} 
        else 
        {
			printf("Error: Could not open file "
				"`%s': %s\n", strdevice.c_str(), strerror(errno));
			if (errno == EACCES)
				printf("Run as root?\n");
		}
	}
    else
    {
        _open = true;
    }
    printf("---Open I2C device\n");
    return _open;
}

bool DS3231::writeData(byte reg, byte value)
{
    bool result = true;

    if(i2c_smbus_write_byte_data(_devI2C, reg, value) < 0) 
    {
        printf("Failed to write data to MCP23017 device\n");
        result = false;
    }
    return result;
}

byte DS3231::readData(byte reg)
{
    byte val = 0x55;
    val = i2c_smbus_read_byte_data(_devI2C, reg);
    return val;
}

void getlocalTime()
{
    struct tm *tm_now = {};
    int seconds_now   = 0;

    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now); 
    tm_now = localtime ( &time_now );
    //seconds_now = tm_now->tm_hour * 3600 + tm_now->tm_min * 60 + tm_now->tm_sec;

    printf ( "Current date and time are: %s \n", asctime (tm_now) );

    int year  = tm_now->tm_year;
    int month = tm_now->tm_mon;
    int day   = tm_now->tm_mday;
    int hour  = tm_now->tm_hour;
    int min   = tm_now->tm_min;
    int sec   = tm_now->tm_sec;
}
