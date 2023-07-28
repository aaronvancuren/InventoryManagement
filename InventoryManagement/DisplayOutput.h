#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace DisplayOutput
{
    enum class DisplayOutput
    {
        DP,
        DVI,
        HDMI,
        VIVO,
        VGA
    };

    std::map<DisplayOutput, std::string> const toStringMapping =
    {
        {DisplayOutput::DP, "Display Port"},
        {DisplayOutput::DVI, "Digital Visual Interface"},
        {DisplayOutput::HDMI, "High-Definition Multimedia"},
        {DisplayOutput::VIVO, "Video-In Video-Out"},
        {DisplayOutput::VGA, "Video Graphics Array"}
    };

    std::map<std::string, DisplayOutput> const toEnumMapping =
    {
        {"DISPLAY PORT", DisplayOutput::DP},
        {"DIGITAL VISUAL INTERFACE", DisplayOutput::DVI},
        {"HIGH-DEFINITION MULITMEDIA", DisplayOutput::HDMI},
        {"VIDEO-IN VIDEO-OUT", DisplayOutput::VIVO},
        {"VIDEO GRAPHICS ARRAY", DisplayOutput::VGA}
    };
}
