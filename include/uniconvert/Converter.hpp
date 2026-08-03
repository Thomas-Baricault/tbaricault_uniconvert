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
         * @throws std::invalid_argument If value cannot be converted to the requested type
         */
        U operator()(const T& value) const;

    };

    /**
     * @brief Utils class to convert a string to another type
     * 
     * @tparam T Destination type
     */
    template<typename T>
    struct Converter<std::string, T>
    {

        /**
         * @brief Converts a value from a string to another type
         * 
         * @param value Value to convert
         * @param base Number base used
         * 
         * @return Converted value
         * 
         * @throws std::invalid_argument If value cannot be converted to the requested type
         */
        T operator()(const std::string& value, int base = 10) const;

    };

    /**
     * @brief Utils class to convert a type to string
     * 
     * @tparam T Source type
     */
    template<typename T>
    struct Converter<T, std::string>
    {

        /**
         * @brief Converts a value from a type to string
         * 
         * @param value Value to convert
         * 
         * @return Converted value
         * 
         * @throws std::invalid_argument If value cannot be converted to string
         */
        std::string operator()(const T& value) const;

    };

}


#include "Converter.tpp"
