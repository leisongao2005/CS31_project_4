//
//  main.cpp
//  project_4
//
//  Created by Leison Gao on 11/5/23.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void printString(string a[], int l) {
    for (int i = 0; i < l; i ++) {
        cerr << a[i] << " ";
    }
    cerr << endl;
}

int reduplicate(string a[], int n) {
    if (n < 0)
        return -1;
    for (int i = 0; i < n; i ++) {
        a[i] = a[i] + a[i];
    }
    return n;
    
}

int locate(const string a[], int n, string target) {
    if (n < 0)
        return -1;
    for (int i = 0; i < n; i ++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int locationOfMax(const string a[], int n) {
    if (n <= 0)
        return -1;
    string max = a[0];
    int maxPos = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] > max) {
            max = a[i];
            maxPos = i;
        }
    }
    return maxPos;
}

int circleLeft(string a[], int n, int pos) {
    if (n < 0 || pos < 0 || n <= pos)
        return -1;
    string val = a[pos];
    for (int i = pos; i < n; i ++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = val;
    return pos;
}

int enumerateRuns(const string a[], int n) {
    if (n < 0)
        return -1;
    int count = 0;
    string start;
    for (int i = 0; i < n; i ++) {
        start = a[i];
//        cerr << start << endl;
        while (a[i + 1] == start && i < n) {
            i ++;
        }
        count ++;
    }
    return count;
}

int flip(string a[], int n) {
    if (n < 0)
        return -1;
    string tempVal;
    for (int i = 0; i < n/2; i ++) {
        tempVal = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tempVal;
    }
    return n;
}

int locateDifference(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    int n = min(n1, n2);
    for (int i = 0; i < n; i ++) {
        if (a1[i] != a2[i]) {
            n = i;
            break;
        }
    }
    return n;
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    if (n2 == 0)
        return 0;
    bool matching = false;
//    int pos = n1;
    for (int i = 0; i < n1; i ++) {
        if (a1[i] == a2[0]) {
            for (int j = 0; j < n2; j ++) {
                if (a1[i + j] != a2[j]) {
                    matching = false;
                    break;
                }
                matching = true;
            }
            if (matching)
                return i;
        }
    }
    return -1;
}

int locateAny(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    for (int i = 0; i < n1; i ++) {
//        cerr << "checking for " << a1[i] << endl;
        for (int j = 0; j < n2; j ++) {
            if (a1[i] == a2[j]) {
                return i;
            }
        }
//        cerr << "checked!" << endl;
    }
    return -1;
}

//int divide(string a[], int n, string divider) {
//    if (n < 0)
//        return -1;
////    for (int i = 0; i < n; i ++) {
////        if (a[i] > divider) {
////            
////        }
////    }
//    int i = 0;
//    int bigger = 0;
//    string tempVal;
//    while (i + bigger < n) {
//        if (a[i] >= divider) {
//            for (int j = n - 1 - i - bigger; j > i; j --) {
//                if (a[j] <= divider) {
//                    tempVal = a[i];
//                    a[i] = a[n - 1 - bigger];
//                    a[n - 1 - bigger] = tempVal;
//                }
//            }
//            bigger ++;
//        }
//        else
//            i ++;
//        cerr << i << " " << bigger << endl;
//        printString(a, n);
//    }
//    return n - bigger;
//}

int divide(string a[], int n, string divider) {
    if (n < 0)
        return -1;
    int bigger = 0;
    int div = 0;
    for (int i = 0; i < n; i ++) {
        while (a[i] > divider && i + bigger < n) {
            circleLeft(a, n, i);
            bigger ++;
        }
        if (a[i] == divider)
            div ++;
    }
    cerr << bigger << " " << div << endl;
    return n - bigger - div;
}

int main() {
    // reduplicate test cases
    const int num = 9;
    string a[num] = {"alex", "zed", "bob", "james", "alex", " ", "keith", "charles", "zed"};
    assert(reduplicate(a, -12) == -1); // out of bounds
    assert(reduplicate(a, 0) == 0); // no change to array
    printString(a, num);
    assert(reduplicate(a, 5) == 5); // duplicate select number
    printString(a, num);
    
    cerr << endl;
    // locate test cases
    string b[num] = {"alex", "zed", "bob", "james", "alex", " ", "keith", "charles", "zed"};
    assert(locate(b, -12, "alex") == -1); // out of bounds
    assert(locate(b, 0, "alex") == -1); // element not found
    assert(locate(b, 3, "alex") == 0); // finding element
    assert(locate(b, num, "alex") == 0); // finding first occurence
    assert(locate(b, num, "chip") == -1); // element not in array
    
    // locationOfMax test cases
    assert(locationOfMax(b, -2) == -1); // out of bounds
    assert(locationOfMax(b, 0) == -1); // examining no elements
    assert(locationOfMax(b, 3) == 1); // max
    assert(locationOfMax(b, num) == 1); // max with duplicates
    
    // circleLeft test cases
    string running[5] = { "nikki", "donald", "asa", "tim", "ron" };
    assert(circleLeft(running, 5, -2) == -1); // out of bounds
    assert(circleLeft(running, -2, 1) == -1); // out of bounds
    assert(circleLeft(running, 3, 3) == -1); // pos greater than interesting elements
    assert(circleLeft(running, 5, 4) == 4); // nothing should have changed
    printString(running, 5);
    assert(circleLeft(running, 5, 1) == 1); // shifting one in middle
    printString(running, 5);
    assert(circleLeft(running, 5, 0) == 0); // shifting all
    printString(running, 5);
    
    cerr << endl;
    // enumerateRuns test cases
    string d[9] = {"chris", "doug", "tim", "tim", "vivek", "vivek", "vivek", "tim", "tim"};
    assert(enumerateRuns(d, -1) == -1); // out of bounds
    assert(enumerateRuns(d, 0) == 0); // none checked
    assert(enumerateRuns(d, 3) == 3); // unique elements
    assert(enumerateRuns(d, 9) == 5); // repeated elements
    
    // flip test cases
    string folks[6] = { "donald", "tim", "", "chris", "nikki", "donald" };
    assert(flip(folks, -2) == -1); // out of bounds
    assert(flip(folks, 0) == 0); // nothing flipped
    printString(folks, 6);
    assert(flip(folks, 4) == 4); // flip even number
    printString(folks, 6);
    assert(flip(folks, 5) == 5); // flip odd number
    printString(folks, 6);
    assert(flip(folks, 6) == 6); // flip all
    printString(folks, 6);
    
    // locateDifference test cases
    string group1[6] = { "donald", "tim", "", "chris", "nikki", "donald" };
    string group2[5] = { "donald", "tim", "donald", "", "chris" };
    assert(locateDifference(group1, -2, group2, 5) == -1); // out of bounds
    assert(locateDifference(group1, 6, group2, -2) == -1); // ""
    assert(locateDifference(group1, 1, group2, 2) == 1); // both identical before stopping point
    assert(locateDifference(group1, 2, group2, 1) == 1); // ""
    assert(locateDifference(group1, 0, group2, 1) == 0); // examine no elements
    assert(locateDifference(group1, 3, group2, 0) == 0); // ""
    assert(locateDifference(group1, 6, group2, 5) == 2); // identical before stopping point
    
    // subsequence test cases
    string names[10] = { "nikki", "ron", "tim", "vivek", "doug" };
    string names1[10] = { "ron", "tim", "vivek" };
    assert(subsequence(names, 5, names1, 3) == 1);  // search found
    string names2[10] = { "nikki", "vivek" };
    assert(subsequence(names, 4, names2, 2) == -1); // search not found
    assert(subsequence(names, 4, names2, 0) == 0); // searching subsequence of 0
    assert(subsequence(names, 0, names2, 0) == 0); // subsequence of sequence of 0
    
    // locateAny test cases
    string namez[10] = { "nikki", "ron", "tim", "vivek", "doug", "ron"};
    string set1[10] = { "donald", "doug", "vivek", "ron" };
    assert(locateAny(namez, -2, set1, 0) == -1); // out of bounds
    assert(locateAny(namez, 5, set1, -2) == -1); // ""
    assert(locateAny(namez, 5, set1, 0) == -1); // no elements to match
    assert(locateAny(namez, 3, set1, 4) == 1); // checking unique names
    assert(locateAny(namez, 6, set1, 4) == 1);  // checking with repeats
    string set2[10] = { "chris", "asa" };
    assert(locateAny(namez, 5, set2, 2) == -1);  // none found
    
    // divide test cases
    string cand[10] = { "a", "b", "e", "x", "n", "l", "y", "e", "y", "e" };
    assert(divide(cand, -2, "a") == -1); // out of bounds
    assert(divide(cand, 10, "a") == 0); // divide by smallest value, nothing should change
    printString(cand, 10);
    printString(cand, 10);
    assert(divide(cand, 10, "e") == 2); // duplicates of divider
    printString(cand, 10);
    assert(divide(cand, 10, "y") == 8); // duplicates of divider at greatest value
    printString(cand, 10);

    cerr << endl << "all tests succeeded" << endl;
}

//int main()
//    {
//        string h[7] = { "nikki", "ron", "asa", "vivek", "", "chris", "donald" };
//        assert(locate(h, 7, "chris") == 5);
//        assert(locate(h, 7, "asa") == 2);
//        assert(locate(h, 2, "asa") == -1);
//        assert(locationOfMax(h, 7) == 3);
//
//        string g[4] = { "nikki", "ron", "chris", "tim" };
//        assert(locateDifference(h, 4, g, 4) == 2);
//        assert(circleLeft(g, 4, 1) == 1 && g[1] == "chris" && g[3] == "ron");
//
//        string c[4] = { "ma", "can", "tu", "do" };
//        assert(reduplicate(c, 4) == 4 && c[0] == "mama" && c[3] == "dodo");
//
//        string e[4] = { "asa", "vivek", "", "chris" };
//        assert(subsequence(h, 7, e, 4) == 2);
//
//        string d[5] = { "ron", "ron", "ron", "chris", "chris" };
//        assert(enumerateRuns(d, 5) == 2);
//    
//        string f[3] = { "vivek", "asa", "tim" };
//        assert(locateAny(h, 7, f, 3) == 2);
//        assert(flip(f, 3) == 3 && f[0] == "tim" && f[2] == "vivek");
//        
//        assert(divide(h, 7, "donald") == 3);
//    
//        cout << "All tests succeeded" << endl;
//    }
