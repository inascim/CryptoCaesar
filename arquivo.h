#ifndef FILLET
#define FILLET

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class arquivo {
	public:
		arquivo (string);

		string getFileName();
		ifstream ArqInput;
		ofstream ArqOutput;

		int abrir(string);
		void fechar(string);

	protected:
		string fileName;
	};
#endif
