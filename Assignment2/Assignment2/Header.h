//#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

template <typename T>
struct node {
    T data;
    node<T>* next;

    node()
    {
        
        next = NULL;
    }


};

template <typename T>
class stack {

    int SIZE;
    node<T>* top;
public:
    stack() {
        //top=-1;
        SIZE = 0;
        top = NULL;
    }


    node<T>* Peek()
    {
        return top;
    }

    T Top()
    {
        return top->data;
    }

    void push(T element) {
        node<T>* temp = new node<T>;
        temp->data = element;
        if (!isEmpty())
        {
            temp->next = top;
            top = temp;
            temp = NULL;
            delete temp;
        }
        else
        {
            top = temp;
            temp = NULL;
            delete temp;
        }        
        SIZE++;
    }



    T pop()
    {
        if (!isEmpty())
        {
            node<T>* del = top;
            top = top->next;
            T element = del->data;
            SIZE--;
            delete del;
            return element;
        }
        else
        {
            cout << "\nSuccessfully emptied\n";
        }

    }

    int sizeofstack()
    {
        return SIZE;
    }

    bool isEmpty()
    {
        if (SIZE == 0)
            return true;
        return false;
    }

    void display()
    {
        if (!isEmpty())
        {
            node<T>* temp = top;

            displaystack(temp);
        }
        else
        {
            cout << "\nCode run Successfully!\n";
        }
    }



    void displaystack(node<T>* n)
    {
        if (n->next != NULL)
        {
            displaystack(n->next);
        }
        cout << " " << n->data << endl;

    }

    void clear()
    {
        if (!isEmpty())
        {
            pop();
        }
    }

    ~stack()
    {
        while (top != NULL)
        {
            node<T>* del = top;
            top = top->next;
            delete del;
            del = NULL;
        }
        delete top;
        top = NULL;
    }
};

stack<char> postfixexp(string exp)
{
    stack<char> outputStack;
    string Output;
    for (int i = 0; i < exp.length(); i++)
    {
        int a = exp[i];

        if ((a > 64 && a < 91) || (a > 96 && a < 123))
        {
            Output += exp[i];
        }

        else if (a == 40)
        {
            outputStack.push(exp[i]);
        }

        else if (a == 41)
        {

            while (outputStack.isEmpty() != true)
            {
                char op = outputStack.pop();
                int a = op;

                if (a == 40)
                {
                    break;
                }
                else
                {
                    Output += op;
                }

            }

        }
        else if (exp[i] == '*' || exp[i] == '/')
        {
            outputStack.push(exp[i]);
        }
        else if (exp[i] == '-' || exp[i] == '+')
        {
            char op = outputStack.Top();

            if (op == '*' || op == '/' || op == '+' || op == '-')
            {
                Output += outputStack.pop();
                outputStack.push(exp[i]);

            }
            else
            {
                outputStack.push(exp[i]);
            }
        }


    }

    while (outputStack.isEmpty() != true)
    {
        Output += outputStack.pop();
    }

    return outputStack;
}

void writeHead(string line)
{
    string path = "Assignment2_Materials/Output_files/Result-1.txt";
    fstream file;
    file.open(path, ios::app);
    file << "\t\t";

    int k = 0;

    for (; k < line.length(); k++)
    {
        if (line[k] != '\t')
        {
            //file.open(path, ios::app);
            if (line[k] == '|' && line[k + 1] == '\\')
            {
                k++;
                while (line[k] != '|')
                {
                    k++;
                }

            }
            else if (line[k] == '|' && line[k + 1] != '\\' && line[k + 1] != ' ' && line[k + 1] != '.')
            {
                k++;
                while (line[k] != '|')
                {
                    k++;
                }
            }
            if (line[k] != '|')
                file << line[k];
        }
    }

}

void writePara(string line)
{
    string path = "Assignment2_Materials/Output_files/Result-1.txt";
    fstream file;
    if (line == "\t|\\paragraph|")
        return;
    file.open(path, ios::app);
    
    int k = 0;
    for (; k < line.length(); k++)
    {
        if (line[k] != '\t')
        {
             //file.open(path, ios::app);
            if (line[k] == '|' && line[k + 1] == '\\')
            {
                k++;
                while (line[k] != '|')
                {
                    k++;
                }
                
            }
            else if (line[k] == '|' && line[k + 1] != '\\' && line[k + 1] != ' ' && line[k + 1] != '.')
            {
                    k++;
                while (line[k] != '|')
                {
                    k++;
                }
            }
            if(line[k]!='|')
                file << line[k];
        }
    }
    file << endl;
    

}

void writeTab()
{   
    string path = "Assignment2_Materials/Output_files/Result-1.txt";
    fstream file;
    file.open(path,ios::app);
    file << '\t';
}

