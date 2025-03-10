#pragma once

#include "Command.h"

class CmdModel : public Command
{
public:
    const char* GetName() override
    {
        return "Model";
    }

    const char* GetDescription() override
    {
        return "Model (fileName)"
            "\n"
            "- Loads a model into memory and adds vertices to primatives manager.";
    }

    bool Execute(const std::vector<std::string>& params) override;

private:

};