// February17_2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<fstream> //because we're going to read a file (dictionary)!
#include <iostream>
#include<list> //again, this is a DOUBLY-linked list (we'll write OUR OWN class for this later ...) 
#include<map> 
#include<queue> 
#include<stack> 
#include<string> //string IS a container (data structure) 
#include<set>
#include<unordered_map>


void demoList()
{

    std::list<std::string> names =
    {
        "Alice",
        "Bob"
    };

    //names.assign(1, "adsfasdf");

    names.push_back("Carol"); //alice, bob, carol
    names.push_front("Someone in front of Alice"); //someone..., alice, bob, carol
    names.insert(names.begin(), "Someone BETWEEN");
    //? notsure (like a character in the movie Idiocracy)

        
    /*    names[2] = "1234i4oi*/

    //print contents of list: 
    for (const auto& name : names) //certain data structures have no .begin() and .end() function, 
                                    //so the range-based for loop won't work! Caution!
    //for (int i = 0; i < names.size(); ++i)
    {
        std::cout << name << "\n";
    }
}

void demoMap()
{
    std::map<std::string, std::string> wordsToTheirMeanings; 

    std::ifstream fin{ "shortDictionary.csv" };

    while (!fin.eof())
    {
        std::string currentWord; 
        std::getline(fin, currentWord, ',');
        std::string currentWordMeaning; 
        std::getline(fin, currentWordMeaning, '\n');

        wordsToTheirMeanings.insert({ currentWord, currentWordMeaning });
        //std::cout << currentWord << "-" << currentWordMeaning << "\n";
    }

    fin.close();

    std::cout << "Enter a word that you would like the meaning of:\n";
    std::string desiredWord; 

    std::getline(std::cin, desiredWord); 

    std::cout << "The meaning of the word " << desiredWord
        << " is " << wordsToTheirMeanings[desiredWord] << "\n";
}

/*This function will read The Jabberwock (a nonsense poem by Lewis Carroll)
AND it counts the number of occurrences of each word in the poem*/
void doAnotherDemoOfTheGloriousMapContainer()
{
    std::ifstream fin{ "C:/Users/Work/Desktop/jabberwocky.txt" }; //NOTE: Windows filenames aren't case sensitive

    if (!fin)
    {
        throw std::exception("Unable to find file"); 
        return; 
    }

    std::map<std::string, int> wordsMappedToTheirNumberOfOccurences; 

    std::string currentWord; 
    while (std::getline(fin, currentWord, ' '))
    {
        //std::cout << currentWord << "\n";
        wordsMappedToTheirNumberOfOccurences[currentWord]++;
    }

    fin.close(); 
    //this is (one method) of printing the elements in a map (key-value pairs): 
    for (const auto& currentPair : wordsMappedToTheirNumberOfOccurences)
    {
        std::cout << currentPair.first << " occurs this many times: " << currentPair.second << "\n";
    }

}
 
void demoSet()
{
    std::set<int> someUNIQUEnums =
    {
        1, 1,
        2,
        3,
        4,
        5
    };

    std::cout << "The number of elements in this set is: " << someUNIQUEnums.size() << "\n";
}

int main()
{

    demoSet(); 

    //demoList(); 
    //demoMap(); 


    //try
    //{
    //    doAnotherDemoOfTheGloriousMapContainer(); 
    //}

    //catch (const std::exception& e)
    //{
    //    std::cout << e.what() << "\n";
    //}

    //std::cout << "Hello World!\n";
}

