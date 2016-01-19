/*
One Away: There are three types of edits that can be performed on strings: insert a character, remove a character,
or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE
pale, ple ->true
pales, pale -> true
pale, bale -> true
pale, bake -> false
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool oneAway(string str1, string str2)
{
    if(str2.size() > str1.size())
    {
        string tempStr = str1;
        str1 = str2;
        str2 = tempStr;
    }

    int sizeDifference = str1.size() - str2.size();

    if(sizeDifference > 1)
    {
        return false;
    }

    int numErrors = 0;

    for(int i = 0; i < str1.size() ; i++)
    {
        if(str1[i] != str2[i - sizeDifference*numErrors])
        {
            numErrors++;
            if(numErrors > 1)
            {
                return false;
            }
        }
    }

    return (numErrors == 1);
}

int main(){
    vector<pair<string,string>> data = {{"pale" , "ple" },
                                        {"pales", "pale"},
                                        {"pale",  "bale"},
                                        {"pale",  "bake"},
                                        {"pale",  "pale"},
                                        {"pale",  "pales"}};

    for(int i = 0; i < data.size(); i++)
    {
        bool result = oneAway(data[i].first, data[i].second);

        string resultStr = result?"True":"False";

        cout << "Pair " << i << ", " << data[i].first << " and " << data[i].second << ": " << resultStr << endl;
    }
}


