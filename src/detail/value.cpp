// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/value.hpp"
#include "tard/detail/identifier.hpp"
#include "tard/detail/block.hpp"

// ---------------------------------------------------------------
void value::do_analyze_context()
{
	assert(get_num_children() == 1);
	get_first_child()->analyze_context(this);
	_type = get_first_child()->get_type();
}

// ---------------------------------------------------------------
type_tag value::get_type() const
{
	return _type;
}

// ---------------------------------------------------------------
void value::generate_code(std::ostream& ostr)
{
	get_first_child()->generate_code(ostr);
}
