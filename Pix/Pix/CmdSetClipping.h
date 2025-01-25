#pragma once

#include "Command.h"

class CmdSetClipping : public Command
{
public:
	const char* GetName() override
	{
		return "SetClipping";
	}
	const char* GetDescription() override
	{
		return
			"SetClipping(clip)"
			"\n"
			"- enables or disable clipping within the viewport";
	}

	bool Execute(const std::vector<std::string>& params) override;

private:

};