/*
 * Run Time: 0.000
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void backToInitial(vector<int>::iterator itr, vector<vector<int> > & blockWorld, vector<int> & blockColumn) {
    while (*itr != -1) {
        if (blockWorld[*itr][0] == -1) {
            blockWorld[*itr][0] = *itr;
            blockColumn[*itr] = *itr;
        }
        *itr = -1;
        ++itr;
    }
}

void movePile(vector<int>::iterator itr, vector<int>::iterator itrB, vector<int> & blockColumn) {
    vector<int>::iterator destr = itrB + 1;
    while (*itr != -1) {
        *destr = *itr;
        blockColumn[*itr] = blockColumn[*itrB];
        *itr = -1;
        ++itr;
        ++destr;
    }
}

int main() {
    int nBlocks, blockA, blockB;
    string command;
    string action; // move, pile, quit
    string to; // onto, over
    cin >> nBlocks;
    getchar();
    vector<vector<int> > blockWorld(nBlocks, vector<int>(nBlocks, -1));
    vector<int> blockColumn(nBlocks);
    vector<int>::iterator itrA, itrB, itr;
    for (int c = 0; c < nBlocks; ++c) {
        blockColumn[c] = blockWorld[c][0] = c;
    }
    while(getline(cin, command), command != "quit") {
        istringstream iss(command);
        iss >> action;
        iss >> blockA;
        iss >> to;
        iss >> blockB;
        if (blockColumn[blockA] == blockColumn[blockB]) { continue; }
        itrA = find(blockWorld[blockColumn[blockA]].begin(), blockWorld[blockColumn[blockA]].end(), blockA);
        itrB = find(blockWorld[blockColumn[blockB]].begin(), blockWorld[blockColumn[blockB]].end(), blockB);
        if (action == "move") {
            backToInitial(itrA + 1, blockWorld, blockColumn);
            if (to == "onto") {
                backToInitial(itrB + 1, blockWorld, blockColumn);
                *(itrB + 1) = *itrA;
            } else if (to == "over") {
                itr = find(blockWorld[blockColumn[blockB]].begin(), blockWorld[blockColumn[blockB]].end(), -1);
                *itr = *itrA;
            }
            blockColumn[*itrA] = blockColumn[*itrB];
            *itrA = -1;
        } else if (action == "pile") {
            if (to == "onto") {
                backToInitial(itrB + 1, blockWorld, blockColumn);
                movePile(itrA, itrB, blockColumn);
            } else if (to == "over") {
                itr = find(blockWorld[blockColumn[blockB]].begin(), blockWorld[blockColumn[blockB]].end(), -1);
                movePile(itrA, itr - 1, blockColumn);
            }
        }
    }
    for (int r = 0; r < nBlocks; ++r) {
        cout << r << ":";
        for (int c = 0; blockWorld[r][c] != -1; ++c) {
            cout << " " << blockWorld[r][c];
        }
        cout << endl;
    }

    return 0;
}
