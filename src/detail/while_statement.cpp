// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/while_statement.hpp"
#include "tard/exception.hpp"
#include <limits>

// ---------------------------------------------------------------
namespace
{
	int while_label_counter = 0;
	int max_number_of_while_statements = std::numeric_limits<int>::max();
}

// ---------------------------------------------------------------
while_statement::while_statement()
 : _label_id(while_label_counter++), _condition(), _body()
{
	if (while_label_counter == max_number_of_while_statements)
		throw std::exception("maximum number of while-statements generated");
}

// ---------------------------------------------------------------
void while_statement::do_analyze_context()
{
	assert(get_num_children() == 2);
	
	_condition = &get_child(0);
	_condition->analyze_context(this);
	
	if (_condition->get_type() != TARD_TYPE_BOOL)
		throw tard_exception(tard_exception::WHILE_CONDITION_MUST_BE_BOOLEAN);

	_body = &get_child(1);
	_body->analyze_context(this);
}

// ---------------------------------------------------------------
type_tag while_statement::get_type() const
{
	return TARD_TYPE_VOID;
}

// ---------------------------------------------------------------
void while_statement::generate_code(std::ostream& ostr)
{
	ostr << "\twhile_begin_" << _label_id << ":\n";
	_condition->generate_code(ostr);
	ostr << "\tbrzero while_end_" << _label_id << "\n";
	
	_body->generate_code(ostr);

	if (_body->get_type() != TARD_TYPE_VOID)
		ostr << "\tpop\n";

	ostr << "\tbr while_begin_" << _label_id << "\n";
	
	ostr << "\twhile_end_" << _label_id << ":\n";
}

// ---------------------------------------------------------------
var_decl* while_statement::find(const identifier& id) const
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
