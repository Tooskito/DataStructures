#include <vector>
#include <iostream>
#include <string>

using namespace std;

template<class T>
void printv(const vector<T> & vec) {
    
    // print vector.
    for (T elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}


template<class T>
void printvp(const vector<T> & vec, size_t p, size_t l, size_t r) {

    // print vector.
    printv(vec);

    // print pointer vector.
    vector<char> pv(vec.size(), ' ');
    pv.at(p) = 'p';
    pv.at(l) = 'l';
    pv.at(r) = 'r';
    printv(pv);

    // print divider.
    for (size_t i = 0; i < vec.size() * 2 - 1; ++i) {
        cout << "-";
    }
    cout << endl;
}


template<class T>
void swapvp(vector<T> & vec, size_t a, size_t b) {

    // swaps indices a and b.
    T temp = vec.at(a);
    vec.at(a) = vec.at(b);
    vec.at(b) = temp;

    // print out after swap.
    printv(vec);

    // print divider.
    for (size_t i = 0; i < vec.size() * 2 - 1; ++i) {
        cout << "-";
    }
    cout << endl;
}

template <class T>
void quicksort(vector<T> & vec) {
    
    // initial print.
    size_t p = 0, l = 1, r = vec.size() - 1;
    printvp(vec, p, l, r);

    
}

int main() {
    string str = "THECORONAVIRUSSUCKS";
    vector<char> vec(str.begin(), str.end());
    quicksort(vec);
    return 0;
}