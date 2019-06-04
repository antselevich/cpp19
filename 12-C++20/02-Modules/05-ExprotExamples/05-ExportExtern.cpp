export module ModuleName;

export extern "C++" {
    #include <vector> // exported as std::vector 
    #export *
}