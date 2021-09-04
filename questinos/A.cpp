ѕусть у нас есть сортированный вектор с длинными последовательност€ми одинаковых чисел.ѕредставим его в виде списка пар вида(value, count).
Ќапример[(1, 3), (2, 4)] €вл€етс€ представлением вектора[1, 1, 1, 2, 2, 2, 2].
“ребуетс€ написать функцию, котора€ считает скал€рное произведение двух векторов в такой форме.


// time : len of seq, mem same
//
// (1, 3) * (2, 3) = (2 * 1, 3)
p.first = _num, p.second = _cnt;

int res(const vector<pair<int, int> >& a, const vector<pair<int, int> >& b) {

    int Na = a.size(), Nb = b.size();
    int num_of_elements_in_a = 0, num_of_elements_in_b = 0;

    for (int i = 0; i < Na; i++)
        num_of_elements_in_a += a[i].second;
}

for (int i = 0; i < Nb; i++)
    num_of_elements_in_b += b[i].second;
    }

    if (num_of_elements_in_b != num_of_elements_in_a) {
        cout << "wrong format\n";
        return -1;
    }

    int a_num, a_cnt, b_num, b_cnt, mn;
    int a_ptr = 0, b_ptr = 0;
    int a_prev_cnt = 0, b_prev_cnt = 0;

    bool move_a = 1, move_b = 1;

    int sum = 0;

    // a[i] and b[i] . second > 0 always
    while (a_ptr < Na && b_ptr < Nb) {

        if (move_a == 1) {
            a_prev_cnt = 0;
            a_num = a[a_ptr].first;
            a_cnt = a[a_ptr].second;
        }
        else {
            a_cnt = a_prev_cnt;
        }

        if (move_b == 1) {
            b_prev_cnt = 0;
            b_num = b[b_ptr].first;
            b_cnt = b[b_ptr].second;
        }
        else {
            b_cnt = b_prev_cnt;
        }

        mn = min(a_cnt, b_cnt);

        sum += (a_num * b_num) * mn;
        a_cnt -= mn;
        b_cnt -= mn;

        a_prev_cnt = a_cnt;
        b_prev_cnt = b_cnt;

        if (!a_prev_cnt) { // 1,3 x 2, 3
            move_a = 1;
            a_ptr++;
        }
        else
            move_a = 0;

        if (!b_prev_cnt) {
            b_ptr++;
            move_b = 1;
        }
        else
            move_b = 0;

    }
    return sum;
}

