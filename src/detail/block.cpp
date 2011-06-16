// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/block.hpp"
#include "tard/detail/var_decl.hpp"
#include "tard/exception.hpp"

// ---------------------------------------------------------------
void block::do_analyze_context()
{
	node_ptr ptr = get_first_child();
	while (ptr)
	{
		ptr->analyze_context(this);

		if (ptr->is<var_decl>())
		{
			var_decl& var = ptr->as<var_decl>();

			for (std::size_t i = 0; i < _local_vars.size(); ++i)
			{
				if (_local_vars[i]->identifier_name() == var.identifier_name())
					throw tard_exception(tard_exception::MULTIPLY_DEFINED_SYMBOL);
			}

			_local_vars.push_back(&var);
		}
		else
		{
			_statements.push_back(&*ptr);
		}
		
		ptr = ptr->get_next_sibling();
	}

	if (_statements.empty())
		_type = TARD_TYPE_VOID;
	else
		_type = _statements[_statements.size() - 1]->get_type();
}

// ---------------------------------------------------------------
type_tag block::get_type() const
{
	return _type;
}

// ---------------------------------------------------------------
var_decl* block::find(const identifier& id) const
{
	for (std::size_t i = 0; i < _local_vars.size(); ++i)
	{
		if (_local_vars[i]->identifier_name() == id.name())
			return _local_vars[i];
	}

	return parent() ? parent()->find(id) : 0;
}

// ---------------------------------------------------------------
void block::generate_local_var_decls(bool& comma_in_front, std::ostream& ostr)
{
	for (std::size_t i = 0; i < _local_vars.size(); ++i)
	{
		ostr << (comma_in_front ? "\t\t, " : "\t\t  ") << _local_vars[i]->type_as_string() << ' ';
		_local_vars[i]->generate_internal_name(ostr);
		ostr << '\n';

		comma_in_front = true;
	}
}

// ---------------------------------------------------------------
void block::generate_code(std::ostream& ostr)
{
	const std::size_t idx_of_last_statement = _statements.size() - 1;
	
	for (std::size_t i = 0; i < _statements.size(); ++i)
	{
		_statements[i]->generate_code(ostr);
		
		if (i != idx_of_last_statement)
			if (_statements[i]->get_type() != TARD_TYPE_VOID)
				ostr << "\tpop\n";
	}
}
