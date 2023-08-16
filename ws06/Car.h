/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include "Utilities.h"

namespace sdds 
{
	
	class Car :public Vehicle
	{
		
		std::string maker{};
		char condition1{};
		double topSpeed11{};

	public:

		
		Car() {};
		
		~Car() {};
		Car(std::istream& is);
		
		std::string condition() const;
		
		double topSpeed() const;

		void display(std::ostream& out) const;
	};
}

#endif