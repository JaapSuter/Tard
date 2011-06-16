// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_COMPILER_HPP
#define TARD_INCLUDED_COMPILER_HPP

#include <ostream>
#include <istream>


// ---------------------------------------------------------------
// Core Tard compiler interface. Takes an input stream pointing to
// a .tard script and generates .NET MSIL code to the given output
// stream. This code can then be assembled using ilasm.exe.
// ---------------------------------------------------------------
struct compiler
{
    void compile(std::istream& istream, std::ostream& ostream);
};

#endif
