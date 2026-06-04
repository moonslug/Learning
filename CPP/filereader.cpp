#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input;
    input.open("macbeth.txt");

    std::string data, longestword;
    
    int wordcount = 0, wordlengthtotal = 0, numsentence = 0, longestlength = -1;

    while(input >> data)
    {
        // std::cout << data << std::endl;
        wordcount++;
        int wordlength = data.length();
        wordlengthtotal += wordlength;
        if (wordlength > longestlength)
        {
            longestlength = wordlength;
            longestword = data;
        }
        if (data.find(".") != -1)
        {
            numsentence++;
        }
    }

    std::cout << "avg word length: "
                << (double)(wordlengthtotal) / wordcount
                << " characters." << std::endl;
    std::cout << "the longest word is "
                << longestword
                << " with a length of " 
                << longestlength << std::endl;
    std::cout << "number of sentences: " << numsentence << std::endl;
    input.close();

    return 0;
}