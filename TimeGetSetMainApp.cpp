#include <cstdlib>
#include <iostream> 
#include <ostream>
#include <chrono>
#include <thread>
#include <string>

#include "DS3231.h"

std::string version("0.0.1");

// start ./TimeGetSet setTime or ./TimeGetSet getTime
int main(int argc, char *argv[])
{
   printf("TimeGetSetter %s is starting \n" ,version.c_str());
   printf("Program Name Is: %s",argv[0]);

   DS3231 *ds3231 = new DS3231();
   ds3231->getlocalTime_setDS3231();
   ds3231->getDS3231_setLocalTime();

   int counter = 0;
   if(argc ==1 ) printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
   if(argc >= 2)
   {
       printf("\nNumber Of Arguments Passed: %d",argc);
       printf("\n----Following Are The Command Line Arguments Passed----\n");
       for(counter=0; counter<argc; counter++)
       {
           printf("\nargv[%d]: %s\n",counter,argv[counter]);
       }
       std::string strArgument = argv[1];

       printf("strArg::%s\n", strArgument.c_str());

       if(strArgument == "setTime")
       {

       }
       else if(strArgument == "getTime")
       {

       }
       else
       {
           printf("FAILURE:: wrong Argument by TimeGetSetter start\n\n");
           printf("usage:: ./TimeGetSetMainApp getTime\n");
           printf("\nor\n\n");
           printf("./TimeGetSetMainApp setTime\n\n");
       }     
    }
  
    printf("Exit TimeGetSetter App\n");
   
    return EXIT_SUCCESS; // return value
}
