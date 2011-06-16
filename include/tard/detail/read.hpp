// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_READ_HPP
#define TARD_INCLUDED_DETAIL_READ_HPP

#include "tard/detail/node.hpp"
#include "tard/detail/identifier.hpp"
#include "tard/exception.hpp"

// ---------------------------------------------------------------
class read : public node
{
public:

	TARD_DETAIL_FACTORY_IMPL(read)
	
	virtual void do_analyze_context()
	{
		node_ptr ptr = get_first_child();
		while (ptr)
		{
			ptr->analyze_context(this);
			
			if (0 == find(ptr->as<identifier>()))
				throw tard_exception(tard_exception::UNDECLARED_IDENTIFIER);

			ptr = ptr->get_next_sibling();
		}
	}

	virtual type_tag get_type() const
	{
		return get_num_children() == 1 ? get_first_child()->get_type() : TARD_TYPE_VOID;
	}

	virtual void generate_code(std::ostream& ostr)
	{
		node_ptr ptr = get_first_child();
		while (ptr)
		{
			var_decl* var = find(ptr->as<identifier>());
			assert(var);			

			ostr << "\tcall string [mscorlib]System.Console::ReadLine()\n";			
			
			if (var->get_type() != TARD_TYPE_STRING)
				ostr << "\tcall int32 [mscorlib]System.Int32::Parse(string)\n";
			
			if (get_num_children() == 1)
				ostr << "\tdup\n";

			ostr << "\tstloc ";
			var->generate_internal_name(ostr);
			ostr << '\n';
			ptr = ptr->get_next_sibling();
		}
	}
};

#endif
