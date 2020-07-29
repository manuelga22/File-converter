#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TOKENLENGTH 5

char * cutString(char *token){//helper function 
    char *newString=(char*)malloc(sizeof(token));
    for(int a = 0 ; a < TOKENLENGTH ; a++){
        newString[a] = token[a];
    }
    return newString;
}

char * removeSpaces(char *token){
  char *newString=(char*)malloc(strlen(token));
   for(int a = 0 ; a < strlen(token) ; a++){
       if(!isspace(token[a])){
          newString[a] = token[a];
       }   
   }
 
  return newString;
}

void toTL5 (FILE *out_file, char *token){
    char *out = (char*)malloc(sizeof(token));
    out = token;    
    if(strlen(out)<5){
        fprintf(out_file,"|%-5s", out);  
        printf("|%-5s", out);           
    }else if(strlen(out)>5){
        out = cutString(out);
        fprintf(out_file,"|%-5s", out);  
        printf("|%-5s", out);  
    }
}

void toCSV(FILE *out_file, char *token){
    char *out = (char*)malloc(sizeof(token));
    out = removeSpaces(token);
    printf("%s", out);
    fprintf(out_file,"%s",out);
    if(token != NULL && token != '\0'){
      printf(",");
      fprintf(out_file,",");
    }
   
}

//if input file is a .tl5
void readTL5(char *inFile , char *output){
   FILE *the_file = fopen(inFile,"r");
   FILE *out_file = fopen(output, "w");
   if(the_file == NULL){
        perror("couldn't open INPUT file");
        exit(1);
   }else if(out_file == NULL){
        perror("couldn't open OUTPUT file");
        exit(1);
   }
   char line[200];
   while(fgets(line, sizeof(line), the_file)){
      char *token;
      token = strtok(line,"|");
      while(token != NULL){
        toCSV(out_file, token);
        token = strtok(NULL, "|");
      }
      if(token == NULL){
         printf("\n");
         fprintf(out_file,"\n");
      }
   }
}

//if input file is a .csv
void readCSV(char *inFile , char *output){
    FILE *the_file = fopen(inFile,"r");
    FILE *out_file = fopen(output, "w");

    if(the_file == NULL){
        perror("couldn't open INPUT file");
        exit(1);
    }else if(out_file == NULL){
        perror("couldn't open OUTPUT file");
        exit(1);
    }
    char line[200];
    while(fgets(line, sizeof(line), the_file)){
        char *token;
        token = strtok(line, ",");
        while(token != NULL){
            toTL5(out_file, token);
            token = strtok(NULL, ",");
        }
        printf("\n");
        fprintf(out_file,"\n");
    }
}


