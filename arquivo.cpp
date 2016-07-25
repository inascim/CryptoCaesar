#include <iostream>
#include <string>
#include "arquivo.h"
#include <stdio.h>
#include <fstream>
using namespace std;

arquivo::arquivo (string nome): fileName (nome){}

string  arquivo::getFileName()
{
		return fileName;
}

int arquivo::abrir(string mode)
{
        //cout<< fileName<< endl;

        if (mode=="r"){
        //cout<< "mode eh R"<<endl;
		ArqInput.open(fileName.c_str());
		}

        if (mode=="w"){
        //cout<< "mode eh W"<<endl;
        string fileNameSaida="output" + fileName;
		ArqOutput.open( fileNameSaida.c_str());
        }

		if ((ArqInput.is_open())&&(mode=="r")){
            //cout << "Arquivo aberto para leitura com sucesso!"<<endl;
			return 1;
			}


		if ((ArqOutput.is_open())&&(mode=="w")){
           // cout << "Arquivo aberto para escrita com sucesso!"<<endl;
			return 1;
			}
        cout<< "Falha ao abrir o arquivo: " << fileName << endl;
		return 0;
}

void arquivo::fechar(string mode)
{
            if (mode=="w")
                ArqOutput.close();
			if (mode=="r")
                ArqInput.close();
}
