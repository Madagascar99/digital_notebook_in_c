#include<stdio.h>

int main(int argc, char *argv[])
{    
    //declaring and initializing 

    char h_string[3]="-h";
    char i_string[3]="-i";
    char a_string[3]= "-a";
    char s_string[3]= "-s";
    char d_string[3]="-d";

    // checking giving parameter
    if(argc<2 || argc>3)
    {
        printf("Enter the righr amount of paramiter.");
    }
    

    // checking condition and calling respective function
    
    else if((strcmp(argv[1],h_string))==0)
    {
        help_function(argv[1]);
    }
    else if((strcmp(argv[1],i_string))==0)
    {
        
        new_database(argv[2]);
    }
    else if((strcmp(argv[1],a_string))==0)
    {
        append_in_darabase(argv[2]);
    }
    else if((strcmp(argv[1],s_string))==0)
    {
        search_function(argv[2]);
    }
    else if((strcmp(argv[1],d_string))==0)
    {
        delete_entry(argv[2]);
    }
 
  

    return 0;
}