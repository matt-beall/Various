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

int main(){
    vector<string> data = {"pale", "aabcccccaaa", "abcdefg"};

    for(int i = 0; i < data.size(); i++)
{
    bool result = oneAway(data[i].first, data[i].second);

    string resultStr = result?"True":"False";

    cout << "Pair " << i << ", " << data[i].first << " and " << data[i].second << ": " << resultStr << endl;
    }
}
