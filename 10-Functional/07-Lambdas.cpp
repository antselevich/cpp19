#include <iostream>

int main() {
    int a = 2;
    int b = 2;
    using FuncPtr = void (*)();
    FuncPtr fptr = [] () { std::cout << "Hi!" << std::endl; };
    fptr();

    // fptr = [a] () { std::cout << "a: " << a << std::endl; };

    // struct lambda_62b68418a72224d6b2933214024aae64 {
    //     void operator()() const {
    //         std::cout << "a: " << a << std::endl;
    //     }
    //     int a;
    // };
    // fptr = lambda_62b68418a72224d6b2933214024aae64{a};

    auto aCapture = [a] () { std::cout << "a: " << a << std::endl; };
    a = 10;
    aCapture();

    auto valueCapture = [=] () {
        std::cout
            << "lambda a: " << a
            << ", lambda b: " << b
            << std::endl;
    };
    valueCapture();

    auto expCapture = [x = a + 2, y = b * 3] () {
        std::cout
            << "lambda x: " << x
            << ", lambda y: " << y
            << std::endl;
    };
    expCapture();

    auto refCapture = [&a] (int val) { a = val; };
    refCapture(10);
    std::cout << "a: " << a << std::endl;

    auto changeCapture = [b] (int val) mutable {
        std::cout << "lambda b: " << b << std::endl;
        b = val;
    };
    changeCapture(15);
    std::cout << "b: " << b << std::endl;
    changeCapture(20);
    std::cout << "b: " << b << std::endl;

    struct Foo {
        auto GetCalc() {
            return [this] (int x) {
                return x + a;
            };
        }
        int a;
    };
    Foo foo{10};
    auto fooCalc = foo.GetCalc();
    std::cout << "fooCalc(3): " << fooCalc(3) << std::endl;

    auto ret = [&a] () -> float {
        if (a > 0) return 1;
        return 1.5f;
    };
    std::cout << "ret(): " << ret() << std::endl;

    return 0;
}
