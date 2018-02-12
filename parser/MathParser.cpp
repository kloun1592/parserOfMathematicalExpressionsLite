#include "stdafx.h"
#include "MathParser.h"

double MathParser::number()
{
    int res = 0;
    for (;;)
    {
        char c = m_expr_stream.get();
        if (c >= '0' && c <= '9')
            res = res * 10 + c - '0';
        else
        {
            m_expr_stream.putback(c);
            return res;
        }
    }
}

double MathParser::brackets()
{
    char c = m_expr_stream.get();
    if (c == '(')
    {
        double x = expr();
        m_expr_stream.get();
        return x;
    }
    else
    {
        m_expr_stream.putback(c);
        return number();
    }
}

double MathParser::factor()
{
    double x = brackets();
    for (;;)
    {
        char c = m_expr_stream.get();
        switch (c)
        {
            case '*':
                x *= brackets();
                break;
            case '/':
                x /= brackets();
                break;
            default:
                m_expr_stream.putback(c);
                return x;
        }
    }
}

double MathParser::expr()
{
    double x = factor();
    for (;;)
    {
        char c = m_expr_stream.get();
        switch (c)
        {
            case '+':
                x += factor();
                break;
            case '-':
                x -= factor();
                break;
            default:
                m_expr_stream.putback(c);
                return x;
        }
    }
}
