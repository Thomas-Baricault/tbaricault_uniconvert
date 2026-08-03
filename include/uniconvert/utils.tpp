/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include "utils.hpp"


namespace tbaricault::uniconvert
{

    template<typename T, typename U, typename... Args>
    U convert(const T& value, Args&&... args)
    {
        if constexpr (std::is_same_v<T, U>)
            return (value);
        else
            return (Converter<std::decay_t<T>, U>{}(value, std::forward<Args>(args)...));
    }

}
