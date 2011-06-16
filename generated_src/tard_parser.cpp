/* $ANTLR 2.7.5 (20050128): "../../grammar/tard.grammar" -> "tard_parser.cpp"$ */
#include "tard_parser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 1 "../../grammar/tard.grammar"
#line 8 "tard_parser.cpp"
tard_parser::tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

tard_parser::tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,1)
{
}

tard_parser::tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

tard_parser::tard_parser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,1)
{
}

tard_parser::tard_parser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,1)
{
}

void tard_parser::program() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr program_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	{ // ( ... )+
	int _cnt40=0;
	for (;;) {
		if (((LA(1) >= VOID && LA(1) <= INT))) {
			fun_def();
			if (inputState->guessing==0) {
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
		}
		else {
			if ( _cnt40>=1 ) { goto _loop40; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
		}
		
		_cnt40++;
	}
	_loop40:;
	}  // ( ... )+
	if ( inputState->guessing==0 ) {
		program_AST = node_ptr(currentAST.root);
#line 115 "../../grammar/tard.grammar"
		
				program_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(PROGRAM,"PROGRAM")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(program_AST))));
			
#line 62 "tard_parser.cpp"
		currentAST.root = program_AST;
		if ( program_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			program_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = program_AST->getFirstChild();
		else
			currentAST.child = program_AST;
		currentAST.advanceChildToEnd();
	}
	program_AST = node_ptr(currentAST.root);
	returnAST = program_AST;
}

void tard_parser::fun_def() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr fun_def_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	type();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	identifier();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	match(L_PAREN);
	match(R_PAREN);
	block();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	if ( inputState->guessing==0 ) {
		fun_def_AST = node_ptr(currentAST.root);
#line 120 "../../grammar/tard.grammar"
		
				fun_def_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(FUN_DEF,"FUN_DEF")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(fun_def_AST))));
			
#line 100 "tard_parser.cpp"
		currentAST.root = fun_def_AST;
		if ( fun_def_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			fun_def_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = fun_def_AST->getFirstChild();
		else
			currentAST.child = fun_def_AST;
		currentAST.advanceChildToEnd();
	}
	fun_def_AST = node_ptr(currentAST.root);
	returnAST = fun_def_AST;
}

void tard_parser::type() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr type_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	switch ( LA(1)) {
	case STRING:
	{
		Reftype tmp3_AST = Reftype(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp3_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp3_AST));
		}
		match(STRING);
		type_AST = node_ptr(currentAST.root);
		break;
	}
	case CHAR:
	{
		Reftype tmp4_AST = Reftype(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp4_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp4_AST));
		}
		match(CHAR);
		type_AST = node_ptr(currentAST.root);
		break;
	}
	case VOID:
	{
		Reftype tmp5_AST = Reftype(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp5_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp5_AST));
		}
		match(VOID);
		type_AST = node_ptr(currentAST.root);
		break;
	}
	case BOOL:
	{
		Reftype tmp6_AST = Reftype(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp6_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp6_AST));
		}
		match(BOOL);
		type_AST = node_ptr(currentAST.root);
		break;
	}
	case INT:
	{
		Reftype tmp7_AST = Reftype(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp7_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp7_AST));
		}
		match(INT);
		type_AST = node_ptr(currentAST.root);
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = type_AST;
}

void tard_parser::identifier() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr identifier_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	Refidentifier tmp8_AST = Refidentifier(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
	if ( inputState->guessing == 0 ) {
		tmp8_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp8_AST));
	}
	match(IDENTIFIER);
	identifier_AST = node_ptr(currentAST.root);
	returnAST = identifier_AST;
}

void tard_parser::block() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr block_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	match(L_CURL);
	{ // ( ... )*
	for (;;) {
		if ((_tokenSet_0.member(LA(1)))) {
			statement();
			if (inputState->guessing==0) {
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
		}
		else {
			goto _loop44;
		}
		
	}
	_loop44:;
	} // ( ... )*
	match(R_CURL);
	if ( inputState->guessing==0 ) {
		block_AST = node_ptr(currentAST.root);
#line 125 "../../grammar/tard.grammar"
		
				block_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BLOCK,"BLOCK")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(block_AST))));
			
#line 225 "tard_parser.cpp"
		currentAST.root = block_AST;
		if ( block_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			block_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = block_AST->getFirstChild();
		else
			currentAST.child = block_AST;
		currentAST.advanceChildToEnd();
	}
	block_AST = node_ptr(currentAST.root);
	returnAST = block_AST;
}

