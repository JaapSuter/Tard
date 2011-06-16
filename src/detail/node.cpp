// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
node::node()
: _parent() 
{}

// ---------------------------------------------------------------
int node::depth() const
{ 
	return parent() ? (1 + parent()->depth()) : 0; 
}

// ---------------------------------------------------------------
void node::analyze_context(node* parent)
{
	_parent = parent;
	do_analyze_context();
}

// ---------------------------------------------------------------
var_decl* node::find(const identifier& id) const
{
	return parent() ? parent()->find(id) : 0;
}

// ---------------------------------------------------------------
node& node::get_child(int index) const
{ 
	node_ptr np = get_first_child();
	while (np && index > 0)
	{
		--index;
		np = np->get_next_sibling();
	}

	assert(np);

	return *np;
}

// ---------------------------------------------------------------
var_decl* node::find_from_bottom_up(const identifier& id) const
{
	node_ptr np = get_first_child();
	
	if (!np)
		return find(id);
	
	while (np)
	{
		var_decl* v = np->find_from_bottom_up(id);
		if (v)
			return v;

		np = np->get_next_sibling();
	}

	return 0;
}
