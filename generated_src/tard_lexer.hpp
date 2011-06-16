#ifndef INC_tard_lexer_hpp_
#define INC_tard_lexer_hpp_

#line 7 "../../grammar/tard.grammar"

	#include "tard/detail/nodes.hpp"

	#ifdef _MSC_VER
		#pragma warning(disable:4512)
		#pragma warning(disable:4100)
		#pragma warning(disable:4511)
		#pragma warning(disable:4244)
		#pragma warning(disable:4127)
	#endif

#line 17 "tard_lexer.hpp"
#include <antlr/config.hpp>
/* $ANTLR 2.7.5 (20050128): "../../grammar/tard.grammar" -> "tard_lexer.hpp"$ */
#include <antlr/CommonToken.hpp>
#include <antlr/InputBuffer.hpp>
#include <antlr/BitSet.hpp>
#include "tard_lexerTokenTypes.hpp"
#include <antlr/CharScanner.hpp>
class CUSTOM_API tard_lexer : public ANTLR_USE_NAMESPACE(antlr)CharScanner, public tard_lexerTokenTypes
{
#line 1 "../../grammar/tard.grammar"
#line 28 "tard_lexer.hpp"
private:
	void initLiterals();
public:
	bool getCaseSensitiveLiterals() const
	{
		return true;
	}
public:
	tard_lexer(ANTLR_USE_NAMESPACE(std)istream& in);
	tard_lexer(ANTLR_USE_NAMESPACE(antlr)InputBuffer& ib);
	tard_lexer(const ANTLR_USE_NAMESPACE(antlr)LexerSharedInputState& state);
	ANTLR_USE_NAMESPACE(antlr)RefToken nextToken();
	public: void mWHITESPACE(bool _createToken);
	public: void mPLUS(bool _createToken);
	public: void mDASH(bool _createToken);
	public: void mSTAR(bool _createToken);
	public: void mSLASH(bool _createToken);
	public: void mASSIGN(bool _createToken);
	public: void mSEMI(bool _createToken);
	public: void mCOMMA(bool _createToken);
	public: void mL_CURL(bool _createToken);
	public: void mR_CURL(bool _createToken);
	public: void mL_PAREN(bool _createToken);
	public: void mR_PAREN(bool _createToken);
	public: void mNOT(bool _createToken);
	public: void mLESS(bool _createToken);
	public: void mGREATER(bool _createToken);
	public: void mGREATER_EQ(bool _createToken);
	public: void mLESS_EQ(bool _createToken);
	public: void mNOT_EQUALS(bool _createToken);
	public: void mEQUALS(bool _createToken);
	public: void mAND(bool _createToken);
	public: void mOR(bool _createToken);
	public: void mTICK(bool _createToken);
	public: void mQUOTE(bool _createToken);
	public: void mINTEGER(bool _createToken);
	public: void mIDENTIFIER(bool _createToken);
	public: void mCHARACTER(bool _createToken);
	public: void mSTRING_(bool _createToken);
private:
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
};

#endif /*INC_tard_lexer_hpp_*/
