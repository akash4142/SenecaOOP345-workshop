/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Book.h"
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

namespace sdds {

	

	const std::string& Book::title() const {
		return o_title;
	}

	const std::string& Book::country() const {
		return o_country;
	}

	const size_t& Book::year() const {
		return o_year;
	}

	double& Book::price() {
		return o_price;
	}

	Book::Book(const std::string& strBook) {
		size_t comma1 = strBook.find(',');
		author = strBook.substr(0, comma1);
		author.erase(0, author.find_first_not_of(' '));
		author.erase(author.find_last_not_of(' ') + 1);

		size_t comma2 = strBook.find(',',comma1+1);
		o_title = strBook.substr(comma1+1, comma2-comma1-1);
		o_title.erase(0, o_title.find_first_not_of(' '));
		o_title.erase(o_title.find_last_not_of(' ') + 1);

		size_t comma3 = strBook.find(',', comma2 + 1);
		o_country = strBook.substr(comma2 + 1, comma3 - comma2 - 1);
		o_country.erase(0, o_country.find_first_not_of(' '));
		o_country.erase(o_country.find_last_not_of(' ') + 1);

		size_t comma4 = strBook.find(',', comma3 + 1);
		o_price = std::stod(strBook.substr(comma3 + 1, comma4 - comma3 - 1));
		
		size_t comma5 = strBook.find(',', comma4 + 1);
		o_year = std::stoi(strBook.substr(comma4 + 1, comma5 - comma4 - 1));

		o_summary = strBook.substr(comma5 + 1);
		o_summary.erase(0, o_summary.find_first_not_of(' '));
		o_summary.erase(o_summary.find_last_not_of(' ') + 1);


	}

	std::ostream& operator<<(std::ostream&ostr,const Book& book){
		ostr << std::right << std::setw(20) << book.author << " | ";
		ostr << std::right << std::setw(22) << book.o_title << " | ";
		ostr << std::right << std::setw(5) << book.o_country<< " | ";
		ostr << std::right << std::setw(4) << book.o_year << " | ";
		ostr << std::right << std::setw(6) << std::fixed << std::setprecision(2) << book.o_price << " | ";
		ostr << std::left << book.o_summary << endl;

		return ostr;
	}

	Book::~Book() {};

}

