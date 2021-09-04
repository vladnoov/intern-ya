/*
Примеры палиндромов:
    Казак
    А роза упала на лапу Азора
    Do geese see God?
    Madam, I’m Adam
*/

bool check2(char& c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

bool is_eq(char c1, char c2) {
    if (c1 == c2) {
        return true;
    }

    int t1, t2;
    if (c1 >= 'A' && c1 <= 'Z') {
        t1 = c1 - 'A';
    }
    else
        t1 = c1 - 'a';

    if (c2 >= 'A' && c2 <= 'Z')
        t2 = c2 - 'A';
    else
        t2 = c2 - 'a';

    return (t1 == t2);
}

bool check(const string& s) {

    int n = s.size();
    if (!n) {
        return false;     //'\0'
    }
    char = c1, c2;
    // 
    int l = 0, r = n - 1;
    while (l <= r) { // 0 <= -1 ?
        c1 = s[l];
        c2 = s[r];
        if (!check2(c1)) {
            l++;
            continue;
        }
        if (!check2(c2)) {
            r--; continue;
        }
        if (is_eq(c1, c2)) {
            l++; r--;
        }
        else {
            return false;
        }
    }
    return true;
}


/*
int a, int b;

s
sum (a0 .. ak), k = 1.. n=a.size();

a1 a2 a3 a4 a5  a6
x - const
s(r) - s(l-1) = x;
//s(r) = x + s(l-1);
s(l-1) = (s(r) - x) //

s (5) - s(2) // l - 1;
*/



pair<int, int> solve(const vector<int>& a, const int& x) {
    int n = a.size();

    int l = -1, r = -1;

    pair<int, int>p;
    p = make_pair(l, r);

    unordered_map<int, int> hash;
    hash.clear();
    int cur = 0;

    for (int i = 0; i < n; i++) {
        cur += a[i];
        if (cur == x) {
            l = 0; r = i;
            p = make_pair(l, r);
            return p;
        }
        hash[cur] = i; // sum of a[0] .. a[i]
        auto it = hash.find(cur - x);
        if (it != hash.end()) { // it
            l = it->second; // because a[i] - a[l-1]
            l++;
            r = i;
            p = make_pair(l, r);
            return p;
        }
        // 1 3 4 find 7
        // 1 4 8 
       // 8 - 7 - exits - > second 0 -> l++
    }

    return p;
}
