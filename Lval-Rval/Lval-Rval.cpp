#include <iostream>
#include <assert.h>

// GetValue() returns an rvalue.
int getValue()
{
    return 10;
}

// betVal() returns an int reference, lvalue.
int& getVal()
{
    // Since GetVal is now returning an lvalue, storage
    // must be made for the value.
    static int value = 10;
    return value;
}

// setValue takes an lvalue reference
void setValue(int& value) {}

// Overload
void setValue(const int& value) {}

// lvalue reference
// This is a way to easily tell if a value is an
// lvalue or a temporary value. If the argument works
// without the const modifier in the parameter then it
// is an lvalue. If it does not, then its an rvalue.
void printName(std::string& name)
{
    std::cout << name << "\n\n";
}

void printName(const std::string& name)
{
    std::cout << name << "\n\n";
}

// rvalue reference only accepts rvalues.
void printRName(std::string&& name)
{
    std::cout << "Rvalue reference: " << name << "\n\n";
}

int main()
{
    // Returning temporary object, rvalue.
    int i = getValue();
    assert(i == 10);

    // A value can be assigned directly to the function since
    // it is an lvalue reference.
    getVal() = 20;
    assert(getVal() == 20);

    // setValue takes an lvalue reference.
    int x = 20;
    setValue(x);
    // setValue(10);    Will not work, must pass lvalue.

    // You cannot have an lvalue reference an rvalue
    // unless its a const. You can do this to allow
    // a function to accept both types of data.
    // Notice, an rvalue can now be passed to setValue().
    // It has to be const due to it being temporary.
    const int& y = 30;
    setValue(30);

    std::string foo = "foo";
    std::string bar = "bar";
    
    // foo and bar are both lvalues.
    std::string foobar = foo + " " + bar;
    printName(foo);
    printName(bar);

    // printName("foo");    Will not work, must pass lvalue.
    // change parameter to const, can now pass
    // temporary value.
    printName("Lorem");
}