#include "ApplicationConfig.h"

ApplicationConfig::ApplicationConfig() {
	// Hard coded for now...
	configMap["xres"] = 800;
	configMap["yres"] = 600;
	configMap["framerateLimit"] = 60;
	configMap["difficulty"] = 1;
}

ApplicationConfig::~ApplicationConfig() {
}

int ApplicationConfig::get_prop(const std::string& key) {
	if (configMap.find(key) != configMap.end()) {
		return configMap[key];
	}	
	else {
		throw "Attempt to access config key " + key + " failed. Key not found.";
	}
}
