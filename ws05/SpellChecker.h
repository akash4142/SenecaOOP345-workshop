/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>


namespace sdds {
	
	const int size = 6;
	class SpellChecker {
	private:
		std::string m_badWords[size]{};
		std::string m_goodWords[size]{};
		size_t num_replacements[size]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);

		void showStatistics(std::ostream& out) const;

	};
	



}
#endif