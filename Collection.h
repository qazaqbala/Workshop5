#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
namespace sdds {

	template <class T>
	class Collection
	{
	private:
		std::string m_nameOfCollection;
		T* m_arr;
		size_t m_size;
		void (*m_obs)(const Collection<T>&, const T&);
		//extra var
		size_t m_capacity;
	public: 
		Collection(const std::string& name):m_nameOfCollection(""), m_arr(nullptr), m_size(0u), m_obs(nullptr), m_capacity(10u) {
			m_nameOfCollection = name;
		}

		Collection(const Collection&) = delete;

		~Collection() {
			delete[] m_arr;
		}

		const std::string& name() const {
			return m_nameOfCollection;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_obs = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool check = false;
			for (size_t i = 0u; i < m_size; i++) {
				if (m_arr[i].title() == item.title()) check = true;
			}
			/*
			if (check) return *this;

			T* temp_arr = m_arr;

			m_arr = new T[m_size + 1];
			for (size_t i = 0u; i < m_size; i++) {
				m_arr[i] = temp_arr[i];
			}

			m_arr[m_size] = item;

			m_size++;

			if (m_obs != nullptr) {
				m_obs(*this, item);
			}
			delete[] temp_arr;

			return *this;
			*/
			if (!check) {
			/*	T* tempArr = m_arr;
				
				m_arr = new T[m_size + 1];
				
				for (size_t i = 0u; i < m_size; i++)
					m_arr[i] = tempArr[i];
				
				m_arr[m_size] = item;
				m_size++;

				if (m_obs != nullptr)
					m_obs(*this, item);

				delete[] tempArr;*/
				//---------------WRONG----------
				
				T* temp = m_arr;
				m_arr = nullptr;
				m_arr = new T[m_size + 1];
				memcpy(m_arr, temp, m_size * sizeof(T));
				m_arr[m_size] = item;
				m_size++;
				
				if (m_obs != nullptr)
					m_obs(*this, item);

				
			}
			return *this;
			
		}

		T& operator[](size_t idx) const {
			if (idx < m_size) {
				return m_arr[idx];
			}
			std::string exception = { "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items." };
			throw std::out_of_range(exception);
		}
		T* operator[](const std::string& title) const {
			for (int i = 0; i < m_size; i++) {
				if (m_arr[i].title() == title)return &m_arr[i];
			}
			return nullptr;
		}
	};
	template <class T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& coll) {
		for (int i = 0; i < coll.size(); i++) {
			ostr << coll[i];
		}
		return ostr;
	}
}
#endif // !SDDS_COLLECTION_H

