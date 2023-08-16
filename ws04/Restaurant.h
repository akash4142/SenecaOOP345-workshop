/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 10/ june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
        size_t rt_count{ 0u }; 
		Reservation* rt_reservations{ nullptr }; 
		

	public:
		Restaurant(const Reservation* reservations[], size_t cnt); //parameterised constructor
        ~Restaurant(); //destructor
		size_t size() const; 

		Restaurant(const Restaurant& src); //copy constructor 
		Restaurant& operator=(const Restaurant& src);//operator overloading
		
		Restaurant(Restaurant&& src); // move constructor
		Restaurant& operator=(Restaurant&& src);//rvalue operator overloading
		
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest); //friend helper function overloading
		
		
	};
}

#endif 
