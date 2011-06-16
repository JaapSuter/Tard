// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_PROGRAM_HPP
#define TARD_INCLUDED_DETAIL_PROGRAM_HPP

// ---------------------------------------------------------------
#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class program : public node
{
public:

	TARD_DETAIL_FACTORY_IMPL(program)

	void do_analyze_context();
	virtual void generate_code(std::ostream& ostr);
};

#endif
