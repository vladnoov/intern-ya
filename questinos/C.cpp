
// "some    string  " -> "some string " ''\n
// it : ++ !' ', ' '
//it s.begin -> s,end

void delete_spaces(string& s) { // o(n) time, mem = 0(1)
    string::iterator it1, it2;
    it1 = s.begin();
    char prev = 'a';
    it2 = s.begin(); // right
    while (it2 != s.end()) {
        if (*it2 == ' ') {
            if (prev == ' ') {    //  aa b  b   \n          
            }
            else {
                *it1 = *it2;
                ++it1;
            }
            // prev = *it2;          
        }
        else {
            *it1 = *it2;
            ++it1;

        }
        prev = *it2;
        ++it2;
    }
    s.erase(it1, s.end());
}





// abcddd // text
//acb
//dc, dcd 
// al_size

// n - len of T
// l - len of S

// n * l * log (al_size) * al_size// <char s, int cnt> - базовое
// n * log (al_size) * al_size// <char s, int cnt> - оптимизировали построение мапа
// hash_map -> n * al_size - time
// hash s1 , hash s2
// l ++, r++
// s1[s[l-1]]--; ~? s2[s[l-1]]
// s1[s[r]]++; ~? s2[s[r]] //
 // if both 1 -> find



//  o(n) * l log l
// l log l 
// vector<map<char, int>> v_mp
// i 'ai'++
// 'ai' in rang i, k = F(a[i]) - F(a[k-1])
// n*logl
// 


// baaabaaa
// l, r: r - l + 1 == len(s)
// aaaab
/*
m1.size() = m2,size();
for (auto m: m1 ){
    char c : m1[c] != m2[c]
    // cnt - num of chars :  m1[c] != m2[c]
    if sl == sr
        //  m [ sl -1 == m2 []
        {
            cnt++;
        }
        else
        if become eq
            cnt--
        m>second == m2[m->first]
}
*/


//s = text
int solve(const string& text, const string& s) {
    unordered_map<char, int>m;


    int n = text.size(), len = s.size();
    if (n == 0 || len == 0 || len > n)
        return -1;

    int cnt = 0;
    int r = 0;

    while (r < len) {
        m[text[r]]++;
        m[s[r]]--;
        r++;
    }

    for (auto a : m) {
        if (a->second != 0)
            cnt++;
    }
    int l = 0;
    if (!cnt)
        return l;


    for (r = len; r < n; r++) {
        if (text[l] == text[r]) {

        }
        else {
            if (m[text[l]] == 0) {
                m[text[l]]--;
                cnt++;
            }
            else {
                m[text[l]]--;
                if (m[text[l]] == 0) {
                    cnt--;
                }
            }
            if (m[text[r]] == 0) {
                m[text[r]]++;
                cnt++;
            }
            else {
                m[text[r]]++;
                if (m[text[r]] == 0) {
                    cnt--;
                }
            }
        }
        l++;
        if (!cnt)
            return l;
    }
    return -1;
}
