#pragma once 

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

namespace library{

    class book
    {
    private:
        string *title;
        int pages;
        string *author = nullptr;
        float rating;
        string editorial;
        friend ostream& operator<<(ostream& os, const book& b);
    public:


        // todo ~ DEFAULT CONSTRUCTOR -> 0 args

        book() : title{nullptr}{
            cout<<"default constructor\n";
            this->editorial = "Penguin Books\n";
        }

        // todo ~ PARAMETERIZED CONSTRUCTOR pair<string, string>";
        book(string _title, string _author) : title{new string(_title)}{
            cout<<"parameterized constructor\n";
            author = new string(_author);
        }

        // todo ~ PARAMETERIZED CONSTRUCTOR pair<string, string>";

        book(const pair<string, string>& pair){
            cout<<"parameterized constructor pair<float, float>\n";
            // destructuring 
            auto [a, t] = pair;
            // cout<<"Author: " << a << " " << "Title: " << t << endl;
            author = new string(a);
            title = new string(t);
        }

        // todo ~ COPY CONSTRUCTOR
        book(book& other){
            
            cout<<"copy constructor\n";

            if (other.author != nullptr)
                this->author = new string(*other.author);
            else    
                this->author = nullptr;
            
            if(other.title)
                title = new string(*other.title);
            else    
                title = nullptr;
        }

        // todo ~ COPYT ASSINGMENT OPERATOR
        book& operator=(book& other){
            
            cout<<"copy assignment operator\n";

            if (other.author != nullptr)
                this->author = new string(*other.author);
            else    
                this->author = nullptr;
            
            if(other.title)
                title = new string(*other.title);
            else    
                title = nullptr;
            
            book& aux = *this; // se retorna a si mismo
            // ! A TI MISMO ES A QUIEN LE COPIAS LOS VALORES (A QUIEN SE LOS DAS)
            return aux;
        }

        // todo ~ MOVE CONSTRUCTOR
        book(book&& other){
            
            cout<<"move constructor\n";

            if(other.author){
                author = other.author;
                other.author = nullptr;
            }
            else    
                this-> author = nullptr;
            
            if(other.title){
                title = other.title;
                other.title = nullptr;
            }
            else
                this-> title = nullptr;

        }

        // todo ~ MOVE ASSINGMENT CONSTRUCTOR
        book& operator=(book&& other){

            cout<<"move assignment constructor\n";

            if(other.author){
                author = other.author;
                other.author = nullptr;
            }
            else    
                this-> author = nullptr;
            
            if(other.title){
                title = other.title;
                other.title = nullptr;
            }
            else
                this-> title = nullptr;

            return *this;

        }

        ~book(){
            cout<<"destructor\n";
            if (author != nullptr)
                delete author, author = nullptr;
            if (title)
                delete title, title = nullptr;
        };
    };

    ostream& operator<<(ostream& os, const book& b){
        os << "{ ";
        if(b.author) os << "Author: " << *b.author << " | " << " Memory Address: " << b.author << endl; 
        else os << "no data found" << endl;

        if(b.title) os << "  Title: " << *b.title << " | " << " Memory Address: " << b.title; 
        else os << "  no data found";
        os << " }" << endl;
        return os;
    }

}