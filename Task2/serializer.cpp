#include "serializer.h"

std::string ToXML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- XML representation of MAP -->";
}

std::string ToXML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- XML representation of VECTOR -->";
}

std::string ToXML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- XML representation of STRING -->";
}

std::string ToJSON(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- JSON representation of MAP -->";
}

std::string ToJSON(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- JSON representation of VECTOR -->";
}

std::string ToJSON(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- JSON representation of STRING -->";
}

std::string ToYAML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent) {
	return indent + "<!-- YAML representation of MAP -->";
}

std::string ToYAML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent) {
	return indent + "<!-- YAML representation of VECTOR -->";
}

std::string ToYAML(const std::string& tagName, const std::string& data, const std::string& indent) {
	return indent + "<!-- YAML representation of STRING -->";
}