void tard_parser::statement() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr statement_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	{
	switch ( LA(1)) {
	case VOID:
	case CHAR:
	case BOOL:
	case STRING:
	case INT:
	{
		var_decl();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case PLUS:
	case DASH:
	case L_CURL:
	case L_PAREN:
	case NOT:
	case INTEGER:
	case IDENTIFIER:
	case CHARACTER:
	case STRING_:
	case TRUE:
	case FALSE:
	case WRITE_:
	case READ_:
	case IF:
	case WHILE:
	{
		expression();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	}
	}
	match(SEMI);
	statement_AST = node_ptr(currentAST.root);
	returnAST = statement_AST;
}

void tard_parser::var_decl() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr var_decl_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	type();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	identifier();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	if ( inputState->guessing==0 ) {
		var_decl_AST = node_ptr(currentAST.root);
#line 132 "../../grammar/tard.grammar"
		
				var_decl_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(VAR_DECL,"VAR_DECL")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(var_decl_AST))));
			
#line 309 "tard_parser.cpp"
		currentAST.root = var_decl_AST;
		if ( var_decl_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			var_decl_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = var_decl_AST->getFirstChild();
		else
			currentAST.child = var_decl_AST;
		currentAST.advanceChildToEnd();
	}
	var_decl_AST = node_ptr(currentAST.root);
	returnAST = var_decl_AST;
}

void tard_parser::expression() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr expression_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	and_expr();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{
	if ((LA(1) == OR)) {
		node_ptr tmp12_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
		if ( inputState->guessing == 0 ) {
			tmp12_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp12_AST));
		}
		match(OR);
		and_expr();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
	}
	else if ((_tokenSet_1.member(LA(1)))) {
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	
	}
	if ( inputState->guessing==0 ) {
		expression_AST = node_ptr(currentAST.root);
#line 139 "../../grammar/tard.grammar"
		
				expression_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BIN_OP,"BIN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(expression_AST))));
			
#line 357 "tard_parser.cpp"
		currentAST.root = expression_AST;
		if ( expression_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			expression_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = expression_AST->getFirstChild();
		else
			currentAST.child = expression_AST;
		currentAST.advanceChildToEnd();
	}
	expression_AST = node_ptr(currentAST.root);
	returnAST = expression_AST;
}

void tard_parser::and_expr() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr and_expr_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	compare_expr();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{
	if ((LA(1) == AND)) {
		node_ptr tmp13_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
		if ( inputState->guessing == 0 ) {
			tmp13_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp13_AST));
		}
		match(AND);
		compare_expr();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
	}
	else if ((_tokenSet_1.member(LA(1)))) {
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	
	}
	if ( inputState->guessing==0 ) {
		and_expr_AST = node_ptr(currentAST.root);
#line 144 "../../grammar/tard.grammar"
		
				and_expr_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BIN_OP,"BIN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(and_expr_AST))));
			
#line 405 "tard_parser.cpp"
		currentAST.root = and_expr_AST;
		if ( and_expr_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			and_expr_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = and_expr_AST->getFirstChild();
		else
			currentAST.child = and_expr_AST;
		currentAST.advanceChildToEnd();
	}
	and_expr_AST = node_ptr(currentAST.root);
	returnAST = and_expr_AST;
}

void tard_parser::compare_expr() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr compare_expr_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	add_expr();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{
	if (((LA(1) >= LESS && LA(1) <= EQUALS))) {
		{
		switch ( LA(1)) {
		case LESS:
		{
			node_ptr tmp14_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp14_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp14_AST));
			}
			match(LESS);
			break;
		}
		case GREATER:
		{
			node_ptr tmp15_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp15_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp15_AST));
			}
			match(GREATER);
			break;
		}
		case GREATER_EQ:
		{
			node_ptr tmp16_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp16_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp16_AST));
			}
			match(GREATER_EQ);
			break;
		}
		case LESS_EQ:
		{
			node_ptr tmp17_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp17_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp17_AST));
			}
			match(LESS_EQ);
			break;
		}
		case NOT_EQUALS:
		{
			node_ptr tmp18_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp18_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp18_AST));
			}
			match(NOT_EQUALS);
			break;
		}
		case EQUALS:
		{
			node_ptr tmp19_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp19_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp19_AST));
			}
			match(EQUALS);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		add_expr();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
	}
	else if ((_tokenSet_1.member(LA(1)))) {
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	
	}
	if ( inputState->guessing==0 ) {
		compare_expr_AST = node_ptr(currentAST.root);
#line 149 "../../grammar/tard.grammar"
		
				compare_expr_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BIN_OP,"BIN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(compare_expr_AST))));
			
#line 515 "tard_parser.cpp"
		currentAST.root = compare_expr_AST;
		if ( compare_expr_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			compare_expr_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = compare_expr_AST->getFirstChild();
		else
			currentAST.child = compare_expr_AST;
		currentAST.advanceChildToEnd();
	}
	compare_expr_AST = node_ptr(currentAST.root);
	returnAST = compare_expr_AST;
}

