/*
String Compression: Implement a metod to perform basic string compression using the counts 
of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the 
"compressed" string would not become smaller than the original string, your method should 
return the original string. You can assume the string has only uppercase and lowercase letters (a-z)
*/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string processString(string inputString)
{
    stringstream newStringStream;
    for(int i = 0; i < inputString.size(); i++)
{
    char thisChar = inputString[i];
    int occurances = 1;
    while(i < inputString.size() && inputString[i+1] == thisChar)
    {
        occurances++;
        i++;
    }
    newStringStream << thisChar << occurances; 
}
string newString = newStringStream.str();
if(newString.size() < inputString.size())
{
    return newString;
}
else
{
    return inputString;
}
}

int main(){
    vector<string> data = {"pale","aabcccccaaa", "abaabbcaccad", "abcb", "aaaaaaaaaaaaaaaaaababad"};

    for(int i = 0; i < data.size(); i++)
{
    string thisString = processString(data[i]);
    cout << data[i] << " yields " << thisString << endl;
}
}
