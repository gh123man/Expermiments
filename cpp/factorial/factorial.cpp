/* 
    By: Brian Floersch (gh123man@gmail.com)
    some fun factorial stuff - just for fun (and to see if I could do it)
*/
#include <stdlib.h>
#include <functional>
#include <iostream>



int factorial(int n) {
    if (n == 1) {
        return n;
    } else {
        return n * factorial(n - 1);
    }   
}

int facshort(int n) {
    return (n == 1) ? n : n * facshort(n - 1);
}

int main(int argc, char* argv[]) {
    
    std::function<int(int)> fact = [&fact] (int n) {return (n == 1) ? n : n * fact(n - 1);};

    std::cout << fact (atoi(argv[1])) << std::endl;

    return 0;
}





