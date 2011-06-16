// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_EXCEPTION_HPP
#define TARD_INCLUDED_DETAIL_EXCEPTION_HPP

#include <exception>

// ---------------------------------------------------------------
// Tard exception class for parse and context sensitive errors
// encountered during the compilation fase.
// ---------------------------------------------------------------
class tard_exception : public std::exception
{
public:

	enum tag
	{
		PARSE_ERROR,
		NO_ENTRY_POINT_DEFINED,
		MULTIPLE_ENTRY_POINTS,
		ENTRY_POINT_SIGNATURE_ERROR,
		TYPE_MISMATCH,
		UNDECLARED_IDENTIFIER,
		IF_CONDITION_MUST_BE_BOOLEAN,
		WHILE_CONDITION_MUST_BE_BOOLEAN,
		MULTIPLY_DEFINED_SYMBOL,
		LHS_OF_ASSIGNMENT_MUST_BE_SINGLE_IDENTIFIER
	};

	const char* what() const { return "tard_exception"; }

	tard_exception(tag v) : _value(v) {}

	tag value() const { return _value; }
    
private:

	tag _value; 
};

#endif
