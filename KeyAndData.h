//
// Created by Kareem Elnaghy on 10/21/23.
//

#ifndef ADS_ASSIGNMENT_3_KEYANDDATA_H
#define ADS_ASSIGNMENT_3_KEYANDDATA_H
#include <string>
using namespace std;

class DMS       //class for longitude and latitude
{
public:
    int degrees;
    int minutes;
    int seconds;
    char direction;

    DMS();
};


class CityData      //class to represent data
{
public:
    DMS latitude;
    DMS longitude;
    string lat;
    string lon;
    string country;

    CityData ();
};



#endif //ADS_ASSIGNMENT_3_KEYANDDATA_H
