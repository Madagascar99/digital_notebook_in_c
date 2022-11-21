#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#include"memo.h"

char *file_name1;

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


char *new_database(char *str)
{
   FILE *name_file, *data_file;
    name_file=fopen("name_file.txt","a+");

    char file_name[30];
    char option;
   
    while(!feof(name_file))
    {
       fscanf(name_file,"%s",file_name);
        
        if(strcmp(file_name,str)==0)
        {
             
            break;

        }
           
    }

    if(strcmp(file_name,str)==0)
    {
        printf("file is already exist over write [y n]: ");
        scanf(" %c",&option);
        if(option=='y')
        {
            data_file=fopen(str,"w");
            fclose(data_file);
            
        }
        else
        {
            printf("Enter the file name: ");
            scanf(" %s",str);
            new_database(str);
        }
    }
    else
    {
        data_file= fopen(str,"w");
        fprintf(name_file,"%s\n",str);
        fclose(data_file);
    }
    //file_name1=str;
    fclose(name_file);
return str;
 }


 void append_in_darabase(char *str)
 {  //Opening file in read and append mode
    FILE *file;
    file=fopen(file_name1,"a+");
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
    bool keep_reading =true;

    //checking for error opening
    if(file==NULL)
    {
        printf("Error to open file.\n");
    }
    
    
    
    do{
        //reading file line by line
        fgets(buffer,MAX_LINE,file);

        //checking for end of file
        if(feof(file))
        {
            keep_reading=false; 
        }
        else
        { 
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

        
    }while (keep_reading);
 
        
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
    bool keep_reading =true;
    
    
    do{
        //reading file line by line
        fgets(buffer,MAX_LINE,file);
        
        ////checking for end of file
        if(feof(file))
        {
            keep_reading=false; 
        }
        else
        {   //comparing buffer with given string and
            // if it same then printing whole string in terminal
            if((strstr(buffer,str)!=NULL))
            {
                printf("%s",buffer);
            }

        }

        
    }while (keep_reading);
  
    fclose(file);
}




