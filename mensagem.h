#ifndef CABECAMSG
#define CABECAMSG


#include <iostream>
#include <string>
#include <fstream>
#include "arquivo.h"
using namespace std;

class mensagem: public arquivo {
	public:
	    mensagem(string, int, char ** , char**);
		void criptografar(string);
		void descriptografar(string);
	private:
		//string lerLinha (int);
};
#endif
