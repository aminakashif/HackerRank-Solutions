#include <bits/stdc++.h> 
   
using namespace std; 
   
string ltrim(const string &); 
string rtrim(const string &); 
   
/* 
 * Complete the 'sherlockAndAnagrams' function below. 
 * 
 * The function is expected to return an INTEGER. 
 * The function accepts STRING s as parameter. 
 */ 
   
int sherlockAndAnagrams(string s) { 
    int ans = 0;
    int n = s.size();

    for (int len = 1; len < n; len++) {
        map<string, int> freq;

        for (int i = 0; i + len <= n; i++) {
            string sub = s.substr(i, len);
            sort(sub.begin(), sub.end());
            freq[sub]++;
        }

        for (auto x : freq) {
            int count = x.second;
            ans += count * (count - 1) / 2;
        }
    }

    return ans;
} 
   
int main() 
{ 
    ofstream fout(getenv("OUTPUT_PATH")); 
   
    string q_temp; 
    getline(cin, q_temp); 
   
    int q = stoi(ltrim(rtrim(q_temp))); 
   
    for (int q_itr = 0; q_itr < q; q_itr++) { 
        string s; 
        getline(cin, s); 
   
        int result = sherlockAndAnagrams(s); 
   
        fout << result << "\n"; 
    } 
   
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
