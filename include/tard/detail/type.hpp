// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_TYPE_HPP
#define TARD_INCLUDED_DETAIL_TYPE_HPP

#include "tard/detail/node.hpp"
#include "tard/detail/type_tag.hpp"
#include <string>

// ---------------------------------------------------------------
class type : public node
{
public:

	type();
	type(type_tag t) : _value(t) {}

	std::string to_string() const;

	TARD_DETAIL_FACTORY_IMPL(type)

	virtual type_tag get_type() const { return _value; }
		
	virtual void do_analyze_context();
	virtual void generate_code(std::ostream&) {}
    
private:

	type_tag _value; 
};

TARD_IMPL_NODE_PTR_SYNONYM(type)

#endif
