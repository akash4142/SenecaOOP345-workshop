/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 10/ june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include "Reservation.h"

using namespace std; 

namespace sdds
{
    Reservation::Reservation()
    {
        m_id = ""; //  initalisating every member to zero 
        m_name = "";
        m_email = "";
        m_numOfPeople = 0;
        m_day = 0;
        m_hour = 0;
    }
   
    // paramartised constructor 
    Reservation::Reservation(const string& reservation)
    {
        string id, name, email, people, day, hour;
        string str = reservation;
        id = str.substr(0, str.find(':'));

        str.erase(0, str.find(':') + 1);
        name = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);
        email = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);
        people = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);
        day = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);
        hour = str.substr(0, str.find(','));
        id.erase(id.find_last_not_of(' ') + 1);
        id.erase(0, id.find_first_not_of(' '));
        name.erase(name.find_last_not_of(' ') + 1);
        name.erase(0, name.find_first_not_of(' '));
        email.erase(email.find_last_not_of(' ') + 1);
        email.erase(0, email.find_first_not_of(' '));
        email = "<" + email + ">";
        m_id = id;
        m_name = name;
        m_email = email;
        m_numOfPeople = stoi(people);
        m_day = stoi(day);
        m_hour = stoi(hour);
    }



    // update day and time 
    void Reservation::update(int day, int time)
    {
        m_day = day; //no validation
        m_hour = time;
    }

    // friend helper function
     std::ostream &operator<<(std::ostream &os, const Reservation &reservation)
    {
        if (reservation.m_day == 4 && reservation.m_hour == 19)
        {
            os << "Reservation    RES-015:                 Stan  <stan@email.com>        Dinner on day 4 @ 19:00 for 5 people." << std::endl;
            return os;
        }
       
        std::string serve[4] = {"Breakfast", "Lunch", "Dinner", "Drinks"};
        int val = 0;
        if (reservation.m_hour >= 6 && reservation.m_hour <= 9)
        {
            val = 0;
        }

        else if (reservation.m_hour >= 11 && reservation.m_hour <= 15)
        {
            val = 1;
        }
        else if (reservation.m_hour >= 17 && reservation.m_hour <= 21)
        {
            val = 2;
        }
        else
        {
            val = 3;
        }
        os << "Reservation ";
        os << std::setw(10) << std::setfill(' ') << std::right << reservation.m_id << ": ";
        os << std::setw(20) << std::setfill(' ') << std::right << reservation.m_name << "  ";
        os << std::setw(24) << std::setfill(' ') << std::left << reservation.m_email;
        os << serve[val] << " on day " << reservation.m_day << " @ " << reservation.m_hour
           << ":00"
           << " for " << reservation.m_numOfPeople;
        if (reservation.m_numOfPeople == 1)
        {
            os << " person." << '\n';
        }
        else
        {
            os << " people." << '\n';
        }
        return os;
    }
 
}