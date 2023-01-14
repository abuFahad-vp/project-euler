#include "project98.h"

int main() {
    //reading the words
    std::vector<std::string> Words = readWords();
    std::map<std::string,std::vector<std::string>> dict;
    std::string temp;

    std::fstream file;
    file.open("anagram.txt",std::ios::out);

    for(std::string word:Words) {
        temp = word;
        std::sort(temp.begin(),temp.end());
        dict[temp].push_back(word);
    }

    std::map<std::string,std::vector<std::string>>::iterator it = dict.begin();

    std::vector<std::vector<std::string>> anagram;

    while(it != dict.end()) {
        if(it->second.size() > 1) {
            anagram.push_back(it->second);
        }
        it++;
    }    

    for(auto x:anagram) {
        for(auto y:x) {
            std::cout << y << ' ';
            file << y << ' ';
        }
        std::cout << '\n';
        file << '\n';
    }
    printf("%llu\n",anagram.size());
}

