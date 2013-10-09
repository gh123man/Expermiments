/* 
    By: Brian Floersch (gh123man@gmail.com)
    One-lined fibonacci algorithm - just for fun (and to see if I could do it)
*/
#include <stdlib.h>
#include <functional>
#include <iostream>

int main(int argc, char* argv[]) {

    std::function<int(int)> fib = [&fib] (int n) { return (n == 0 || n == 1) ? n : fib(n -1) + fib(n - 2); };

    std::cout << fib(atoi(argv[1])) << std::endl;

	return 0;
}



