/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>


namespace sdds {

	class Movie {
	private:

		std::string m_title = "";
		std::size_t m_year = 0;
		std::string m_desc = "";
	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);

		}

		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);

	};


}
#endif