void tard_parser::add_expr() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr add_expr_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	mul_expr();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == PLUS || LA(1) == DASH)) {
			{
			switch ( LA(1)) {
			case PLUS:
			{
				node_ptr tmp20_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
				if ( inputState->guessing == 0 ) {
					tmp20_AST = astFactory->create(LT(1));
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp20_AST));
				}
				match(PLUS);
				break;
			}
			case DASH:
			{
				node_ptr tmp21_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
				if ( inputState->guessing == 0 ) {
					tmp21_AST = astFactory->create(LT(1));
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp21_AST));
				}
				match(DASH);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			mul_expr();
			if (inputState->guessing==0) {
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
		}
		else {
			goto _loop59;
		}
		
	}
	_loop59:;
	} // ( ... )*
	if ( inputState->guessing==0 ) {
		add_expr_AST = node_ptr(currentAST.root);
#line 154 "../../grammar/tard.grammar"
		
				add_expr_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BIN_OP,"BIN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(add_expr_AST))));
			
#line 586 "tard_parser.cpp"
		currentAST.root = add_expr_AST;
		if ( add_expr_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			add_expr_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = add_expr_AST->getFirstChild();
		else
			currentAST.child = add_expr_AST;
		currentAST.advanceChildToEnd();
	}
	add_expr_AST = node_ptr(currentAST.root);
	returnAST = add_expr_AST;
}

void tard_parser::mul_expr() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr mul_expr_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	sign_expr();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == STAR || LA(1) == SLASH)) {
			{
			switch ( LA(1)) {
			case STAR:
			{
				node_ptr tmp22_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
				if ( inputState->guessing == 0 ) {
					tmp22_AST = astFactory->create(LT(1));
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp22_AST));
				}
				match(STAR);
				break;
			}
			case SLASH:
			{
				node_ptr tmp23_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
				if ( inputState->guessing == 0 ) {
					tmp23_AST = astFactory->create(LT(1));
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp23_AST));
				}
				match(SLASH);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			sign_expr();
			if (inputState->guessing==0) {
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
		}
		else {
			goto _loop63;
		}
		
	}
	_loop63:;
	} // ( ... )*
	if ( inputState->guessing==0 ) {
		mul_expr_AST = node_ptr(currentAST.root);
#line 159 "../../grammar/tard.grammar"
		
				mul_expr_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BIN_OP,"BIN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(mul_expr_AST))));
			
#line 657 "tard_parser.cpp"
		currentAST.root = mul_expr_AST;
		if ( mul_expr_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			mul_expr_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = mul_expr_AST->getFirstChild();
		else
			currentAST.child = mul_expr_AST;
		currentAST.advanceChildToEnd();
	}
	mul_expr_AST = node_ptr(currentAST.root);
	returnAST = mul_expr_AST;
}

