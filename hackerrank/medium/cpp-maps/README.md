# Maps-STL

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.The mainly used member functions of maps are:

- *Map Template:*

		std::map <key_type, data_type>

- *Declaration:*

		map<string,int>m; //Creates a map m where key_type is of type string and data_type is of type int.
       
- *Size:*

		int length=m.size(); //Gives the size of the map.
        
- *Insert:*

		m.insert(make_pair("hello",9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.
        
- *Erasing an element:*

		m.erase(val); //Erases the pair from the map where the key_type is val.
        
- *Finding an element:*

		map<string,int>::iterator itr=m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end() .
        Ex: map<string,int>::iterator itr=m.find("Maps"); //If Maps is not present as the key value then itr==m.end().
        
- *Accessing the value stored in the key:*
		
        To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value.
        

To know more about maps [click Here](http://www.cplusplus.com/reference/map/map/).

You are appointed as the assistant to a  teacher in a school and  she is correcting the answer sheets of the students.Each student can have multiple answer sheets.So the teacher has $Q$ queries:

$1\ X\  Y$ :Add the marks $Y$ to the student whose name is $X$.

$2\ X$: Erase the marks of the students whose name is $X$.

$3\ X$: Print the marks of the students whose name is $X$.  (If $X$ didn't get any marks print $0$.)

**Input Format**

The first line of the input contains $Q$ where $Q$ is the number of queries. The next $Q$ lines contain $1$ query each.The first integer, $type$ of each query is the type of the query.If  query is of type $1$, it consists of one string and an integer $X$ and $Y$ where $X$ is the name of the student and $Y$ is the marks of the student.If query is of type $2$ or $3$,it consists of a single string $X$ where $X$ is the name of the student. 

**Constraints**

$1 \le Q \le 10^5$

$1 \le type \le 3$

$1 \le |X| \le 6$

$1 \le Y \le 10^3$


**Output Format**

For queries of type $3$ print the marks of the given student.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-12T09:17:28.415Z  

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> m;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        string name;
        cin >> name;

        if (type == 1) {
            int marks;
            cin >> marks;
            m[name] += marks;
        }
        else if (type == 2) {
            m.erase(name);
        }
        else if (type == 3) {
            cout << m[name] << endl;
        }
    }

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/cpp-maps/problem)