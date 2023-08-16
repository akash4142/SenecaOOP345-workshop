/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <string>

namespace sdds {

	class Book {
	private:

		std::string author="";
		std::string o_title="";
		std::string o_country="";
		double o_price=0;
		size_t o_year=0;
		std::string o_summary="";

	public:
		Book()=default; // Default constructor
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(o_summary);
		}

		~Book();


	};

}

#endif