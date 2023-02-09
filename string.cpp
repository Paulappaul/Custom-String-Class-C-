#include <iostream>
#include <cstring>

class String{
     public:
     
    String(const char* input_string)

        {

        array_size = strlen(input_string); // we use a C Function to detect how long our string is
        char_buffer = new char[array_size +1]; // we create an array of characters at the length of input, +1 is for our NULL CHARACTER
         for(int i=0; i < array_size +1 ; i++ ){    // iterate over the array copying the input to the buffer.
            char_buffer[i] = input_string[i];
        }
        //memcpy(char_buffer, input_string, array_size ); Faster alternative. 

        }

    String(const String& copy)              // COPY CONSTRUCTOR: we create a copy an instance of the String Class, by passing it a refrence to another instance
        : array_size(copy.array_size)       // we intialize the array size to the copies array size

        {

            char_buffer = new char[array_size +1];
            for(int i=0; i < array_size + 1; i++){
                char_buffer[i] = copy.char_buffer[i];
            }
          //alternatively: memcpy(char_buffer, copy.char_buffer, array_size+1);    This is much faster, as it dumps the entire stream rather then iterating element by element. 

        }

    char& operator[](const unsigned int index) // allows for use of the [] operator to access specific elements of the array.
     {
            return char_buffer[index];
     }
    
    ~String(){
        delete char_buffer; // deletes our new memory allocations. 
    }

     friend std::ostream& operator <<(std::ostream& stream, const String&); // this will allow the function below to access private member variable ex. char_buffer

     private:
     char* char_buffer; // this will store the characters we input.
     unsigned int array_size; // this will keep track how many characters we input.
};

std::ostream& operator<<(std::ostream& stream, const String& string){ // definines an overloaded function for operator<<(), allowing our String to be outputted on the stream using std::cout

    stream << string.char_buffer;
    return stream;
}

int main(){

    String name = "Paul";
    std::cout << name << std::endl;

    String copy = name;

    copy[1] = 'C';
    std::cout << copy;

    return 0;
}

