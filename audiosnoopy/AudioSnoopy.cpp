// audiosnoopy/AudioSnoopy.cpp

#include "AudioSnoopy.h"

AudioSnoopy::AudioSnoopy(const std::string& pluginPath) {
    juce::AudioPluginFormatManager formatManager;
    formatManager.addDefaultFormats();
    
    juce::PluginDescription desc;
    desc.fileOrIdentifier = juce::String(pluginPath);

    juce::String error;
    plugin = formatManager.createPluginInstance(desc, 44100, 512, error);

    if (plugin) {
        pluginInfo = "{";
        pluginInfo += "\"name\": \"" + plugin->getName().toStdString() + "\",";
        pluginInfo += "\"format\": \"" + plugin->getPluginDescription().pluginFormatName.toStdString() + "\",";
        pluginInfo += "\"manufacturer\": \"" + plugin->getManufacturer().toStdString() + "\",";
        pluginInfo += "\"version\": \"" + plugin->getVersion().toStdString() + "\",";
        pluginInfo += "\"parameters\": [";

        auto params = plugin->getParameters();
        for (size_t i = 0; i < params.size(); ++i) {
            auto param = params[i];
            pluginInfo += "{";
            pluginInfo += "\"name\": \"" + param->getName(512).toStdString() + "\",";
            pluginInfo += "\"default\": " + std::to_string(param->getDefaultValue());
            pluginInfo += i < params.size() - 1 ? "}," : "}";
        }

        pluginInfo += "]}";
    }
    else {
        throw std::runtime_error("Failed to create plugin instance: " + error.toStdString());
    }
}

std::string AudioSnoopy::getPluginInfo() const {
    return pluginInfo;
}