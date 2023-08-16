/*
NAME - AKASH YADAV
EMAIL - ayadav35@myseneca.ca
STUDENT ID  - 172566218
DATE- 25/MAY/2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>
#include <iomanip>
#include <string>
#include <fstream>
#include "TennisLog.h"
#include "TennisLog.h"

using namespace std;

namespace sdds {

	


	TennisMatch::TennisMatch()
	{
		std::string t_id = "";
		std::string t_name = "";
		std::string w_name = "";
		std::string l_name = "";
	}

	TennisMatch::TennisMatch(const std::string& id, const std::string& name, int Matchid, const std::string& winner, const std::string& last) {

		t_id = id;
		t_name = name;
		m_id = Matchid;
		w_name = winner;
		l_name = last;
	}
	
	
	bool TennisMatch::is_empty()  {
		if (t_id.empty() || t_name.empty() || w_name.empty() || l_name.empty() || m_id <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
	


	std::ostream& operator<<(std::ostream& ostr, TennisMatch& tMatch) {
		if (tMatch.t_id.empty() || tMatch.t_name.empty() || tMatch.w_name.empty() || tMatch.l_name.empty() || tMatch.m_id == 0) {
			ostr << "Empty Match";
			return ostr;
		}
		else{
			ostr << right << setw(20)<< setfill('.') << "Tourney ID" << " : " << left << setw(30) << setfill('.') << tMatch.t_id << '\n';
			ostr << right << setw(20) << "Match ID"<< " : " << left << setw(30) << setfill('.') << tMatch.m_id << '\n';
			ostr << right << setw(20) << "Tourney" << " : " << left << setw(30) << setfill('.') << tMatch.t_name << '\n';
			ostr << right << setw(20) << "Winner" << " : " << left << setw(30) << setfill('.') << tMatch.w_name << '\n';
			ostr << right << setw(20) << "Loser" << " : " << left << setw(30) << setfill('.') << tMatch.l_name << '\n';
			return ostr;
		}
		return ostr;
		
	}

	TennisLog::TennisLog() {
		match_count = 0;
		tmatches = nullptr;
	}

	TennisLog::TennisLog(const std::string& file) {
		
		ifstream in(file);
		string line;
		std::getline(in, line);


		while (getline(in, line)) {
			match_count++;
		}



		tmatches = new TennisMatch[match_count];
		
		in.clear();
		in.seekg(0, std::ios::beg);

		std::getline(in, line);


		for (int i = 0; i < match_count; i++) {

			getline(in, tmatches[i].t_id, ',');
			getline(in, tmatches[i].t_name, ',');
			in >> tmatches[i].m_id;
			in.ignore();
			getline(in, tmatches[i].w_name, ',');
			getline(in, tmatches[i].l_name, '\n');

			
		}

		in.close();

	}

	void TennisLog::addMatch(TennisMatch& match) {

		
		TennisMatch* newMatches = new TennisMatch[match_count+1];

		for (int i = 0; i < match_count; ++i) {
			newMatches[i] = tmatches[i];
		}
		newMatches[match_count] = match;

		delete[] tmatches;
		
		tmatches = newMatches;
		
		match_count++;


	}

	TennisLog TennisLog::findMatches(const string& p_name)
	{

		TennisLog findedMatch;
		
		for (size_t i = 0; i < static_cast<size_t>(match_count); i++) {
			if (tmatches[i].w_name==p_name || tmatches[i].l_name==p_name) {
				findedMatch.addMatch(tmatches[i]);
				
			}
		}
		
		return findedMatch;

	}


	TennisMatch& TennisLog::operator[](size_t index) {
		if (index <static_cast<size_t>(match_count)) {
		
			return this->tmatches[index];
		}
		else {
			static TennisMatch emptyMatch;
			return emptyMatch;
		}
	}


	TennisLog::operator size_t() const {

		return match_count;
	}

	
	TennisLog::TennisLog(const TennisLog& copyTennis) {
		*this = copyTennis;
	}

	TennisLog& TennisLog::operator=(const TennisLog& tennis) {
		if (this != &tennis) {
			delete[] tmatches;
			tmatches = nullptr;
			if (tennis.tmatches != nullptr) {
				tmatches = new TennisMatch[tennis.match_count];
				for (size_t i = 0; i<static_cast<size_t>(tennis.match_count); i++) {
					tmatches[i] = tennis.tmatches[i];
				}
			}
			match_count = tennis.match_count;
		}

		return *this;
	}

	TennisLog& TennisLog::operator=(TennisLog&& tennis) {

		if (this != &tennis) {
			delete[] tmatches;
			
			tmatches = tennis.tmatches;
			tennis.tmatches = nullptr;

			match_count = tennis.match_count;
			tennis.match_count = 0;


		}
		return *this;

	}

	TennisLog::TennisLog(TennisLog&& moveTennis) {
		*this = std::move(moveTennis);
	}

	TennisLog::~TennisLog() {
		
		delete[] tmatches;
		
	}
	

}