/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include "Converter.hpp"


namespace tbaricault::uniconvert
{

    /**
     * @brief Converts a value from a type to another
     * 
     * @tparam T Source type
     * @tparam U Destination type
     * 
     * @param value Value to convert
     * 
     * @return Converted value
     * 
     * @throws std::invalid_argument If value cannot be converted to the requested type
     */
    template<typename T, typename U, typename... Args>
    U convert(const T& value, Args&&... args);

}


#include "utils.tpp"
