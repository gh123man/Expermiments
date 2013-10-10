/* 
    By: Brian Floersch (gh123man@gmail.com)
    recurisve reverse string - just for fun (and to see if I could do it)
*/
#include <stdlib.h>
#include <functional>
#include <iostream>
#include <string>



std::string revStr(std::string s) {

    if (s.length() == 1) {
        return s;
    } else {
        return s.substr(s.length() - 1, s.length()) + revStr(s.substr(0, s.length() - 1));
    }   
}


int main(int argc, char* argv[]) {
    

    std::cout << revStr("something") << std::endl;

    return 0;
}