void tard_parser::sign_expr() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr sign_expr_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	{
	switch ( LA(1)) {
	case PLUS:
	{
		node_ptr tmp24_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
		if ( inputState->guessing == 0 ) {
			tmp24_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp24_AST));
		}
		match(PLUS);
		break;
	}
	case DASH:
	{
		node_ptr tmp25_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
		if ( inputState->guessing == 0 ) {
			tmp25_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp25_AST));
		}
		match(DASH);
		break;
	}
	case L_CURL:
	case L_PAREN:
	case NOT:
	case INTEGER:
	case IDENTIFIER:
	case CHARACTER:
	case STRING_:
	case TRUE:
	case FALSE:
	case WRITE_:
	case READ_:
	case IF:
	case WHILE:
	{
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	}
	}
	not_expr();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	if ( inputState->guessing==0 ) {
		sign_expr_AST = node_ptr(currentAST.root);
#line 164 "../../grammar/tard.grammar"
		
				sign_expr_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(UN_OP,"UN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(sign_expr_AST))));
			
#line 729 "tard_parser.cpp"
		currentAST.root = sign_expr_AST;
		if ( sign_expr_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			sign_expr_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = sign_expr_AST->getFirstChild();
		else
			currentAST.child = sign_expr_AST;
		currentAST.advanceChildToEnd();
	}
	sign_expr_AST = node_ptr(currentAST.root);
	returnAST = sign_expr_AST;
}

void tard_parser::not_expr() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr not_expr_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == NOT)) {
			node_ptr tmp26_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
			if ( inputState->guessing == 0 ) {
				tmp26_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp26_AST));
			}
			match(NOT);
		}
		else {
			goto _loop68;
		}
		
	}
	_loop68:;
	} // ( ... )*
	value();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	if ( inputState->guessing==0 ) {
		not_expr_AST = node_ptr(currentAST.root);
#line 169 "../../grammar/tard.grammar"
		
				not_expr_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(UN_OP,"UN_OP")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(not_expr_AST))));
			
#line 774 "tard_parser.cpp"
		currentAST.root = not_expr_AST;
		if ( not_expr_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			not_expr_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = not_expr_AST->getFirstChild();
		else
			currentAST.child = not_expr_AST;
		currentAST.advanceChildToEnd();
	}
	not_expr_AST = node_ptr(currentAST.root);
	returnAST = not_expr_AST;
}

void tard_parser::value() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr value_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	{
	switch ( LA(1)) {
	case INTEGER:
	case CHARACTER:
	case STRING_:
	case TRUE:
	case FALSE:
	{
		literal();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case IDENTIFIER:
	{
		assignment();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case READ_:
	{
		read();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case WRITE_:
	{
		write();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case L_PAREN:
	{
		match(L_PAREN);
		expression();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		match(R_PAREN);
		break;
	}
	case L_CURL:
	{
		block();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case IF:
	{
		if_statement();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case WHILE:
	{
		while_statement();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	}
	}
	if ( inputState->guessing==0 ) {
		value_AST = node_ptr(currentAST.root);
#line 184 "../../grammar/tard.grammar"
		
				value_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(VALUE,"VALUE")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(value_AST))));
			
#line 876 "tard_parser.cpp"
		currentAST.root = value_AST;
		if ( value_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			value_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = value_AST->getFirstChild();
		else
			currentAST.child = value_AST;
		currentAST.advanceChildToEnd();
	}
	value_AST = node_ptr(currentAST.root);
	returnAST = value_AST;
}

void tard_parser::literal() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr literal_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	switch ( LA(1)) {
	case TRUE:
	{
		Refliteral tmp29_AST = Refliteral(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp29_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp29_AST));
		}
		match(TRUE);
		literal_AST = node_ptr(currentAST.root);
		break;
	}
	case FALSE:
	{
		Refliteral tmp30_AST = Refliteral(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp30_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp30_AST));
		}
		match(FALSE);
		literal_AST = node_ptr(currentAST.root);
		break;
	}
	case INTEGER:
	{
		Refliteral tmp31_AST = Refliteral(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp31_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp31_AST));
		}
		match(INTEGER);
		literal_AST = node_ptr(currentAST.root);
		break;
	}
	case CHARACTER:
	{
		Refliteral tmp32_AST = Refliteral(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp32_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp32_AST));
		}
		match(CHARACTER);
		literal_AST = node_ptr(currentAST.root);
		break;
	}
	case STRING_:
	{
		Refliteral tmp33_AST = Refliteral(node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST));
		if ( inputState->guessing == 0 ) {
			tmp33_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp33_AST));
		}
		match(STRING_);
		literal_AST = node_ptr(currentAST.root);
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	}
	returnAST = literal_AST;
}

void tard_parser::assignment() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr assignment_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	identifier();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{
	switch ( LA(1)) {
	case ASSIGN:
	{
		match(ASSIGN);
		expression();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		break;
	}
	case PLUS:
	case DASH:
	case STAR:
	case SLASH:
	case SEMI:
	case COMMA:
	case R_PAREN:
	case LESS:
	case GREATER:
	case GREATER_EQ:
	case LESS_EQ:
	case NOT_EQUALS:
	case EQUALS:
	case AND:
	case OR:
	case ELSE:
	{
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	}
	}
	if ( inputState->guessing==0 ) {
		assignment_AST = node_ptr(currentAST.root);
#line 193 "../../grammar/tard.grammar"
		
				assignment_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(ASSIGNMENT,"ASSIGNMENT")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(assignment_AST))));
			
