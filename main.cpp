#include <iostream>

using namespace std;

bool is_letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);
void Lexical(string str);

int main()
{
    string input;
    cout<<" Ad-Hoc LEXICAL ANALYSER FOR C++"<<endl<<endl;
    cout<<" C++ which generates the token for the following categories:"<<endl<<"� Keywords"<<endl<<"� Identifiers"<<endl;
    cout<<"� Operators"<<endl<<"� Numeric constants"<<endl<<"� Character constants"<<endl;
    cout<<"� Punctuations "<<endl<<"� Special Symbols"<<endl;
     cout<<" "<<endl<<endl;
    cout<<"Enter the string"<<endl<<endl;
    getline(cin,input);
    //cout<<input<<endl;
    cout<<" "<<endl<<endl;
    Lexical(input);
    return 0;
}

bool is_letter(char ch)
{
    if (ch>='a' && ch<='z' )
        return true;
    else
        return false;
}
bool is_Digit(char ch)
{
    if (ch>='0' && ch<='9')
        return true;
    else
        return false;
}
bool is_Delimeter(char ch)
{
if (ch==' '|| ch=='\t'|| ch=='\n')
        return true;
    else
        return false;
}
void Lexical(string str)
{
    int state=0;
    int i=0;
    string lexeme="";
    int flag=1;
    char c='\0';

    while(str[i]!='\0')
    {
            c=str[i];
            flag=1;
            switch(state)
            {
                case 0:
                    if(is_letter(c))
                    {
                        state=1;

                    }
                    else if(is_Digit(c))
                    {
                        state=2;

                    }
                    else if(c=='"')
                    {
                        state=0;
                          lexeme=c;
                        cout<<" Tokken< "<<"  Operators , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                    else if(c=='-')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken<  "<<"  Operators , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                    else if(c=='*')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken< "<<"  Operators , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                    else if(c=='%')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken< "<<"  Operators , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                     else if(c=='=')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken< "<<"  Operators , "<<lexeme<<" >"<<endl;


                    }
                    else if(c==';')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken< "<<"  Special Symbols , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                    else if(c=='<')
                    {
                        state=3;
                    }
                    else if(c=='{')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken<  "<<"  Special Symbols  , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                    else if(c=='}')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken< "<<"  Special Symbols  , "<<lexeme<<" >"<<endl;
                        lexeme="";

                    }
                    else if(c=='{')
                    {
                        state=0;
                        lexeme=c;
                        cout<<" Tokken<  "<<"  Special Symbols , "<<lexeme<<" >"<<endl;
                        lexeme="";


                    }
                    else if(is_Delimeter(c))
                    {
                        flag=0;

                    }
                    else
                    {
                        cout<<"Invalid Tokken   Invalid Tokken  Invalid Tokken  Invalid Tokken "<<endl;
                        break;
                    }

                    break;

                    case 1:
                            if(!(is_letter(c) || is_Digit(c)))
                            {
                                state=0;
                                    if(lexeme=="int" || lexeme=="float" || lexeme=="string"|| lexeme=="char"|| lexeme=="double")
                                    {
                                        cout<<" Tokken   < "<<"Keywords, "<<lexeme<<" >"<<endl;
                                    }
                                    else if(lexeme=="include" || lexeme=="main" || lexeme=="cout"|| lexeme=="asm")
                                    {
                                        cout<<" Tokken   < "<<"Keywords, "<<lexeme<<" >"<<endl;
                                    }
                                    else if(lexeme=="void" || lexeme=="return" || lexeme=="getch"|| lexeme=="continue")
                                    {
                                        cout<<" Tokken   < "<<"Keywords, "<<lexeme<<" >"<<endl;
                                    }
                                    else if(lexeme=="if" || lexeme=="for" || lexeme=="while"|| lexeme=="do while")
                                    {
                                        cout<<" Tokken   < "<<"Keywords, "<<lexeme<<" >"<<endl;
                                    }
                                    else if(lexeme=="switch" || lexeme=="private" || lexeme=="protected"|| lexeme=="public")
                                    {
                                        cout<<" Tokken   < "<<"Keywords, "<<lexeme<<" >"<<endl;
                                    }
                                    else
                                    {
                                        cout<<" Tokken   < "<<" Character constants , "<<lexeme<<" >"<<endl;
                                    }
                                    lexeme="";
                                        continue;
                            }
                          break;
                            case 4:
                            if(!(is_Digit(c)))
                            {
                                state=0;

                                    {
                                        cout<<" Tokken   < "<<"Identifiers , "<<lexeme<<" >"<<endl;
                                    }
                                    lexeme="";
                                        continue;
                            }
                          break;
                 case 2:
                    if(!is_Digit(c))
                    {
                        state=0;
                        cout<<" Tokken<  "<<"  Numeric constants  , "<<lexeme<<" >"<<endl;
                         lexeme="";
                         continue;
                    }
                    break;

                 case 3:
                     if(c=='=')
                     {
                         state=0;
                        cout<<" Tokken   < "<<" Operators , "<<lexeme<<" >"<<endl;
                         lexeme="";
                     }
                     else
                        {
                          state=0;
                        cout<<" Tokken   < "<<"  LT , "<<lexeme<<" >"<<endl;
                         lexeme="";
                         continue;
                        }
                    break;
            }

            lexeme=lexeme+c;

        i++;
         }
        }

