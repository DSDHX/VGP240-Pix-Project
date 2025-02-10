#pragma once

#include "Command.h"

class CmdSetCameraPosition : public Command
{
public:
	const char* GetName() override { return "SetCameraPosition"; }
	const char* GetDescription() override
	{
		return
			"SetCameraPosition(x, y, z)"
			"\n"
			"- sets the camera position";
	}

	bool Execute(const std::vector<std::string>& params) override;
private:

};

class CmdSetCameraDirection : public Command
{
public:
	const char* GetName() override { return "SetCameraDirection"; }
	const char* GetDescription() override
	{
		return
			"SetCameraDirection(x, y, z)"
			"\n"
			"- sets the camera direction";
	}

	bool Execute(const std::vector<std::string>& params) override;
private:

};

class CmdSetCameraNear : public Command
{
public:
	const char* GetName() override { return "SetCameraNear"; }
	const char* GetDescription() override
	{
		return
			"SetCameraNear(value)"
			"\n"
			"- sets the camera near value";
	}

	bool Execute(const std::vector<std::string>& params) override;
private:

};

class CmdSetCameraFar : public Command
{
public:
	const char* GetName() override { return "SetCameraFar"; }
	const char* GetDescription() override
	{
		return
			"SetCameraFar(value)"
			"\n"
			"- sets the camera far value";
	}

	bool Execute(const std::vector<std::string>& params) override;
private:

};

class CmdSetCameraFov : public Command
{
public:
	const char* GetName() override { return "SetCameraFov"; }
	const char* GetDescription() override
	{
		return
			"SetCameraFov(value)"
			"\n"
			"- sets the camera field of view angle";
	}

	bool Execute(const std::vector<std::string>& params) override;
private:

};