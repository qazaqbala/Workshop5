#include <fstream>
#include <iomanip>
#include "SpellChecker.h"


namespace sdds {
	size_t SpellChecker::m_times[6] = { 0 };
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		std::string strWords;
		int i = 0;
		do {
			std::getline(file, strWords);
			if (strWords != "") {
				std::string idx = "";

				idx = strWords.substr(0, strWords.find(' '));
				m_badWords[i] = idx;
				idx.clear();
				strWords.erase(0, strWords.find(' ') + 1);
				strWords.erase(strWords.find_last_not_of(' ') + 1);
				strWords.erase(0, strWords.find_first_not_of(' '));
				m_goodWords[i] = strWords;
				//--------
				i++;
			}
			
		} while (!file.eof());
		file.close();
	}
	/*std::string str = strBook;
		std::string index = "";

		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_author = index;
		str.erase(0, str.find(",") + 1);
		index.clear();*/

	void SpellChecker::operator()(std::string& text) {
		int idx;
		for (int i = 0; i < 6; i++) {
			
			do {
				idx = text.find(m_badWords[i]);
				if (idx != -1) {
					text.replace(idx, m_badWords[i].length(), m_goodWords[i]);
					m_times[i] += 1;
				}
				
			}while(idx != std::string::npos);
			/*
			idx = text.find(m_badWords[i]);
			if (idx != std::string::npos) {
				text.replace(idx, m_badWords[i].length(), m_goodWords[i]);
				m_times[i] += 1;
			}
			*/
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		std::cout << "Spellchecker Statistics" << std::endl;
		for (auto i = 0u; i < 6; i++) {
			out << std::setw(15) << m_badWords[i] << ": " << m_times[i] << " replacements" << std::endl;
		}
	}
}
