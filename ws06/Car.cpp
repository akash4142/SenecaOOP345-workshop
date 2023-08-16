/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

#include <exception>
#include "Car.h"

namespace sdds {
	
	Car::Car(std::istream& is){

		
		 std::string tem;

		 std::getline(is,tem,',');

		 maker = trim(tem);


		 
		 std::getline(is, tem, ',');
		 tem = trim(tem);


		 if (tem.empty()) 
			condition1 = 'n';

		 else {

			 
			 condition1 = tem[0];


			 if (condition1 != 'u' && condition1 != 'n' && condition1 != 'b') {
				 throw std::invalid_argument("the record is invalid");
			 }
		 }


		 try {

			 std::getline(is, tem, ',');

			 topSpeed11 = stod(trim(tem));
		 }


		catch (std::invalid_argument & e) {
			 throw e;
		}
	}
	
	std::string Car::condition() const
	{
		std::string condition;

		// Convert the car condition character to a descriptive string
		if (condition1 == 'n') {
			condition = "new";
		}


		else if(condition1 == 'u') {
			condition = "used";
		}


		else if (condition1 == 'b') {
			condition = "broken";
		}


		return condition;
	}


	double Car::topSpeed() const{
		return topSpeed11;
	}


	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << std::right  << maker;

		out << " | " << std::setw(6) << std::left << condition();

		out << " | " << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
	}
	
}