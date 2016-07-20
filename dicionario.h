#ifndef DICK
#define DICK

#include <iostream>
#include <string>
#include <vector>
#include "arquivo.h"
using namespace std;

class dicionario: public arquivo{
	public:
		vector <string>  verbetes();
		int numVerbetes;
	private:

};
#endif
