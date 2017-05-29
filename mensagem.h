#ifndef CABECAMSG
#define CABECAMSG


#include <iostream>
#include <string>
#include <fstream>
#include "arquivo.h"


#include "/usr/lib/x86_64-linux-gnu/perl/5.22/CORE/EXTERN.h"
#include "/usr/lib/x86_64-linux-gnu/perl/5.22/CORE/perl.h"


//#include "EXTERN.h"
//#include "perl.h"

using namespace std;

class mensagem: public arquivo {
	public:
	    mensagem( string,  int, char ** , char**);
		~mensagem(void);
		void criptografar(int);
		void descriptografar();

	private:
		int endHash;
		int sizeKey;
		PerlInterpreter * my_perl; // O interpretador
		//string lerLinha (int);
};
#endif
