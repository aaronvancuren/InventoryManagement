#pragma once
#include <algorithm>
#include <map>
#include <string>

namespace DisplayOutput
{
    enum class DisplayOutput
    {
        NOTFOUND,
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
        {"Display Port", DisplayOutput::DP},
        {"Digital Visual Interface", DisplayOutput::DVI},
        {"High-Definition Multimedia", DisplayOutput::HDMI},
        {"Video-In Video-Out", DisplayOutput::VIVO},
        {"Video Graphics Array", DisplayOutput::VGA}
    };
}
