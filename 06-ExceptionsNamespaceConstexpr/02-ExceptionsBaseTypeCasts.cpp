#include <iostream>

int main() {
    std::cout << "I." << std::endl;
    try {
        throw 42;
    } catch (float) {
        std::cout << "got float" << std::endl;
    } catch (long) {
        std::cout << "got long" << std::endl;
    } catch (unsigned int) {
        std::cout << "got unsigned int" << std::endl;
    } catch (int*) {
        std::cout << "got int ptr" << std::endl;
    } catch (int&) {
        std::cout << "got int ref" << std::endl;
    } catch (...) {
        std::cout << "got smth else" << std::endl;
    }

    std::cout << "II." << std::endl;
    try {
        int x = 3;
        throw &x;
    } catch (int) {
        std::cout << "got int val" << std::endl;
    } catch (int&) {
        std::cout << "got int ref" << std::endl;
    } catch (long*) {
        std::cout << "got long ptr" << std::endl;
    } catch (void*) {
        std::cout << "got void ptr" << std::endl;
    } catch (...) {
        std::cout << "got smth else" << std::endl;
    }

    std::cout << "III." << std::endl;
    try {
        // int* x = nullptr;
        // throw x;

        // int* x = NULL;
        // throw x;

        // throw nullptr;

        // throw NULL;
    } catch (long) {
        std::cout << "got long val" << std::endl;
    } catch (int*) {
        std::cout << "got int ptr" << std::endl;
    } catch (void*) {
        std::cout << "got void ptr" << std::endl;
    } catch (std::nullptr_t) {
        std::cout << "got nullptr" << std::endl;
    } catch (...) {
        std::cout << "got smth else" << std::endl;
    }

    return 0;
}
