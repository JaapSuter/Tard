// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_VALUE_HPP
#define TARD_INCLUDED_DETAIL_VALUE_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class value : public node
{
public:

	value() : _type(TARD_TYPE_NONE) {}

	TARD_DETAIL_FACTORY_IMPL(value)
	
	virtual void do_analyze_context();
	virtual void generate_code(std::ostream& ostr);
	virtual type_tag get_type() const;

private:

	type_tag _type;
	
};

#endif
