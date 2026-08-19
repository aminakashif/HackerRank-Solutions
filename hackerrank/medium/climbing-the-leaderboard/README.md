# Climbing the Leaderboard

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

An arcade game player wants to climb to the top of the leaderboard and track their ranking. The game uses [Dense Ranking](https://en.wikipedia.org/wiki/Ranking#Dense_ranking_.28.221223.22_ranking.29), so its leaderboard works like this:  
  
- The player with the highest score is ranked number $1$ on the leaderboard. 
- Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.


**Example**  

$ranked = [100, 90, 90, 80]$   
$player = [70, 80, 105]$  

The ranked players will have ranks $1$, $2$, $2$, and $3$, respectively.  If the player's scores are $70$, $80$ and $105$, their rankings after each game are $4^{th}$, $3^{rd}$ and $1^{st}$. Return $[4, 3, 1]$.

**Function Description**  

Complete the *climbingLeaderboard* function in the editor below.  

climbingLeaderboard has the following parameter(s):  

- *int ranked[n]*: the leaderboard scores  
- *int player[m]*: the player's scores  

**Returns**  

- *int[m]:*  the player's rank after each new score

**Input Format**

The first line contains an integer $n$, the number of players on the leaderboard. 		
The next line contains $n$ space-separated integers $ranked[i]$, the leaderboard scores in decreasing order. 		
The next line contains an integer, $m$, the number games the player plays. 		
The last line contains $m$ space-separated integers $player[j]$, the game scores.

**Constraints**

* $1 \le n \le 2 \times 10^5$
* $1 \le m \le 2 \times 10^5$
* $0 \le ranked[i] \le 10^9$ for $0 \le i < n$
* $0 \le player[j] \le 10^9$ for $0 \le j < m$
* The existing leaderboard, $ranked$, is in *descending* order.
* The player's scores, $player$, are in *ascending* order.

**Subtask**

For $60\%$ of the maximum score:

* $1 \le n \le 200$
* $1 \le m \le 200$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-19T11:55:42.304Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    vector<int> uniqueScores;

    // Remove duplicate scores
    for (int score : ranked) {
        if (uniqueScores.empty() || uniqueScores.back() != score) {
            uniqueScores.push_back(score);
        }
    }

    vector<int> result;
    int i = uniqueScores.size() - 1;

    for (int score : player) {
        while (i >= 0 && score >= uniqueScores[i]) {
            i--;
        }

        result.push_back(i + 2);
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem)