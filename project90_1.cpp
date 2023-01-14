
#include "project90.h"

void insertThe69(std::vector<int>* a) {
    //adding nine and six to a
    bool isSixa = false;
    bool isNinea = false;
    for(int x:*a){
        if(x==6) isSixa = true;
        if(x==9) isNinea = true;
    }

    if(isSixa == true && isNinea != true) {
        a->push_back(9);
    }
 
    if(isSixa != true && isNinea == true) {
        a->push_back(6);
    }
}

bool isOk(std::vector<int>* a1,std::vector<int>* a2) {
    insertThe69(a1);
    insertThe69(a2);

    //map to check all the square number is counted
    std::map<int,bool> squares;
    //initially making every square number to false
    for(int i=1;i<10;i++) {
        squares[i*i] = false;
    }

    for(int x:*a1) {
        for(int y:*a2) {
            //we need to reverse eg: 01, 10
            squares[x*10 + y] = true;
            squares[x + y*10] = true;
        }
    }

    for(int i=1;i<10;i++) {
        if(squares[i*i] == false) return false;
    }
    return true;
}

int main() {
    //creating the 210 compinations and reading to vector of vectors
    std::vector<std::vector<int>> comps;
    comps = readComp();
    int count = 0;
    for(int i=0;i<comps.size();i++) {
        for(int k=i+1;k<comps.size();k++) {
            if(isOk(&comps[i],&comps[k])==true) count++;
        }
    }
    printf("count = %d\n",count);
    return 0;
}