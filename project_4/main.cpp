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
    if (n < 0)
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
        cerr << start << endl;
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
    bool matching = false;
    int pos = n1;
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

int divide(string a[], int n, string divider) {
    if (n < 0)
        return -1;
//    for (int i = 0; i < n; i ++) {
//        if (a[i] > divider) {
//            
//        }
//    }
    int i = 0;
    int bigger = 0;
    string tempVal;
    while (i + bigger < n) {
        if (a[i] >= divider) {
            tempVal = a[i];
            a[i] = a[n - 1 - bigger];
            a[n - 1 - bigger] = tempVal;
            
            bigger ++;
        }
        else
            i ++;
        cerr << i << " " << bigger << endl;
        printString(a, n);
    }
    return n - bigger;
}


int main() {
    string cand[6] = { "donald", "asa", "ron", "vivek", "chris", "nikki" };
    int x = divide(cand, 6, "doug");  //  returns 3
        // cand must now be
        //      "chris"  "donald"  "asa"  "nikki"  "vivek"  "ron"
        // or   "donald"  "asa"  "chris"  "ron"  "nikki"  "vivek"
        // or one of several other orderings.
        // All elements < "doug" (i.e., "donald", "asa", and "chris")
        //   come before all others
        // All elements > "doug" (i.e., "vivek", "nikki", and "ron")
        //   come after all others
    string cand2[4] = { "ron", "vivek", "asa", "tim" };
    int y = divide(cand2, 4, "tim");  //  returns 2
        // cand2 must now be either
        //      "ron"  "asa"  "tim"  "vivek"
        // or   "asa"  "ron"  "tim"  "vivek"
        // All elements < "tim" (i.e., "asa" and "ron") come
            // before all others.
        // All elements > "tim" (i.e., "vivek") come after all others.
    cerr << x << " " << y << endl;
    printString(cand, 6);
    printString(cand2, 6);
    
}
