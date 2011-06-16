// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#include "tard/compiler.hpp"
#include "tard/exception.hpp"
#include "tard/detail/node.hpp"

#include "antlr/AST.hpp"
#include "antlr/ASTFactory.hpp"
#include "antlr/CommonAST.hpp"
#include "antlr/ANTLRException.hpp"

#include "generated_src/tard_parser.hpp"
#include "generated_src/tard_lexer.hpp"
	
// ---------------------------------------------------------------
void compiler::compile(std::istream& istream, std::ostream& ostr)
{
	try
	{
		antlr::ASTFactory nf("node", &node::factory);

		tard_lexer	lexer(istream);
		tard_parser	parser(lexer);

		parser.initializeASTFactory(nf);
		parser.setASTFactory(&nf);

		parser.program();
		
		node_ptr ast = parser.getAST();
		if (ast)
		{
			ast->analyze_context(0);
			ast->generate_code(ostr);
			
			bool success = true;
			success = success;
		}
		else
		{
			throw tard_exception(tard_exception::PARSE_ERROR);
		}
	}
	catch(antlr::ANTLRException&)
	{
		throw tard_exception(tard_exception::PARSE_ERROR);
	}
}
