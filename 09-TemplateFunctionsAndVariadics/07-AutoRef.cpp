#include <iostream>
#include <map>
#include <string>

struct A {
    void Modify() {
    }
};

void autoVarDeduced() {
    const auto& clvalue = A();

    std::cout << "is rvalue(clvalue): "
              << std::is_rvalue_reference<decltype(clvalue)>()
              << std::endl;
    std::cout << "is lvalue(clvalue): "
              << std::is_lvalue_reference<decltype(clvalue)>()
              << std::endl << std::endl;
    // clvalue.Modify();

    // auto& lvalue = A();
    // lvalue.Act();

    auto&& rvalue = A();

    std::cout << "is rvalue(rvalue): "
              << std::is_rvalue_reference<decltype(rvalue)>()
              << std::endl;
    std::cout << "is lvalue(rvalue): "
              << std::is_lvalue_reference<decltype(rvalue)>()
              << std::endl << std::endl;
    rvalue.Modify();

    A a;
    auto&& still_lvalue = a;

    std::cout << "is rvalue(still_lvalue): "
              << std::is_rvalue_reference<decltype(still_lvalue)>()
              << std::endl;
    std::cout << "is lvalue(still_lvalue): "
              << std::is_lvalue_reference<decltype(still_lvalue)>()
              << std::endl << std::endl;
    still_lvalue.Modify();

    const A ca{};
    auto&& still_clvalue = ca;

    std::cout << "is rvalue(still_clvalue): "
              << std::is_rvalue_reference<decltype(still_clvalue)>()
              << std::endl;
    std::cout << "is lvalue(still_clvalue): "
              << std::is_lvalue_reference<decltype(still_clvalue)>()
              << std::endl << std::endl;
    // still_clvalue.Modify();
}

void autoMapKVDeduced() {
    using Map = std::map<std::string, std::string>;
    Map stats = {
        {"a", "b"},
        {"c", "d"}
    };

    std::cout << "value_type::first is const: "
              << std::is_const<Map::value_type::first_type>::value
              << std::endl;
    std::cout << "value_type::second is const "
              << std::is_const<Map::value_type::second_type>::value
              << std::endl << std::endl;

    for (auto&& [key, value] : stats) {
        std::cout << "key is const: " << std::is_const<decltype(key)>::value << std::endl;
        std::cout << "value is const: " << std::is_const<decltype(value)>::value << std::endl;

        // key = "e";
        value = "f";
    }

    for (auto&& [key, value] : stats) {
        std::cout << key << " - > " << value << std::endl;
    }
}

int main() {
    autoVarDeduced();
    autoMapKVDeduced();
    return 0;
}
