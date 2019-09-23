////////////////////////////////////////////////////////////////////
//                 Evaluate Postfix                               //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool valid_postfix ( char p[] );
int end_post ( char p[], int first, int last );
bool identifier ( char ch );
bool is_operator ( char ch );
void evaluate_postfix ( char p[], int &index, int &result );
int value ( char ch );
int do_op ( int left, char op, int right );


////////////////////////////////////////////////////////////////////
//                    main                                        //
////////////////////////////////////////////////////////////////////
void main()
{
    int  index;
    char p[100];
    int  result = 0;
    
    cout << "Enter postfix expression: ";
    cin >> p;
    index = ( int ) strlen ( p ) - 1;
    
    if ( valid_postfix ( p ) )
    {
        evaluate_postfix ( p, index, result );
        cout << "Result is: " << result << endl;
    }
    else
    {
        cout << "*** Invalid postfix expression ***" << endl;
    }
}

////////////////////////////////////////////////////////////////////
//                 valid_postfix                                  //
////////////////////////////////////////////////////////////////////
bool valid_postfix ( char p[] )
{
    char last_char;
    int  size;
    
    size = ( int ) strlen ( p );
    
    // find the position of the last postfix expression(goes backwards)
    last_char = end_post ( p, size - 1, 0 );
    
    if ( last_char == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

////////////////////////////////////////////////////////////////////
//                 end_post                                       //
////////////////////////////////////////////////////////////////////
int end_post ( char p[], int first, int last )
{
    int first_end;
    
    if ( ( first < 0 ) )
    {
        return -1;
    }
    
    if ( identifier ( p[first] ) )
    {
        return first;
    }
    
    if ( is_operator ( p[first] ) )
    {
        // find position of the first postfix
        first_end = end_post ( p, first - 1, last );
        
        // if Valid, find position of the second postfix
        if ( first_end > -1 )
        {
            return end_post ( p, first_end - 1, last );
        }
    }
    
    return -1;
}

////////////////////////////////////////////////////////////////////
//                 identifier                                     //
////////////////////////////////////////////////////////////////////
bool identifier ( char ch )
{
    //   if ((ch >= '0') && (ch <= '9'))
    if ( isdigit ( ch ) )
    {
        return true;    // true
    }
    else
    {
        return false;    // false
    }
}

////////////////////////////////////////////////////////////////////
//                 operator                                       //
////////////////////////////////////////////////////////////////////
bool is_operator ( char ch )
{
    if ( strchr ( "+-*/", ch ) != nullptr )
    {
        return true;    // true
    }
    else
    {
        return false;    // false
    }
}

////////////////////////////////////////////////////////////////////
//                 evaluate_postfix                               //
////////////////////////////////////////////////////////////////////
void evaluate_postfix ( char p[], int &index, int &result )
{
    char ch;
    int  operand_1;
    int  operand_2;
    
    ch = p[index];
    index--;
    
    if ( identifier ( ch ) )
    {
        result = value ( ch );
    }
    else
    {
        evaluate_postfix ( p, index, operand_2 );
        evaluate_postfix ( p, index, operand_1 );
        result = do_op ( operand_1, ch, operand_2 );
    }
}

////////////////////////////////////////////////////////////////////
//                 value of identifier                            //
////////////////////////////////////////////////////////////////////
int value ( char ch )
{
    return ch - '0';
}

////////////////////////////////////////////////////////////////////
//  do_op : Perform the operation : +, -, *, /                    //
////////////////////////////////////////////////////////////////////
int do_op ( int left, char op, int right )
{
    switch ( op )
    {
        case '+' :
            return left + right;
        case '-' :
            return left - right;
        case '/' :
            return left / right;
        case '*' :
            return left * right;
        default  :
            cout << "Invalid Operation Call " << left
                 << '"' << op << '"' << right << endl;
            exit ( 1 );
    }
}
