/*
NAME - AKASH YADAV
EMAIL - ayadav35@myseneca.ca
STUDENT ID  - 172566218
DATE- 25/MAY/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>
#include <string>

namespace sdds {

	class TennisMatch {
	public:
		std::string t_id="";
		std::string t_name="";
		unsigned int m_id=0;
		std::string w_name="";
		std::string l_name="";

		TennisMatch();
		
		TennisMatch(const std::string& id, const std::string& name, int Matchid, const std::string& winner, const std::string& last);

		bool is_empty();

		friend std::ostream& operator<<(std::ostream& ostr, TennisMatch& tMatch);

	};

	class TennisLog {
		TennisMatch* tmatches = nullptr;
		int match_count = 0;
	public:
		
		TennisLog();

		TennisLog(const std::string& file);

		void addMatch(TennisMatch& match);

		TennisLog findMatches(const std::string& p_name);

		TennisMatch& operator[](size_t index);

		operator size_t()const;
		

		// Rule of 5

		TennisLog& operator=(const TennisLog& tennis);

		TennisLog(const TennisLog& copyTennis);

		TennisLog& operator=(TennisLog&& tennis);

		TennisLog(TennisLog&& moveTennis);

		~TennisLog();

	};

	

}

#endif