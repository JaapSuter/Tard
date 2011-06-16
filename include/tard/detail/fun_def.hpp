// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_FUN_DEF_HPP
#define TARD_INCLUDED_DETAIL_FUN_DEF_HPP

#include <tard/detail/node.hpp>
#include <tard/detail/type.hpp>
class block;
class identifier;

// ---------------------------------------------------------------
class fun_def : public node
{
public:

	fun_def() : _type(), _identifier(), _is_entry_point() {}

	TARD_DETAIL_FACTORY_IMPL(fun_def)

	virtual void do_analyze_context();
	virtual void generate_code(std::ostream&);

	bool is_entry_point() const { return _is_entry_point; }

	virtual type_tag get_type() const { return _type->get_type(); }

private:

	bool		_is_entry_point;
	type*		_type;
	identifier* _identifier;
	block*		_block;
};

#endif