#line 1009 "tard_parser.cpp"
		currentAST.root = assignment_AST;
		if ( assignment_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			assignment_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = assignment_AST->getFirstChild();
		else
			currentAST.child = assignment_AST;
		currentAST.advanceChildToEnd();
	}
	assignment_AST = node_ptr(currentAST.root);
	returnAST = assignment_AST;
}

void tard_parser::read() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr read_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	match(READ_);
	match(L_PAREN);
	identifier();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == COMMA)) {
			match(COMMA);
			identifier();
			if (inputState->guessing==0) {
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
		}
		else {
			goto _loop80;
		}
		
	}
	_loop80:;
	} // ( ... )*
	match(R_PAREN);
	if ( inputState->guessing==0 ) {
		read_AST = node_ptr(currentAST.root);
#line 203 "../../grammar/tard.grammar"
		
				read_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(READ,"READ")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(read_AST))));					
			
#line 1056 "tard_parser.cpp"
		currentAST.root = read_AST;
		if ( read_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			read_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = read_AST->getFirstChild();
		else
			currentAST.child = read_AST;
		currentAST.advanceChildToEnd();
	}
	read_AST = node_ptr(currentAST.root);
	returnAST = read_AST;
}

void tard_parser::write() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr write_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	match(WRITE_);
	match(L_PAREN);
	expression();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == COMMA)) {
			match(COMMA);
			expression();
			if (inputState->guessing==0) {
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
		}
		else {
			goto _loop77;
		}
		
	}
	_loop77:;
	} // ( ... )*
	match(R_PAREN);
	if ( inputState->guessing==0 ) {
		write_AST = node_ptr(currentAST.root);
#line 198 "../../grammar/tard.grammar"
		
				write_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(WRITE,"WRITE")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(write_AST))));					
			
#line 1103 "tard_parser.cpp"
		currentAST.root = write_AST;
		if ( write_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			write_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = write_AST->getFirstChild();
		else
			currentAST.child = write_AST;
		currentAST.advanceChildToEnd();
	}
	write_AST = node_ptr(currentAST.root);
	returnAST = write_AST;
}

void tard_parser::if_statement() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr if_statement_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	match(IF);
	match(L_PAREN);
	expression();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	match(R_PAREN);
	{
	bool synPredMatched84 = false;
	if (((_tokenSet_2.member(LA(1))))) {
		int _m84 = mark();
		synPredMatched84 = true;
		inputState->guessing++;
		try {
			{
			expression();
			match(ELSE);
			}
		}
		catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
			synPredMatched84 = false;
		}
		rewind(_m84);
		inputState->guessing--;
	}
	if ( synPredMatched84 ) {
		expression();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		match(ELSE);
		expression();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
	}
	else if ((_tokenSet_2.member(LA(1)))) {
		expression();
		if (inputState->guessing==0) {
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
	}
	
	}
	if ( inputState->guessing==0 ) {
		if_statement_AST = node_ptr(currentAST.root);
#line 208 "../../grammar/tard.grammar"
		
				if_statement_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(IF_STATEMENT,"IF_STATEMENT")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(if_statement_AST))));
			
#line 1174 "tard_parser.cpp"
		currentAST.root = if_statement_AST;
		if ( if_statement_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			if_statement_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = if_statement_AST->getFirstChild();
		else
			currentAST.child = if_statement_AST;
		currentAST.advanceChildToEnd();
	}
	if_statement_AST = node_ptr(currentAST.root);
	returnAST = if_statement_AST;
}

void tard_parser::while_statement() {
	returnAST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	node_ptr while_statement_AST = node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	match(WHILE);
	match(L_PAREN);
	expression();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	match(R_PAREN);
	expression();
	if (inputState->guessing==0) {
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
	}
	if ( inputState->guessing==0 ) {
		while_statement_AST = node_ptr(currentAST.root);
#line 213 "../../grammar/tard.grammar"
		
				while_statement_AST = node_ptr(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(WHILE_STATEMENT,"WHILE_STATEMENT")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(while_statement_AST))));
			
