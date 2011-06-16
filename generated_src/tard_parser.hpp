#ifndef INC_tard_parser_hpp_
#define INC_tard_parser_hpp_

#line 7 "../../grammar/tard.grammar"

	#include "tard/detail/nodes.hpp"

	#ifdef _MSC_VER
		#pragma warning(disable:4512)
		#pragma warning(disable:4100)
		#pragma warning(disable:4511)
		#pragma warning(disable:4244)
		#pragma warning(disable:4127)
	#endif

#line 17 "tard_parser.hpp"
#include <antlr/config.hpp>
/* $ANTLR 2.7.5 (20050128): "../../grammar/tard.grammar" -> "tard_parser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "tard_lexerTokenTypes.hpp"
#include <antlr/LLkParser.hpp>

class CUSTOM_API tard_parser : public ANTLR_USE_NAMESPACE(antlr)LLkParser, public tard_lexerTokenTypes
{
#line 1 "../../grammar/tard.grammar"
#line 28 "tard_parser.hpp"
public:
	void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
protected:
	tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k);
public:
	tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf);
protected:
	tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k);
public:
	tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer);
	tard_parser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state);
	int getNumTokens() const
	{
		return tard_parser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return tard_parser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return tard_parser::tokenNames;
	}
	public: void program();
	public: void fun_def();
	public: void type();
	public: void identifier();
	public: void block();
	public: void statement();
	public: void var_decl();
	public: void expression();
	public: void and_expr();
	public: void compare_expr();
	public: void add_expr();
	public: void mul_expr();
	public: void sign_expr();
	public: void not_expr();
	public: void value();
	public: void literal();
	public: void assignment();
	public: void read();
	public: void write();
	public: void if_statement();
	public: void while_statement();
public:
	ANTLR_USE_NAMESPACE(antlr)RefAST getAST()
	{
		return ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST);
	}
	
protected:
	node_ptr returnAST;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 57;
#else
	enum {
		NUM_TOKENS = 57
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
	static const unsigned long _tokenSet_2_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_2;
};

#endif /*INC_tard_parser_hpp_*/
