#include <iostream>
#include <iomanip>
#include "Movie.h"


namespace sdds {
	Movie::Movie(): m_title(""), m_yearOfRelease(0), m_description(""){}

	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		std::string str = strMovie;
		std::string index = "";

		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_title = index;
		str.erase(0, str.find(",") + 1);
		index.clear();

		index = str.substr(0, str.find(","));
		m_yearOfRelease = stoul(index);
		str.erase(0, str.find(",") + 1);
		index.clear();

		index = str.substr(0);
		index.erase(0, index.find_first_not_of(' '));
		index.erase(index.find_last_not_of(' ') + 1);
		m_description = index;
		str.erase(0);
		index.clear();
	}


	std::ostream& operator<<(std::ostream& ostr, const Movie& movie) {
		ostr << std::setw(40) << std::right << movie.m_title << " | " << std::setw(4) << movie.m_yearOfRelease
			<< " | " <<std::left <<movie.m_description << std::endl;
		return ostr;
	}
}