#pragma once

struct ExtendedGCDResult {
    long long gcd;
    long long x;
    long long y;
};

inline ExtendedGCDResult extendedGCD(long long a, long long b) {
    if (b == 0) {
        return {a, 1, 0};
    }

    ExtendedGCDResult result = extendedGCD(b, a % b);

    long long x = result.y;
    long long y = result.x - (a / b) * result.y;

    return {result.gcd, x, y};
}
