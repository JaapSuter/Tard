// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_IF_STATEMENT_HPP
#define TARD_INCLUDED_DETAIL_IF_STATEMENT_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class if_statement : public node
{
public:

	if_statement();

	TARD_DETAIL_FACTORY_IMPL(if_statement)

	virtual void do_analyze_context();
	virtual type_tag get_type() const;	
	virtual void generate_code(std::ostream&);
	virtual var_decl* find(const identifier& id) const;

private:

	int	  _label_id;
	node* _condition;
	node* _then;
	node* _else;
};

#endif
