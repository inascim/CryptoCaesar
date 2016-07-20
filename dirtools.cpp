#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
#include "dirtools.h"
using namespace std;

dirtools::dirtools (string caminho){
	path=caminho;
}

void dirtools::mostrarTxts (){
	DIR *directory;
	struct dirent *direntDir;
	directory = opendir(path.c_str());
	cout << "Os arquivos encontrados foram:" << endl;
	if (directory != NULL){
	   while (direntDir = readdir(directory)){
		  //printf("Filename: %s",direntDir->d_name);
		  int a=strlen(direntDir->d_name);
		  if ( a>= 4){
				if ( ((direntDir->d_name)[a-1]=='t') && 
				  ((direntDir->d_name)[a-2]=='x') && 
				  ((direntDir->d_name)[a-3]=='t') && 
				  ((direntDir->d_name)[a-4]=='.'))
					cout << direntDir->d_name << endl;
			}
		}
	}
	
	cout << "Fim da lista de arquivos encontrados." << endl;
}