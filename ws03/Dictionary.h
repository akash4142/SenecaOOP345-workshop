/*name - KirtanKumar Hirenkumar Patel
student no. = 174408211
seneca email- kpatel470@myseneca.ca
date - 04 / june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include <iostream>
#include <iomanip>
#include <string>

namespace sdds {



	class Dictionary


	{
		std::string m_term{};
		std::string m_definition{};
	public:


		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}

	        Dictionary();
		void set(const std::string& term, const std::string& definition);
		std::ostream& display(std::ostream& os = std::cout) const;
		bool operator==(const Dictionary& dict) const;
	};



	std::ostream& operator<<(std::ostream& os, const Dictionary& definition);
}

#endif 