/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 10/ june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>
#include <bits/stdc++.h>
namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** c_ptrReservations{ nullptr }; //const variable
		size_t c_count{ 0u }; 

	public:
		ConfirmationSender(); //default constructor

		ConfirmationSender(const ConfirmationSender& src); //copy constructor

		ConfirmationSender& operator+=(const Reservation& reservation); //+= operator overloading
		ConfirmationSender& operator-=(const Reservation& reservation);//- = operator overloading
		ConfirmationSender& operator=(const ConfirmationSender& src); // = operator overloading


		ConfirmationSender(ConfirmationSender&& src); //move constructor
		ConfirmationSender& operator=(ConfirmationSender&& src);// rvalue operator oberloading
        
		~ConfirmationSender();//destructor

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c); //<<operator overloading
		
	};
}

#endif 
