1. Дан массив из нулей и единиц.Нужно определить, какой максимальный по длине подинтервал единиц можно получить, удалив ровно один элемент массива.
size_t maxOnes(const std::vector<int>& v);

assert(maxOnes({ 0, 0 }) == 0);
assert(maxOnes({ 1, 0 }) == 1);
assert(maxOnes({ 0, 1 }) == 1);
assert(maxOnes({ 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1 }) == 5);
assert(maxOnes({ 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 }) == 6);
Удалять один элемент из массива обязательно.
Требуется решение без дополнительной памяти - O(1), и за линейное время - O(N), исходный массив менять нельзя

1, 1, 1, 0, 1  0 1 1 1 0
0  1  2  3  0  1       3
2  1  0  1  0  3

size_t maxOnes(const std::vector<int>&v) {

    int n = v.size();
    if (!n) {
        return -1;
    }
    int answer = 0, prev = 0, pos0 = 0, cnt1 = 0;
    bool check = 1;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            cnt1++;
        }
        else { // 1 1 0 0 1 1 0 1
            check = 0;
            answer = max(answer, cnt1 + prev);
            prev = cnt1;

            cnt1 = 0;
            // pos0 = i;
        }
    }


    if (check)
        return cnt1 - 1;

    answer = max(answer, cnt1 + prev);
    return answer;
}

2. Для двух поисковых выдач, заданных массивами DocId'ов (т.е. просто векторами целых чисел) длины N, для всех K от 1 до N нужно посчитать 
количество общих документов в топах размера K.
Непоисковая формулировка :


Для двух массивов целых чисел длины N, для всех K от 1 до N, посчитать количество общих чисел на префиксах длины K.

std::vector<int> Doit(
    const std::vector<int>& a,
    const std::vector<int>& b
);

assert(Doit({ 1,2,3,4 }, { 2,0,1,3 }) == std::vector<int>({ 0,1,2,3 }));

intersection l = 1..n' (a[1.. k], b[1..k]]);


1 1 2 3
2 4 1 5

// ptr1, ptr2 :a , b
// ++ hasha[], hashb[], hahs[a[ptra]], hashb[b[ptr]]

// a[ptr] == b[ptrb]
// ++
// min(hasha[a[ptra], hashb[b[ptr]]); /// 





std::vector<int> Doit(
    const std::vector<int>&a,
    const std::vector<int>&b
) {
    int n1 = a.size(), n2 = b.size();

    if (!n1 || !n2)
        return {};

    vector<int> answer;
    int ptr1 = 0, ptr2 = 0, cntr = 0, first_add, second_add;
    unordered_map<int, int> hasha, hashb;

    // answer.push_back(cntr);

    while (ptr1 < n1 && ptr2 < n2) {
        if ([a[ptr1] == b[ptr2]) {
            cntr++;
            answer.push_back(cntr);
            continue;
        }

        hasha[a[ptr1]]++;
        hashb[b[ptr2]]++;

        if (hashb[a[ptr1]] != 0) {
            hashb[a[ptr1]] --;
            hasha[a[ptr1]]--;
            cntr++;
        }

        if (hasha[b[ptr2]] != 0) {
            hasha[b[ptr2]] --;
            hashb[b[ptr2]]--;
            cntr++;
        }

        answer.push_back(cntr);

    }
    return answer;
    //while (ptr1 < max(n1,n2))

}