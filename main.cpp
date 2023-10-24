// Student Name: Kareem Elnaghy
// Student ID:  900223587

#include <iostream>
#include <sstream>
#include <fstream>
#include "binaryTree.h"
#include "KeyAndData.h"
using namespace std;

// Function to convert latitude and longitude from degrees, minutes, and direction to CityData structure
void convertDMS(CityData &data, string x, string y) {//latitude
    char degPos = x.find((char) 176);
    char minPos = x.find('\'');
    string degStr = x.substr(0, degPos);
    string minStr = x.substr(degPos + 1, minPos - 1);
    string direction = x.substr(minPos + 1);
    if (degPos != string::npos && minPos != string::npos) {
        int deg = stoi(degStr);
        int min = stoi(minStr);

        // Store latitude information in CityData structure
        data.latitude.degrees = deg;
        data.latitude.minutes = min;
        data.latitude.direction = direction[0];

        // Process longitude information
        degPos = y.find((char) 176);
        minPos = y.find('\'');
        degStr = y.substr(0, degPos);
        minStr = y.substr(degPos + 1, minPos - 1);
        direction = y.substr(minPos + 1);

        deg = stoi(degStr);
        min = stoi(minStr);

        // Store longitude information in CityData structure
        data.longitude.degrees = deg;
        data.longitude.minutes = min;
        data.longitude.direction = direction[0];
    }
}

// Function to enter city data into the binary tree
void enterData(binaryTree<string, CityData> &x) {
    CityData d;
    string city;
    cout << "Enter the city, country, latitude and longitude: ";
    cin >> city >> d.country >> d.lat >> d.lon;

    // Insert city data into the binary tree
    x.insert(city, d);
}

// Function to search for a city in the binary tree and display its data
void citySearch(binaryTree<string, CityData> &x, string city) {
    string lat, lon, count;
    CityData d;
    x.retrieve(city, d);
    lat = d.lat;
    lon = d.lon;
    count = d.country;

    // Output city data
    cout << city << " " << count << " " << lat << " " << lon << endl;
}

// Function to retrieve city information and convert latitude and longitude to CityData structure
CityData cityInfo(binaryTree<string, CityData> &x, string city, string &lat, string &lon, string &count) {
    CityData d;
    x.retrieve(city, d);
    lat = d.lat;
    lon = d.lon;
    count = d.country;
    convertDMS(d, lat, lon);
    return d;
}

// Function to calculate the distance between two points on Earth using Haversine formula
double distanceEQ(double lat1, double lat2, double lon1, double lon2) {
    const double R = 6371.137; // Earth radius in kilometers

    // Convert decimal degrees to radians
    lat1 *= M_PI / 180.0;
    lat2 *= M_PI / 180.0;
    lon1 *= M_PI / 180.0;
    lon2 *= M_PI / 180.0;

    double deltaLat = lat2 - lat1;
    double deltaLong = lon2 - lon1;

    double a = pow(sin(deltaLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double dist = R * c;

    return dist;
}

// Function to convert degrees, minutes, and seconds to decimal degrees
double convertDeci(int deg, int min, int sec, char direction) {
    double deciDeg = deg + min / 60.0 + sec / 3600.0;
    if (direction == 'S' || direction == 'W') {
        // Swap the sign of the result for South or West directions
        deciDeg = -deciDeg;
    }
    return deciDeg;
}

// Function to get the distance between two cities
double getDistance(string city1, string city2, binaryTree<string, CityData> &x) {
    string lat1, lat2, lon1, lon2, count1, count2;
    CityData d1 = cityInfo(x, city1, lat1, lon1, count1);
    CityData d2 = cityInfo(x, city2, lat2, lon2, count2);
//convert into deci
    double latDec1 = convertDeci(d1.latitude.degrees, d1.latitude.minutes, d1.latitude.seconds, d1.latitude.direction);
    double longDec1 = convertDeci(d1.longitude.degrees, d1.longitude.minutes, d1.longitude.seconds, d1.longitude.direction);
    double latDec2 = convertDeci(d2.latitude.degrees, d2.latitude.minutes, d2.latitude.seconds, d2.latitude.direction);
    double longDec2 = convertDeci(d2.longitude.degrees, d2.longitude.minutes, d2.longitude.seconds, d2.longitude.direction);

    return distanceEQ(latDec1, longDec1, latDec2, longDec2);
}

int main() {
    binaryTree<string, CityData> dictionary;
    string filename = "MCityList.txt";

    ifstream file;
    string k;
    CityData d;
    file.open("MCityList.txt");
    while (file >> k) {     //reads file
        file >> d.lat >> d.lon >> d.country;
        convertDMS(d, d.lat, d.lon);

        // Insert city data into the binary tree
        dictionary.insert(k, d);
    }
    file.close();

    string city;

    char c;
    // Search for a city and display its data
    do{
        cout << "Enter a city to search for: ";
        cin >> city;
        citySearch(dictionary, city);
        cout<<"Would you like to go again (Y/N) ";
        cin>>c;
    }while(c == 'Y' || c=='y');


// Enter new city data
    cout<<"Do you want to add a new city? (y/n) ";
    cin>>c;
if(c == 'Y' || c=='y'){
    do{
        enterData(dictionary);
        cout<<"Would you like to enter new data? (y/n)";
        cin>>c;
    }while(c == 'Y' || c=='y');}

    // Save the data to a file
    dictionary.saveFile2(filename);


    string city1, city2; // Calculate and display the distance between two cities
    do{
        cout << "Enter two cities to find the distance between them: ";
        cin >> city1 >> city2;
        cout << "The distance between them is " << getDistance(city1, city2, dictionary) << " Km"<<endl;

        cout<<"Would you like to go again? (y/n)";
        cin>>c;
    }while(c == 'Y' || c=='y');



    return 0;
}
