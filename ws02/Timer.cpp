/*
NAME - AKASH YADAV
EMAIL - ayadav35@myseneca.ca
STUDENT ID  - 172566218
DATE- 25/MAY/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Timer.h"

using namespace std;



namespace sdds {

	

	void Timer::start() {
		startTime = std::chrono::high_resolution_clock::now();
		
	}

	long long Timer::stop() {
		

		std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
		

		return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
	}



}


