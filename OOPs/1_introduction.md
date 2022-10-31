# Introduction to OOPs

### Definition

Object-Oriented Programming is basically a programming style that we used to follow in modern programming. It primarily revolves around classes and objects. Object-Oriented programming or OOPs refers to the language that uses the concept of class and object in programming.

### Class

A class is a logical entity used to define a new data type. A class is a user-defined type that describes what a particular kind of object will look like. Thus, a class is a template or blueprint for an object. A class contains variables, methods, and constructors.

**Syntax:**

```cpp
class class_name {
    // class body
    // properties 1
    // methods
};
```

### Object

An object is an instance of a Class. It is an identifiable entity with some characteristics and behavior. Objects are the basic units of object-oriented programming. It may be any real-world object like a person, chair, table, pen, animal, car, etc.

**Syntax to create an object in C++:**

```cpp
    class_name objectName;
```

**Syntax to create an object dynamically in C++:**

```cpp
    class_name * objectName = new class_name();
```

The class’s default constructor is called, and it dynamically allocates memory for one object of the class. The address of the memory allocated is assigned to the pointer, i.e., objectName.

**Creating a class Animal and objects mammal, amphibian and bird:**

```cpp
// creating Animal class
class Animal {
public:
    bool gives_birth;
    bool lay_egg;
    bool live_in_ground;
    bool live_in_water;
    bool have_wings;
};

int main()
{
    // creating an object of animal class
    Animal mammal;
    mammal.gives_birth = true;
    mammal.lay_egg = false;
    mammal.live_in_ground = true;
    mammal.live_in_water = false;
    mammal.have_wings = false;

    Animal amphibian;
    amphibian.gives_birth = false;
    amphibian.lay_egg = true;
    amphibian.live_in_ground = true;
    amphibian.live_in_water = true;
    amphibian.have_wings = false;

    Animal bird;
    bird.gives_birth = false;
    bird.lay_egg = true;
    bird.live_in_ground = true;
    bird.live_in_water = false;
    bird.have_wings = true;
}
```

### Features of OOPs:

Four major object-oriented programming features make them different from non-OOP languages:

-   **Abstraction** is the property by virtue of which only the essential details are displayed to the user.
-   **Inheritance** allows you to create class hierarchies, where a base class gives its behavior and attributes to a derived class.
-   **Polymorphism** ensures that it will execute the proper method based on the calling object’s type.
-   **Encapsulation** allows you to control access to your object’s state while making it easier to maintain or change your implementation at a later date.

### Need of object-oriented programming?

-   To make the development and maintenance of projects more effortless.
-   To provide the feature of data hiding that is good for security concerns.
-   We can solve real-world problems if we are using object-oriented programming.
-   It ensures code reusability.
-   It lets us write generic code: which will work with a range of data, so we don't have to write basic stuff over and over again.

### Resource

-   [Codestudio - Introduction to oops.](https://www.codingninjas.com/codestudio/guided-paths/oops-in-c/content/238489/offering/3210642)
