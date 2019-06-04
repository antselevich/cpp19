export class Thing;

export class Thing;  // Redundant

class Thing;  // Implicit `export` keyword

class Thing { // Implicit `export` keyword
    int a;
    int b;
};

class SomethingElse; // Not exported.

export class SomethingElse;