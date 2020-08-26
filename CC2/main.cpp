#include <vector>
#include <iostream>
#include <string>

using namespace std;

template<class T>
void printv(const vector<T> & vec) {
    for (T elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

template<class T>
void printvp(const vector<T> & vec, size_t p, size_t l, size_t r) {
    printv(vec);

    vector<char> pv(vec.size(), ' ');
    pv.at(p) = 'p';
    pv.at(l) = 'l';
    pv.at(r) = 'r';
    printv(pv);

    /*
    vector<char> lv(vec.size(), ' ');
    lv.at(l) = 'l';
    printv(lv);

    vector<char> rv(vec.size(), ' ');
    rv.at(r) = 'r';
    printv(rv);
    */

    for (size_t i = 0; i < vec.size() * 2; ++i) {
        cout << "-";
    }
    cout << endl;
}

template <class T>
void quicksort(vector<T> & vec) {
    size_t p = 0, l = 1, r = vec.size() - 1;
    printvp(vec, p, l, r);
    while (l < r) {
        while (vec.at(l) < vec.at(p) and l < r) {
            ++l;
        }
        while (vec.at(r) > vec.at(p) and r > l) {
            --r;
        }
        T temp = vec.at(l);
        vec.at(l) = vec.at(r);
        vec.at(r) = temp;
    }
    T temp = vec.at(p);
    vec.at(p) = vec.at(--r);
    vec.at(r) = temp;
    
    printv(vec);
    while (vec.at(l) < vec.at(p) and l < r) {
        ++l;
        cout << "l is now " << l << " where the val is " << vec.at(l) << endl;
    }
    while (vec.at(r) > vec.at(p) and r > l) {
        --r;
        cout << "r is now " << r << " where the val is " << vec.at(r) << endl;
    }
}

int main() {
    string str = "THECORONAVIRUSSUCKS";
    vector<char> vec(str.begin(), str.end());
    quicksort(vec);
    return 0;
}