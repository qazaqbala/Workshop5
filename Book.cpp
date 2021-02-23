#include <iostream>
#include <iomanip>
#include "Book.h"


namespace sdds {
	Book::Book() {
		m_author = "";
		m_title ="";
		m_country = "";
		m_year = 0u;
		m_price = 0.0;
		m_description = "";
	}

	const std::string& Book::title() const { return m_title; }
	const std::string& Book::country() const { return m_country; }
	const size_t& Book::year() const { return m_year; }
	double& Book::price() { return m_price; }
	Book::Book(const std::string& strBook) {
		std::string str = strBook;
		std::string index = "";

		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_author = index;
		str.erase(0, str.find(",") + 1);
		index.clear();
		//std::cout << "OK 1" << std::endl;
		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_title = index;
		str.erase(0, str.find(",") + 1);
		index.clear();
		//std::cout << "OK 2" << std::endl;

		index = str.substr(0, str.find(","));
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_country = index;
		str.erase(0, str.find(",") + 1);
		index.clear();
		//std::cout << "OK 3" << std::endl;

		index = str.substr(0, str.find(","));
		m_price = stod(index);
		str.erase(0, str.find(",") + 1);
		index.clear();
		//std::cout << "OK 4" << std::endl;

		index = str.substr(0, str.find(","));
		m_year = stoul(index);
		str.erase(0, str.find(",") + 1);
		index.clear();
		//std::cout << "OK 5" << std::endl;

		index = str.substr(0);
		index.erase(index.find_last_not_of(' ') + 1);
		index.erase(0, index.find_first_not_of(' '));
		m_description = index;
		str.erase(0);
		index.clear();
		//std::cout << "OK 6" << std::endl;

	}
	
	std::ostream& operator<<(std::ostream& ostr, const Book& book) {
		ostr << std::right << std::setw(20) << std::setfill(' ') << book.m_author << " | "
			<< std::setw(22) << book.m_title << " | "
			<< std::setw(5) << book.m_country << " | "
			<< std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
			ostr << std::left << book.m_description << std::endl;
		return ostr;
	}
}