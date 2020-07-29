#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_csv.h"

int checkFileType(char input[], char output[]){
   char *infile, *str = ".csv";
   char *outfile, *str2 = ".tl5";
   infile = input;
   outfile = output;

  if(strstr(infile,str ) != NULL && strstr(outfile,str2)!=NULL){
   return 1;
  }else if(strstr(infile,str2)!=NULL && strstr(outfile,str)!=NULL){
    return 0;
  }else{
    printf("Error, wrong formats for input and/or output file");
    exit(0);
  }
  return 0;
}

int main(void){

   printf("input the name of the input file\n");
   char inFile[50];
   scanf("%s", &inFile);
   printf("input the name of the output file\n");
   char out[50];
   scanf("%s", &out);
  
  if(checkFileType(&inFile, &out)){
     readCSV(&inFile, &out);
  }else{

     readTL5(&inFile, &out);
  }
 
  
  return 0;
}