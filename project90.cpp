//generate all possible compinations:- total 210

#include <iostream>
#include <stdio.h>
#include <vector>

std::vector<std::vector<int>> readComp() {
    FILE* fp;
    std::vector<std::vector<int>> comps;

    fopen_s(&fp,"comps.txt","r");
    for(int i=1;i<=210;i++) {
        std::vector<int> temp(0);
        int numbers[6] = {0};
        fscanf_s(fp, "%d%d%d%d%d%d",&numbers[0],&numbers[1],&numbers[2],&numbers[3],&numbers[4],&numbers[5]);
        for(int k = 0;k<6;k++) temp.push_back(numbers[k]);
        comps.push_back(temp);
    }
    // for(auto x:comps) {
    //     for(auto y:x) {
    //         printf("%d ",y);
    //     }
    //     printf("\n");
    // }
    return comps;
}

void generateComps() {
    FILE* fp;
    fopen_s(&fp,"comps.txt","w");
    int i = 1;
    for(int first = 0;first < 10;first++) {
        for(int second = first+1;second<10;second++) {
            for(int third = second + 1;third < 10;third++) {
                for(int forth=third+1;forth<10;forth++) {
                    for(int fifth=forth+1;fifth<10;fifth++) {
                        for(int sixth=fifth+1;sixth<10;sixth++) {
                            std::cout<< i << " : " << first << " " << second << " " << third << " " << forth << " " << fifth << " " << sixth << '\n';
                            fprintf(fp,"%d %d %d %d %d %d\n",first,second,third,forth,fifth,sixth);
                            i++;
                        }
                    }
                }
            }
        }
    }    
    fclose(fp);
}