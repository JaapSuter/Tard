// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/fun_def.hpp"
#include "tard/detail/type.hpp"
#include "tard/detail/identifier.hpp"
#include "tard/detail/block.hpp"
#include "tard/exception.hpp"
#include <cstring>

// ---------------------------------------------------------------
void fun_def::do_analyze_context()
{
	const char* entry_point = "main";

	assert(get_num_children() == 3);
	
	_type	    = &get_child(0).as<type>();
	_identifier = &get_child(1).as<identifier>();
	_block		= &get_child(2).as<block>();
	
	_type->analyze_context(this);
	_identifier->analyze_context(this);
	_block->analyze_context(this);

	_is_entry_point = entry_point == _identifier->name();

	const type_tag fun_ret_type = get_type();
	const type_tag block_type   = _block->get_type();

	if (fun_ret_type != TARD_TYPE_VOID && fun_ret_type != block_type)
		throw tard_exception(tard_exception::TYPE_MISMATCH);
}

// ---------------------------------------------------------------
namespace
{
	struct generate_local_var_decls
	{
		generate_local_var_decls() : _comma_in_front(false) {}

		void operator () (node& n) const
		{
			if (n.is<block>())
			{
				n.as<block>().generate_local_var_decls(_comma_in_front, *_ostr);
			}
		}

		generate_local_var_decls(std::ostream& ostr) : _ostr(&ostr), _comma_in_front(false) {}

		mutable bool  _comma_in_front;
		std::ostream* _ostr;
	};
}

// ---------------------------------------------------------------
void fun_def::generate_code(std::ostream& ostr)
{
	ostr << ".method static public " << _type->to_string() << " " << _identifier->name() << "() il managed\n";
	ostr << "{\n";

	if (_is_entry_point)
		ostr << "\t.entrypoint\n";

	const int stack_size = 128;
	ostr << "\t.maxstack " << stack_size << '\n';

	ostr << "\t.locals init\n";
	ostr << "\t(\n";
		_block->visit(generate_local_var_decls(ostr));
	ostr << "\t)\n";
	
	_block->generate_code(ostr);

	if (get_type() == TARD_TYPE_VOID && _block->get_type() != TARD_TYPE_VOID)
		ostr<< "\tpop\n";

	ostr << "\tret\n";
	ostr << "}\n\n";
}
