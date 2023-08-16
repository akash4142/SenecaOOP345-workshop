/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>

#include "Utilities.h"
#include "Racecar.h"




namespace sdds 
{

	
	Vehicle* createInstance(std::istream& in)
	{

		
		std::string tem;

		std::getline(in, tem, '\n');

		std::string nm1 = trim(tem);

		std::stringstream str;
		str << tem;

		
		if (str && !tem.empty()) {
			if (nm1 == "c" || nm1 == "C") {

				return new Car(str);

			}
			else if (nm1 == "r" || nm1 == "R") {
				return new Racecar(str);
			}
			else {

				
				if (nm1 != "u" && nm1 != "n" && nm1 != "b")
				{
					std::string err = "Unrecognized record type: [" + nm1 + "]";

					throw err;

				}

			}
		}

		return nullptr;
	}

	
	std::string trim(std::string& str)
	{
		const char* spaces = " \f\n\r\t\v";
		std::string tem;

		
		tem = str.substr(0, str.find(","));	
		tem.erase(0, tem.find_first_not_of(spaces));
		
		tem.erase(tem.find_last_not_of(spaces) + 1);
		
		str.erase(0, str.find(",") + 1);

		return tem;
	}
}