/*name - KirtanKumar Hirenkumar Patel
student no. = 174408211
seneca email- kpatel470@myseneca.ca
date - 04 / june

citation-:

 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/




#include "Dictionary.h"

namespace sdds {
    Dictionary::Dictionary() {
    }

    void Dictionary::set(const std::string& term, const std::string& definition) {
        m_term = term;
        m_definition = definition;
    }




    std::ostream& Dictionary::display(std::ostream& os) const {
        os << std::right << std::setw(20) << m_term << ": " << m_definition;
        return os;
    }





    std::ostream& operator<<(std::ostream& os, const Dictionary& definition) {
        return definition.display(os);
    }





    bool Dictionary::operator==(const Dictionary& definition) const {
        return m_term == definition.m_term && m_definition == definition.m_definition;
    }
}