#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

std::vector<std::string> readWords() {
    std::fstream file;
    file.open("project98.txt",std::ios::in);
    std::string word;
    std::vector<std::string> Words;
    int count = 0;
    while(std::getline(file,word,',')) {
        word.pop_back();
        word.erase(word.begin());
        Words.push_back(word);
        count++;
    }
    // std::cout << count << '\n';
    return Words;
}