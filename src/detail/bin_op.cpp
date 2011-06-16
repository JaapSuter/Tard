// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/bin_op.hpp"
#include "tard/exception.hpp"
#include <cassert>

// ---------------------------------------------------------------
void bin_op::do_analyze_context()
{
	node_ptr np = get_first_child();
	np->analyze_context(this);

	node_ptr op = np->get_next_sibling();
	if (op)
	{
		struct op_type_rule
		{
			const char* tard_op;
			type_tag lhs;
			type_tag rhs;
			type_tag result;
		};

		op_type_rule op_table[] = 
		{
			{"+",  TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_INT},
			{"-",  TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_INT},
			{"*",  TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_INT},
			{"/",  TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_INT},
			{"<",  TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_BOOL},
			{">",  TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_BOOL},
			{">=", TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_BOOL},
			{"<=", TARD_TYPE_INT, TARD_TYPE_INT, TARD_TYPE_BOOL},
			{"==", TARD_TYPE_COMPARABLE, TARD_TYPE_LHS, TARD_TYPE_BOOL},
			{"!=", TARD_TYPE_COMPARABLE, TARD_TYPE_LHS, TARD_TYPE_BOOL},
			{"&&", TARD_TYPE_BOOL, TARD_TYPE_BOOL, TARD_TYPE_BOOL},
			{"||", TARD_TYPE_BOOL, TARD_TYPE_BOOL, TARD_TYPE_BOOL}		
		};

		const int num_ops = sizeof(op_table) / sizeof(op_table[0]);

		int i = 0;
		for (; i < num_ops; ++i)
		{
			if (op->getText() == op_table[i].tard_op)
			{
				_type = op_table[i].result;

				if (np->get_type() & op_table[i].lhs)
				{
					np = np->get_next_sibling();
					np = np->get_next_sibling();

					while (np)
					{
						type_tag rhs_should_be = op_table[i].rhs;
						if (op_table[i].rhs == TARD_TYPE_LHS)
							rhs_should_be = op_table[i].lhs;

						np->analyze_context(this);

						if (!(np->get_type() & rhs_should_be))
							throw tard_exception(tard_exception::TYPE_MISMATCH);

						np = np->get_next_sibling();
						if (np)
							np = np->get_next_sibling();
						else
							break;
					}
					
					break;					
				}
				else
				{
					throw tard_exception(tard_exception::TYPE_MISMATCH);
				}				
			}
		}

		assert(i != num_ops);
	}
	else
	{
		_type = np->get_type();
	}
}

// ---------------------------------------------------------------
void bin_op::generate_code(std::ostream& ostr)
{
	node_ptr np = get_first_child();
	np->generate_code(ostr);
	np = np->get_next_sibling();
	while (np)
	{
		node_ptr op = np;
		if (!op)
			break;

		np = np->get_next_sibling();
		np->generate_code(ostr);

		np = np->get_next_sibling();
		
		struct op_mapping
		{
			const char* tard_op;
			const char* msil_op;
		};

		op_mapping op_table[] = 
		{
			{"+",  "add"},
			{"-",  "sub"},
			{"*",  "mul"},
			{"/",  "div"},
			{"&&", "and"},
			{"||", "or"},
			{"==", "ceq"},
			{"<",  "clt"},
			{">",  "cgt"},
			{">=", "clt\n\tnot"},
			{"<=", "cgt\n\tnot"},
			{"!=", "ceq\n\tnot"},			
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
