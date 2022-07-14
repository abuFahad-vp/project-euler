#include <cstdint>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    uint64_t i;
    uint64_t x;
    uint64_t n;
    uint64_t superN;
    uint64_t superI;

    std::map<uint64_t, uint64_t> memory;

    superN = 0;
    superI = 0;

    for (i = 1; i <= 1000000; i++) {
        x = i;
        n = 1;

        do {
            if (memory.find(x) != memory.end()) {
                n += memory[x];
                break;
            }

            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            n++;
        } while (x != 1);

        if (n > superN) {
            superN = n;
            superI = i;
        }

        memory[i] = n;
    }

    cout << "The number " << superI << " ran for " << superN << " terms.\n";
    return 0;
}