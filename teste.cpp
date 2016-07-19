	#include <stdio.h>
	#include <dirent.h>
	#include <iostream>
	#include <string.h>
	using namespace std;
	
	int main (){
	DIR *dpdf;
	struct dirent *epdf;
	

	dpdf = opendir("./");
	if (dpdf != NULL){
   while (epdf = readdir(dpdf))
{
      //printf("Filename: %s",epdf->d_name);
      int a=strlen(epdf->d_name);
      if ( a>= 4){
			if ( ((epdf->d_name)[a-1]=='t') && 
			  ((epdf->d_name)[a-2]=='x') && 
			  ((epdf->d_name)[a-3]=='t') && 
			  ((epdf->d_name)[a-4]=='.'))
			    cout << epdf->d_name << endl;
          }
	}

	}
	}
