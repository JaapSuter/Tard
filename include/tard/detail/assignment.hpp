// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_ASSIGNMENT_HPP
#define TARD_INCLUDED_DETAIL_ASSIGNMENT_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class var_decl;

// ---------------------------------------------------------------
class assignment : public node
{
public:

	assignment() : _var(0) {}

	TARD_DETAIL_FACTORY_IMPL(assignment)

	virtual type_tag get_type() const;
	virtual void do_analyze_context();
	virtual void generate_code(std::ostream&);

private:

	var_decl* _var;
};


#endif
