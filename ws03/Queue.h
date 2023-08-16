/*name - KirtanKumar Hirenkumar Patel
student no. = 174408211
seneca email- kpatel470@myseneca.ca
date - 04 / june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Dictionary.h"

namespace sdds {



	template <typename T, unsigned int capacity> //template declaration
	class Queue {


	protected:


		T m_queue[capacity];
		unsigned Size = 0;
		T object;

	public:


		Queue() : object() {  // default constructor
			Size = 0;
		}

		virtual ~Queue() {}



		virtual bool push(const T& item) { //push function
			bool done = false;

			if (Size < capacity) {
				m_queue[size()] = item;
				Size++;
				done = true;
			}

			return done;
		}






		T pop() { //pop function
			T temp = m_queue[0];

			for (unsigned i = 0; i < Size - 1; i++) {
				m_queue[i] = m_queue[i + 1];
			}
			Size--;
			return temp;
		}






		unsigned size() const {
			return Size;
		}



		T& operator[](unsigned index) // overloading [] operator
		{
			if (index >= size())
			{
				return object;
			}
			else return m_queue[index];
		}




		std::ostream& display(std::ostream& ostr = std::cout) const {
			ostr << "----------------------\n";
			ostr << "| Dictionary Content |\n";
			ostr << "----------------------\n";
			for (unsigned i = 0; i < size(); i++) {
				ostr << m_queue[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
			return ostr;
		}

	};






	template<>
	Dictionary& Queue<Dictionary, 100u>::operator[](unsigned index) {
		if (index > Size) {
			m_queue[index].set("Empty Term", "Empty Substitute");
		}
		return m_queue[index];
	}
}
#endif