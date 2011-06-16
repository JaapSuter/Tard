// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/identifier.hpp"
#include "tard/detail/block.hpp"
#include "tard/detail/var_decl.hpp"
#include "tard/exception.hpp"

// ---------------------------------------------------------------
void identifier::do_analyze_context()
{
	_name = getText();
}

// ---------------------------------------------------------------
void identifier::generate_code(std::ostream& ostr)
{ 
	var_decl* var = find(*this);
	assert(var);

	ostr << "\tldloc ";
	var->generate_internal_name(ostr);
	ostr << '\n';
}

// ---------------------------------------------------------------
type_tag identifier::get_type() const
{
    var_decl* var = find(*this);
	if (!var)
		throw tard_exception(tard_exception::UNDECLARED_IDENTIFIER);

	return var->get_type();
}