void parseFile(string path)
{
    string statement, line;
    stack<char> tags;
    fstream file;
    bool startTag = false, headTag = false, paragraphTag = false, tabTag=false, priorityTag=false, preTag=false, postTag=false, solTag=false, funTag=false, srcTag=false;  //src is ImgDisp
    int j = 0;
    int c = 0;
    file.open(path, fstream::in);
    if (!file)
    {
        cout << "\nFile is not open\n";
    }
    /*
        Start ke true honay par file create karni hai or phir usko create karne e baad usme pehle poora text paas kara kar phir uske andar parse karke hum 
        tags identify karsakte or phir usko  hum tags ki precedence ko use karke same chee karsakte par idhr hum parsing through string karein gay or phir
        us string me tags identify karke usko edit karein gay, after that we will enter that string into a text file.
    */
    else
    {
        cout << "hey" << endl;
        int linenum = 1;
        
        while (getline(file,line))
        {
            int i = 0;
            int length = 0,counter=0;
            if (paragraphTag)
            {
                writePara(line);
            }
            while (line[counter]!='\0')
            {
                
                length++;
                counter++;
            }
          //cout << "hey" << endl;
            for (; i < length; i++)
            {
               // cout << "1 : " << line[i] << " 2: " << line[i + 1] << endl;
                if(line[i] == '|' && line[i + 1] != '\\' && line[i+1]!=' '&& line[i+1]!='.')
                {
                    bool flag = false;

                    for (int k = i+1; k < length; k++)
                    {
                        if (line[k] == '|')
                        {
                            flag = true;
                        }
                    }
                    if (flag)
                    {
                        /*if (paragraphTag)
                        {
                            writePara(line);
                        }*/

                        flag = false;
                        if (line[i + 1] == 's' && line[i + 3] == 'a')   //start
                        {
                            startTag = true;
                            flag = true;
                        }
                        if (line[i + 1] == 'h' && line[i + 3] =='a')     //head
                        {
                            headTag = true;
                            string str = line;
                            getline(file, str);
                            writeHead(str);
                            flag = true;

                        }
                        if (line[i + 1] == 't' && line[i + 3]== 'b')     //tab
                        {
                            tabTag = true;
                            writeTab();
                            flag = true;
                        }
                        if (line[i + 1] == 'p' && line[i + 3] == 'r')       //paragraph
                        {
                            paragraphTag = true;
                            writePara("");
                            /**/
                            flag = true;
                        }
                        if (line[i + 1] == 'p' && line[i + 3] == 'i')       //priority
                        {
                            priorityTag = true;
                            flag = true;
                        }
                        if (line[i + 1] == 'p' && line[i + 3] == 'e')       //prefix
                        {
                            preTag = true;
                            flag = true;
                            //paragraphTag = false;

                        }
                        if (line[i + 1] == 'p' && line[i + 3] == 's')       //postfix
                        {
                            postTag = true;
                            flag = true;
                            //paragraphTag = false;
                        }
                        if (line[i + 1] == 's' && line[i + 3] == 'l')       //sol_exp
                        {
                            solTag = true;
                            flag = true;
                        }
                        if (line[i + 1] == 'f' && line[i + 3] == 'n')       //Function
                        {
                            srcTag = true;
                            flag = true;
                        }
                        if (line[i + 1] == 's' && line[i + 3] == 'c')       //src
                        {
                            srcTag = true;
                            flag = true;
                        }

                        

                        if (!flag)
                        {
                            paragraphTag = true;
                            for (; i < length; i++)
                            {
                                if (line[i] == '|')
                                    break;
                            }
                            flag = true;
                        }

                        if (flag && startTag)
                        {
                            tags.push('|');
                            i += 2;
                            cout << "\n Pushed \n";
                            cout << "legth is : " << length << endl;
                            cout << "line num is : " << linenum << endl;
                            cout << "i num is : " << i << endl;


                            //tags.display();
                            //cout <<"line was : \n"<<line << "\n Length was: " << length << endl;
                        }
                    }
                    
                }
                if (line[i] == '|' && line[i + 1] == '\\')
                {
                    bool flag = false;
                    for (int k = i + 1; k < length; k++)
                    {
                        if (line[k] == '|')
                        {
                            flag = true;
                        }
                    }
                    if (flag && startTag)
                    {

                        flag = false;

                        if (line[i + 2] == 's' && line[i + 4] == 'a')   //start
                        {
                            startTag = false;
                            flag = true;

                        }
                        if (line[i + 2] == 'h'  && line[i + 4] == 'a')     //head
                        {
                            headTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 't' && line[i + 4] == 'b')     //tab
                        {
                            tabTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 'p' && line[i + 4] == 'r')       //paragraph
                        {
                            paragraphTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 'p' && line[i + 4] == 'i')       //priority
                        {
                            priorityTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 'p' && line[i + 4] == 'e')       //prefix
                        {
                            preTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 'p' && line[i + 4] == 's')       //postfix
                        {
                            postTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 's' && line[i + 4] == 'l')       //sol_exp
                        {
                            solTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 'f' && line[i + 4] == 'n')       //Function
                        {
                            srcTag = false;
                            flag = true;
                        }
                        if (line[i + 2] == 's' && line[i + 4] == 'c')       //src
                        {
                            srcTag = false;
                            flag = true;
                        }

                        if (!flag)
                        {
                            paragraphTag = false;
                            flag = true;
                        }

                        if (flag)
                        {
                            tags.pop();
                            cout << "\n Popped \n";
                            cout << "legth is : " << length << endl;
                            cout << "line num is : " << linenum << endl;
                            cout << "i num is : " << i << endl;
                            
                            i += 2;
                        }

                        
                        //tags.display();

                    }

                }
            }
            
           linenum++;
        }
        
        if (tags.isEmpty()!=true)
        {
            cout << "\a \nSyntax Error! Tags are unbalanced\n";
        }
        else
        {
            tags.display();
        }
        fstream file;
        file.open("Assignment2_Materials/Output_files/Result-1.txt", ios::app);
        file << endl;
        
    }
    
}   


