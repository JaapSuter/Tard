// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/type.hpp"
#include <cstring>
#include <cassert>

// ---------------------------------------------------------------
type::type() : _value(TARD_TYPE_NONE)
{}

// ---------------------------------------------------------------
void type::do_analyze_context()
{
	if (getText() == "void")    _value = TARD_TYPE_VOID;   else 
	if (getText() == "bool")    _value = TARD_TYPE_BOOL;   else 
	if (getText() == "char")    _value = TARD_TYPE_CHAR;   else
	if (getText() == "int")     _value = TARD_TYPE_INT;    else
	if (getText() == "string")  _value = TARD_TYPE_STRING; else
	{ 
		assert(false); 
	}
}

// ---------------------------------------------------------------
std::string type::to_string() const
{ 
	if (_value == TARD_TYPE_BOOL)
		return "bool";
	else
	if (_value == TARD_TYPE_VOID)
		return "void";
	else
	if (_value == TARD_TYPE_CHAR)
		return "char";
	if (_value == TARD_TYPE_STRING)
		return "string";
	else
		return "int32";
}
