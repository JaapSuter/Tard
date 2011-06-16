// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_WHILE_STATEMENT_HPP
#define TARD_INCLUDED_DETAIL_WHILE_STATEMENT_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class while_statement : public node
{
public:

	while_statement();

	TARD_DETAIL_FACTORY_IMPL(while_statement)

	virtual void do_analyze_context();
	virtual type_tag get_type() const;	
	virtual void generate_code(std::ostream&);
	virtual var_decl* find(const identifier& id) const;

private:

	int	  _label_id;
	node* _condition;
	node* _body;
};

#endif
