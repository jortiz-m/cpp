#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>

class Base {
	public:
		virtual	~Base();

		static Base*	generate();
		static void		identify(Base* p);
		static void		identify(Base& p);
};

#endif