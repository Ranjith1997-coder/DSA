#include"../stdc++.h"

using namespace std;

bool dota2_game_simulation(string senate) {
    int count = 0;

    for (auto ch: string) {
        if (ch == 'R') {
            if (count < 0) {
                senate.push_back('D');
            }
            count++;
        } else {
            if (count > 0) {
                senate.push_back('R');
            }
            count--;
        }
    }

    if (count > 0) {
        return 1;
    }else {
        return 0;
    }
}

int main() {
    string senate = "RDD";

    bool out = dota2_game_simulation(senate);
}