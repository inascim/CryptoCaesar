#include <iostream>
#include <string>
#include "mensagem.h"
#include <fstream>

#include "/usr/lib/perl5/core_perl/CORE/EXTERN.h"
#include "/usr/lib/perl5/core_perl/CORE/perl.h"

using namespace std;

	mensagem::mensagem (string nome, int argc, char ** argv, char ** env):arquivo(nome){
	
	char *meuArgv[] = { (char*)  "" , (char*) "Pythonmelhor.pl" };
	// inicialização
	
	PERL_SYS_INIT3 (&argc, &argv, &env);
	
	// criação de um interpretador
	
	my_perl = perl_alloc();
	perl_construct(my_perl);
	PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
	
	// invocação do perl com argumentos
	
	perl_parse (my_perl, NULL, 2, meuArgv, (char **) NULL);
	perl_run (my_perl);
	}


void mensagem::criptografar (string senha)
{
	//inicializa o interpretador perl
	//
	//fseek(f, 0, SEEK_END);
	//long fsize = ftell(f);
	//fseek(f, 0, SEEK_SET);

	if (abrir("r")){
    abrir("w");

    //char  *linhaAtual= new char [senha.length()+1];

    ArqInput.seekg(0, std::ios::end);
    int tamanhoArquivo = ArqInput.tellg();
    ArqInput.seekg(0, std::ios::beg);
    char *buffer = new char[tamanhoArquivo+1];
    ArqInput.read (buffer, tamanhoArquivo);
	
	const int len = senha.length();
	const char * senha2 = senha.c_str();

	//copiado do slide	
	//parte propicia a dar erro
	
		dSP;
		ENTER;
		SAVETMPS;
		PUSHMARK(SP);
		XPUSHs (sv_2mortal(newSViv(len)));
		XPUSHs (sv_2mortal(newSVpv(senha2,0)));		
		XPUSHs (sv_2mortal(newSVpv(buffer,0)));
		PUTBACK;
		call_pv("code", G_SCALAR);
		SPAGAIN;		
		string resultado(POPp);
		PUTBACK;
		FREETMPS;
		LEAVE;
	
	resultado.resize(tamanhoArquivo);
	cout << "Estamos no cpp" << tamanhoArquivo << endl << resultado << endl;
	
	fechar("r");
	fechar("w");
	}
	//Finaliza o interpretador de perl;
}
