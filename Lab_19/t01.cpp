//
// Created by Yaroslava Krenevych on 26.11.2025.
//

#include <iostream>
#include <queue>


using namespace std;

struct Client {
    int id; //номер покупця
    int arrive_t;   //коли він прийшов
    int service_t; //час обслуговування
};


int main() {
    vector<int> s_times = {3, 5, 1, 2};
    int n = s_times.size();
    int cur_s_end_time = 0;
    queue<Client> q1;

    vector<int> c_times;

    for (int i = 0; i < n; i++) {
        int arrive_t = i;

        q1.push({i+1, arrive_t, s_times[i]});
        cout << "Покупець " << i + 1 << " прибуває о: " << arrive_t << " | Час t_i: " << s_times[i] << endl;
    }

    queue <Client> copy_q = q1;

    while (!copy_q.empty()) {
        Client current = copy_q.front();
        copy_q.pop();

        int A_i = current.arrive_t;
        int t_i = current.service_t;


        int S_i = max(A_i, cur_s_end_time);

        int C_i = S_i - A_i;

        cur_s_end_time = S_i + t_i;

        c_times.push_back(C_i);

        cout << "Покупець " << current.id << ": час початку обслуговування = " << S_i
                  << " | час у черзі = " << C_i
                  << " | час завершення = " << cur_s_end_time << endl;


    }

    auto min_t_it = min_element(s_times.begin(), s_times.end());
    int min_t_index = distance(s_times.begin(), min_t_it) + 1; // +1 бо індексація у нас з 1, а не 0

    cout << "Покупець з НАЙМЕНШИМ ЧАСОМ обслуговування (min t_i): №"
              << min_t_index << " (" << *min_t_it << " хв)" << endl;

    auto max_c_it = max_element(s_times.begin(), s_times.end());
    int max_c_index = distance(s_times.begin(), max_c_it) + 1;

    cout << "Покупець, що провів НАЙБІЛЬШЕ ЧАСУ в черзі (max c_i): №"
              << max_c_index << " (" << *max_c_it << " хв)" << endl;
}