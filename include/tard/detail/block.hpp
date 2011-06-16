// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_BLOCK_HPP
#define TARD_INCLUDED_DETAIL_BLOCK_HPP

#include "tard/detail/node.hpp"
#include "tard/detail/type_tag.hpp"
#include <vector>

// ---------------------------------------------------------------
class var_decl;
class statement;
class identifier;

// ---------------------------------------------------------------
class block : public node
{
public:

	block() : _type(TARD_TYPE_NONE) {}

	TARD_DETAIL_FACTORY_IMPL(block)
	
	virtual void do_analyze_context();
	virtual void generate_code(std::ostream&);

	var_decl* find(const identifier&) const;

	type_tag get_type() const;

	void generate_local_var_decls(bool& comma_in_front, std::ostream& ostr);

private:

	std::vector<var_decl*>	_local_vars;
	std::vector<node*>		_statements;
	type_tag				_type;
};

#endif
