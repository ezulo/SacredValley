#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

#include <map>
#include <string>

class ApplicationConfig {
	public:
		ApplicationConfig();
		~ApplicationConfig();
		int get_prop(const std::string& key);
	private:
		std::map<std::string,int> configMap; 
};

#endif
