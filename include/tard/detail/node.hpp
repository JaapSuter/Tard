// ---------------------------------------------------------------
// Tard - Copyright 2005 Jaap Suter
// ---------------------------------------------------------------

#ifndef TARD_INCLUDED_DETAIL_NODE_HPP
#define TARD_INCLUDED_DETAIL_NODE_HPP

// ---------------------------------------------------------------
#ifdef _MSC_VER
	#pragma warning(disable:4100)
	#pragma warning(disable:4512)
#endif

// ---------------------------------------------------------------
#include "tard/detail/type_tag.hpp"
#include "antlr/CommonAST.hpp"
#include <iosfwd>
#include <cassert>

// ---------------------------------------------------------------
class var_decl;
class identifier;

// --------------------------------------------------------------
// Base class for all nodes in a Tard AST. Provides some common
// utility functions as well as a virtual interface all nodes need
// to implement.
//
// Most importantly, each derived type for a particular language construct
// needs to implement the following three funtions:
//
//      do_analyze_context
//      generate_code
//      get_type
//
// --------------------------------------------------------------
class node : public antlr::CommonAST
{
public:

	typedef antlr::ASTRefCount<node> ptr;

    // Handy macro for derived classes so they can quicly implement a node factory.
	#define TARD_DETAIL_FACTORY_IMPL(_name_) \
		static antlr::RefAST factory() { return antlr::RefAST(new _name_); }	

	TARD_DETAIL_FACTORY_IMPL(node)	
	
	virtual ~node() {}
	
    void analyze_context(node* parent);
	virtual void generate_code(std::ostream&) { assert(false); }
	virtual type_tag get_type() const { assert(false); return TARD_TYPE_NONE; }
	virtual var_decl* find(const identifier& id) const;
	
	var_decl* find_from_bottom_up(const identifier& id) const;
	
	int depth() const;

	node& get_child(int index) const;

	int get_num_children() const { return static_cast<int>(getNumberOfChildren()); }

	ptr get_first_child() const { return static_cast<ptr>(getFirstChild()); }
	ptr get_next_sibling() const { return static_cast<ptr>(getNextSibling()); }

	node* parent() const { return _parent; }
	
	template<class T> T& as();
	template<class T> const T& as() const;	
	template<class T> bool is() const;	
	template<class V> void visit(V v);
	
protected:

	node();

private:
	
	virtual void do_analyze_context() { assert(false); }

	node(const node&);
	node& operator = (const node&);

	node* _parent;
};

// ---------------------------------------------------------------
typedef node::ptr node_ptr;

// ---------------------------------------------------------------
template<class T>
bool node::is() const
{
	return 0 != dynamic_cast<const T*>(&(*this));
}

// ---------------------------------------------------------------
template<class T>
T& node::as()
{
	return dynamic_cast<T&>(*this);
}

// ---------------------------------------------------------------
template<class T>
const T& node::as() const
{
	return dynamic_cast<const T&>(*this);
}

// ---------------------------------------------------------------
template<class V>
void node::visit(V v)
{
	v(*this);
	node_ptr p = get_first_child();
	while (p)
	{
		p->visit(v);
		p = p->get_next_sibling();
	}
}

// ---------------------------------------------------------------
// required due to a bug in ANTLR code generation, the 
// type generated is just a synonym for a node pointer
// ---------------------------------------------------------------
#define TARD_IMPL_NODE_PTR_SYNONYM(_name_) typedef node_ptr Ref ## _name_;

#endif
