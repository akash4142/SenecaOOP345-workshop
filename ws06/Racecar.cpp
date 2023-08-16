/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#include <string>

#include "Racecar.h"

namespace sdds 

{

	Racecar::Racecar(std::istream& in) : Car(in)
	{

		std::string tem;

		std::getline(in, tem, ',');
		booster = std::stod(trim(tem));
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);

		out << "*";
	}
	double Racecar::topSpeed() const
	{

		return (Car::topSpeed() + (Car::topSpeed() * booster));

	}
}