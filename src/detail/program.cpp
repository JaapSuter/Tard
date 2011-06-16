// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/detail/program.hpp"
#include "tard/detail/fun_def.hpp"
#include "tard/exception.hpp"

// ---------------------------------------------------------------
void program::do_analyze_context()
{
	bool entry_point_found = false;
	for (int i = 0; i < get_num_children(); ++i)
	{
		fun_def& fd = get_child(i).as<fun_def>();
		fd.analyze_context(this);
		if (fd.is_entry_point())
		{
			if (entry_point_found)
				throw tard_exception(tard_exception::MULTIPLE_ENTRY_POINTS);

			if (fd.get_type() != TARD_TYPE_VOID)
				throw tard_exception(tard_exception::ENTRY_POINT_SIGNATURE_ERROR);

			entry_point_found = true;
		}
	}

	if (!entry_point_found)
	{
		throw tard_exception(tard_exception::NO_ENTRY_POINT_DEFINED);
	}
}

// ---------------------------------------------------------------
void program::generate_code(std::ostream& ostr)
{
	ostr << ".assembly tard {}\n\n";

	for (int i = 0; i < get_num_children(); ++i)
	{
		get_child(i).generate_code(ostr);
	}
}
