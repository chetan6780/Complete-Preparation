### Complex Number Class

```cpp
class ComplexNumbers {
private:
    int real;
    int imaginary;

public:
    ComplexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers const& c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }

    void multiply(ComplexNumbers const& c2)
    {
        int temp = this->real;
        this->real = this->real * c2.real - this->imaginary * c2.imaginary;
        this->imaginary = temp * c2.imaginary + this->imaginary * c2.real;
    }
    void print()
    {
        cout << this->real << " + i" << this->imaginary << endl;
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }
}
```

### Polynomial Class

```cpp
#include <bits/stdc++.h>
using namespace std;

class Polynomial {
public:
    int* degCoeff;
    int capacity;

    Polynomial()
    {
        this->degCoeff = new int[6];
        this->capacity = 5;
    }

    Polynomial(int capacity)
    {
        this->degCoeff = new int[capacity + 1];
        this->capacity = capacity;
    }

    Polynomial(Polynomial const& p)
    {
        int* newdeg = new int[p.capacity + 1];

        for (int i = 0; i <= p.capacity; i++)
            newdeg[i] = p.degCoeff[i];

        this->degCoeff = newdeg;

        this->capacity = p.capacity;
    }

    void setCoefficient(int deg, int coef)
    {
        if (deg > capacity) {
            int newcapacity = deg;
            int* newdeg = new int[newcapacity + 1];

            for (int i = 0; i <= capacity; i++)
                newdeg[i] = degCoeff[i];

            this->degCoeff = newdeg;
            this->capacity = newcapacity;

            degCoeff[deg] = coef;
        } else {
            degCoeff[deg] = coef;
        }
    }

    Polynomial operator+(Polynomial const& P2)
    {

        int newcap = max(this->capacity, P2.capacity);

        Polynomial P3(newcap);

        for (int i = 0; i <= newcap; i++) {
            if (i <= capacity && i <= P2.capacity)
                P3.degCoeff[i] = this->degCoeff[i] + P2.degCoeff[i];
            else if (i <= capacity)
                P3.degCoeff[i] = this->degCoeff[i];
            else
                P3.degCoeff[i] = P2.degCoeff[i];
        }

        return P3;
    }

    Polynomial operator-(Polynomial const& P2)
    {

        int newcap = max(this->capacity, P2.capacity);
        Polynomial P3(newcap);

        for (int i = 0; i <= newcap; i++) {
            if (i <= capacity && i <= P2.capacity)
                P3.degCoeff[i] = this->degCoeff[i] - P2.degCoeff[i];
            else if (i <= capacity)
                P3.degCoeff[i] = this->degCoeff[i];
            else
                P3.degCoeff[i] = -P2.degCoeff[i];
        }

        return P3;
    }

    Polynomial operator*(Polynomial const& P2)
    {

        int newcap = this->capacity + P2.capacity;
        Polynomial P3(newcap);

        for (int i = 0; i <= this->capacity; i++) {

            for (int j = 0; j <= P2.capacity; j++) {
                P3.degCoeff[i + j] += this->degCoeff[i] * P2.degCoeff[j];
            }
        }
        return P3;
    }

    void operator=(Polynomial const& p)
    {
        int* newdeg = new int[p.capacity + 1];

        for (int i = 0; i < p.capacity; i++)
            newdeg[i] = p.degCoeff[i];

        this->degCoeff = newdeg;

        this->capacity = p.capacity;
    }

    void print()
    {

        for (int i = 0; i <= this->capacity; i++) {
            if (degCoeff[i] != 0)
                cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    int count1, count2, choice;
    cin >> count1;

    int* degree1 = new int[count1];
    int* coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int* degree2 = new int[count2];
    int* coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    switch (choice) {

    case 1: {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }

    case 2: {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }

    case 3: {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
```

### Fraction Class

```cpp
#include <bits/stdc++.h>
using namespace std;

class Fraction {
    // Complete the class
public:
    int numerator;
    int denominator;
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void add(Fraction obj)
    {
        this->numerator = numerator * obj.denominator + obj.numerator * denominator;
        this->denominator = denominator * obj.denominator;
    }
    void multiply(Fraction obj)
    {
        this->numerator = this->numerator * obj.numerator;
        this->denominator = this->denominator * obj.denominator;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++) {
            if (this->numerator % i == 0 && this->denominator % i == 0) {
                gcd = i;
            }
        }
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;
    }
    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{

    // Write your code here
    int num, demo;
    cin >> num >> demo;
    int queries;
    cin >> queries;
    Fraction ob(num, demo);
    while (queries > 0) {
        int qtype, num2, demo2;
        cin >> qtype >> num2 >> demo2;
        Fraction obj(num2, demo2);
        if (qtype == 1) {
            ob.add(obj);
            ob.simplify();
            ob.print();
        } else {
            ob.multiply(obj);
            ob.simplify();
            ob.print();
        }
        queries--;
    }

    return 0;
}
```

### Print name and age

```cpp
#include <bits/stdc++.h>
using namespace std;

class Person {
    // Complete the class
private:
    string name;
    int age;

public:
    void setValue(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void getValue()
    {
        cout << "The name of the person is " << name << " and the age is " << age << "." << endl;
    }
};

int main()
{

    // Write your code here
    string name;
    cin >> name;

    int age;
    cin >> age;

    Person p;
    p.setValue(name, age);
    p.getValue();

    return 0;
}
```

### Area Of Rectangle

```cpp
#include <bits/stdc++.h>
class Rectangle {
    // Write your code here.
public:
    double length;
    double breadth;
    double getArea()
    {
        return length * breadth;
    }
};
```
