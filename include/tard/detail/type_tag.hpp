// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_TARD_TYPE_HPP
#define TARD_INCLUDED_DETAIL_TARD_TYPE_HPP

#include "tard/detail/type_tag.hpp"

// ---------------------------------------------------------------
enum type_tag
{
	TARD_TYPE_NONE = 0,
	
	TARD_TYPE_VOID   = 1 << 0,
	TARD_TYPE_INT    = 1 << 2,
	TARD_TYPE_BOOL   = 1 << 3,
	TARD_TYPE_CHAR   = 1 << 4,
	TARD_TYPE_STRING = 1 << 5,

	TARD_TYPE_COMPARABLE = TARD_TYPE_INT | TARD_TYPE_CHAR | TARD_TYPE_BOOL,
	TARD_TYPE_LHS	  = -1
};

#endif
