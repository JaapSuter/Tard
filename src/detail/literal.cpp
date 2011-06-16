// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/literal.hpp"
#include <sstream>

// ---------------------------------------------------------------
void literal::do_analyze_context()
{
	std::string val = getText();
    if (val == "true")
		_type = TARD_TYPE_BOOL;
	else
	if (val == "false")
		_type = TARD_TYPE_BOOL;
	else
	if (val.size() == 3 && val[0] == '\'' && val[2] == '\'')
		_type = TARD_TYPE_CHAR;
	else
	if (val[0] == '"' && val[val.size() - 1] == '"')
		_type = TARD_TYPE_STRING;
	else
		_type = TARD_TYPE_INT;

}

// ---------------------------------------------------------------
type_tag literal::get_type() const
{
	return _type;
}

// ---------------------------------------------------------------
void literal::generate_code(std::ostream& ostr)
{
	std::string val = getText();
    if (val == "true")
		val = "1";
	if (val == "false")
		val = "0";
	
	if (_type == TARD_TYPE_CHAR)
	{
		// convert char representation to integer representation
		std::stringstream s;
		s << static_cast<int>(val[1]);
		val = s.str();
	}

	if (_type == TARD_TYPE_STRING)
	{
		ostr << "\tldstr " << val << "\n";
	}
	else
	{
		ostr << "\tldc.i4 " << val << '\n';
	}
}
