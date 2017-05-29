#include <iostream>
#include <string>
#include "mensagem.h"
#include <fstream>
#include "perlxsi.h"


#include "/usr/lib/x86_64-linux-gnu/perl/5.22/CORE/EXTERN.h"
#include "/usr/lib/x86_64-linux-gnu/perl/5.22/CORE/perl.h"


//#include "EXTERN.h"
//#include "perl.h"


using namespace std;

	mensagem::mensagem (string nome, int argc, char ** argv, char ** env):arquivo(nome){
	
		char *meuArgv[] = { (char*)  "" , (char*) "RSA3.pl" };
		// inicialização

		
		PERL_SYS_INIT3 (&argc, &argv, &env);
		
		// criação de um interpretador
		
		my_perl = perl_alloc();
		perl_construct(my_perl);
		PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
		
		// invocação do perl com argumentos
		
		perl_parse (my_perl, xs_init, 2, meuArgv, (char **) NULL);
		perl_run (my_perl);
	}
	
	
	
	mensagem::~mensagem(void)
{
	// limpeza
	perl_destruct(my_perl);
	perl_free(my_perl);
    // término
	PERL_SYS_TERM();
}


void mensagem::criptografar (int tamanhoChave)
{
	sizeKey = tamanhoChave;
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
		//void *ponte  = new unsigned long long;
		ArqInput.read (buffer, tamanhoArquivo);
		
		const char * arqName = fileName.c_str();	//possivel erro de string const	

		const int tamanhoChave2 = sizeKey;
		
		//copiado do slide	
		//parte propicia a dar erro
		
			dSP;
			ENTER;
			SAVETMPS;
			PUSHMARK(SP);
			XPUSHs (sv_2mortal(newSViv(tamanhoChave2)));
			PUTBACK;
			call_pv("KeysGen", G_SCALAR);
			SPAGAIN;		
			endHash = POPi;
			PUTBACK;
			FREETMPS;
			LEAVE;
		
		//copiado do slide	
		//parte propicia a dar erro
		

			const int enderecoHash = endHash;

//			dSP;
			ENTER;
			SAVETMPS;
			PUSHMARK(SP);
			XPUSHs (sv_2mortal(newSViv(enderecoHash)));
			XPUSHs (sv_2mortal(newSVpv(arqName,0)));
			PUTBACK;
			call_pv("code", G_SCALAR);
			SPAGAIN;		
			string arqCode(POPp);
			PUTBACK;
			FREETMPS;
			LEAVE;
		
		//cout<< "Criptografado com sucesso! Salvo arquivo criptografado em: output"<< fileName << endl;
		
		fechar("r");
		fechar("w");
	}
	else {
		cout << "Falha ao abrir o arquivo de mensagem! Tente novamente" << endl;
	}
	//Finaliza o interpretador de perl;
}

void mensagem::descriptografar ()
{
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
		
		const char * arqName = fileName.c_str();	//possivel erro de string const	

		const int enderecoHash = endHash;
		
		//copiado do slide	
		//parte propicia a dar erro
		
			dSP;
			ENTER;
			SAVETMPS;
			PUSHMARK(SP);
			XPUSHs (sv_2mortal(newSViv(enderecoHash)));
			XPUSHs (sv_2mortal(newSVpv(arqName,0)));
			PUTBACK;
			call_pv("decode", G_SCALAR);
			SPAGAIN;		
			string arqDecode(POPp);
			PUTBACK;
			FREETMPS;
			LEAVE;
		
		//cout<< "Descriptografado com sucesso! Salvo arquivo descriptografado em: output"<< fileName << endl;
		
		fechar("r");
		fechar("w");
	}
	else {
		cout << "Falha ao abrir o arquivo! Tente novamente" << endl;
	}
	//Finaliza o interpretador de perl;
}
