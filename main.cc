#include <iostream>
#include"vector.cc"
using namespace std;


int main(){
    Vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        for (size_t i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        return 0;
}