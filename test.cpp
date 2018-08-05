//
//  test.cpp
//  replizer
//
//  Created by Laurence Trippen on 26.07.18.
//  Copyright © 2018 Laurence Trippen. All rights reserved.
//

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