#pragma once

#include "Command.h"

class CmdUseFilter : public Command
{
public:
    const char* GetName() override
    {
        return "SetUseFilter";
    }
    const char* GetDescription() override
    {
        return
            "SetUseFilter(bool)"
            "\n"
            "- enables/disables using biliner filtering";
    }

    bool Execute(const std::vector<std::string>& params) override;

private:

};