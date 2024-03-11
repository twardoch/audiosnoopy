// audiosnoopy/AudioSnoopy.cpp

#include "AudioSnoopy.h"
#include "json/json.hpp"

using json = nlohmann::json;

AudioSnoopy::AudioSnoopy(const std::string& pluginPath) {
    juce::AudioPluginFormatManager formatManager;
    formatManager.addDefaultFormats();

    juce::PluginDescription desc;
    desc.fileOrIdentifier = juce::String(pluginPath);

    juce::String error;
    plugin = formatManager.createPluginInstance(desc, 44100, 512, error);

    if (plugin) {
        json pluginJson;
        pluginJson["name"] = plugin->getName().toStdString();
        pluginJson["format"] = plugin->getPluginDescription().pluginFormatName.toStdString();
        pluginJson["manufacturer"] = plugin->getPluginDescription().manufacturerName.toStdString();
        pluginJson["version"] = plugin->getPluginDescription().version.toStdString();

        json parametersJson = json::array();
        auto params = plugin->getParameters();
        for (auto param : params) {
            json paramJson;
            paramJson["name"] = param->getName(512).toStdString();
            paramJson["default"] = param->getDefaultValue();
            parametersJson.push_back(paramJson);
        }
        pluginJson["parameters"] = parametersJson;

        pluginInfo = pluginJson.dump();
    }
    else {
        throw std::runtime_error("Failed to create plugin instance: " + error.toStdString());
    }
}

std::string AudioSnoopy::getPluginInfo() const {
    return pluginInfo;
}