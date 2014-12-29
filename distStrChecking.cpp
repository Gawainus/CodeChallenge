/*
This is a test probelm
Write an algorithm to check whether a string cotains only distinctive chars or not
*/

// Suraj, solve this

#include <iostream>
#include <string>

int main(int argc, char ** argv) {
    string target = argv[1];
    
    //check the target below
    int check[256] = {0};
    
    if(target.length() > 26) //should this not be 256? assuming 256 unique characters? depend  what can be in the str. yeah can't just return 0 if size is >26?
 
        return 0;
    
    for(i=0;i<target.size() ;i++)
    {
    if( check[(int)target[i]] == 1)
    return 0 ; // returning zero on failure
    
    else
    check[(int) target[i]] = 1;
    }
    
    return 1; //means only distinct characters exist
}
