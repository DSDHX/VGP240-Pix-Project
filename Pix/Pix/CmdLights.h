#pragma once

#include "Command.h"

class CmdSetLightAmbient : public Command
{
public:
    const char* GetName() override
    {
        return "SetLightAmbient";
    }

    const char* GetDescription() override
    {
        return "SetLightAmbient(r, g, b)"
               "\n"
               "- Sets the Ambient Color for the light.";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetLightDiffuse : public Command
{
public:
    const char* GetName() override
    {
        return "SetLightDiffuse";
    }

    const char* GetDescription() override
    {
        return "SetLightDiffuse(r, g, b)"
            "\n"
            "- Sets the Diffuse Color for the light.";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetLightSpecular : public Command
{
public:
    const char* GetName() override
    {
        return "SetLightSpecular";
    }

    const char* GetDescription() override
    {
        return "SetLightSpecular(r, g, b)"
            "\n"
            "- Sets the Specular Color for the light.";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddDirectionalLight : public Command
{
public:
    const char* GetName() override
    {
        return "AddDirectionalLight";
    }

    const char* GetDescription() override
    {
        return "AddDirectionalLight(x, y, z)"
            "\n"
            "- Add a Directional Light to the scene.";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddPointLight : public Command
{
public:
    const char* GetName() override
    {
        return "AddPointLight";
    }

    const char* GetDescription() override
    {
        return "AddPointLight(x, y, z, <constant>, <linear>, <quadratic>)"
            "\n"
            "- Add a Point Light to the scene.";
    }

    bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddSpotLight : public Command
{
public:
    const char* GetName() override
    {
        return "AddSpotLight";
    }

    const char* GetDescription() override
    {
        return "AddSpotLight(pX, pY, pZ, dX, dY, dZ, <constant>, <linear>, <quadratic>, <angle>, <decay>"
            "\n"
            "- Add a Spot Light to the scene.";
    }

    bool Execute(const std::vector<std::string>& params) override;
};