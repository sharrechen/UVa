#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>

#define INCORRECT_PENALTY_TIME 20

using namespace std;

struct Team {
    unsigned int name;
    unsigned int problem;
    unsigned int time;
    map<int, int> error;
};

bool cmp (const Team & a, const Team & b) {
    if (a.problem != b.problem) {
        return a.problem > b.problem;
    }
    if (a.time != b.time) {
        return a.time < b.time;
    }
    return a.name < b.name;
}

int main(void) {
    int T, team, problem, time;
    char L;
    string submit;

    cin >> T;
    cin.get();
    cin.get();
    while (T--) {
        vector<Team> scoreBoard(100);
        while (getline(cin, submit), submit != "") {
            istringstream iss(submit);
            iss >> team >> problem >> time >> L;
            if (L == 'C' && scoreBoard[team - 1].error[problem] != -1) {
                scoreBoard[team - 1].name = team;
                scoreBoard[team - 1].problem++;
                scoreBoard[team - 1].time += time
                + scoreBoard[team - 1].error[problem] * INCORRECT_PENALTY_TIME; // add penalty time
                scoreBoard[team - 1].error[problem] = -1; // record solved problem
            } else if (L == 'I' && scoreBoard[team - 1].error[problem] != -1) {
                scoreBoard[team - 1].name = team;
                scoreBoard[team - 1].error[problem]++; // record error try problem
            } else {
                scoreBoard[team - 1].name = team; // record participate team
            }
        }
        sort(scoreBoard.begin(), scoreBoard.end(), cmp);
        for (size_t i = 0; i < scoreBoard.size(); ++i) {
            if (scoreBoard[i].name) {
                cout << scoreBoard[i].name << " "
                     << scoreBoard[i].problem << " "
                     << scoreBoard[i].time << endl;
            }
        }
        if (T) cout << endl;
    }
    return 0;
}
