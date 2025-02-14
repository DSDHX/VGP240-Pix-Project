#pragma once

#include "Command.h"

class CmdSetCullMode : public Command
{
public:
	const char* GetName() override { return "SetCullMode"; }
	const char* GetDescription() override
	{
		return
			"SetCullMode(mode)"
			"\n"
			"- none will not use any face culling"
			"- back will not render anything facing away from the camera"
			"- front will not render anything facing towards the camera";
	}

	bool Execute(const std::vector<std::string>& params) override;
private:

};