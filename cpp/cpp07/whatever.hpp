#include <iostream>

template <typename T>
class Whatever
{
	private:

	public:
		Whatever();
		Whatever(Whatever const& w);
		~Whatever();
		Whatever&	operator=(Whatever const& w);

		void		swap(T& a, T& b);
		T const&	min(T const& a, T const& b);
		T const&	max(T const& a, T const& b);
};
