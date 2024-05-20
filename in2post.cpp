#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include "stack.h"


using namespace std;
using namespace cop4530;

int order(string s)
{
    if(s == "+" || s == "-"){return 1;}
    else if(s == "*" || s == "/"){return 2;}
    else if(s== "(" || s == ")"){return 3;}
    else{return 0;}
    
}

bool check(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(!isalnum(s[i])){return false;}
    }

    return true;
}

void convert(vector<string>& iexpression,vector<string> &pexpression)
{
    Stack<string> c;

    for(int i = 0; i < iexpression.size(); ++i)
    {
        if(order(iexpression[i]) != 0)
        {
            if(((!c.empty()) && (c.top() != "("))
             && (order(c.top()) >= order(iexpression[i])))
            {
                while(((!c.empty()) && (c.top() != "(")) && 
                (order(c.top()) >= order(iexpression[i])))
                {
                    pexpression.push_back(c.top());
                    cout << c.top() << " ";
                    c.pop();
                }
            }
            c.push(iexpression[i]);
            if(iexpression[i] == ")")
            {
                c.pop();
                while(c.top() != "(")
                {
                    cout << c.top() << " ";
                    pexpression.push_back(c.top());
                    c.pop();
                }
                c.pop();
            }
        }
        else if(check(iexpression[i]))
        {
            pexpression.push_back(iexpression[i]);
            cout << iexpression[i] << " ";
        }
    }
    while(!c.empty())
    {
        cout << c.top() << " ";
        pexpression.push_back(c.top());
        c.pop(); 
    }
    cout << endl;
}

void evaluate(vector<string> &pexpression)
{
    Stack<string> c;
    bool isnum = false;
    for(int i = 0; i< pexpression.size();i++)
    {
        if(check(pexpression[i]))
        {
            for(int j = 0; j <  pexpression[j].size();j++)
            {
                if(isdigit(pexpression[i][j]) || pexpression[i][j] == '.')
                {
                    isnum = true;
                }
                else
                {
                    isnum = false;
                    break;
                }
            }
        }
    }

    if(isnum)
    {
        for(int i =0;i<pexpression.size();i++)
        {
            if(check(pexpression[i]))
            {c.push(pexpression[i]);}
            
            if(order(pexpression[i]) != 0)
            {
                float temp;
                float num1 = stof(c.top());
                c.pop();
                float num2 = stof(c.top());
                c.pop();
            

            if(pexpression[i][0] == '*'){temp = num2 * num1;}
            else if(pexpression[i][0] == '/'){temp = num2/num1;}
            else if(pexpression[i][0] == '+'){temp = num2 + num1;}
            else if(pexpression[i][0] == '-'){temp = num2 - num1;}

            c.push(to_string(temp));

            }
        }
        for(int i =0; i < pexpression.size();i++)
        {
             cout << pexpression[i] << " ";
        }
        cout << "= " << c.top() << endl;
    }
    else
    {
          for(int i =0; i < pexpression.size();i++)
        {
             cout << pexpression[i] << " ";
        }
        cout << "= ";
          for(int i =0; i < pexpression.size();i++)
            {
                 cout << pexpression[i] << " ";
            }
        cout << endl;
    }
}

int main()
{
    vector<string> iexpression;
    vector<string> pexpression;
    string input;

    do
    {
        cout << "Enter infix or expression or \"exit\" to quit program\n";

        getline(cin,input);
        iexpression.clear();
        pexpression.clear();
        stringstream ss(input);

        while(ss >> input)
        {
            iexpression.push_back(input);
        }

        cout << "Postfix Expression: ";
        convert(iexpression,pexpression);

        cout << "Postfix Evaluation: ";
        evaluate(pexpression);

    }while(input != "exit");
}