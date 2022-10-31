# Pillars of OOPs

-   [Encapsulation](#encapsulation)
-   [Abstraction](#abstraction)
-   [Inheritance](#inheritance)
-   [Polymorphism](#polymorphism)

### Encapsulation

-   Encapsulation is about wrapping data and methods into a single class and protecting it from outside intervention.
-   The general idea of this mechanism is simple. For example, you have an attribute that is not visible from the outside of an object. You bundle it with methods that provide read or write access. Encapsulation allows you to hide specific information and control access to the object’s internal state.
-   It is achieved using access modifiers like public, private, protected.
-   Create **public member functions** to access private data members from **class object**.

### Abstraction

-   Abstraction is the process of hiding the implementation details from the user, only the functionality will be provided to the user. In other words, the user will have the information on what the object does instead of how it does it.

**Advantages Of Abstraction**

-   Only you can make changes to your data or function, and no one else can.
-   It makes the application secure by not allowing anyone else to see the background details.
-   Increases the reusability of the code.
-   Avoids duplication of your code

Encapsulation and Abstraction are two different concepts. Encapsulation is about binding the data and methods together into a single unit. Abstraction is about hiding the implementation details from the user.

### Inheritance

-   Inheritance is a mechanism in which one object acquires all the properties and behaviors of a parent object.
-   It allows us to create a new class (derived class) from an existing class (base class).
-   It is an important part of object-oriented programming and is used to achieve runtime polymorphism.
-   The existing class is called the base class, and the new class is referred to as the derived class.

**Syntax**

```cpp
class parent_class {
    // Body of parent class
};
class child_class : access_modifier_parent_class {
    // Body of child class
};
```

#### Modes of inheritance

1. **Public Inheritance:** If we derive a subclass from a public base class. Then, the base class’s public members will become public in the derived class, and protected class members will become protected in the derived class.
2. **Protected Inheritance:** If we derive a subclass from a protected base class. Then, the base class’s both public and protected members will become protected in the derived class.
3. **Private Inheritance:** If we derive a subclass from a private base class. Then, the base class’s both public and protected members will become private in the derived class.

| Base Class Member Access Specifier | Public         | Protected      | Private        |
| :--------------------------------- | :------------- | :------------- | :------------- |
| Public                             | Public         | Protected      | Private        |
| Protected                          | Protected      | Protected      | Private        |
| Private                            | Not Accessible | Not Accessible | Not Accessible |

#### Types of Inheritance

1. [Single Inheritance](#single-inheritance)
2. [Multilevel Inheritance](#multilevel-inheritance)
3. [Multiple Inheritance](#multiple-inheritance)
4. [Hierarchical Inheritance](#hierarchical-inheritance)
5. [Hybrid Inheritance](#hybrid-inheritance)

##### 1. Single Inheritance

In single inheritance, one class can extend the functionality of another class. There is only one parent class and one child class in single inheritances.

##### 2. Multilevel Inheritance

When a class inherits from a derived class, and the derived class becomes the base class of the new class, it is called multilevel inheritance. In multilevel inheritance, there is more than one level

##### 3. Multiple Inheritance

In multiple inheritance, one class can inherit the properties of more than one class. There is only one child class and more than one parent class in multiple inheritances.

##### 4. Hierarchical Inheritance

In hierarchical inheritance, more than one derived class is created from a single base class. There is only one parent class and more than one child class in hierarchical inheritances.

##### 5. Hybrid Inheritance

Hybrid inheritance is a combination of more than one type of inheritance.


### Polymorphism

-   Polymorphism is the ability of an object to take on many forms.

**Types of Polymorphism**
1. [Compile Time Polymorphism](#compile-time-polymorphism)
2. [Run Time Polymorphism](#run-time-polymorphism)

##### 1. Compile Time Polymorphism

-   Compile time polymorphism is also known as static polymorphism.
-   It is achieved by function overloading or operator overloading.
-   Function overloading is a technique in which more than one function can have the same name but different parameters.
-   Operator overloading is a technique in which we can change the behavior of an operator.

##### 2. Run Time Polymorphism

-   Run time polymorphism is also known as dynamic polymorphism.
-   It is achieved by function overriding.
-   Function overriding is a technique in which we can change the behavior of a function in the child class.

### Interview Questions
- [Interview Questions](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274159/offering/3757649)

### References

-   [Pillers of OOPs](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/274159/offering/3757644)