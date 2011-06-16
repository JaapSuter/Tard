// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_WRITE_HPP
#define TARD_INCLUDED_DETAIL_WRITE_HPP

#include "tard/detail/node.hpp"

// ---------------------------------------------------------------
class write : public node
{
public:

	TARD_DETAIL_FACTORY_IMPL(write)
	
	virtual void do_analyze_context()
	{
		node_ptr ptr = get_first_child();
		while (ptr)
		{
			ptr->analyze_context(this);
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
			type_tag tt = ptr->get_type();
			ptr->generate_code(ostr);
			
			
			if (get_num_children() == 1)
				ostr << "\tdup\n";
			
			ostr << "\tcall void [mscorlib]System.Console::WriteLine(";
			ostr << type(tt).to_string();
			ostr << ")\n";
			
			ptr = ptr->get_next_sibling();
		}
	}
};

#endif
