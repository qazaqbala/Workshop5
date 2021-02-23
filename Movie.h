#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
namespace sdds {
	class Movie
	{
	private:
		std::string m_title;
		size_t m_yearOfRelease;
		std::string m_description;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <class T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);
	};

}
#endif // !SDDS_MOVIE_H

