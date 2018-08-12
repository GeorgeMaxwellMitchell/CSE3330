// Precompiled header

#pragma once

// Disable warnings about dll-interface
#ifdef _MSC_VER
#pragma message("Note: disabled warning 4251 (dll-interface mismatch)")
#pragma warning(disable : 4251)
#endif

// Must build program as x64-Release
#if _M_IX86 || _DEBUG
#error Building as x64 Release is required
#endif


// Standard C++ headers
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <vector>
#include <algorithm>

// Standard C headers
#include <cstdlib>
#include <assert.h>

// MySQL Connector C++ headers
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// Nana GUI headers
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/wvl.hpp>