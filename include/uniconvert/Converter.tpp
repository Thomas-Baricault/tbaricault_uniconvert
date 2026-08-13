/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <stdexcept>

#include "Converter.hpp"


namespace tbaricault::uniconvert
{

    template<typename T, typename U>
    U Converter<T, U>::operator()(const T& value) const
    {
        if constexpr (std::is_same_v<T, U>)
            return (value);
        if constexpr (std::is_constructible_v<U, T>)
            return (U{value});
        if constexpr (requires { static_cast<U>(value); })
            return (static_cast<U>(value));
        if constexpr (requires { reinterpret_cast<U>(value); })
            return (reinterpret_cast<U>(value));
        throw std::invalid_argument("unsupported conversion");
    }

    template<typename T>
    requires (
        std::same_as<T, bool> ||
        std::same_as<T, float> ||
        std::same_as<T, double> ||
        std::same_as<T, long double> ||
        std::same_as<T, char>
    )
    T Converter<std::string, T>::operator()(const std::string& value) const
    {
        T result{};
        std::size_t length = SIZE_MAX;
        if constexpr (std::is_same_v<T, bool>)
        {
            if (value == "0" || value == "false")
                return (false);
            if (value == "1" || value == "true")
                return (true);
        }
        else if constexpr (std::is_same_v<T, float>)
            result = std::stof(value, &length);
        else if constexpr (std::is_same_v<T, double>)
            result = std::stod(value, &length);
        else if constexpr (std::is_same_v<T, long double>)
            result = std::stold(value, &length);
        else if constexpr (std::is_same_v<T, char>)
        {
            length = 1;
            if (!value.empty())
                result = value.at(0);
        }
        if (length != value.length())
            throw std::invalid_argument("convertion failed");
        return (result);
    }

    template<typename T>
    requires (
        std::same_as<T, int> ||
        std::same_as<T, long> ||
        std::same_as<T, long long> ||
        std::same_as<T, unsigned long> ||
        std::same_as<T, unsigned long long>
    )
    T Converter<std::string, T>::operator()(const std::string& value, int base) const
    {
        T result{};
        std::size_t length = SIZE_MAX;
        if constexpr (std::is_same_v<T, int>)
            result = std::stoi(value, &length, base);
        else if constexpr (std::is_same_v<T, long>)
            result = std::stol(value, &length, base);
        else if constexpr (std::is_same_v<T, long long>)
            result = std::stoll(value, &length, base);
        else if constexpr (std::is_same_v<T, unsigned long>)
            result = std::stoul(value, &length, base);
        else if constexpr (std::is_same_v<T, unsigned long long>)
            result = std::stoull(value, &length, base);
        if (length != value.length())
            throw std::invalid_argument("convertion failed");
        return (result);
    }

    template<typename T>
    requires (
        std::same_as<T, bool> ||
        std::same_as<T, int> ||
        std::same_as<T, long> ||
        std::same_as<T, long long> ||
        std::same_as<T, unsigned long> ||
        std::same_as<T, unsigned long long> ||
        std::same_as<T, float> ||
        std::same_as<T, double> ||
        std::same_as<T, long double> ||
        std::same_as<T, char>
    )
    std::string Converter<T, std::string>::operator()(const T& value) const
    {
        if constexpr (std::is_same_v<T, bool>)
            return (value ? "true" : "false");
        else if constexpr (std::is_same_v<T, char>)
            return (std::string(1, value));
        else
            return (std::to_string(value));
    }

}
