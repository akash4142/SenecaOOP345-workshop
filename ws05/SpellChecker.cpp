/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "SpellChecker.h"
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (file.is_open() == false) {
			throw "Bad file name!";
		}
		std::string badWord;
		std::string goodWord;
		int count = 0;
		while (file>>badWord>>goodWord) {
			m_badWords[count] = badWord;
			m_goodWords[count] = goodWord;
			count++;

		}
		file.close();
	}
	
	void SpellChecker::operator()(std::string& text) {
		size_t start{};
		for (int i = 0; i < size; i++) {
			start = 0;
			while ((start = text.find(m_badWords[i],start))!=std::string::npos) {
				text.replace(start, m_badWords[i].length(), m_goodWords[i]);
				start += m_goodWords[i].length();
				num_replacements[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		size_t index = 0;
		out << "Spellchecker Statistics" << endl;
		for (auto& bad : m_badWords) {
			out << right << setw(15) << bad << ": " << num_replacements[index] << " replacements" << endl;
			index++;
		}
	}

}