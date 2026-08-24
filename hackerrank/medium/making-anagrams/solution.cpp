#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {

    int count[26] = {0};

    // Count characters in s1
    for (char c : s1) {
        count[c - 'a']++;
    }

    // Remove characters that are present in s2
    for (char c : s2) {
        count[c - 'a']--;
    }

    int deletions = 0;

    // Sum of all frequency differences
    for (int i = 0; i < 26; i++) {
        deletions += abs(count[i]);
    }

    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
