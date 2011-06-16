// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_VAR_DECL_HPP
#define TARD_INCLUDED_DETAIL_VAR_DECL_HPP

#include "tard/detail/node.hpp"
#include "tard/detail/type.hpp"
#include "tard/detail/identifier.hpp"
#include <cassert>

// ---------------------------------------------------------------
class var_decl : public node
{
public:

	TARD_DETAIL_FACTORY_IMPL(var_decl);

	virtual void do_analyze_context();

	virtual type_tag get_type() const { return get_child(0).get_type(); }
	std::string type_as_string() const { return get_child(0).as<type>().to_string(); }
	std::string identifier_name() const { return get_child(1).as<identifier>().name(); }

	void generate_internal_name(std::ostream& ostr);
};

#endif
 