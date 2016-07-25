#ifndef DICK
#define DICK

#include <iostream>
#include <string>
#include <vector>
#include "arquivo.h"
using namespace std;

class dicionario: public arquivo{
	public:
		dicionario (string);
		int verificaMatch(string);
		vector <string>  verbetes;
		int numVerbetes;
		int aberto;
		
	private:
	

};
#endif
