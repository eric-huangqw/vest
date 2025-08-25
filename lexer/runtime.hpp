#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <iostream>
#include <string>
using namespace std;

class vest_error
{
    public:
        size_t lineno;
        size_t charno;
        string mesg;
        vest_error(string msg, size_t nline, size_t nchar)
        {
            mesg = msg;
            lineno = nline;
            charno = nchar;
        }
        virtual void raise(ostream &os = cerr)
        {
            os << "(error at line " << lineno << " char " << charno << ") " << mesg;
        }
};

class vest_syntax_error: public vest_error
{
    public:
        vest_syntax_error(string msg, size_t nline, size_t nchar)
            : vest_error(msg, nline, nchar) {   }
        void raise(ostream &os = cerr)
        {
            os << "(syntax error at line " << lineno << " char " << charno << ") " << mesg;
        }
};

#endif