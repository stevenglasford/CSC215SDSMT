////////////////////////////////////////////////////////////////////
//                 Evaluate Prefix                                //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool valid_prefix(char p[]);
int end_pre(char p[], int first, int last);
bool identifier(char ch);
bool is_operator(char ch);
void evaluate_prefix(char p[], int &index, int &result);
int value(char ch);
int do_op(int left, char op, int right);


////////////////////////////////////////////////////////////////////
//                    main                                        //
////////////////////////////////////////////////////////////////////
void main()
{
   int  index;
   char p[100];
   int  result;

   cout << "Enter prefix expression: ";
   cin >> p;
   index = 0;
   
   if (valid_prefix(p))
   {
      evaluate_prefix(p, index, result);
      cout << "Result is: " << result << endl;
   }
   else
      cout << "*** Invalid prefix expression ***" << endl;
}

////////////////////////////////////////////////////////////////////
//                 valid_prefix                                   //
////////////////////////////////////////////////////////////////////
bool valid_prefix(char p[])
{
   char last_char;
   int  size;

   size = (int) strlen(p);

   // get the position of the last character of a valid prefix
   last_char = end_pre(p, 0, size - 1);
  
   // make sure the index of last character is a valid index
   // and that it matches the position of the ending character
   if (last_char >= 0 && last_char == size - 1)
      return true;
   else
      return false;
}

////////////////////////////////////////////////////////////////////
//                 end_pre                                        //
////////////////////////////////////////////////////////////////////
int end_pre(char p[], int first, int last)
{
   int first_end;

   // is the first position valid
   if ((first < 0) || (first > last))
      return -1;

   if (identifier(p[first]))
      return first;

   if (is_operator(p[first]))
   {
      // Get the end of the first valid prefix
      first_end = end_pre(p, first + 1, last);

      // if Valid end, get the end of the next valid previx
      if (first_end > -1)
         return end_pre(p, first_end + 1, last);
   }
   return -1;

}

////////////////////////////////////////////////////////////////////
//                 identifier                                     //
////////////////////////////////////////////////////////////////////
bool identifier(char ch)
{
   //if ((ch >= '0') && (ch <= '9'))
   if ( isdigit(ch) )
      return true;  // true
   else
      return false;  // false
}

////////////////////////////////////////////////////////////////////
//                 operator                                       //
////////////////////////////////////////////////////////////////////
bool is_operator(char ch)
{
   if (strchr("+-*/", ch) != nullptr)
      return true;  // true
   else
      return false;  // false
}

////////////////////////////////////////////////////////////////////
//                 evaluate_prefix                                //
////////////////////////////////////////////////////////////////////
void evaluate_prefix(char p[], int &index, int &result)
{
   char ch;
   int  operand_1;
   int  operand_2;

   ch = p[index];
   index++;

   if (identifier(ch))
      result = value(ch);
   else
   {
      evaluate_prefix(p, index, operand_1);
      evaluate_prefix(p, index, operand_2);
      result = do_op(operand_1, ch, operand_2);
   }
}

////////////////////////////////////////////////////////////////////
//                 value of identifier                            //
////////////////////////////////////////////////////////////////////
int value(char ch)
{
   return ch - '0';
}

////////////////////////////////////////////////////////////////////
//  do_op : Perform the operation : +, -, *, /                    //
////////////////////////////////////////////////////////////////////
int do_op(int left, char op, int right)
{
   switch (op)
   {
      case '+' : return left + right;
      case '-' : return left - right;
      case '/' : return left / right;
      case '*' : return left * right;
      default  : cout << "Invalid Operation Call " << left 
                      << '"' << op << '"' << right << endl;
                 exit(0);
   }
}
