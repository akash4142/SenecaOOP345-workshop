/*name - KirtanKumar Hirenkumar Patel
student no. = 174408211
seneca email- kpatel470@myseneca.ca
date - 04 / june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"

namespace sdds {
	


	template <typename T>
	class UniqueQueue :public Queue<T, 100> { 
	public:





		bool push(const T& item) {
			bool done = false;
			for (unsigned i = 0; i < Queue<T, 100>::size(); i++) {
				if (Queue<T, 100>::m_queue[i] == item) {
					return done;
				}
			}
			return Queue<T, 100>::push(item);
		}

	};
	



	
	template <>
	bool UniqueQueue<double>::push(const double& item) {
		bool done = false;
		for (unsigned i = 0; i < Queue <double, 100>::size(); i++) {
			
			if (std::abs(Queue<double, 100>::m_queue[i] - item) <= 0.005) {
				return done;
			}
		}
		return Queue<double, 100>::push(item);
	}
}


#endif 