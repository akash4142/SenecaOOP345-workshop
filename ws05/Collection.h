/* Name - akash yadav
student id = 172566218
email - ayadav35
date - 25 - 06-2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds {

	template<typename T>
	class Collection {
	private:
		std::string c_name = "";
		T* c_array = nullptr;
		size_t c_size = 0;
		void (*c_observer)(const Collection<T>&, const T&);

	public:
		Collection(const std::string& name) {
			c_name = name;
			c_array = nullptr;
			c_size = 0;
			c_observer = nullptr;
		}
		// Deleting Copy Operations
		Collection(const Collection& collection) = delete;
		Collection& operator=(const Collection&) = delete;
		
		// Destructor
		~Collection() {
			delete[] c_array;
		}

		const std::string& name() const {
			return c_name;
		}

		size_t size() const {
			return c_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool flag = false;
			for (size_t i = 0; i < c_size; i++) {
				if (c_array[i].title() == item.title()) {
					flag = true;
				}
			}
			if (!flag) {
				T* temp = new T[c_size + 1];
				for (size_t i = 0; i < c_size; i++) {
					temp[i] = c_array[i];

				}
				temp[c_size] = item;
				c_size++;

				delete[] c_array;
				c_array = temp;

				if (c_observer) {
					c_observer(*this, item);
				}
			}

			return *this;
		}
				
				

		T& operator[](size_t idx) const {
			if (idx >= c_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
			}
			else {
				return c_array[idx];
			}
		}

		T* operator[](const std::string& title) const {
			for (int i = 0; static_cast<size_t>(i) < c_size; i++) {
				if (c_array[i].title() == title) {
					return &c_array[i];
				}
			}
			return nullptr;
		}
		

	};

	template<typename T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			ostr << collection[i];
		}
		return ostr;
	}

}


#endif