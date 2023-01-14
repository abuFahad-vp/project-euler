#include <iostream>
#include <vector>
#include <map>

void printArray(std::vector<float> a) {
    for(auto x:a) {
        std::cout << x << ' ';
    }
    // std::cout << '\n';
}

std::vector<float> arithmetic(std::vector<float> array,float a,int i, int k) {
    array.erase(array.begin()+i);
    array.erase(array.begin()+k-1);
    array.push_back(a);
    return array;
}


void binaryConquer(std::vector<float> array, std::vector<float>* ans) {

    if(array.size() == 2) {
        ans->push_back(array[0] + array[1]);
        ans->push_back(array[0] * array[1]);
        ans->push_back(array[0] - array[1]);
        ans->push_back(array[1] - array[0]);
        ans->push_back(array[0] / array[1]);
        ans->push_back(array[1] / array[0]);

    }else {
        for(int i=0;i<array.size();i++) {
            for(int k=i+1;k<array.size();k++) {

                //addition
                float a = array[i] + array[k];
                binaryConquer(arithmetic(array,a,i,k),ans);
                //substraction ai - ak
                a = array[i] - array[k];
                binaryConquer(arithmetic(array,a,i,k),ans);
                //substraction ak - ai
                a = array[k] - array[i];
                binaryConquer(arithmetic(array,a,i,k),ans);
                //multiplication
                a = array[i] * array[k];
                binaryConquer(arithmetic(array,a,i,k),ans);
                //division ai / ak
                a = array[i] / array[k];
                binaryConquer(arithmetic(array,a,i,k),ans);
                //division ak / ai
                a = array[k] / array[i];
                binaryConquer(arithmetic(array,a,i,k),ans);
            }
        }
    } 
}

int howManyConseq(std::vector<float> array) {
    std::map<float,bool> conseq;
    std::vector<float> ans;
    binaryConquer(array,&ans);
    for(auto x:ans) {
        conseq[x] = true;
    }
    int count = 0;
    for(float i = 1;;i++) {
        if(conseq[i] == true) count++;
        else break;
    }
    return count;
}

int main() {
    int max = 0;
    std::vector<float> maxArray;
    for(float first = 0;first < 10;first++) {
        for(float second = first+1;second<10;second++) {
            for(float third = second + 1;third < 10;third++) {
                for(float forth=third+1;forth<10;forth++) {
                    std::vector<float> array = {first,second,third,forth};
                    int count = howManyConseq(array);
                    if(max < count) {
                        max = count;
                        maxArray = array;
                    }
                }
            }
        }
    }
    printArray(maxArray);
    std::cout << " Max number = " << max << '\n';
}
