

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>

using namespace std;


const int tablesize = 17;

char t[tablesize][2][255];

size_t f(char*,size_t);

bool place_in_hash_tables(char*);


int main(int argc, char** argv) {

    char s[255];
    char null_st[] = "";
    size_t i;
    size_t len;
    bool placed;
    
    for(i = 0; i < tablesize; i++)
    {
        strcpy(t[i][0], null_st);
        strcpy(t[i][1], null_st);
    }
    
    char filename[255] = "";
    
    cout << endl << "CPSC 335-1 - Programming Assignment #4: ";
    cout << "Cukoo Hashing algorithm" << endl;
    
    cout << "Input the file name (no spaces)!" << endl;
    cin >> filename;
    
    FILE *file = fopen(filename,"r");
    if(file != NULL)
    {
        while(fgets( s, 255, file) != NULL)
        {
            len = strlen(s);
            s[len-1] = '\0';
            placed = place_in_hash_tables(s);
            
            if(!placed)
            {
                cout << "Placement has failed" << endl;
                return -1;
            }
            
        }
        fclose(file);
    }
    else
    {
        perror( filename );
    }
    
    
    
    return 0;
}

bool place_in_hash_tables(char *s)
{
    
    bool placed;
    size_t pos;
    int index;
    char temp_s[255];
    char temp[255];
    
    strcpy(temp_s, s);
    
    int counter = 0;
    
    index = 0;
    
    placed = false;
    
    pos = f(temp_s,index);
    while((!placed)&&(counter < 2 * tablesize))
    {
        if(strcmp(t[pos][index],"") == 0)
        {
            cout << "String <" << temp_s << "> will be placed at ";
            cout << "t[" << pos << "][" << index << "]" << endl;
            strcpy(t[pos][index], temp_s);
            placed = true;
            return placed;
        }
        else
        {
            cout <<"String <" << temp_s << "> will be placed at " << "t[" << pos;
            cout << "][" << index << "]" << " replacing <" << t[pos][index] << ">";
            cout << endl;
            
            strcpy(temp, t[pos][index]);
            strcpy(t[pos][index], temp_s);
            
            strcpy(temp_s, temp);
            
            index = 1 - index;
            
            pos = f(temp_s, index);
            
            
            counter++;
        }
    }
    return placed;
};

size_t f(char *s, size_t index)
{
    size_t po;
    size_t len;
    int i;
    int val;
    int temp;
    
    po = 1;
    
    len = strlen(s);
    
    if(index==0)
    {
        val =s[0];
        val = val % tablesize;
        
        if(val < 0) val+= tablesize;
        
        if(len == 1)
        {
            return val;
        }
        
        for(i=1; i< len; i++)
        {
            temp = s[i];
            po *= 31;
            
            po = po % tablesize;
            
            if(po < 0) val += tablesize;
            
            val += temp * po;
            val = val % tablesize;
            
            if(val < 0) val += tablesize;
        }
        return val;
    }
    else
    {
        
        val = s[len - 1];
        val = val % tablesize;
        
        
        if(val < 0) 
        {
            val += tablesize;
        }
        
        if(len == 1)
        {
            return val;
        }
        
        for(i = len-2; i >= 0; i--)
        {
            temp = s[i];
            po *= 31;
            
            po = po % tablesize;
            if(po< 0) val += tablesize;
            
            val += temp * po;
            val = val % tablesize;
            
        
        
            if(val < 0)
            {
                val += tablesize;
            }
        }
        
   
        return val;
    }
}