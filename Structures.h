#pragma once


struct position {
    int x{};
    int y{};
};

struct IParam {
    int maxLvl{};
    int maxBranches{};
    const int minBranches{ 2 };
    float length{};
};
