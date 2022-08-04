// lab4zad2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Pi;

int search_algorithm(string P, string T, Pi& Pi) {
    int m, n;
    int q, i;
    n = T.length();
    m = P.length();
    q = 0;
    for (i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i])
            q = Pi[q - 1];
        if (P[q] == T[i])
            q++;
        if (q == m) {
            return i - q + 1; // индекс начала совпадения
        }
    }
    return -1; // совпадений не найдено
}

// построение префиксной функции
// Pi& prefix_func(string P, Pi& Pi)
void prefix_func(string T, string P, Pi& Pi) {
    int m, k, q;
    m = P.length(); // длина строки
    // массив префиксной функции
    Pi.push_back(0);
    k = 0;
    for (q = 1; q < m; q++) // цикл построения по подстрокам
    {
        while (k > 0 && P[k] != P[q])
            k = Pi[k - 1];
        if (P[k] == P[q])
            k++;
        Pi.insert(Pi.begin() + q, k);
    }
    cout << search_algorithm(T, P, Pi) << endl;
    cout << T << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    Pi pi;
    string str, str2;
    cout << "Введите подстроку" << endl;
    cin >> str2;
    cout << "Введите строку" << endl;
    cin >> str;

    // 2 - аргумент ababacc;
    // 1 - ababa
    prefix_func(str2, str, pi);
    return 0;
}
