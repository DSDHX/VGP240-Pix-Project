#pragma once

#include "Command.h"

class CmdSetMaterialEmissive : public Command
{
public:
	const char* GetName() override { return "SetMaterialEmissive"; }
	const char* GetDescription() override
	{
		return
			"SetMaterialEmissive(r, g, b)\n"
			"\n"
			"- sets the emissive color for a material";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};

class CmdSetMaterialAmbient : public Command
{
public:
	const char* GetName() override { return "SetMaterialAmbient"; }
	const char* GetDescription() override
	{
		return
			"SetMaterialAmbient(r, g, b)\n"
			"\n"
			"- sets the ambient color for a material";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};

class CmdSetMaterialDiffuse : public Command
{
public:
	const char* GetName() override { return "SetMaterialDiffuse"; }
	const char* GetDescription() override
	{
		return
			"SetMaterialDiffuse(r, g, b)\n"
			"\n"
			"- sets the diffuse color for a material";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};

class CmdSetMaterialSpecular : public Command
{
public:
	const char* GetName() override { return "SetMaterialSpecular"; }
	const char* GetDescription() override
	{
		return
			"SetMaterialSpecular(r, g, b)\n"
			"\n"
			"- sets the specular color for a material";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};

class CmdSetMaterialShininess : public Command
{
public:
	const char* GetName() override { return "SetMaterialShininess"; }
	const char* GetDescription() override
	{
		return
			"SetMaterialShininess(shininess)\n"
			"\n"
			"- sets the shininess value for a material";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};