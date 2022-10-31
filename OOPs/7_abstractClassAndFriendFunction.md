# Abstract class and friend function

### Virtual functions

-   A virtual function is a member function in the base class that **we expect to redefine in derived classes**. It is declared using the virtual keyword. A virtual function is used in the base class to ensure that the function is overridden. This especially applies to cases where a pointer of base class points to a derived class object.
-   C++ determines which function is invoked at the runtime based on the type of object pointed by the base class pointer when the function is made virtual.
-   Virtual function mainly used to achieve **run time polymorphism**.

```cpp
class Base {
public:
    virtual void print()
    {
        cout << "Base Function" << endl;
    }
};
class Derived : public Base {
public:
    void print()
    {
        cout << "Derived Function" << endl;
    }
};
int main()
{
    Derived derived1;
    // pointer of Base type that points to derived1
    Base* base1 = &derived1;
    // calls member function of Derived class
    base1->print();
    return 0;
}
// Output :
// Derived Function
```

### Pure virtual functions

-   A pure virtual function is a virtual function in C++ for which we need not write any function definition and only have to declare it. It is declared by assigning 0 in the declaration.
-   A pure virtual function (or abstract function) in C++ is a virtual function for which we can implement, But we must override that function in the derived class; otherwise, the derived class will also become an abstract class.

```cpp
class A {
public:
    virtual void s() = 0;
    // Pure Virtual Function
};
```

### Abstract class

-   Abstract classes can’t be instantiated, i.e., we cannot create an object of this class. However, we can derive a class from it and instantiate the object of the derived class. An Abstract class **has at least one pure virtual function**.
-   If we do not override the pure virtual function in the derived class, then the derived class also becomes an abstract class.
-   We cannot create objects of an abstract class. However, we can derive classes from them and use their data members and member functions (except pure virtual functions).

**Properties of the abstract classes:**

-   It can have normal functions and variables along with pure virtual functions.
-   Prominently used for upcasting(converting a derived-class reference or pointer to a base-class. In other words, upcasting allows us to treat a derived type as a base type), so its derived classes can use its interface.
-   If an abstract class has a derived class, they must implement all pure virtual functions, or they will become abstract.

```cpp
class Base {
public:
    virtual void s() = 0; // Pure Virtual Function
};

class Derived : public Base {
public:
    void s(){
        cout << "Virtual Function in Derived_class";
    }
};

int main()
{
    Base* b;
    Derived d_obj;
    b = &d_obj;
    b->s();
}
// Output
// Virtual Function in Derived_class
```

### Friend function

-   A friend function is a function that is not a member of a class but has access to its private and protected members. It is declared using the keyword friend.
-   The function can be defined anywhere in the program like a normal C++ function. The function definition does not use either the keyword friend or scope resolution operator.

```cpp
class class_name {
    friend data_type function_name(argument);
    // syntax of friend function.
};
```

-   Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

```cpp

class Rectangle {
private:
    int length;

public:
    Rectangle() {
        length = 10;
    }
    friend int printLength(Rectangle); // friend function
};

int printLength(Rectangle b)
{
    b.length += 10;
    return b.length;
}

int main()
{
    Rectangle b;
    cout << "Length of Rectangle: " << printLength(b) << endl;
    return 0;
}
// Output :
// Length of Rectangle : 20
```

**Characteristics of friend function:**

-   A friend function can be declared in the private or public section of the class.
-   **It can be called a normal function without using the object**.
-   A friend function is not in the scope of the class, of which it is a friend.
-   A friend function is not invoked using the class object as it is not in the class’s scope.
-   A friend function cannot access the private and protected data members of the class directly. It needs to make use of a class object and then access the members using the dot operator.
-   A friend function **can be a global function or a member of another class**.

### Interview Questions

-   [Interview Questions](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274161/offering/3757653)

### Resources

-   [Abstract class and friend function](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274161/offering/3757650)
