#include <iostream>
#include <vector>

void printArray(std::vector<int> seq) {
    for(auto x:seq) {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

int reduce(std::vector<int> seq) {
    if(seq.size() == 1) return seq[0];

    int len = seq.size();
    std::vector<int> newSeq;

    for(int i=1;i<len;i++) {
        newSeq.push_back(seq[i]-seq[i-1]);
    }
    printArray(newSeq);
    return seq[len-1] + reduce(newSeq);
}

int main() {
    std::vector<int> seq = {1,8,27,64};
    std::cout << reduce(seq);
    return 0;
}