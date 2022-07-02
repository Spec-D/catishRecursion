
/** A recursive program to determine if a string contains
 * the word cat within its characters in any order or location
 * @file wk2_catishRecursion_dpraegitzer.cpp
 * @author Derek Praegitzer
 * @date 10/04/2021
*/

// Pre-processor directives
#include <iostream>
#include <string>

// Function Prototype
bool isCatish(const std::string, int, int, int, int);

// Program
int main(){
    const int SIZE = 5; // Amount of words to enter & test
    std::string words[SIZE]; // Array to hold words entered
    
    std::cout << "---------------------------\n";
    std::cout << "| Enter a series of words |\n";
    std::cout << "---------------------------\n";
    
    for(int i;i<SIZE;i++) // User enters five words
    {
        std::cout << i+1 << ". ";
        getline(std::cin, words[i]);
    }
    
    std::cout << std::endl;

    std::cout << "-----------\n";
    std::cout << "| Results |\n";
    std::cout << "-----------\n";

    /** for loop to call the isCatish() recursive function for each word */
    for(int i=0;i<SIZE;i++) {
        if(isCatish(words[i], 0, 0, 0, 0)==true)
            std::cout << i+1 << ". " << words[i] << " is cat-ish!\n";
        else
            std::cout << i+1 << ". " << words[i] << " is not cat-ish.\n";
    }
    return 0;
}

/** Function to check a string for the word cat in any
 * location, orientation or order in the string
 * @param word Word to check for cat-ish-ness
 * @param pointer Pointer to keep track of where we are
 * @param c Calculates # of instances of 'c' or 'C'
 * @param a Calculates # of instances of 'a' or 'A'
 * @param t Calculates # of instances of 't' or 'T'
 * @return true if cat-ish else false
 */
bool isCatish(const std::string word, int pointer, int c, int a, int t) {

        if(c >= 1 && a >= 1 && t >= 1)
            return true;

        if (word == "")
            return false;

        if (word[pointer] == 'c' || word[pointer] == 'C')
            c++;

        if (word[pointer] == 'a' || word[pointer] == 'A')
            a++;

        if (word[pointer] == 't' || word[pointer] == 'T')
            t++;

        if (pointer > word.length())
            return false;

        return isCatish(word, pointer+1, c, a, t);
}
