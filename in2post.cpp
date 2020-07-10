#include "Stack.h"
#include <iostream>
#include <sstream>
#include <string>
#include "List.h"

bool Operator(std::string token);
int Precedence(std::string token);
void Convert(std::string, Stack<std::string>&);
Stack<float> Evaluate(Stack<std::string>&);
float Calculate(float, float);

int main(int argc, char* argv[])
{
    std::string infix(argv[1]);
    Stack<std::string> stack;
    Convert(infix, stack);
    std::cout << "\nProgram Terminated Normally" << std::endl;
    return 0;
}

bool Operator(std::string token)
{
    if(token.compare("*") == 0 || token.compare("/") == 0 || token.compare("-") == 0 || token.compare("+") == 0)
    {
        return true;
    }
    
    return false;
}

int Precedence( std::string token )
{
    if(token.compare("*") == 0)
    {
        return 1;
    }

    if(token.compare("/") == 0)
    {
        return 1;
    }

    if(token.compare("-") == 0)
    {
        return 2;
    }

    if(token.compare("+") == 0)
    {
        return 2;
    }

    return 0;
}

void Convert(std::string infix, Stack<std::string>& stack)
{ 
    std::stringstream infixStream(infix);
    std::string token;
    Stack<std::string> operators;
    bool evaluate = true;

    while(infixStream.good())
    {
        getline(infixStream, token, ' ');

        if(Operator(token))
        {
            while(!operators.empty() && (Precedence(operators.top()) <= Precedence(token)) && token.compare("(") == 0)
            {
                stack.push(operators.top());
                operators.pop();
            }

            operators.push(token);
        }

        else if ( token.compare("(") == 0) 
        { 
            operators.push(token); 
        }

        else if ( token.compare(")") == 0)
        {
            while(!operators.empty())
            {
                if(operators.top().compare("(") == 0)
                {
                    operators.pop();
                }

                else
                {
                    stack.push(operators.top());
                    operators.pop();
                } 
            } 
        }

        else
        {
            stack.push(token);
        }
    }
    
    while(!operators.empty())
    {
        stack.push(operators.top());
        operators.pop();
    }

    stack.print(std::cout, ' ');
    std::cout << std::endl;
    Evaluate(stack).print(std::cout, ' ');

}

float Calculate(float a, float b, std::string token)
{
    if(token.compare("*") == 0)
    {
        return a * b;
    }

    if(token.compare("/") == 0)
    {
        return a / b;
    }

    if(token.compare("-") == 0)
    {
        return a - b;
    }

    if(token.compare("+") == 0)
    {
        return a + b;
    }

    return 0;
}

Stack<float> Evaluate(Stack<std::string>& stack)
{
    Stack<float> eval_stack;
    float result = 0;
    float operandA, operandB;
    std::string operation;
    stack.reverse();

    while(!stack.empty())
    {
        if(stack.top().compare(")") == 0 || stack.top().compare(")") == 0)
        {
            std::cout << "Invalid Equation. Program Terminated" << std::endl;
            exit(0);
        }

        else if (Operator(stack.top()))
        {
            operandA = eval_stack.top();
            eval_stack.pop();
            operandB = eval_stack.top();
            eval_stack.pop();
            operation = stack.top();
            stack.pop();
            result = Calculate(operandA, operandB, operation);
            eval_stack.push(result);
        }
        
        else{
            try
            {
                eval_stack.push(stof(stack.top()));
                stack.pop();
            }

            catch(std::exception e)
            {
                std::cout <<stack.top() << " Improper equation cannot be evaluated " << std::endl;
                exit(0);
            }
        }     
    }

    return eval_stack;
}


