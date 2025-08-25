#include "../lexer/token.hpp"
#include <iostream>
#include <string>
using namespace std;
string buf, t;
vector <vest_token> tokens;
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	while (getline(cin, t))
	{
		buf += t;
		buf += '\n';
	}
	tokens = tokenize(buf);
	for (vector <vest_token> ::iterator p = tokens.begin(); 
		p != tokens.end(); p++)
	{
		cout << "line " << (*p).lineno << ", char " << 
				(*p).charno << "-" << (*p).charno + (*p).len - 1 << " ";
		switch ((*p).type)
		{
			case int_:
				cout << "(interger) " << ((vest_token_int *) (*p).data) -> num << endl;
				break;
			case flt_:
				cout << "(float) " << ((vest_token_float *) (*p).data) -> num << endl;
				break;
			case brc_:
				cout << "(bracket) ";
				if (((vest_token_bracket *) (*p).data) -> dir) cout << "post ";
				else cout << "pre ";
				switch (((vest_token_bracket *) (*p).data) -> btype)
				{
					case round_: cout << "round"; break;
					case squar_: cout << "square"; break;
					case curly_: cout << "curly"; break;
					default: cout << "???";
				}
				cout << endl;
				break;
			case opr_:
				cout << "(operator) ";
				switch (((vest_token_operator *) (*p).data) -> op)
				{
					case add_: cout << "plus"; break;
					case sub_: cout << "minus"; break;
					case mul_: cout << "times"; break;
					case div_: cout << "divide"; break;
					case pow_: cout << "power"; break;
					case mod_: cout << "modulus"; break;
					case logical_not_: cout << "logical not"; break;
					case neg_: cout << "binary negate"; break;
					case neg_eq_: cout << "binary negate assignment"; break;
					case and_: cout << "and"; break;
					case or_: cout << "or"; break;
					case xor_: cout << "xor"; break;
					case lt_: cout << "less than"; break;
					case gt_: cout << "greater than"; break;
					case le_: cout << "less than or equal to"; break;
					case ge_: cout << "greater than or equal to"; break;
					case eq_: cout << "equal to"; break;
					case ne_: cout << "not equal to"; break;
					case assign_: cout << "assignment"; break;
					case attribute_: cout << "attribute"; break;
					case add_eq_: cout << "plus assignment"; break;
					case sub_eq_: cout << "minus assignment"; break;
					case mul_eq_: cout << "times assignment"; break;
					case div_eq_: cout << "divide assignment"; break;
					case mod_eq_: cout << "modulus assignment"; break;
					case pow_eq_: cout << "power assignment"; break;
					case and_eq_: cout << "and assignment"; break;
					case or_eq_: cout << "or assignment"; break;
					case xor_eq_: cout << "xor assignment"; break;
					case logical_and_: cout << "logical and"; break;
					case logical_or_: cout << "logical or"; break;
					case logical_xor_: cout << "logical xor"; break;
					case lshift_: cout << "left shift"; break;
					case rshift_: cout << "right shift"; break;
					default: cout << "???";
				}
				cout << endl;
				break;
			case idn_:
				cout << "(identifier) " << ((vest_token_identifier *) (*p).data) -> text << endl;
				break;
			case kwd_:
				cout << "(keyword) " << ((vest_token_keyword *) (*p).data) -> text << endl;
				break;
			case str_:
				cout << "(string) " << ((vest_token_string *) (*p).data) -> text << endl;
				break;
			case chr_:
				cout << "(char) " << ((vest_token_char *) (*p).data) -> ch << endl;
				break;
			case cmt_:
				cout << "(comment) " << ((vest_token_comment *) (*p).data) -> text << endl;
				break;
			case spc_:
				cout << "(special char) ";
				switch (((vest_token_special_char *) (*p).data) -> ctype)
				{
					case comma_: cout << "comma"; break;
					case semicolon_: cout << "semicolon"; break;
					case colon_: cout << "colon"; break;
					default: cout << "???";
				}
				cout << endl;
				break;
			case wsp_:
				cout << "(whitespace) ";
				switch (((vest_token_whitespace *) (*p).data) -> wtype)
				{
					case space_: cout << "space"; break;
					case tab_: cout << "tab"; break;
					case return_: cout << "carriage return"; break;
					case newline_: cout << "newline"; break;
					case vtab_: cout << "vertical tab"; break;
					case formfd_: cout << "form feed"; break;
					default: cout << "???";
				}
				cout << endl;
				break;
			default:
				char ch = ((vest_token_unknown *) (*p).data) -> ch;
				cout << "(unknown) " << ch << endl;
				break;
		}
	}
	return 0;
}
