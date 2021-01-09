#include <iostream>
#include <stack>

void _subset_generation2(int a, int N) {
    //std::cout << std::bitset<3>(a) << std::endl;
    std::stack<int> output;
    for (int i = 0; i < N;i++) {
        int c = (a>>i) & 1;
        output.push(c);
    }
    for (int i = 0; i < N; i++) {
        std::cout << output.top();
        output.pop();
    }
    std::cout << std::endl;
    if (a <= 0) {
        return;
    }
    else {
        _subset_generation2(a - 1,N);
    }
}

void subset_generation(const size_t n){
    int a = pow(2, n) - 1;
    std::cout << a << std::endl;
    //std::cout<<std::bitset<3>(a)<<std::endl;
    _subset_generation2(a,n);
    
}
