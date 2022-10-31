# Constructors and Destructors

### Constructor

-   Special member function **automatically called when an object is created**.
-   Does not have any return type.
-   Has the same name as the class itself.
-   Initializes the class data members with garbage value if we don’t put any value to it explicitly.
-   must be placed in the public section of the class, because we want the class to be instantiated anywhere.
-   For every object in its lifetime constructor is **called only once at the time of creation**.

```cpp
class Class_name {
    int data_member1;
    string data_member2;
    // creating constructor
public:
    class_name() { }
};
```

### Types of Constructor

-   Default Constructor
-   Parameterized Constructor
-   Copy Constructor

1.  **Default Constructor**
    A constructor that doesn't take any argument or has no parameters is known as a default constructor

    ```cpp
    class Class_name {
        int data_member1;
        string data_member2;
    public:
        // default constructor
        class_name() {
            data_member1 = 0;
            data_member2 = "chetan";
        }
    };
    ```

2.  **Parameterized Constructor**
    This is another type of Constructor with parameters. The parameterized constructor takes its arguments provided by the programmer. These arguments help initialize an object when it is created.

    ```cpp
    class Class_name {
        int data_member1;
        string data_member2;
    public:
        // parameterized constructor
        class_name(int a, string b) {
            data_member1 = a;
            data_member2 = b;
        }
    };
    ```

3.  **Copy Constructor**
    These are a particular type of constructor that takes an object as an argument and copies values of one object’s data members into another object.
    ```cpp
    class Class_name {
        int data_member1;
        string data_member2;
    public:
        // copy constructor
        class_name(Class_name &obj) {
            // copies data of object parameter
            data_member1 = obj.data_member1;
            data_member2 = obj.data_member2;
        }
    };
    ```

### Constructor Overloading

Constructor overloading can be defined as the concept of having more than one constructor with different parameters so that every constructor can perform a different task.

```cpp
class Class_name {
    int data_member1;
    string data_member2;
public:
    // default constructor
    class_name() {
        data_member1 = 0;
        data_member2 = "chetan";
    }
    // parameterized constructor
    class_name(int a, string b) {
        data_member1 = a;
        data_member2 = b;
    }
    // copy constructor
    class_name(Class_name &obj) {
        // copies data of object parameter
        data_member1 = obj.data_member1;
        data_member2 = obj.data_member2;
    }
};
```

-   **NOTE:** Default constructor is available only till we don't create any constructor in the class. If we create any constructor then default constructor is not available, so total number of constructors in a class is equal to number of constructors we create in the class.

---

### Destructor

-   A destructor is a special member function that works just opposite to a constructor.
-   Unlike constructors that are used for initializing an object, destructors destroy (or delete) the object.
-   The purpose of the destructor is to free the resources that the object may have acquired during its lifetime.
    ```cpp
    ~class_name() {
        // body of destructor
    }
    ```
-   Like the constructor, the destructor name should exactly match the class name.
-   A destructor declaration should always begin with the tilde(~) symbol, as shown in the syntax above.
-   If the object is created by using new or the constructor uses new to allocate memory that resides in the heap memory or the free store, the destructor should use delete to free the memory.

### When Destructor is called?

-   Object goes out of scope.
-   When the program ends.
-   A scope (the { } parenthesis) containing local variable ends.
-   A delete operator is called.

### Destructor rules

-   The name should begin with a tilde sign(~) and match the class name.
-   There **cannot be more than one destructor** in a class.
-   Unlike constructors that can have parameters, **destructors do not allow any parameter**.
-   They **do not have any return type**, not even void.
-   A destructor should be **declared in the public section** of the class.
-   The programmer cannot access the address of the destructor.
-   When you do not specify any destructor in a class, the compiler generates a **default destructor** and inserts it into your code.
-   Destructors with the access modifier as private are known as **Private Destructors**. Whenever we want to control the destruction of an object, we can make the destructor private.

### Interview Questions

-   All [Interview Questions](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/266821/offering/3651492) are in the linked article.

### Resources

-   [Codestudio - Constructors and Destructors](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/266821/offering/3651488)
