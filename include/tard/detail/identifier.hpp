// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_IDENTIFIER_HPP
#define TARD_INCLUDED_DETAIL_IDENTIFIER_HPP

#include "tard/detail/node.hpp"
#include <string>

// ---------------------------------------------------------------
class identifier : public node
{
public:

	TARD_DETAIL_FACTORY_IMPL(identifier)
	
	virtual void do_analyze_context();
	virtual void generate_code(std::ostream& ostr);

	std::string name() const { return _name; }

	type_tag get_type() const;

private:

	std::string _name;
};

// ---------------------------------------------------------------
TARD_IMPL_NODE_PTR_SYNONYM(identifier)

#endif
