/* Check Permutation: Given two strings, write a method to decide if one 
   is a permutation of the other
 */


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

bool isPermutation(std::pair<std::string, std::string> stringPair)
{
    if(stringPair.first.size() != stringPair.second.size())
        return false;

    std::sort(stringPair.first.begin(), stringPair.first.end());
    std::sort(stringPair.second.begin(), stringPair.second.end());

    return (stringPair.first == stringPair.second);
}

int main(){
    std::vector<std::pair<std::string, std::string>> data = {{"abc","bca"},
                                                             {"abb","bba"},
                                                             {"dada", "dadd"}};

    for(int i = 0; i < data.size(); i++)
    {
        std::cout << data[i].first << " and " << data[i].second << " ... Permutation? ";
        if(isPermutation(data[i]))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

}   