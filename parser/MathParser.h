class MathParser
{
private:
    double number();
    double expr();
    double factor();
    double brackets();
    stringstream m_expr_stream;
    
public:
    double Calc(string str_expr)
    {
        m_expr_stream = stringstream(str_expr);
        return expr();
    }
};
