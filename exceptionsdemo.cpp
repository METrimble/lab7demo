#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/*************
lab 7 demo
Elayne Trimble
preventing a seg fault
*************/

/*global constant size*/
const int SIZE = 3;

struct weather_report{
    int inches_snow;
    string town;
};

void access_report(weather_report weather[SIZE]){
    //try to access a report
    cout << "There are " << SIZE << " reports available." << endl;
    cout << "To read a report enter 0 - " << SIZE - 1 << " to read the corresponding report" << endl;
    cout << "Enter here: ";

    int user_index;
    //try block
    try{
        cin >> user_index;

        //see if the user entered an invalid index
        if(user_index >= SIZE || user_index < 0){
            throw invalid_argument("Tried to access a report that doesn't exist"); //function which exists within the stdexcept library http://www.cplusplus.com/reference/stdexcept/invalid_argument/
        }

        //print out requested report
        cout << "---------------------------------" << endl;
        cout << "Town: " << weather[user_index].town << endl;
        cout << "Inches of Snow: " << weather[user_index].inches_snow << endl;
        cout << "---------------------------------" << endl;
    }
    //catch block
    catch(const invalid_argument& ia){
        cout << "Invalid Argument: " << ia.what() << endl;
        cout << "Re enter: " << endl;
        access_report(weather);
    }
}

int main(){
    //create an array of weather reports
    weather_report weather[SIZE];

    //set the members
    weather[0].town = "Portland";
    weather[0].inches_snow = 6;

    weather[1].town = "Corvallis";
    weather[1].inches_snow = 0;

    weather[2].town = "Kelso";
    weather[2].inches_snow = 5;

    //try to access a index
    access_report(weather);
    return 0;
}