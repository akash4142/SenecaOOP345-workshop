/*
*****************************************************************************
						  Workshop - #8 (Part-2)
Full Name  : Akash yadav
Student ID#: 172566218
Email      : ayadav35@myseneca.ca
Date       : 26/07/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the valadity of SIN No's
		bool checkLuhn(const std::string& SIN) {
			int nDigits = SIN.length();

			int nSum = 0, isSecond = false;
			for (int i = nDigits - 1; i >= 0; i--) {  //Starting from the rightmost digit

				int d = SIN[i] - '0';

				if (isSecond == true)
					d = d * 2;    //double the value of every second digit 

				//If doubling of a number results in a two digit number, then add the digits to get a single digit number (e.g. 12: 1 + 2 = 3, 15: 1 + 5 = 6). 
				nSum += d / 10;   //add to sum the ten digit if there's one
				nSum += d % 10;   //add to sum the ones digit

				isSecond = !isSecond;   //only double every other digit
			}
			//If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid
			return (nSum % 10 == 0);
		}

		//TODO: Overload the += operator with a smart pointer as a second operand.
		void operator+=(const std::shared_ptr<T> &obj) {
			list.push_back(*obj);
		}
		
		//TODO: Overload the += operator with a raw pointer as a second operand.
		void operator+=(const T&& obj) {
			list.push_back(std::move(obj));
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
