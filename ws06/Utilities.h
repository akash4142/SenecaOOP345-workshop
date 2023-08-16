/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H


#include "Vehicle.h"
#include "Car.h"


namespace sdds
{

	
	std::string trim(std::string& str);

	Vehicle* createInstance(std::istream& in);
}
#endif