#include "OfferTest.h"
#include "DynamicArrayTest.h"
#include "Offer.h"
#include "Date.h"
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

#include "DynamicArray.h"
Offer read_offer();
Date read_date();

Date read_date() {
    cout << "Day: ";
    int day, m, y;
    cin >> day;
    cout << "\nMonth: ";
    cin >> m;
    cout << "\nYear: ";
    cin >> y;
    return Date{ day,m,y };
}
int read_type() {
    bool ok = 0;

    string t;
    cout << "\nTypes:\n";
    cout << "Circuit, CityBreak, Cruise, Allinclusive\n";
    cout << "Type: ";
    cin >> t;
    if (t == "Circuit") {
        return (int)0;
    }
    else if (t == "CityBreak") {
        return (int)1;
    }
    else if (t == "Cruise") {
        return int(2);
    }
    else if (t == "Allinclusive") {
        return (int)3;
    }
    else
        return -1;

}
Offer read_offer() {
    string id, dest, dep;
    Date s, e;
    int type;
    float price;
    cout << "Id: ";
    cin >> id;
    cout << "\nDeparture: ";
    cin >> dep;
    cout << "\nDestination: ";
    cin >> dest;
    cout << "\nPrice: ";
    cin >> price;
    type = read_type();
    while (type == -1) {
        cout << "Invalid Type";
        type = read_type();
    }
    cout << "\nStart date: \n";
    s = read_date();
    cout << "\nEnd date: \n";
    e = read_date();
    cout << endl;
    return Offer{ id,dest,dep,s,e,price,type };

}
void displayMenu() {
    cout << "Please select an option:\n";
    cout << "\t A|a\tAdd an offer\n";
    cout << "\t S|s\tShow all offers\n";
    cout << "\t B|b\tFilter offers by price and type\n";
    cout << "\t D|d\tFilter offers by  and type\n";
    cout << "\t Q|q\t Quit" << endl;
}
bool validate_input(char c[]) {
    if (strlen(c) <= 1) {
        if (strchr("AaSsQqTtBbPp", c[0]))
            return 1;
    }
    return 0;
}
void run_ui(DynamicArray& arr) {
    bool ok = 0;

    string input = "";
    bool valid = 1;
    while (input != "q") {
        displayMenu();
        cin >> input;
        std::for_each(input.begin(), input.end(), [](char& c) {
            c = ::tolower(c);
        });
        if (input.size() == 1) {
            if (input == "a") {
                Offer o1{ read_offer() };
                cout << o1.get_id() << endl;
                arr.append(o1);
            }
            else if (input == "s") {
                cout << arr << endl;
            }
            else if (input == "b") {
                float price;
                cout << "Price: ";
                cin >> price;
                int type = read_type();
                while (type == -1) {
                    cout << "Invalid Type";
                    int type = read_type();
                }
                if (type >= 0) {
                    FilteringCriteriaAnd r;
                    cout << r;
                }
            }
            else if (input == "d") {
                float price;
                cout << "Departure: ";
                cin >> departure;
                cout << "Destination: ";
                cin >> dest;
                FilteringCriteriaOr s;
                cout << s;
            }
            else if (input == "q") {
                break;
            }
            else
                cout << "Invalid input!" << endl;

        }
    }

}

int main() {

    Date s_d{ 1, 1, 2022 };
    Date e_d{ 8, 1, 2022 };
    OfferTest::runAllTests();
    FilteringTest::runAllTests();
    DynamicArrayTest::runAllTests();
    Offer o1{ "1","lax","otp",s_d,e_d,1000,1 };
    DynamicArray arr{ 1 };
    arr.append(o1);

    run_ui(arr);

    return 0;
}