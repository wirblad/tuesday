#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "safeinput.h"

void swap(int* nr1, int* nr2){

    int temp = *nr1;
    *nr1 = *nr2;
    *nr2 = temp;
}

void printIntArray(const int* array, int size){

    int i = 0;
    while(i<size){

        printf("VALUE%d: %d\n", i+1, *(array+i));
        i++;
    }
}

void printSumOfIntArray(int* array, int size){

    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += array[i];
    }
    printf("%d", sum);

}

void mostChar(){ //EV TA BORT MELLANSLAG

    char string[100] = "";
    int array[255];
    memset(array, 0, 255*sizeof(array[0]));
    GetInput("Enter string: ", string, sizeof(string));
    //printf("%lld", strlen(string));

    for(int i = 0; i < strlen(string);  i++){

        //printf("ASCII %d\n", string[i]);
        //printf("%c\n", string[i]);
        array[(int)string[i]]++;

    }

    int max = array[0];
    int place = 0;

    for(int i = 0; i < sizeof(array)/sizeof(int); i++ ){

            if(array[i]>max){
                max = array[i]; 
                place = i;
            }
    }

    printf("Most common char is %c that occurs %d times", (char)place, max);

}

void partOfString(){

    char string[100] = "";
    int start;
    int end;
    GetInput("Enter string: ", string, sizeof(string));
    GetInputInt("Enter start pos:  ", &start);
    GetInputInt("Enter start pos:  ", &end);

    printf("Between pos %d and %d the string is: ", start, end);
    for(int i = start; i < end; i++)
        printf("%c", string[i]);

}

void reversedCasing(){

    char string[100] = "";
    GetInput("Enter string: ", string, sizeof(string));

    
    for(int i = 0; i < strlen(string); i++){

        if(isupper(string[i]))
            printf("%c", tolower(string[i]));
    
        else
            printf("%c", toupper(string[i]));
    }

}

int removeNotLetters(char *Orig, char *New){

    int newIndex = 0;

    for(int i = 0; i < strlen(Orig); i++){
        
        
        if(isalpha(Orig[i])){
            New[newIndex] = Orig[i];
            newIndex++;
        }          
    }
    return 0;
}

void file(){

    FILE *fResult = fopen("test.txt", "r");

    if(fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(fResult);
        return;
    }

    char string[100] = "";
    while(fgets(string,250,fResult)){
        
        string[strlen(string)-1] = '\0';
        printf("%s", string);        
    }

    fclose(fResult);
}

void replaceLine(){

    char filepath[100] = "";
    char newLine[100] = "";
    int rowToReplace = 0;

    GetInput("Input the file name to be opened: ", filepath, sizeof(filepath));
    GetInput("Input the content of the new line: ", newLine, sizeof(filepath));
    GetInputInt("Input the line number you want to replace: ", &rowToReplace);

    FILE *f2 = fopen(filepath, "r");


    if(f2 == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(f2);
        return;
    }


    char buffer[1000] = "";
    char string[250] = "";
    int row = 1;

    while(fgets(string,250,f2)){
        
        if(row == rowToReplace){
            strcat(buffer,newLine);
            strcat(buffer,"\n");
        }
        else 
            strcat(buffer,string);
        row++;  
    }

    fclose(f2);

    FILE *f = fopen(filepath, "w");

    if(f == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(f);
        return;
    }

    fputs(buffer, f);

    fclose(f);

}

int main(){

    /*int nr1;
    int nr2;
    printf("ENTER TWO NUMERS WITH SPACE BETWEEN: ");
    scanf(" %d %d", &nr1, &nr2);
    swap(&nr1,&nr2);
    printf("TEST: %d %d", nr1, nr2);*/

    /*int *arr;
    int n;
    
    printf("WHAT IS N: ");
    scanf(" %d", &n);
    arr = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf(" %d", (arr+i));
    }
    printIntArray(arr, n);
    printSumOfIntArray(arr, n);*/

    //UPPG 2.3
    /*char string[100];
    printf("Enter string: ");
    scanf(" %s", string);

    //char check = string[0];
    int i = 0;
    bool same = true;

    while(i < strlen(string)){   

        if(string[0] != string[i] ){   
            same = false;    
        }
        i++;
    }

    if(same)
        printf("YES");
    else    
        printf("NO");*/

    //mostChar();
    //partOfString();
    //reversedCasing();
    /*char Orig[100] = "";
    char New[100] = "";
    GetInput("Enter string: ", Orig, sizeof(Orig));
    removeNotLetters(Orig, New);
    printf("ONLY LETTERS: %s", New);*/

    //file();

    //replaceLine();

    struct tm *timinfo;

    time_t tid;
    time(&tid);
    timinfo = localtime(&tid);
    printf("The current time is: %s", asctime (timinfo));

    printf("TEST %d ", timinfo->tm_mday);
    printf("TEST %d ", timinfo->tm_hour);
    printf("TEST %d ", timinfo->tm_min);
    printf("TEST %d ", timinfo->tm_sec);
    int seconds = ((timinfo->tm_mday) * 24 * 60 * 60) + ((timinfo->tm_hour) * 60 * 60) + (timinfo->tm_min*60) + timinfo->tm_sec;
    printf("\n%d seconds have passed since the beginning of the month", seconds) ;
    return 0;
}