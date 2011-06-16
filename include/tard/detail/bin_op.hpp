// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_BIN_OP_HPP
#define TARD_INCLUDED_DETAIL_BIN_OP_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class bin_op : public node
{
public:

	bin_op() : _type(TARD_TYPE_NONE) {}

	TARD_DETAIL_FACTORY_IMPL(bin_op)

	virtual void do_analyze_context();
	virtual type_tag get_type() const { return _type; }

	virtual void generate_code(std::ostream& ostr);

private:
	type_tag _type;
};

#endif
