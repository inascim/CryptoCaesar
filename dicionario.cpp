#include <iostream>
#include <string>
#include "dicionario.h"
using namespace std;

dicionario::dicionario (string nome): arquivo(nome), numVerbetes (0){
	aberto=0;
	if (abrir ("r")){
		aberto=1;
		string palavra;
		while (ArqInput >> palavra ){
			verbetes.push_back(palavra);
			numVerbetes++;
		}
		cout << "Foram carregados " << numVerbetes << "verbetes" << endl;
	}
	else {
		cout << "Falha ao abrir o arquivo! Tente novamente" << endl;
	}
}

int dicionario::verificaMatch (string palavra){
		for (int i=0; i<numVerbetes ; i++){
				if (verbetes.at(i)==palavra){
					return 1;
				}
		}
	return 0;
}	
