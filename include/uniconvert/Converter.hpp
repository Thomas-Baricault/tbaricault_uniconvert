/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>


namespace tbaricault::uniconvert
{

    /**
     * @brief Utils class to convert a type to another
     * 
     * @tparam T Source type
     * @tparam U Destination type
     */
    template<typename T, typename U>
    struct Converter
    {

        /**
         * @brief Converts a value from a type to another
         * 
         * @param value Value to convert
         * 
         * @return Converted value
         * 
         * @throws std::invalid_argument If convertion failed
         */
        U operator()(const T& value) const;

    };

    /**
     * @brief Utils class to convert a string to another basic type
     * 
     * @tparam T Destination type
     */
    template<typename T>
    requires (
        std::same_as<T, bool> ||
        std::same_as<T, float> ||
        std::same_as<T, double> ||
        std::same_as<T, long double> ||
        std::same_as<T, char>
    )
    struct Converter<std::string, T>
    {

        /**
         * @brief Converts a value from a string to another basic type
         * 
         * @param value Value to convert
         * @param base Number base used
         * 
         * @return Converted value
         * 
         * @throws std::invalid_argument If convertion failed
         */
        T operator()(const std::string& value) const;

    };

    /**
     * @brief Utils class to convert a string to another basic numeric type
     * 
     * @tparam T Destination type
     */
    template<typename T>
    requires (
        std::same_as<T, int> ||
        std::same_as<T, long> ||
        std::same_as<T, long long> ||
        std::same_as<T, unsigned long> ||
        std::same_as<T, unsigned long long>
    )
    struct Converter<std::string, T>
    {

        /**
         * @brief Converts a value from a string to another basic numeric type
         * 
         * @param value Value to convert
         * @param base Number base used
         * 
         * @return Converted value
         * 
         * @throws std::invalid_argument If convertion failed
         */
        T operator()(const std::string& value, int base = 10) const;

    };

    /**
     * @brief Utils class to convert a basic type to string
     * 
     * @tparam T Source type
     */
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
    struct Converter<T, std::string>
    {

        /**
         * @brief Converts a value from a basic type to string
         * 
         * @param value Value to convert
         * 
         * @return Converted value
         * 
         * @throws std::invalid_argument If convertion failed
         */
        std::string operator()(const T& value) const;

    };

}


#include "Converter.tpp"
