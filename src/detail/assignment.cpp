// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/assignment.hpp"
#include "tard/detail/identifier.hpp"
#include "tard/detail/var_decl.hpp"
#include "tard/detail/block.hpp"
#include "tard/exception.hpp"

// ---------------------------------------------------------------
void assignment::do_analyze_context()
{
	node* p = parent();
	
	get_child(0).analyze_context(this);

	_var = find(get_child(0).as<identifier>());
	if (!_var)
		throw tard_exception(tard_exception::UNDECLARED_IDENTIFIER);

	if (get_num_children() == 2)
	{
		while (p && !p->is<block>())
		{
			if (!p->is<assignment>() && p->get_num_children() > 1)
				throw tard_exception(tard_exception::LHS_OF_ASSIGNMENT_MUST_BE_SINGLE_IDENTIFIER);
			p = p->parent();
		}

		get_child(1).analyze_context(this);	

		type_tag lhs_type = _var->get_type();
		type_tag rhs_type = get_child(1).get_type();
		
		if (lhs_type != rhs_type)
			throw tard_exception(tard_exception::TYPE_MISMATCH);
	}
}

// ---------------------------------------------------------------
type_tag assignment::get_type() const
{
	return _var->get_type();
}

// ---------------------------------------------------------------
void assignment::generate_code(std::ostream& ostr)
{
	if (get_num_children() == 2)
	{
		get_child(1).generate_code(ostr);
	
		ostr << "\tstloc " ;
		_var->generate_internal_name(ostr);
		ostr << '\n';
	}

	get_child(0).generate_code(ostr);
}
