/*
NAME - AKASH YADAV
EMAIL - ayadav35@myseneca.ca
STUDENT ID  - 172566218
DATE- 25/MAY/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <iostream>
#include <chrono>


namespace sdds {

	class Timer {
	public:
		std::chrono::high_resolution_clock::time_point startTime;
		
	public:
		
		void start();
		long long stop();

	};


}
#endif // !SDDS_TIMER_H
