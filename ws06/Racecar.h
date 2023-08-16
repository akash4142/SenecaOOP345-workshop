/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H


#include <istream>

#include "Car.h"


namespace sdds
{

	class Racecar : public Car
	{
		
		double booster{ 0 };
		
	public:
		Racecar(std::istream& in);		
		void display(std::ostream& out) const;
		double topSpeed() const;


	};
}
#endif