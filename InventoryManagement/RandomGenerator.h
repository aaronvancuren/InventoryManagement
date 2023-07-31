#pragma once
#include<stdio.h>
#include <random>

static std::random_device dev;
static std::mt19937 mt(dev());

/// <summary>
/// Returns a random number.
/// </summary>
/// <param name="upperBound">Lower bound of possible random number.</param>
/// <param name="lowerBound">Upper bound of possible random number.</param>
/// <returns></returns>
int static GetRandomNumber(int upperBound = INT_MAX, int lowerBound = INT_MIN)
{
    std::uniform_int_distribution<int> dist(lowerBound, upperBound);
    return dist(mt);
}

char static GetRandomAlphaNumeric()
{
    int randomValue = 0;
    do
    {
        randomValue = GetRandomNumber(48, 122);
    } while ((randomValue >= 58 && randomValue <= 64) || (randomValue >= 91 && randomValue <= 96));

    return (char)randomValue;
}
