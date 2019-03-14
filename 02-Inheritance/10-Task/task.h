#include <iostream>

struct GrandMa {
    short gm = 44;
    char ololo[2] = {'a', 'b'};
    int gmgm = 503;
};

struct GrandDad {
    short smth = 12;
    int gd = 847837;
    char azaza = '!';
    void PrintAllFields() const;
};

struct Mom : public GrandMa, public GrandDad {
    char mom1 = 'a';
    char mom2 = 'b';
    long momomom = 1234567L;
};

struct Dad {
    char pha = 'q';
};

struct Son : public Mom, public Dad {
    int diary = 13;
    const char* name = "Vasya";
};
