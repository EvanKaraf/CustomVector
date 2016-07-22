#include <iostream>
#include <vector>
#include <ctime>
#include "myVector.h"

using namespace std;
#define MAX 200000

class Course {
public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Course::name = name;
    }

private:
    string name;
};

int main() {
    myVector<Course> Courses;
    vector<Course> Courses2;
    Course c;
    c.setName("hey");
    clock_t begin;
    begin = clock();
    for (int i = 0; i < MAX; i++) {
        Courses.push_back(c);
    }
    clock_t end = clock();
    cout << (double) (end - begin) / CLOCKS_PER_SEC << endl;
    clock_t begin1 = clock();
    for (int i = 0; i < MAX; i++) {
        Courses2.push_back(c);
    }
    clock_t end1 = clock();
    cout << (double) (end1 - begin1) / CLOCKS_PER_SEC << endl;

    string ggg;
    cin >> ggg;
    return 0;
}