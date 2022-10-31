# Classes, Objects and Access modifiers

### Class

A class is a logical entity used to define a new data type. A class is a user-defined type that describes what a particular kind of object will look like. A class contains variables(data members), methods, and constructors. Class is a blueprint or a set of instructions to build a specific type of object. It is a fundamental concept of Object-Oriented Programming which revolves around real-life entities. Class determines how an object will behave and what the object will contain.
Data encapsulation is supported with "class". The class consists of both data and functions. The data in a class is called a member, while _functions in the class are called methods_.

-   **Data Members:** The variables declared inside a class. They are also called **instance variables**.

-   **Methods:** A method is function inside a class. A method accepts parameters as arguments, manipulates these, and then produces an output when the method is called on an object.

-   **Constructor:** Constructors are special class functions that perform the initialization of every object. In C++, the constructor is automatically called when an object is created. It is a special method of the class because it **does not have any return type**. It has the same name as the class itself.

**Example of smartphone class**

```cpp
class smartphone {
    string model;
    int year_of_manufacture;
    bool _5g_supported;

    smartphone(string mod, int manu, bool _5g_supp)
    {
        model = mod;
        year_of_manufacture = manu;
        _5g_supported = _5g_supp;
    }

    void print_details()
    {
        cout << "Model : " << model << endl;
        cout << "Year of Manufacture : " << year_of_manufacture << endl;
        cout << "5g Supported : " << _5g_supported << endl;
    }
};
```

---

### Object

An object is an instance of a Class. It is an identifiable entity with some characteristics and behavior. To access the members defined inside the class, we need to create the object of that class. Objects are the basic units of object-oriented programming. It may be any real-world object like a person, chair, table, pen, animal, car, etc.

**Syntax to create an object in C++:**

```cpp
    class_name objectName;
```

**Syntax to create an object dynamically in C++:**

```cpp
    class_name * objectName = new class_name();
```

The class’s default constructor is called, and it dynamically allocates memory for one object of the class. The address of the memory allocated is assigned to the pointer, i.e., objectName.

**Example of creating an object**

```cpp
int main()
{
    // creating objects of smartphone class
    smartphone iphone("iphone 11", 2019, false);
    smartphone redmi("redmi note 11 t", 2021, true);
    smartphone oneplus("oneplus nord", 2020, true);

    // accessing class variables
    int iphone_manufacture_date = iphone.year_of_manufacture;
    bool redmi_support_5g = redmi._5g_supported;
    string oneplus_model = oneplus.model;

    // calling methods on objects
    iphone.print_details();
    redmi.print_details();
    oneplus.print_details();
}
```

---

### Access Specifier

Access Specifiers in a class are used to assign access to the class members. It sets some restrictions on the class members from accessing the outside functions directly.

There are three types of access specifiers in C++:

1. **Public:** **Accessed from anywhere**(inside and outside the class).

    ```cpp
    class person {
    public:
        string name;
    };
    ```

2. **Private: Only be accessed by the member function inside the class.**

    ```cpp
    class person {
    private:
        int fb_password;
    };
    ```

3. **Protected: The access level of a protected modifier is within the class and outside the class through child class(or subclass).If you do not make the child class, it cannot be accessed outside the class.**
    ```cpp
    class person {
    protected:
        string assets;
    };
    ```

-   **By default**, in C++, all class members are **private** if you don't specify an access specifier.

### Scope Table

| Access Specifier | Inside class | Child (or sub-class) | Outside class |
| :--------------: | :----------: | :------------------: | :-----------: |
|      Public      |      ✅      |          ✅          |      ✅       |
|     Private      |      ✅      |          ✅          |      ❌       |
|    Protected     |      ✅      |          ❌          |      ❌       |

### Interview Questions

-   All [Interview Questions](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/265025/offering/3625237) are in the linked article.

### References

-   [Codestudio - Classes, Objects and Access modifiers](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/265025/offering/3625221)
