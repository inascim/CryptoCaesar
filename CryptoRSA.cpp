#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "arquivo.h"
#include "dicionario.h"
#include "mensagem.h"
#include "dirtools.h"
//#include "C:\Perl64\lib\CORE\EXTERN.h"
//#include "C:\Perl64\lib\CORE\perl.h"   <--- do note do Panak

#include "/usr/lib/x86_64-linux-gnu/perl/5.22/CORE/EXTERN.h"
#include "/usr/lib/x86_64-linux-gnu/perl/5.22/CORE/perl.h"

//#include "/usr/lib/perl5/core_perl/CORE/EXTERN.h"
//#include "/usr/lib/perl5/core_perl/CORE/perl.h" 

//#include "EXTERN.h"
//#include "perl.h"

using namespace std;

int main(int argc, char **argv, char **env)
{
	string opcaoMenu, nomeDoArquivo, senha, nomeDoDicionario;
	string melhorSenha;
	int numMatches, melhorMatches, tamanhoChave, carry;
	while (opcaoMenu != "6"){
        // cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "Bem vindo ao CryptoRSA!" << endl;
		cout << "(1) Listar todos os arquivos que se encontram no mesmo diretorio do programa" << endl;
		cout << "(2) Abrir e criptografar um arquivo especificado" << endl;
		cout << "(3) Abrir e descriptografar um arquivo especificado" << endl;
		cout << "(4) Tentar quebrar a senha de um arquivo criptografado" << endl;
		cout << "(5) Ler um arquivo e imprimir seu conteudo na tela" << endl;
		cout << "(6) Sair" << endl;
		cin >> opcaoMenu;
		if (opcaoMenu=="1"){
			const string caminhoAtual("./");
			dirtools meuDiretorio(caminhoAtual);
			meuDiretorio.mostrarTxts();
		}
		
		if (opcaoMenu=="2"){
			cout << "Digite o nome do arquivo" << endl;
			cin >> nomeDoArquivo;
			mensagem myMsg(nomeDoArquivo, argc, argv, env);
			cout << "Digite o tamanho da chave:" << endl;
			cin >> tamanhoChave;
			myMsg.criptografar(tamanhoChave);
			return 0;
		}
		if (opcaoMenu=="3"){
			cout << "Digite o nome do arquivo a ser descriptografado" << endl;
			cin >> nomeDoArquivo;
			mensagem myMsg(nomeDoArquivo, argc, argv, env);
			myMsg.descriptografar();
			return 0;
		}
		if (opcaoMenu=="4"){
			string palavra;
			senha="a";
			int tamMaxSenha=5;
			cout << "Digite o nome do arquivo que contém o dicionário de palavras" << endl;
			cin >> nomeDoDicionario;
			dicionario meuDic(nomeDoDicionario);
			melhorMatches = 0;
			if (meuDic.aberto==1){
				cout << "Digite o nome do arquivo a tentar ser descriptografado" << endl;
				cin >> nomeDoArquivo;
				mensagem myMsg(nomeDoArquivo, argc, argv, env);
				melhorSenha='a';
				carry=1;
				cout << "Digite o numero maximo de caracteres a serem tentados para a senha:" <<endl;
				cin >> tamMaxSenha;
				while (senha.length() < tamMaxSenha){
					
					
					
					// incrementa a string senha;
					//cout << senha << endl;
					for (int i=senha.length()-1; i>=0; i--){
						if (carry==1){
							if (senha[i]=='z'){
								senha[i]='a';
								carry=1;
							}
							else {
								senha[i]=senha[i] + 1;
								carry=0;
							}
						}							
					}
					if (carry==1){
						senha = "a" + senha;
					}
					carry=1;
					////////////////////////////
					
					//tenta descriptografar com ela;
					
					myMsg.descriptografar();
					
					//verifica cada palavra do output, e chama o verificaMatch()
					arquivo tentativaSenha ("output"+nomeDoArquivo);
					tentativaSenha.abrir("r");
					numMatches=0;
					while (tentativaSenha.ArqInput >> palavra){
						if (meuDic.verificaMatch(palavra)){
							numMatches++;
						}
					}
					tentativaSenha.fechar("r");
					////////////////////////////////////
					//Se muitos outputs, atualiza melhor senha, e trouls
					if (numMatches>melhorMatches) {
						melhorMatches = numMatches;
						melhorSenha = senha;
					}
				}
				cout << "A senha com maior numero de matches com o dicionario fornecido foi:" << endl;
				cout << melhorSenha <<endl;
				cout << "Com " << melhorMatches << " matches." << endl;
				
				
			}
			else {
			 cout << "Falha ao abrir o arquivo de dicionário!" << endl;
			}
		}
		if (opcaoMenu=="5"){
			cout << "Digite o nome do arquivo a ser lido" << endl;
			cin >> nomeDoArquivo;
			arquivo leitura(nomeDoArquivo);
			if (leitura.abrir("r")){
				leitura.ArqInput.seekg(0, std::ios::end);
				int tamanhoArquivo = leitura.ArqInput.tellg();
				leitura.ArqInput.seekg(0, std::ios::beg);
				char *buffer = new char[tamanhoArquivo+1];
				leitura.ArqInput.read (buffer, tamanhoArquivo);
				string lido=buffer;
				cout << "Conteudo do arquivo:" << endl;
				cout << lido<< endl;
				cout << "Fim do conteudo do arquivo." << endl;
			}
			else {
				cout << "Falha ao abrir o arquivo! Tente novamente" << endl;
			}
		}

		
	}
	return 0;
}
