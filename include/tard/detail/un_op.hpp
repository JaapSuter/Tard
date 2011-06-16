// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_UN_OP_HPP
#define TARD_INCLUDED_DETAIL_UN_OP_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class un_op : public node
{
public:

	un_op() : _type(TARD_TYPE_NONE) {}

	TARD_DETAIL_FACTORY_IMPL(un_op)

	virtual void do_analyze_context();

	virtual void generate_code(std::ostream& ostr);

	virtual type_tag get_type() const { return _type; }

private:
	type_tag _type;
};

#endif
