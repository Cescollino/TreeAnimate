#pragma once
#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)


struct position {
    float x{};
    float y{};
};

struct IParam {
    int maxLvl{};
    int maxBranches{};
    const int minBranches{ 2 };
    float length{};
};

const int initX = 250;
const int initY = 250;
