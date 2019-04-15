/*++
  Copyright (c) 2017 Microsoft Corporation

  Module Name:

  <name>

  Abstract:

  <abstract>

  Author:
  Nikolaj Bjorner (nbjorner)
  Lev Nachmanson (levnach)

  Revision History:


  --*/
#include "util/lp/nla_common.h"
#include "util/lp/nla_core.h"

namespace nla {
bool common::done() const { return m_core->done(); }

template <typename T> void common::explain(const T& t) {
    c().explain(t, c().current_expl());
}
template void common::explain<monomial>(const monomial& t);
template void common::explain<factor>(const factor& t);
template void common::explain<rooted_mon>(const rooted_mon& t);
template void common::explain<factorization>(const factorization& t);

void common::explain(lpvar j) { c().explain(j, c().current_expl()); }

template <typename T> rational common::vvr(T const& t) const { return m_core->vvr(t); }
template rational common::vvr<monomial>(monomial const& t) const;
template rational common::vvr<rooted_mon>(rooted_mon const& t) const;
template rational common::vvr<factor>(factor const& t) const;
rational common::vvr(lpvar t) const { return m_core->vvr(t); }
template <typename T> lpvar common::var(T const& t) const { return m_core->var(t); }
template lpvar common::var<factor>(factor const& t) const;
template lpvar common::var<rooted_mon>(rooted_mon const& t) const;
void common::add_empty_lemma() { c().add_empty_lemma(); }
template <typename T> rational common::canonize_sign(const T& t) const {
    return c().canonize_sign(t);
}
template rational common::canonize_sign<rooted_mon>(const rooted_mon& t) const;
template rational common::canonize_sign<factor>(const factor& t) const;
rational common::canonize_sign(lpvar j) const {
    return c().canonize_sign_of_var(j);
}
void common::mk_ineq(lp::lar_term& t, llc cmp, const rational& rs){
    c().mk_ineq(t, cmp, rs);
}
void common::mk_ineq(const rational& a, lpvar j, const rational& b, lpvar k, llc cmp, const rational& rs){
    c().mk_ineq(a, j, b, j, cmp, rs);
}

void common::mk_ineq(lpvar j, const rational& b, lpvar k, llc cmp, const rational& rs){
    c().mk_ineq(j, b, k, cmp, rs);
}

void common::mk_ineq(lpvar j, const rational& b, lpvar k, llc cmp){
    c().mk_ineq(j, b, k, cmp);
}

void common::mk_ineq(const rational& a, lpvar j, const rational& b, lpvar k, llc cmp) {
    c().mk_ineq(a, j, b, k, cmp);
}

void common::mk_ineq(const rational& a ,lpvar j, lpvar k, llc cmp, const rational& rs) {
    c().mk_ineq(a, j, k, cmp, rs);
}

void common::mk_ineq(lpvar j, lpvar k, llc cmp, const rational& rs) {
    c().mk_ineq(j, k, cmp, rs);}

void common::mk_ineq(lpvar j, llc cmp, const rational& rs){
    c().mk_ineq(j, cmp, rs);}

void common::mk_ineq(const rational& a, lpvar j, llc cmp, const rational& rs) {
    c().mk_ineq(a, j, cmp, rs);
}
void common::mk_ineq(const rational& a, lpvar j, llc cmp){
    c().mk_ineq(a, j, cmp);
}

void common::mk_ineq(lpvar j, llc cmp){
    c().mk_ineq(j, cmp);
}
std::ostream& common::print_lemma(std::ostream& out) const {
    return c().print_lemma(out);  
}
template <typename T>
std::ostream& common::print_product(const T & m, std::ostream& out) const {
    return c().print_product(m, out);
}
template 
std::ostream& common::print_product<monomial>(const monomial & m, std::ostream& out) const;

template std::ostream& common::print_product<rooted_mon>(const rooted_mon & m, std::ostream& out) const;


std::ostream& common::print_monomial(const monomial & m, std::ostream& out) const {
    return c().print_monomial(m, out);
}
std::ostream& common::print_rooted_monomial(const rooted_mon& rm, std::ostream& out) const {
    return c().print_rooted_monomial(rm, out);
}
std::ostream& common::print_rooted_monomial_with_vars(const rooted_mon& rm, std::ostream& out) const {
        return c().print_rooted_monomial_with_vars(rm, out);
}
std::ostream& common::print_factor(const factor & f, std::ostream& out) const {
    return c().print_factor(f, out);
}

std::ostream& common::print_var(lpvar j, std::ostream& out) const {
    return c().print_var(j, out);
}

bool common::check_monomial(const monomial& m) const {
    return c().check_monomial(m);
}

}
