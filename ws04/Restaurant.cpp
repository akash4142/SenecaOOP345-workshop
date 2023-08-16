/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 10/ june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#include <bits/stdc++.h>
#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds
{
    static int restaurantCounter = 1;
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) //parameterised constructor
	{
		if (reservations != nullptr && cnt > 0u)   //validation 
		{
			this->rt_reservations = new Reservation[cnt]; //dynamic memory allocation

			for (size_t i = 0u; i < cnt; ++i)
			{
				this->rt_reservations[i] = *reservations[i];
				this->rt_count++;
			}
		}
	}

	Restaurant::Restaurant(const Restaurant& src) //copy constructor
	{
		*this = src;
	}


	Restaurant::Restaurant(Restaurant&& src) //move constructor
	{
		*this = move(src);
	}


	Restaurant& Restaurant::operator=(const Restaurant& src)//operator overload
	{

		if (this != &src)
		{
			this->rt_count = src.rt_count;
			delete[] this->rt_reservations;
			if (src.rt_reservations != nullptr)
			{
				this->rt_reservations = new Reservation[this->rt_count];
				for (size_t i = 0u; i < this->rt_count; ++i)
				{
					this->rt_reservations[i] = src.rt_reservations[i];
				}
			}
			else
			{
				this->rt_reservations = nullptr;
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) // rvalue operator 
	{
		if (this != &src)
		{
			this->rt_count = src.rt_count;
			delete[] this->rt_reservations;
			this->rt_reservations = src.rt_reservations;
			src.rt_reservations = nullptr;
			src.rt_count = 0u;
		}
		return *this;
	}


	size_t Restaurant::size() const
	{
		return this->rt_count;
	}

		

	std::ostream& operator<<(ostream& os, const Restaurant& rest)  
	{
		os << "--------------------------\n";
		os << "Fancy Restaurant (" << restaurantCounter++ << ")\n";
		os << "--------------------------\n";
		if (!rest.size())
		{
			os << "This restaurant is empty!\n";
		}
		else
		{
			for (size_t i = 0u; i < rest.rt_count; ++i)
			{
				os << rest.rt_reservations[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}

	Restaurant::~Restaurant()  //destructor
	{
		if (this->rt_reservations != nullptr)
		{
			delete[] this->rt_reservations;
			this->rt_reservations = nullptr;
		}
	}
}

