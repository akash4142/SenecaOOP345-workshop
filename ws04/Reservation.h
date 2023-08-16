/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 10/ june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__


#include <iostream>
#include <string>

namespace sdds{
    class Reservation{
        std::string m_id; // reservation id
        std::string m_name; // reservation name
        std::string m_email; // email
        int m_numOfPeople; // number of people 
        int m_day; // to store the day
        int m_hour; // to store the hour
    public:
        Reservation(); //default constructor
        Reservation(const std::string& reservation); //paramarised constructor
        void update(int day, int time); //update function

        //helper function
        friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation); //operator overload
    };
}
#endif