// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/if_statement.hpp"
#include "tard/exception.hpp"
#include <limits>

// ---------------------------------------------------------------
namespace
{
	int if_label_counter = 0;
	int max_number_of_if_statements = std::numeric_limits<int>::max();
}

// ---------------------------------------------------------------
if_statement::if_statement()
 : _label_id(if_label_counter++), _condition(), _then(), _else()
{
	if (if_label_counter == max_number_of_if_statements)
		throw std::exception("maximum number of if-statements generated");
}

// ---------------------------------------------------------------
void if_statement::do_analyze_context()
{
	const int num_children = get_num_children();
	assert(num_children == 2 || num_children == 3);
	
	_condition = &get_child(0);
	_condition->analyze_context(this);
	
	if (_condition->get_type() != TARD_TYPE_BOOL)
		throw tard_exception(tard_exception::IF_CONDITION_MUST_BE_BOOLEAN);

	_then = &get_child(1);
	_then->analyze_context(this);
	
	if (num_children == 3)
	{
		_else = &get_child(2);
		_else->analyze_context(this);
	}
}

// ---------------------------------------------------------------
type_tag if_statement::get_type() const
{
	if (_else && _else->get_type() == _then->get_type())
		return _else->get_type();
	else
		return TARD_TYPE_VOID;
}

// ---------------------------------------------------------------
void if_statement::generate_code(std::ostream& ostr)
{
	const bool ret_is_void = TARD_TYPE_VOID == get_type();

	_condition->generate_code(ostr);
	ostr << "\tbrzero else_" << _label_id << "\n";
	_then->generate_code(ostr);
	if (ret_is_void && _then->get_type() != TARD_TYPE_VOID)
		ostr << "\tpop\n";
	if (_else)
	{
		ostr << "\tbr skip_else_" << _label_id << "\n";
		ostr << "\telse_" << _label_id << ":\n";
		_else->generate_code(ostr);
		if (ret_is_void && _else->get_type() != TARD_TYPE_VOID)
			ostr << "\tpop\n";
		ostr << "\tskip_else_" << _label_id << ":\n";
	}
	else
	{
		ostr << "\telse_" << _label_id << ":\n";
	}
}

// ---------------------------------------------------------------
var_decl* if_statement::find(const identifier& id) const
{
	static bool searching_from_bottom_up = false;

	var_decl* var = 0;
	if (!searching_from_bottom_up)
	{
		searching_from_bottom_up = true;
		var = _condition->find_from_bottom_up(id);
		searching_from_bottom_up = false;
	}
	
	if (var)
		return var;
	else
		return parent()->find(id);
}
