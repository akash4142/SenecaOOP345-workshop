/*name - Akash yadav
student no. = 172566218
seneca email- ayadav35@myseneca.ca
date - 11/july

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		
		Autoshop& operator +=(Vehicle* theVehicle);		
		void display(std::ostream& out) const;
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{

			for (auto nmm = m_vehicles.begin(); nmm < m_vehicles.end(); nmm++)
			{

				if (test(*nmm))
				{
					vehicles.push_back(*nmm);
				}
			}

		}


	};
}

#endif