#include <string>
#include <vector>
#include <map>
#include <variant>

namespace {
	typedef std::string Key;
	const std::string INDENT_STEP = "  ";
}

template<class...Ts>
struct Node;

template<class...Ts>
using NodeBase = std::variant<std::map<Key, Node<Ts...>>, Ts...>;

template<class...Ts>
struct Node : NodeBase<Ts...> {
	using NodeBase<Ts...>::NodeBase;
	NodeBase<Ts...> const& base() const { return *this; }
	NodeBase<Ts...>& base() { return *this; }
};

std::string ToXML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent = "");

std::string ToXML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent = "");

std::string ToXML(const std::string& tagName, const std::string& data, const std::string& indent = "");

template<typename... Ts>
std::string ToXML(const std::string& tagName, const std::map<Key, Node<Ts...>>& data, const std::string& indent = "") {
	std::string result;

	result += "<" + tagName + ">\n";

	for (const auto& [key, value] : data)
		result += std::visit([key, &indent](const auto& data) { return ToXML(key, data, indent + INDENT_STEP); }, value.base());

	result += "</" + tagName + ">\n";

	return result;
}

std::string ToJSON(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent = "");

std::string ToJSON(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent = "");

std::string ToJSON(const std::string& tagName, const std::string& data, const std::string& indent = "");

template<typename... Ts>
std::string ToJSON(const std::string& tagName, const std::map<Key, Node<Ts...>>& data, const std::string& indent = "") {
	std::string result;

	result += indent + tagName + ": {\n";

	for (const auto& [key, value] : data)
		result += std::visit([key, &indent](const auto& data) { return ToJSON(key, data, indent + INDENT_STEP); }, value.base());

	result += indent + "}\n";

	return result;
}


std::string ToYAML(const std::string& tagName, const std::map<Key, std::string>& data, const std::string& indent = "");

std::string ToYAML(const std::string& tagName, const std::vector<std::string>& data, const std::string& indent = "");

std::string ToYAML(const std::string& tagName, const std::string& data, const std::string& indent = "");

template<typename... Ts>
std::string ToYAML(const std::string& tagName, const std::map<Key, Node<Ts...>>& data, const std::string& indent = "") {
	std::string result;

	result += indent + tagName + ":\n";

	for (const auto& [key, value] : data)
		result += std::visit([key, &indent](const auto& data) { return ToYAML(key, data, indent + INDENT_STEP); }, value.base());

	return result;
}
