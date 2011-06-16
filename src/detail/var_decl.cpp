// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/var_decl.hpp"

// ---------------------------------------------------------------
void var_decl::do_analyze_context()
{
	assert(get_num_children() == 2);
	assert(get_child(0).is<type>());
	assert(get_child(1).is<identifier>());

	get_child(0).analyze_context(this);
	get_child(1).analyze_context(this);	
}

// ---------------------------------------------------------------
void var_decl::generate_internal_name(std::ostream& ostr)
{
	ostr << identifier_name() << '_' << depth();
}
