#pragma once

#include "Command.h"

class CmdSetShadeMode : public Command
{
public:
    const char* GetName() override
    {
        return "SetShadeMode";
    }

    const char* GetDescription() override
    {
        return "SetShadeMode(shadeMode)"
            "\n"
            "- Flat, Gouraud, Phong";
    }

    bool Execute(const std::vector<std::string>& params) override;
};