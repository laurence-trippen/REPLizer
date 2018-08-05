//
//  replizer.cpp
//  replizer
//
//  Created by Laurence Trippen on 26.07.18.
//  Copyright © 2018 Laurence Trippen. All rights reserved.
//

#include "replizer.h"

namespace replizer
{
    void Repl::start()
    {
        if (!exitCommand.empty() && !prefix.empty())
        {
            std::string input;
            do {
                std::cout << prefix;
                std::getline(std::cin, input);
                
                if (callbackList.find(input) == callbackList.end())
                {
                    if (input != exitCommand)
                    {
                        std::cout << "Command not found!" << std::endl;
                    }
                }
                else
                {
                    std::function<void()> callback = this->callbackList[input];
                    callback();
                }
            } while(exitCommand != input);
            
            if (this->onExit != nullptr)
            {
                onExit();
            }
        }
        else
        {
            std::cout << "Couldn't start because exit command isn't set!" << std::endl;
        }
    }
    
    void Repl::setREPLPrefix(const std::string &prefix)
    {
        this->prefix = prefix;
    }
    
    void Repl::on(const std::string &command, std::function<void ()> callback)
    {
        this->callbackList[command] = callback;
    }
    
    void Repl::exit(const std::string &exitCommand)
    {
        this->exitCommand = exitCommand;
    }
    
    void Repl::exit(const std::string &exitCommand, std::function<void ()> onExit)
    {
        this->exitCommand = exitCommand;
        this->onExit = onExit;
    }
}