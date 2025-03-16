#pragma once

#include "Command.h"

class CmdPostProcessingBeginDraw : public Command
{
public:
    const char* GetName() override { return "PostProcessingBeginDraw"; }
    const char* GetDescription() override
    {
        return
            "PostProcessingBeginDraw()"
            "\n"
            "- initiates rendering to the render target instead of the main screen";
    }
    bool Execute(const std::vector<std::string>& params) override;

private:

};

class CmdPostProcessingEndDraw : public Command
{
public:
    const char* GetName() override { return "PostProcessingEndDraw"; }
    const char* GetDescription() override
    {
        return
            "PostProcessingEndDraw()"
            "\n"
            "- draws the rendertarget back to the main screen\n"
            "- applies any effects to the image";
    }
    bool Execute(const std::vector<std::string>& params) override;

private:

};

class CmdPostProcessingSetEffectType : public Command
{
public:
    const char* GetName() override { return "PostProcessingSetEffectType"; }
    const char* GetDescription() override
    {
        return
            "PostProcessing(effectTypes)"
            "\n"
            "- sets the effect to apply to the image"
            "- none, monochrome, invert, mirror, blur"
            "- colorMaskR, colorMaskG, colorMaskB"
            "- sepia, wave, fishEye";
    }
    bool Execute(const std::vector<std::string>& params) override;

private:

};