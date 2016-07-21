#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "arquivo.h"
#include "dicionario.h"
#include "mensagem.h"
#include "dirtools.h"
//#include "C:\Perl64\lib\CORE\EXTERN.h"
//#include "C:\Perl64\lib\CORE\perl.h"

#include "/usr/lib/perl5/core_perl/CORE/EXTERN.h"
#include "/usr/lib/perl5/core_perl/CORE/perl.h"

using namespace std;

int main(int argc, char **argv, char **env)
{
	string opcaoMenu, nomedoArquivo,senha;
	while (opcaoMenu != "6"){
        // cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "Bem vindo ao CryptoCaesar!" << endl;
		cout << "(1) Listar todos os arquivos que se encontram no mesmo diretorio do programa" << endl;
		cout << "(2) Abrir e criptografar um arquivo especificado" << endl;
		cout << "(3) Abrir e descriptografar um arquivo especificado" << endl;
		cout << "(4) Tentar quebrar a senha de um arquivo criptografado" << endl;
		cout << "(5) Alguma outra parada" << endl;
		cout << "(6) Sair" << endl;
		cin >> opcaoMenu;
		if (opcaoMenu=="1"){
			const string caminhoAtual("./");
			dirtools meuDiretorio(caminhoAtual);
			meuDiretorio.mostrarTxts();
		}
		
		if (opcaoMenu=="2"){
			cout << "Digite o nome do arquivo" << endl;
			cin >> nomedoArquivo;
			mensagem myMsg(nomedoArquivo, argc, argv, env);
			cout << "Digite a senha:" << endl;
			cin >> senha;
			myMsg.criptografar(senha);
		}
		if (opcaoMenu=="3"){
			cout << "Digite o nome do arquivo" << endl;
			cin >> nomedoArquivo;
			mensagem myMsg(nomedoArquivo, argc, argv, env);
			cout << "Digite a senha:" << endl;
			cin >> senha;
			myMsg.descriptografar(senha);
		}
		
	}
	return 0;
}

