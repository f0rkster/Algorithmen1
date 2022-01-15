#include "uebung12.h"
#include <iostream>
#include <string>

struct SAnalyzeItem {
    char m_letter = ' ';
    int  m_value = 0;
};

bool isNotSeen(char* _seenLetters, char _letter, int _length)
{
    for (int i = 0; i < _length; i++)
    {
        if (_seenLetters[i] == _letter)
        {
            return false;
        }
    }
    return true;
}

int getValue(char* _pattern, char _letter, int _length, char* _seenLetters)
{
    int value = 1;
    for (int i = _length - 3; i >= 0; i--)
    {
        if (_letter == _pattern[i] && isNotSeen(_seenLetters, _letter, _length))
        {
            return value;
        }
        else if(!isNotSeen(_seenLetters, _letter, _length))
        {
            return -1;
        }
        value++;
    }
    return value;
}

void broyerMooreHorspool()
{
    std::cout << "BROYER-MOORE-HORSPOOL" << std::endl;
    char text[] = "Eine Nadel im Heuhaufen finden";
    const int lengthText = sizeof(text) / sizeof(text[0]);
    char pattern[] = "finden";
    const int lengthPattern = sizeof(pattern) / sizeof(pattern[0]);
    SAnalyzeItem distance[lengthPattern] = { };

    char seenLetter[lengthPattern] = "";

    int i = 0;
    for (int j = lengthPattern - 1; j >= 0; j--)
    {
        char letter = pattern[j];
        int value = getValue(pattern, letter, lengthPattern, seenLetter);
        seenLetter[i] = letter;
        distance[i].m_letter = letter;
        distance[i].m_value = value;
        i++;
    }

    std::cout << pattern << std::endl;
 
    for (int i = 0; i < lengthPattern; i++)
    {
        std::cout << "[";
        std::cout << distance[i].m_letter << ", ";
        std::cout << distance[i].m_value << "]";
    }
    std::cout << std::endl;

}
