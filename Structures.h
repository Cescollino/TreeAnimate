#pragma once
#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

//because we're too lazy to use two variables
struct position {
    int x{};
    int y{};
};
//the original parameters which are set by the user
struct IParam {
    int maxLvl{};
    int maxBranches{};
    const int minBranches{ 2 };// minimum is always 2
    float length{};
};

//the starting point for the three trunk since pHead already has kids so we still want a nice singilar line as a trunk
const int initX = 250;
const int initY = 250;
