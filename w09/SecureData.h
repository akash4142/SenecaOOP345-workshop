/*
*****************************************************************************
						  Workshop - #9 (Part-2)
Full Name  : Akash yadav
Student ID#: 172566218
Email      : ayadav35@myseneca.ca
Date       : 02/08/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// Workshop 9 - Multi-Threading
// SecureData.h
#ifndef W9_SECUREDATA_H
#define W9_SECUREDATA_H

#include <iostream>

namespace w9
{
	class Cryptor {
	public:
		char operator()(char in, char key) const { return in ^ key; }
	};
	void converter(char*, char, int, const Cryptor&);

	class SecureData {
		char* text;
		std::ostream* ofs;
		int nbytes;
		bool encoded;
		void code(char);
	public:
		SecureData(const char*, char, std::ostream*);
		SecureData(const SecureData&) = delete;
		SecureData& operator=(const SecureData&) = delete;
		~SecureData();
		void display(std::ostream&) const;
		void backup(const char*);
		void restore(const char*, char);
	};
	std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif