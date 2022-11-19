#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include"memo.h"


void help_function(char *str)
{
    FILE *file;
// Opening file in read mode
file = fopen("help.txt","r");

char buffre[MAX_LINE];

while(!feof(file))
{
    //reading line by line
    fgets(buffre,MAX_LINE,file);
    //printing lines in terminal
    printf("%s",buffre);

}
//closing file
fclose(file);
}


void new_database(char *str)
{
    //Opening file in write mode
   FILE *fp;
   fp= fopen(str,"w");
   

    //checking file opening
    if (fp == NULL)
    {
        printf("Error to open the file.");
       
    }
   
   //closing file
    
   fclose(fp);

 }


 void append_in_darabase(char *str)
 {  //Opening file in read and append mode
    FILE *file;
    file=fopen("memo.csv","a+");
    int id,i;
    char buffer[MAX_LINE];
    char c_id[MAX_LINE];

    if(file == NULL)
    {
        printf("Error to opening the file.");
    }

    while(!feof(file))
    {
        fgets(buffer,100,file);
    }
    //checking it is the frist entry in the file
    if(buffer[0]=='\0')
    {
        id=0;
    }
    else
    {   //finding the id
        for(i=0;buffer[i+1]==',';i++)
        {
            c_id[i]=buffer[i];
        }
        //converting string to int
        id=strtol(c_id,'\0',10);
            
    }

   
  
    // taking t in time function
    time_t t;
    //taking current time in t
    t = time(NULL);

    //Putting local time in struct tm
    struct tm tm = *localtime(&t);


    id++;
    
    fprintf(file,"%d,",id);
    fprintf(file,"%d-%d-%d ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900); //month count started from january and year from 1900
    fprintf(file,"%d:%d:%d,", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(file,"\"%s\"\n",str);

    //closing opend file
    fclose(file);
    // fclose(id_file); 


 }


void delete_entry(char *str)
{
    //Opening file read and temp write mode
    FILE *file, *temp;
        file = fopen("memo.csv","r");
        temp = fopen("temp___memo.csv","w");

    
    char buffer[MAX_LINE];
    int i;
    char temp_arr[20];

    //checking for error opening
    if(file==NULL)
    {
        printf("Error to open file.\n");
    }

    while(!feof(file))
    {
        fgets(buffer,MAX_LINE,file);
        //making a new array  from buffer till frist ','
        for(i=0;buffer[i+1]==',';i++)
        {
            temp_arr[i]=buffer[i];
        }
        //comparing the new array with given value
        if(strcmp(temp_arr,str)!=0)
        {
            //writing in temp file which are not same
            fprintf(temp,"%s",buffer);
        }
    }
        
    //closing file
    fclose(file);
    fclose(temp);

    //updating memo file
    remove("memo.csv");
    rename("temp___memo.csv","memo.csv");
    

}


void search_function(char *str)
{   //Opening file in read mode
    FILE *file;
    file = fopen("memo.csv","r");

    char buffer[MAX_LINE];
    //checking error to open the file
    if(file==NULL)
    {
        printf("Error to open file.");
    }
    while(!feof(file))
    {   //reading line by line 
        fgets(buffer,MAX_LINE,file);
        //checking buffer string with the given string
        //if it is not NULL then printing it in terminal
        if(strstr(buffer,str)!=NULL)
        {
            printf("%s",buffer);
        }
    }
    //closing the file
    fclose(file);
}




