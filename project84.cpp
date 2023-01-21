
#include "project84.h"


void rollTheDice(int faces,int dices[]) {
    dices[0] = (rand() % faces) + 1;
    dices[1] = (rand() % faces) + 1;
}

int main() {

    int simulations = 1000000;

    std::srand(time(0));

    // To store the values of dice
    int dice[2];
    int doubles = 0;

    //current position
    int cursor = 0;

    //To keep track how many times each square visited
    std::vector<int> Board(40,0);
    std::map<int,int> Largest;

    for(int i=0;i<=simulations;i++) {

        //4 represent 4 faces
        rollTheDice(4,dice);
        int value = dice[0] + dice[1];
        cursor = (cursor + value) % 40;

        //Condition for doubles
        if(dice[0] == dice[1]) {
            doubles++;
        }else {
            doubles = 0;
        }

        if(doubles == 3) {
            cursor = 10;
            doubles = 0;
        }

        // //Chance
        if(cursor == 7 || cursor == 22 || cursor == 36) {

            int card = rand()%16;

            if(card==1) cursor = 0;
            if(card == 2) cursor = 10;
            if(card == 3) cursor = 11;
            if(card == 4) cursor = 24;
            if(card == 5) cursor = 39;
            if(card == 6) cursor = 5;
            if(card == 7) {
                if (cursor == 7) cursor = 15;
                if (cursor == 22) cursor = 25;
                if (cursor == 36) cursor = 5;
            }
            if(card == 8) {
                if (cursor == 7) cursor = 15;
                if (cursor == 22) cursor = 25;
                if (cursor == 36) cursor = 5;
            }
            if(card==9) {
                if (cursor == 7) cursor = 12;
                if (cursor == 22) cursor = 28;
                if (cursor == 36) cursor = 12;
            }

            if(card==10) cursor = cursor-3;
        }

        //Community Chest
        if(cursor == 2 || cursor == 17 || cursor == 33) {
            int card = std::rand()%16; 
            if(card == 1) {
                cursor = 0; // advance to go
            }
            if(card == 2) {
                cursor = 10; //go to jail
            }
        }

        //G2j
        if(cursor == 30) cursor = 10;
        Board[cursor]++;
    }

    for(int i=0;i<40;i++) {
        Largest[Board[i]] = i;
    }

    std::sort(Board.begin(),Board.end(),std::greater<int>());

    std::cout << Largest[Board[0]] << " " << Largest[Board[1]] << " " << Largest[Board[2]] << '\n';

    return 0;
}