export class GoodExport {
    int a;
    int b;
};

export class BadExport {
    int a;
    export int b;
};

export void foo() {
    export int value = get_value();
}

export void bar(export std::string name) { 
    // ...
}

template <export typename T>
export class my_container {};
