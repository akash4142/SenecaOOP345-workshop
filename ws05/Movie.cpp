/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Movie.h"
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

namespace sdds {

	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {

		size_t m_comma1 = strMovie.find(',');
		m_title = strMovie.substr(0, m_comma1);
		m_title.erase(0, m_title.find_first_not_of(' '));
		m_title.erase(m_title.find_last_not_of(' ') + 1);

		size_t m_comma2 = strMovie.find(',',m_comma1+1);
		m_year = std::stoi(strMovie.substr(m_comma1 + 1, m_comma2 - m_comma1 - 1));

		m_desc = strMovie.substr(m_comma2 + 1);
		m_desc.erase(0, m_desc.find_first_not_of(' '));
		m_desc.erase(m_desc.find_last_not_of(' ') + 1);

	}

	std::ostream& operator<<(std::ostream& ostr, const Movie& movie) {
		ostr << std::right << std::setw(40) << movie.m_title << " | ";
		ostr << std::right << std::setw(4) << movie.m_year << " | ";
		ostr << std::left << movie.m_desc<<endl;
		return ostr;
	}

}