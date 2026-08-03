# tbaricault/uniconvert

[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++20](https://img.shields.io/badge/C%2B%2B-20-blue)
![CMake](https://img.shields.io/badge/CMake-3.20%2B-blue)
![Header Only](https://img.shields.io/badge/header--only-yes-brightgreen)

## Description

This is a lightweight header-only C++20 library that provides a single generic conversion API for converting values between different types. The conversion system can be extended by specializing the `Converter` template for user-defined types.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
    - [Download and install](#download-and-install)
    - [Uninstall](#uninstall)
    - [CMake](#cmake)
    - [Include](#include)
    - [Environment](#environment)
- [Documentation](#documentation)
- [Examples](#examples)
    - [Simple conversion](#simple-conversion)
    - [Create custom converter](#create-custom-converter)
- [License](#license)

## Features

- Conversion between primitive types
- Basic string conversions
- Customizable converter class for user-defined conversions

## Requirements

- C++20 or later
- CMake 3.20 or later

## Usage

### Download and install

```bash
git clone https://github.com/Thomas-Baricault/tbaricault_uniconvert.git
cd tbaricault_uniconvert
make install
```

### Uninstall

```bash
make uninstall
```

### CMake

Add the library to your project:

```cmake
find_package(tbaricault_uniconvert REQUIRED)

target_link_libraries(
    my_target
    PRIVATE
        tbaricault::uniconvert
)
```

### Include

```cpp
#include <tbaricault/uniconvert.hpp>
```

### Environment

If you have a custom C++ installation, you can edit the `ENV` variable in the `Makefile` to specify your environment path.

Example on Windows with MSYS2/MinGW64:

```makefile
ENV = C:/msys64/mingw64
```

## Documentation

Read the complete documentation at [https://docs.thomas-baricault.fr/uniconvert](https://docs.thomas-baricault.fr/uniconvert).

## Examples

### Simple conversion

```cpp
#include <iostream>
#include <tbaricault/uniconvert.hpp>


int main()
{
    int i = 73;

    auto s = tbaricault::uniconvert::convert<int, std::string>(i);

    std::cout << s << std::endl;

    return (0);
}
```

Output:

```text
73
```

### Create custom converter

```cpp
#include <iostream>
#include <tbaricault/uniconvert.hpp>


class MyClass
{

    public:

        int value;


        MyClass(int i)
            : value(i)
        {
            return;
        }

};


namespace tbaricault::uniconvert
{

    template<>
    struct Converter<std::string, MyClass>
    {

        MyClass operator()(const std::string& value) const
        {
            return (MyClass(convert<std::string, int>(value)));
        }

    };

}


int main()
{

    std::string s = "73";

    auto c = tbaricault::uniconvert::convert<std::string, MyClass>(s);

    std::cout << c.value << std::endl;

    return (0);

}
```

Output:

```text
73
```

## License

This project is licensed under the MIT License.

See [LICENSE](LICENSE) for details.
