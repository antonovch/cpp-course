#include "serializer.h"

std::string ToXML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- XML representation of MAP -->\n";
}

std::string ToXML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- XML representation of VECTOR -->\n";
}

std::string ToXML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- XML representation of STRING -->\n";
}

std::string ToJSON(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- JSON representation of MAP -->\n";
}

std::string ToJSON(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- JSON representation of VECTOR -->\n";
}

std::string ToJSON(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- JSON representation of STRING -->\n";
}

std::string ToYAML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- YAML representation of MAP -->\n";
}

std::string ToYAML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- YAML representation of VECTOR -->\n";
}

std::string ToYAML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- YAML representation of STRING -->\n";
}
