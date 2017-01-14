#ifndef FORMFEED_H
#define FORMFEED_H

#include <iostream>
#include "error.hpp"
class FormFeed
{
	public:
		FormFeed(int = 0);
		Error sendFormFeed();
		Error createFormFeed();
		void printSmth();
		//	~FormFeed();
	private:
		int numberos;
};
#endif