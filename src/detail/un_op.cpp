// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/un_op.hpp"
#include "tard/exception.hpp"
#include <cassert>

// ---------------------------------------------------------------
void un_op::do_analyze_context()
{
	node_ptr op = get_first_child();
	node_ptr np = op->get_next_sibling();
	if (!np)
	{
		op->analyze_context(this);
		_type = op->get_type();
	}
	else
	{
		np->analyze_context(this);

		struct op_mapping
		{
			const char* tard_op;
			type_tag tt;
		};

		op_mapping op_table[] = 
		{
			{"+", TARD_TYPE_INT},
			{"-", TARD_TYPE_INT},
			{"!", TARD_TYPE_BOOL}
		};

		const int num_ops = sizeof(op_table) / sizeof(op_table[0]);
		
		int i = 0;
		for (; i < num_ops; ++i)
		{
			if (op->getText() == op_table[i].tard_op)
			{
				if (np->get_type() != op_table[i].tt)
					throw tard_exception(tard_exception::TYPE_MISMATCH);
				_type = op_table[i].tt;
				break;
			}
		}

		assert(i != num_ops);
	}
}

// ---------------------------------------------------------------
void un_op::generate_code(std::ostream& ostr)
{
	node_ptr op = get_first_child();
	node_ptr np = op->get_next_sibling();
	if (!np)
	{
		op->generate_code(ostr);
		
	}
	else
	{
		np->generate_code(ostr);

		struct op_mapping
		{
			const char* tard_op;
			const char* msil_op;
		};

		op_mapping op_table[] = 
		{
			{"+", "nop"},
			{"-", "neg"},
			{"!", "not"}
		};

		const int num_ops = sizeof(op_table) / sizeof(op_table[0]);

		int i = 0;
		for (; i < num_ops; ++i)
		{
			if (op->getText() == op_table[i].tard_op)
			{
				ostr << '\t' << op_table[i].msil_op << '\n';
				break;
			}
		}

		assert(i != num_ops);
	}
}
