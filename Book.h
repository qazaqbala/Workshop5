
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book
	{
	private:
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
		template <class T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		
		}
	};
}
#endif // !SDDS_BOOK_H