#line 1209 "tard_parser.cpp"
		currentAST.root = while_statement_AST;
		if ( while_statement_AST!=node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			while_statement_AST->getFirstChild() != node_ptr(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = while_statement_AST->getFirstChild();
		else
			currentAST.child = while_statement_AST;
		currentAST.advanceChildToEnd();
	}
	while_statement_AST = node_ptr(currentAST.root);
	returnAST = while_statement_AST;
}

void tard_parser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory )
{
	factory.registerFactory(27, "literal", literal::factory);
	factory.registerFactory(28, "identifier", identifier::factory);
	factory.registerFactory(29, "literal", literal::factory);
	factory.registerFactory(30, "literal", literal::factory);
	factory.registerFactory(31, "type", type::factory);
	factory.registerFactory(32, "type", type::factory);
	factory.registerFactory(33, "type", type::factory);
	factory.registerFactory(34, "type", type::factory);
	factory.registerFactory(35, "type", type::factory);
	factory.registerFactory(36, "literal", literal::factory);
	factory.registerFactory(37, "literal", literal::factory);
	factory.registerFactory(45, "program", program::factory);
	factory.registerFactory(46, "fun_def", fun_def::factory);
	factory.registerFactory(47, "block", block::factory);
	factory.registerFactory(48, "var_decl", var_decl::factory);
	factory.registerFactory(49, "value", value::factory);
	factory.registerFactory(50, "write", write::factory);
	factory.registerFactory(51, "read", read::factory);
	factory.registerFactory(52, "bin_op", bin_op::factory);
	factory.registerFactory(53, "un_op", un_op::factory);
	factory.registerFactory(54, "assignment", assignment::factory);
	factory.registerFactory(55, "if_statement", if_statement::factory);
	factory.registerFactory(56, "while_statement", while_statement::factory);
	factory.setMaxNodeType(56);
}
const char* tard_parser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"WHITESPACE",
	"PLUS",
	"DASH",
	"STAR",
	"SLASH",
	"ASSIGN",
	"SEMI",
	"COMMA",
	"L_CURL",
	"R_CURL",
	"L_PAREN",
	"R_PAREN",
	"NOT",
	"LESS",
	"GREATER",
	"GREATER_EQ",
	"LESS_EQ",
	"NOT_EQUALS",
	"EQUALS",
	"AND",
	"OR",
	"TICK",
	"QUOTE",
	"INTEGER",
	"IDENTIFIER",
	"CHARACTER",
	"STRING_",
	"\"void\"",
	"\"char\"",
	"\"bool\"",
	"\"string\"",
	"\"int\"",
	"\"true\"",
	"\"false\"",
	"\"const\"",
	"\"call\"",
	"\"write\"",
	"\"read\"",
	"\"if\"",
	"\"else\"",
	"\"while\"",
	"PROGRAM",
	"FUN_DEF",
	"BLOCK",
	"VAR_DECL",
	"VALUE",
	"WRITE",
	"READ",
	"BIN_OP",
	"UN_OP",
	"ASSIGNMENT",
	"IF_STATEMENT",
	"WHILE_STATEMENT",
	0
};

const unsigned long tard_parser::_tokenSet_0_data_[] = { 4160835680UL, 5951UL, 0UL, 0UL };
// PLUS DASH L_CURL L_PAREN NOT INTEGER IDENTIFIER CHARACTER STRING_ "void" 
// "char" "bool" "string" "int" "true" "false" "write" "read" "if" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet tard_parser::_tokenSet_0(_tokenSet_0_data_,4);
const unsigned long tard_parser::_tokenSet_1_data_[] = { 33459680UL, 2048UL, 0UL, 0UL };
// PLUS DASH STAR SLASH SEMI COMMA R_PAREN LESS GREATER GREATER_EQ LESS_EQ 
// NOT_EQUALS EQUALS AND OR "else" 
const ANTLR_USE_NAMESPACE(antlr)BitSet tard_parser::_tokenSet_1(_tokenSet_1_data_,4);
const unsigned long tard_parser::_tokenSet_2_data_[] = { 2013352032UL, 5936UL, 0UL, 0UL };
// PLUS DASH L_CURL L_PAREN NOT INTEGER IDENTIFIER CHARACTER STRING_ "true" 
// "false" "write" "read" "if" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet tard_parser::_tokenSet_2(_tokenSet_2_data_,4);


