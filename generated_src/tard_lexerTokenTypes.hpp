#ifndef INC_tard_lexerTokenTypes_hpp_
#define INC_tard_lexerTokenTypes_hpp_

/* $ANTLR 2.7.5 (20050128): "../../grammar/tard.grammar" -> "tard_lexerTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API tard_lexerTokenTypes {
#endif
	enum {
		EOF_ = 1,
		WHITESPACE = 4,
		PLUS = 5,
		DASH = 6,
		STAR = 7,
		SLASH = 8,
		ASSIGN = 9,
		SEMI = 10,
		COMMA = 11,
		L_CURL = 12,
		R_CURL = 13,
		L_PAREN = 14,
		R_PAREN = 15,
		NOT = 16,
		LESS = 17,
		GREATER = 18,
		GREATER_EQ = 19,
		LESS_EQ = 20,
		NOT_EQUALS = 21,
		EQUALS = 22,
		AND = 23,
		OR = 24,
		TICK = 25,
		QUOTE = 26,
		INTEGER = 27,
		IDENTIFIER = 28,
		CHARACTER = 29,
		STRING_ = 30,
		VOID = 31,
		CHAR = 32,
		BOOL = 33,
		STRING = 34,
		INT = 35,
		TRUE = 36,
		FALSE = 37,
		CONST = 38,
		CALL = 39,
		WRITE_ = 40,
		READ_ = 41,
		IF = 42,
		ELSE = 43,
		WHILE = 44,
		PROGRAM = 45,
		FUN_DEF = 46,
		BLOCK = 47,
		VAR_DECL = 48,
		VALUE = 49,
		WRITE = 50,
		READ = 51,
		BIN_OP = 52,
		UN_OP = 53,
		ASSIGNMENT = 54,
		IF_STATEMENT = 55,
		WHILE_STATEMENT = 56,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_tard_lexerTokenTypes_hpp_*/
