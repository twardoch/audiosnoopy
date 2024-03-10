// audiosnoopy/AudioSnoopy.h

#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <string>

class AudioSnoopy {
public:
    AudioSnoopy(const std::string& pluginPath);
    std::string getPluginInfo() const;

private:
    std::unique_ptr<juce::AudioPluginInstance> plugin;
    std::string pluginInfo;
};