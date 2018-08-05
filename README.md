# REPLizer
C++ library to create REPL-Applications

```cpp
#include <iostream>
#include <string>
#include "replizer.h"

int main(int argc, const char * argv[])
{
    replizer::Repl repl;
    repl.setREPLPrefix("testapp> ");
    repl.on("help", [](){
        std::cout << "Type in 'quit' to exit the program!" << std::endl;
    });
    repl.on("whoami", [](){
        std::cout << "Laurence Trippen" << std::endl;
    });
    repl.exit("quit", [](){
        std::cout << "Bye!" << std::endl;
    });
    repl.start();
    
    return 0;
}
``` 
