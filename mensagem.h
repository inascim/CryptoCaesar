#ifndef CABECAMSG
#define CABECAMSG


#include <iostream>
#include <string>
#include <fstream>
#include "arquivo.h"


#include "EXTERN.h"
#include "perl.h"

using namespace std;

class mensagem: public arquivo {
	public:
	    mensagem(string, int, char ** , char**);
		~mensagem(void);
		void criptografar(string);
		void descriptografar(string);
	private:
		PerlInterpreter * my_perl; // O interpretador
		//string lerLinha (int);
};
#endif
