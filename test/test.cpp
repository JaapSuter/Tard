// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifdef _MSC_VER
	#pragma warning(disable:4512)
	#pragma warning(disable:4100)
	#pragma warning(disable:4244)
#endif

// ---------------------------------------------------------------
#include "tard/compiler.hpp"
#include "tard/exception.hpp"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cassert>

// ---------------------------------------------------------------
namespace
{
	void test(const char* name);
	void run_il_on_clr(const char* file);
	void test_for_exception(const char* name, tard_exception::tag);
}

// ---------------------------------------------------------------
int main()
{
	try
	{
		test_for_exception("test_parse_error_garbage", tard_exception::PARSE_ERROR);
		test_for_exception("test_parse_error_paren_mismatch", tard_exception::PARSE_ERROR);
		test_for_exception("test_context_error_no_entry_point", tard_exception::NO_ENTRY_POINT_DEFINED);
		test_for_exception("test_context_error_multiple_entry_points", tard_exception::MULTIPLE_ENTRY_POINTS);
		test_for_exception("test_context_error_entry_point_signature", tard_exception::ENTRY_POINT_SIGNATURE_ERROR);
		test_for_exception("test_context_error_define_before_use", tard_exception::UNDECLARED_IDENTIFIER);		
		test_for_exception("test_context_error_multiply_defined_symbol", tard_exception::MULTIPLY_DEFINED_SYMBOL);
		test_for_exception("test_context_error_lhs_of_assignment", tard_exception::LHS_OF_ASSIGNMENT_MUST_BE_SINGLE_IDENTIFIER);
		test_for_exception("test_context_error_assign_bool_to_int", tard_exception::TYPE_MISMATCH);
		test_for_exception("test_context_error_assign_int_to_bool", tard_exception::TYPE_MISMATCH);
		test_for_exception("test_context_error_mix_int_and_bool", tard_exception::TYPE_MISMATCH);
		test_for_exception("test_context_error_mix_bool_and_int", tard_exception::TYPE_MISMATCH);
		test_for_exception("test_context_error_multi_write_in_expression", tard_exception::TYPE_MISMATCH);
		test_for_exception("test_context_error_undefined_identifier", tard_exception::UNDECLARED_IDENTIFIER);
		test_for_exception("test_context_error_if_scope_error", tard_exception::UNDECLARED_IDENTIFIER);
		test_for_exception("test_context_error_if_condition_type_error", tard_exception::IF_CONDITION_MUST_BE_BOOLEAN);
		test_for_exception("test_context_error_ambigious_if_is_void", tard_exception::TYPE_MISMATCH);
		
		test("test_assignment");
		test("test_empty_program");		
		test("test_multiple_fun_defs");
		test("test_var_decl");		
		test("test_expression");
		test("test_write_expression");
		test("test_write_as_expression");
		test("test_if");
		test("test_while");
		test("test_string");
		test("test_large_program");
	}
	catch(std::exception& e)
	{
		std::cerr << "std::exception: " << e.what() << std::endl;
	}
}

// ---------------------------------------------------------------
namespace {

// ---------------------------------------------------------------
void run_il_on_clr(const char* il_file)
{
	std::string location_of_ilasm = "C:/WINDOWS/Microsoft.NET/Framework/v1.1.4322/ilasm.exe";

	std::ifstream ini_with_path_to_ilasm("../../../test/scripts/path_to_ilasm.ini");
	if (ini_with_path_to_ilasm)
		ini_with_path_to_ilasm >> location_of_ilasm;
	
	std::string args = il_file;

	const int assemble_success = std::system((location_of_ilasm + " " + args + " /NOLOGO /QUIET").c_str());

	if (assemble_success == 0)
	{
		args[args.length() - 3] = 0;
		std::system(args.c_str());
	}
}

// ---------------------------------------------------------------
void test(const char* name)
{
	std::cout << "TESTING: " << name << '\n';

	std::string path = std::string("../../../test/scripts/") + name + ".tard";
	std::ifstream script(path.c_str());
	if (!script)
	{
		std::cout << "test failure in '" << name << "': unable to load script\n'";			
	}
	else
	{
		std::string il_file(name);
		il_file += ".il";	
			
		std::ofstream generated_code(il_file.c_str());
		
		compiler c;
		c.compile(script, generated_code);
		generated_code.close();
		run_il_on_clr(il_file.c_str());
	}
}

// ---------------------------------------------------------------
void test_for_exception(const char* name, tard_exception::tag t)
{
	bool expected_failure = false;
	try
	{
		test(name);
	}
	catch(const tard_exception& e)
	{
		expected_failure = e.value() == t;
	}

	assert(expected_failure);
}

}
