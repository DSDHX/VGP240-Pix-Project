#include "CmdPostProcessing.h"
#include "PostProcessing.h"

bool CmdPostProcessingBeginDraw::Execute(const std::vector<std::string>& params)
{
    PostProcessing::Get()->BeginDraw();
    return true;
}

bool CmdPostProcessingEndDraw::Execute(const std::vector<std::string>& params)
{
    PostProcessing::Get()->EndDraw();
    return true;
}

bool CmdPostProcessingSetEffectType::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
    {
        return false;
    }

    EffectTypes effectType = EffectTypes::None;
    if (params[0] == "none") { effectType = EffectTypes::None; }
    else if (params[0] == "monochrome") { effectType = EffectTypes::MonoChrome; }
    else if (params[0] == "invert") { effectType = EffectTypes::Invert; }
    else if (params[0] == "mirror") { effectType = EffectTypes::Mirror; }
    else if (params[0] == "blur") { effectType = EffectTypes::Blur; }
    else if (params[0] == "colorMaskR") { effectType = EffectTypes::ColorMaskR; }
    else if (params[0] == "colorMaskG") { effectType = EffectTypes::ColorMaskG; }
    else if (params[0] == "colorMaskB") { effectType = EffectTypes::ColorMaskB; }
    else if (params[0] == "sepia") { effectType = EffectTypes::Sepia; }
    else if (params[0] == "wave") { effectType = EffectTypes::Wave; }
    else if (params[0] == "fishEye") { effectType = EffectTypes::FishEye; }
    else { return false; }

    PostProcessing::Get()->SetEffectType(effectType);
    return true;
}