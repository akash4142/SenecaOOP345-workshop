/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 10/ june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#include <bits/stdc++.h>
#include "ConfirmationSender.h"


using namespace std;

namespace sdds
{
    ConfirmationSender::ConfirmationSender() {}//default constructor

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)// copy constructor
    {
        *this = src;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)//  move constructor
    {
        *this = move(src);
    }

    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &reservation)
    {
        bool isNotFound = true; //checking status 
        for (size_t i = 0u; i < this->c_count && isNotFound; ++i)
        {
            isNotFound = this->c_ptrReservations[i] != &reservation;
        }
        if (isNotFound == true)
        {
            const Reservation **temp = new const Reservation *[this->c_count + 1u];
            for (size_t i = 0u; i < this->c_count; ++i)
            {
                temp[i] = this->c_ptrReservations[i];
            }
        temp[this->c_count++] = &reservation;
            delete[] this->c_ptrReservations;
            this->c_ptrReservations = temp;
        }
        return *this;
    }
    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&src) //rvalue = operator overloading
    {
        if (this != &src)
        {
            this->c_count = src.c_count;
            delete[] this->c_ptrReservations;
            this->c_ptrReservations = src.c_ptrReservations;
            src.c_count = 0u;
            src.c_ptrReservations = nullptr;
        }

        return *this;
    }
   
    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &reservation)
    {
        bool isNotFound = true;
        for (size_t i = 0u; i < this->c_count && isNotFound; ++i)
        {
            isNotFound = this->c_ptrReservations[i] != &reservation;
        }
        if (isNotFound == false)
        {
            const Reservation **temp = new const Reservation *[this->c_count - 1u];
            size_t tempIndex = 0u;

            for (size_t i = 0u; i < this->c_count; ++i)
            {
                if (this->c_ptrReservations[i] != &reservation)
                {
                    temp[tempIndex] = this->c_ptrReservations[i];
                    tempIndex++;
                }
            }
            this->c_count--;
            delete[] this->c_ptrReservations;
            this->c_ptrReservations = new const Reservation *[this->c_count];

            for (size_t i = 0u; i < this->c_count; ++i)
            {
                this->c_ptrReservations[i] = temp[i];
            }

            delete[] temp;
        }
        return *this;
    }

     
    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &src)//operator = overloading
    {
        if (this != &src)
        {
            this->c_count = src.c_count;

            delete[] this->c_ptrReservations;

            if (src.c_ptrReservations != nullptr)
            {
                this->c_ptrReservations = new const Reservation *[this->c_count];

                for (size_t i = 0u; i < this->c_count; ++i)
                {
                    this->c_ptrReservations[i] = src.c_ptrReservations[i];
                }
            }
            else
            {
                this->c_ptrReservations = nullptr;
            }
        }
        return *this;
    }

    ostream &operator<<(ostream &os, const ConfirmationSender &c)// helper overloading operator
    {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";
        if (!c.c_count)
        {
            os << "There are no confirmations to send!\n";
        }
        else
        {
            for (size_t i = 0u; i < c.c_count; ++i)
            {
                os << *c.c_ptrReservations[i];
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }



 ConfirmationSender::~ConfirmationSender() //destructor 
    {
        if (this->c_ptrReservations != nullptr)
        {
            delete[] this->c_ptrReservations;
            c_ptrReservations = nullptr;
        }
    }

}
