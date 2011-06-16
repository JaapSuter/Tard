// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_LITERAL_HPP
#define TARD_INCLUDED_DETAIL_LITERAL_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class literal : public node
{
public:

	literal() : _type(TARD_TYPE_NONE) {}

	TARD_DETAIL_FACTORY_IMPL(literal)
	
	virtual void do_analyze_context();
	virtual void generate_code(std::ostream& ostr);
	virtual type_tag get_type() const;

private:

	type_tag _type;	
};

TARD_IMPL_NODE_PTR_SYNONYM(literal)

#endif
