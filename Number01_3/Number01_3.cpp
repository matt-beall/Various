/*  URLify: Write a method to replace all spaces in a string with '%20'.
    You may assume that the string has sufficient space at the end to hold
    the additional characters, and that you are given the "true" length of the string.
    (Note: If implementing in Java, please use a character array so you can perform
    this operation in place.)
 */


#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

std::string urlIfy(std::string inputString)
{
    std::string outputString;
    for(int i = 0; i < inputString.size() ; i++)
    {
        char space = ' ';
        if( (char) inputString[i] == space)
        {
            outputString += "%20";
        }
        else
        {
        outputString+= inputString[i];
        }
    }
    return outputString;
}

int main(){
    std::string inputString = "Mr. John Smith";
    
    std::string newString = urlIfy(inputString);
    
    std::cout << newString << std::endl;
}  

