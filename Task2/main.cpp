#include "serializer.h"
#include <iostream>

int main() {

	const auto dataName = "data";
	using MyNode = Node<std::map<Key, std::string>, std::vector<std::string>, std::string>;
	auto data = std::map<Key, MyNode>{
			{"key_to_map",    std::map<Key, std::string>{{"key1","value1"}, {"key2","value2"}}},
			{"key_to_vector", std::vector<std::string>{"string from vector 1", "string from vector 2"}},
			{"key_to_string", "this is a string"},
	};

	std::cout << "Here's how this structure looks in XML:\n";
	std::cout << ToXML(dataName, data);

	std::cout << "\nThis is its representation in JSON:\n";
	std::cout << "{\n" << ToJSON(dataName, data, INDENT_STEP) << "}\n";

	std::cout << "\nAnd finally, YAML:\n";
	std::cout << ToYAML(dataName, data);

	return 0;
}