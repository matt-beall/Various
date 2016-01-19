/*  Palindrome Permutation: Given a string, write a function to check if it is a permutation of a
palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
permutation is a rearrangement of letters. The palindrome does not need to be limited to just
dictionary words.
 */

#include <string>
#include <array>
#include <iostream>

char toLowerCase(char inputChar)
{
    if(inputChar >= 'a' && inputChar <= 'z')
    {
        return inputChar;
    }
    else if(inputChar >= 'A' && inputChar <='Z')
    {
        char newChar =  (inputChar + 'a' - 'A');
        return newChar;
    }
    else
    {
        return '!';
    }
}

bool permOfPal(std::string input)
{
    std::array<int, 26> characterOccurances{};
    int stringSize = input.size();

    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == ' ')
        {
            stringSize --;
            continue;
        }
        char thisChar = toLowerCase(input[i]);
        int index = thisChar - 'a';
        characterOccurances[index] ++;
    }

    int numberOdds = 0;
    for(int i = 0; i < characterOccurances.size(); i++)
    {
        if(characterOccurances[i] % 2 != 0)
        {
            numberOdds++;
        }
    }


    if(stringSize % 2 == 0) 
    {
        if(numberOdds == 0)
        {
            //is a perm of a pal
            return true;
        }
    }
    else
    {
        if(numberOdds == 1)
        {
            return true;
        }
    }
    return false;
}

int main(){

    std::string inputString("ra ce ca r");

    bool result = permOfPal(inputString);

    std::cout << "Result: "<< result << std::endl;

}  





