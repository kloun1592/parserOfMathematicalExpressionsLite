#include "stdafx.h"
#include "MathParser.h"

bool findSymbol(string str, char symbol)
{
    for (unsigned i = 0; i < str.length(); i++)
    {
        if (str[i] == symbol)
            return 1;
    }
    return 0;
}

int main()
{
    string str = "";
    cin >> str;
    
    int i = 0;
    string substr = "";
    bool operationMark = false;
    
    while (str[i] != '\0')
    {
        
        if ((str[i] >= '0' && str[i] <='9') ||
            (str[i + 1] == '(') ||
            (str[i] == '(') ||
            (str[i] == ')') ||
            (str[i + 1] == ')'))
        {
            substr += str[i];
            
            while ((str[i + 1] >= '0' && str[i + 1] <='9') ||
                   (str[i + 1] == '+') ||
                   (str[i + 1] == '-') ||
                   (str[i + 1] == '/') ||
                   (str[i + 1] == '*') ||
                   (str[i + 1] == '(') ||
                   (str[i + 1] == ')'))
            {
                if (operationMark && ((str[i + 1] == '+') ||
                                      (str[i + 1] == '-') ||
                                      (str[i + 1] == '/') ||
                                      (str[i + 1] == '*')))
                {
                    substr = "";
                    break;
                }
                
                substr += str[i + 1];
                
                if ((str[i + 1] == '+') ||
                    (str[i + 1] == '-') ||
                    (str[i + 1] == '/') ||
                    (str[i + 1] == '*'))
                {
                    operationMark = true;
                }
                else
                {
                    operationMark = false;
                }
                i++;
            }
            
            // Отдаём функции для подсчёта, выражение которое нашли
            if (!operationMark && substr != "" &&
                (findSymbol(substr, '+') ||
                findSymbol(substr, '-') ||
                findSymbol(substr, '*') ||
                findSymbol(substr, '/')))
            {
                MathParser p;
                double res = p.Calc(substr);
                cout << substr << " = " << res << endl;
            }
            
            // Обнуляем и двигаем счётчик дальше
            substr = "";
            i++;
        }
        else
        {
            if (operationMark)
            {
                while (!((str[i] >= 'A' && str[i] <='Z') ||
                         (str[i] >= 'a' && str[i] <='z')) && str[i] != '\0')
                {
                    i++;
                }
                
                operationMark = false;
            }
            
            // Снова ищем цифру
            while (!((str[i] >= '0' && str[i] <='9') ||
                     (str[i] == '(')) && str[i] != '\0')
            {
                i++;
            }
        }
    }
    
    return 0;
}
