#include "EnumHelpers.h"

/// <summary>
/// Will use the mapping to find a match for the value and return the mapped value.
/// </summary>
/// <typeparam name="T">The value type that is being returned.</typeparam>
/// <typeparam name="T2">The current value type.</typeparam>
/// <param name="mapping">The mapping from the current type to the return type.</param>
/// <param name="value">The current value to map to a new type.</param>
/// <returns></returns>
template<class T, class T2>
static inline T getEnumType(std::map<T2, T> mapping, T2 value)
{
    if (!mapping.contains(value))
    {
        throw std::logic_error("Failed to find appropriate mapping.");
    }

    return mapping.find(value)->second;
};