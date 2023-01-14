#include "project98.h"

bool isKeyexist(std::map<char,int>::iterator it,std::map<char,int>::iterator end,char c) {
    while (it != end)
    {
        if(it->first == c) return true;
        it++;
    }
    return false;
    
}

int main() {

    std::vector<std::vector<std::string>> anagramWords = readAnagram();
    int max = 0;
    for(int a=0;a<anagramWords.size();a++) {
        std::set<int> digits;
        std::vector<int> vdigits;
        std::map<char,int> digitalSupstitution;
        std::string word1 = anagramWords[a][1];
        std::string word2 = anagramWords[a][0];
        int lowerLimit = sqrt(pow(10,word1.size()-1));
        int upperLimit = 0;
        for(int u=0;u<word1.size();u++) {
            upperLimit = upperLimit*10 + 9;
        }
        upperLimit = sqrt(upperLimit);
        for(int i = lowerLimit+1;i<upperLimit+1;i++) {
            int sqr = i*i;
            int temp = sqr;
            int count = 0;
            while (sqr >=1) {
                digits.insert(sqr%10);
                sqr /= 10;
                count++;
            }
            if(digits.size() == count) {
                vdigits.push_back(temp);
            }
            digits.clear();
        } 
        // for(auto x:vdigits) {
        //     std::cout << x << '\n';
        // }
        int seconNum;
        for(auto num:vdigits) {
            int sqr = num;
            seconNum = num;
            for(int i = word1.size()-1;i>=0;i--) {
                digitalSupstitution[word1[i]] = sqr%10;
                // std::cout << word1[i] << ":" <<sqr%10 << ", ";
                sqr /= 10;
            }
            int ans = 0;
            for(auto x:word2) {
                ans = ans*10 + digitalSupstitution[x];
            }
            if(sqrt(ans) == floor(sqrt(ans)) && sqrt(ans) > lowerLimit) {
                std::cout << ans << " " << seconNum << " " << " word1 = " << word1 << " word2 = " << word2 << '\n';
            }
            digitalSupstitution.empty();
        }
        digits.clear();
        vdigits.clear();
    }
}