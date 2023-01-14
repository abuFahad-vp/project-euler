#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<std::string>> readAnagram() {
    std::fstream file;
    file.open("anagram.txt",std::ios::in);
    char c;
    std::string word;
    std::vector<std::vector<std::string>> anagramWords;
    std::vector<std::string> temp;
    while(file.get(c)) {
        if(c == ' ') {
            temp.push_back(word);
            word.clear();
            continue;
        }
        if(c == '\n') {
            temp.push_back(word);
            anagramWords.push_back(temp);
            word.clear();
            temp.clear();
            continue;
        }
        word.push_back(c);
    }
    // for(auto x:anagramWords) {
    //     for(auto y:x) {
    //         std::cout << y << ' ';
    //     }
    //     std::cout << '\n';
    // }
    return anagramWords;
}