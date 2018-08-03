// Precompiled header

#pragma once

// Standard C++ headers
#include <iostream>
#include <exception>
#include <string>

// Standard C headers
#include <cstdlib>
#include <assert.h>

// Disable warnings about dll-interface
#ifdef _MSC_VER
#pragma message("Note: disabled warning 4251 (dll-interface mismatch)")
#pragma warning(disable : 4251)
#endif

// MySQL Connector C++ headers
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// Nana GUI headers
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>