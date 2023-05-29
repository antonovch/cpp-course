#include <map>
#include <string>
#include <variant>
#include <vector>

namespace {
    typedef std::string Key;
    const std::string INDENT_STEP = "  ";
} // namespace

template <class... Ts> 
struct Node;

template <class... Ts>
using NodeBase = std::variant<std::map<Key, Node<Ts...>>, Ts...>;

template <class... Ts> 
struct Node : NodeBase<Ts...> {
    using NodeBase<Ts...>::NodeBase;
    NodeBase<Ts...> const& base() const { return *this; }
    NodeBase<Ts...>& base() { return *this; }
};

std::string ToXML(const std::string& tagName,
                  const std::map<Key, std::string>& data,
                  const std::string& indent = "");

std::string ToXML(const std::string& tagName,
                  const std::vector<std::string>& data,
                  const std::string& indent = "");

std::string ToXML(const std::string& tagName, const std::string& data,
                  const std::string& indent = "");

template <typename... Ts>
std::string ToXML(const std::string& tagName,
                  const std::map<Key, Node<Ts...>>& data,
                  const std::string& indent = "") {
    std::string result;

    result += "<" + tagName + ">";

    for (const auto& pair : data) {
        result += "\n" + std::visit(
            [&pair, &indent](const auto& data) {
                return ToXML(pair.first, data, indent + INDENT_STEP);
            }, pair.second.base());
    }

    result += "\n</" + tagName + ">\n";

    return result;
}

std::string ToJSON(const std::string& tagName,
                   const std::map<Key, std::string>& data,
                   const std::string& indent = "");

std::string ToJSON(const std::string& tagName,
                   const std::vector<std::string>& data,
                   const std::string& indent = "");

std::string ToJSON(const std::string& tagName,
                   const std::string& data,
                   const std::string& indent = "");

template <typename... Ts>
std::string ToJSON(const std::string& tagName,
                   const std::map<Key, Node<Ts...>>& data,
                   const std::string& indent = "") {
    std::string result;

    result += indent + '"' + tagName + '"' + ": {";
    
    for (auto it = data.cbegin(); it != data.cend(); ++it) {
        result += "\n" + std::visit(
            [&it, &indent](const auto &data) {
                return ToJSON(it->first, data, indent + INDENT_STEP);
            }, it->second.base());

        if (std::distance(it, data.cend()) != 1) {
            result += ",";
        }
    }

    result += "\n" + indent + "}\n";

    return result;
}

std::string ToYAML(const std::string& tagName,
                   const std::map<Key, std::string>& data,
                   const std::string& indent = "");

std::string ToYAML(const std::string& tagName,
                   const std::vector<std::string>& data,
                   const std::string& indent = "");

std::string ToYAML(const std::string& tagName, const std::string& data,
                   const std::string& indent = "");

template <typename... Ts>
std::string ToYAML(const std::string& tagName,
                   const std::map<Key, Node<Ts...>>& data,
                   const std::string& indent = "") {
    std::string result;

    result += indent + tagName + ":";

    for (const auto& pair: data) {
        result += "\n" + std::visit(
            [&pair, &indent](const auto& data) {
                return ToYAML(pair.first, data, indent + INDENT_STEP);
            }, pair.second.base());
    }

    result += "\n";

    return result;
}
