# This pointer, shallow and deep copy

## This pointer

-   this pointer holds the address of the current object.
-   In simple words, you can say that **this pointer points to the current object of the class**.
-   This pointer is accessible within non-static member functions of a class. Static member functions do not have a this pointer.

This pointer can be used to,

-   refer to a current class instance variable.
-   pass the current object as a parameter to another method.
-   declare indexers.

**Example:**

```cpp
class mobile
{
    string model;
    int year_of_manufacture;

public:
    void set_details(string model, int year_of_manufacture)
    {
        this->model = model;
        this->year_of_manufacture = year_of_manufacture;
    }
    void print()
    {
        cout << this->model << endl;
        cout << this->year_of_manufacture << endl;
    }
};

int main()
{
    mobile redmi;
    redmi.set_details("Note 7 Pro", 2019);
    redmi.print();
}

// Output:
// Note 7 Pro
// 2019
```

---

### Shallow copy

-   An object is created by simply copying the data of all variables of the original object.
-   Both objects will reference the exact memory location, then change made by one will reflect those change in another object as well.
-   **Default copy constructor is a shallow copy constructor**.
-   It is not recommended to use shallow copy.
-   A shallow copy can be made by simply copying the reference.

    ```cpp
    class students()
    {
        int age;
        char* names; // names is a pointer to a char array

    public:
        students(int age, char* names)
        {
            this->age = age;
            // shallow copy
            this->names = names;
            // here we are putting the same array.
            // we are just copying the reference
        }
    };
    ```

### Deep copy

-   A deep copy is a copy of an object in which the copied object is completely independent of the original object.
-   Separate memory is allocated for the copied object. So changes made in any object will not affect the other object.
-   An object is created by **copying all the fields**, and it also **allocates similar memory resources with the same value to the object**.
-   To perform Deep copy, we need to** explicitly define the copy constructor** and **assign dynamic memory as well if required**. Also, it is necessary to allocate memory to the other constructors’ variables dynamically.

    ```cpp
    class student()
    {
        int age;
        char* names;

    public:
        student(int age, char* names)
        {
            this->age = age; // deep copy
            this->names = new char[strlen(names) + 1];
            strcopy(this->names, names);
            // Created new array and copied data
        }
    };
    ```

### Interview questions

-   [Interview questions](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274158/offering/3757643)

### Resources

-   [Codestudio - This pointer, shallow and deep copy](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274158/offering/3757641)
