/*
*****************************************************************************
						  Workshop - #7 (Part-2)
Full Name  : Akash yadav
Student ID#: 172566218
Email      : ayadav35@myseneca.ca
Date       : 19/07/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <list>
#ifndef SDDS_CRIMESTATISTICS_H_
#define SDDS_CRIMESTATISTICS_H_

namespace sdds 
{
	struct Crime 
	{
		std::string province;
		std::string district;
		std::string crime;
		int numberOfCases;
		int year;
		int m_resolved;
	};

	class CrimeStatistics {
		std::vector<Crime> m_crimes;
	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out)const;
		void sort(const std::string& field);
		void cleanList();
		bool inCollection(const std::string& crimeName) const;
		std::list<Crime> getListForProvince(const std::string& provinceName) const;
	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);

}


#endif 
