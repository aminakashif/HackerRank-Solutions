# Even Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a tree (a simple connected graph with no cycles). 

Find the maximum number of edges you can remove from the tree to get a [forest](http://en.wikipedia.org/wiki/Tree_(graph_theory)) such that each connected component of the forest contains an even number of nodes.

As an example, the following tree with $4$ nodes can be cut at most $1$ time to create an even forest.  


![image](https://s3.amazonaws.com/hr-assets/0/1533926256-3a1cc069a7-evenforestexb.png)  

**Function Description**  

Complete the *evenForest* function in the editor below.  It should return an integer as described.  

evenForest has the following parameter(s):  

- *t_nodes*: the number of nodes in the tree  
- *t_edges*: the number of undirected edges in the tree  
- *t_from*: start nodes for each edge  
- *t_to*: end nodes for each edge, (Match by index to *t_from*.)  

**Input Format**

The first line of input contains two integers $t_nodes$ and $t_edges$, the number of nodes and edges.  
The next $t_edges$ lines contain two integers $t_from[i]$ and $t_to[i]$ which specify nodes connected by an edge of the tree. The root of the tree is node $1$.

**Constraints**

* $2 \le n \le 100$ 
* $n \in \mathbb Z_\text{even}^+$  

*Note:* The tree in the input will be such that it can always be decomposed into components containing an even number of nodes. $\mathbb Z_\text{even}^+ $ is the set of positive even integers.

**Output Format**

Print the number of removed edges.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-02T18:14:56.136Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector<string> split(const string &);

// Complete the evenForest function below.

int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    vector<vector<int>> graph(t_nodes + 1);

    for (int i = 0; i < t_edges; i++) {
        graph[t_from[i]].push_back(t_to[i]);
        graph[t_to[i]].push_back(t_from[i]);
    }

    int answer = 0;

    function<int(int, int)> dfs = [&](int node, int parent) {
        int nodes = 1;

        for (int child : graph[node]) {
            if (child != parent) {
                int subtree = dfs(child, node);

                if (subtree % 2 == 0) {
                    answer++;
                } else {
                    nodes += subtree;
                }
            }
        }

        return nodes;
    };

    dfs(1, 0);

    return answer;
}

int main()

{

ofstream fout(getenv("OUTPUT_PATH"));

string t_nodes_edges_temp;
getline(cin, t_nodes_edges_temp);

vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

int t_nodes = stoi(t_nodes_edges[0]);
int t_edges = stoi(t_nodes_edges[1]);

vector<int> t_from(t_edges);
vector<int> t_to(t_edges);

for (int i = 0; i < t_edges; i++) {
    string t_from_to_temp;
    getline(cin, t_from_to_temp);

    vector<string> t_from_to = split(rtrim(t_from_to_temp));

    int t_from_temp = stoi(t_from_to[0]);
    int t_to_temp = stoi(t_from_to[1]);

    t_from[i] = t_from_temp;
    t_to[i] = t_to_temp;
}

int res = evenForest(t_nodes, t_edges, t_from, t_to);

fout << res << "\n";

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

[View on HackerRank](https://www.hackerrank.com/challenges/even-tree/problem)