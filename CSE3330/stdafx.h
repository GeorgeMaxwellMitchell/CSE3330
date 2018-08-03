// Precompiled header

#pragma once

// Disable warnings about dll-interface
#ifdef _MSC_VER
#pragma warning(disable : 4251)
#endif

// Standard C++ headers
#include <iostream>
#include <exception>
#include <string>

// Standard C headers
#include <cstdlib>

// MySQL Connector C++ headers
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>