/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Autoshop.h"

namespace sdds 
{	
	

	
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{

		
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	Autoshop::~Autoshop()
	{


		for (auto nmm = m_vehicles.begin();

			nmm < m_vehicles.end(); nmm++)
		{
			delete* nmm;
		}
	}

	
	void Autoshop::display(std::ostream& out) const
	{

		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;


		for (size_t nm1 = 0; nm1 < m_vehicles.size(); nm1++) 
		{
			m_vehicles[nm1]->display(out);

			out << std::endl;
		}


		out << "--------------------------------" << std::endl;


	}
}